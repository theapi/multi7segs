/** 
 * Set the values of the 6 X 4 seven segment displays via a GET request.
 * 
 * e.g.
 * /data.json?d1=8&d2=7&d3=6&d4=5&d5=10&d6=10&d7=10&d8=10&d9=10&d10=10&d11=10&d12=10&d13=0&d14=13&d15=12&d16=11&d17=4&d18=3&d19=2&d20=1
 *
 * COMMON ANODE displays driven by MAX7219
 *  
 */

 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <TimeLib.h>

//Max72xxCA_NUM_DIGITS 24
#include "Max72xxCA.h"

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

#define DRIVER_DIN  14 // D5 on NodeMcu
#define DRIVER_SCK  12 // D6 on NodeMcu
#define DRIVER_LOAD 13 // D7 on NodeMcu

#define NTP_INTERVAL 60 * 60 * 1000

const byte DEBUG_LED = 16;

unsigned int localPort = 2390;      // local port to listen for UDP packets
 
/* Don't hardwire the IP address or we won't get the benefits of the pool.
 *  Lookup the IP address for the host name instead */
//IPAddress timeServer(129, 6, 15, 28); // time.nist.gov NTP server
IPAddress timeServerIP; // NTP server address
const char* ntpServerName = "uk.pool.ntp.org";
 
const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
 
byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets


long ntp_interval = 1500; // Initital try to set the time often.
unsigned long ntp_last = ntp_interval + 1;
const long seconds_interval = 1000;
unsigned long seconds_last = seconds_interval + 1;

Max72xxCA display = Max72xxCA();
ESP8266WebServer server = ESP8266WebServer(80);

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

void setup() {

  Serial.begin(115200);
  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

  display.setDigit(5, display.number_0);
  display.setDigit(6, display.char_L);
  display.setDigit(7, display.char_E);
  display.setDigit(8, display.char_H);

  display.update();
  
  display.displaysOn();
  
  // Start the Over The Air programming.
  denbit.OTAsetup();

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON

  


  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());

  server.on("/data.json", []() {
    // Set the digits.
    for (uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i).indexOf('d') == 0) {
         String d = server.argName(i).substring(1);
         display.setDigitToNumber(d.toInt(), server.arg(i).toInt());
      }
    }
    display.update();

    // Respond with the current digit values.
    String message = "{";
    message += "\"digits\": [";
    for (uint8_t i = 1; i <= Max72xxCA_NUM_DIGITS; i++ ) {
      message += "{\"digit\": " + String(i) + ",";
      // @todo handle the colon in display.getDigitValue(i);
      message += "\"value\": " + String(display.getDigitValue(i)) + "}";
      if (i < Max72xxCA_NUM_DIGITS) {
        message += ",";
      }
    }
    message += "]"; // end digits
    message += "}\n";
    
    server.send(200, "application/json", message);
  });

  server.begin();



  // Display IP address
  IPAddress ip = WiFi.localIP();
  display.setDigitToNumber(20, ip[0] / 100);
  display.setDigitToNumber(19, (ip[0] / 10) % 10);
  display.setDigitToNumber(18, ip[0] % 10);
  
  display.setDigitToNumber(17, ip[1] / 100);
  display.setDigitToNumber(12, (ip[1] / 10) % 10);
  display.setDigitToNumber(11, ip[1] % 10);

  display.setDigitToNumber(10, ip[2] / 100);
  display.setDigitToNumber(9, (ip[2] / 10) % 10);
  display.setDigitToNumber(4, ip[2] % 10);

  display.setDigitToNumber(3, ip[3] / 100);
  display.setDigitToNumber(2, (ip[3] / 10) % 10);
  display.setDigitToNumber(1, ip[3] % 10);

  display.update();
  
}

void loop() {
  // Handel web server requests.
  server.handleClient();
  
  // Check for any Over The Air updates.
  denbit.OTAhandle();

  // Correct the clock time if needed.
  ntp();

  // Show the time.
  unsigned long now = millis();
  if (now - seconds_last >= seconds_interval) {
    seconds_last = now;
    displayCurrentTime();
  }
}


void displayCurrentTime() {
  byte h = hour();
  byte m = minute();

  // Hours
  if (h < 10) {
    display.setDigitToNumber(24, 10);
  }
  else {
    display.setDigitToNumber(24, h / 10);
  }
  display.setDigitToNumber(23, h % 10, true);

  // Minutes
  if (m < 10) {
    display.setDigitToNumber(22, 0);
  }
  else {
    display.setDigitToNumber(22, m / 10);
  }
  display.setDigitToNumber(21, m % 10);
  
  display.update();
}

void ntp() {
  static byte awating_packet = 0;

  unsigned long now = millis();

  if (now - ntp_last >= ntp_interval) {
    ntp_last = now;
    WiFi.hostByName(ntpServerName, timeServerIP); 
   
    sendNTPpacket(timeServerIP); // send an NTP packet to a time server
    awating_packet = 1;
  }

  if (awating_packet == 1 && (now - ntp_last > 1000)) {
    int cb = udp.parsePacket();
    if (cb) {
      // Now that the initial time has been set, check the time less often.
      ntp_interval = NTP_INTERVAL;
      
      //Serial.print("packet received, length=");
      //Serial.println(cb);
      awating_packet = 0;
      // We've received a packet, read the data from it
      udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer
   
      // The timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, esxtract the two words:
   
      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      //Serial.print("Seconds since Jan 1 1900 = " );
      //Serial.println(secsSince1900);
   
      // now convert NTP time into everyday time:
      //Serial.print("Unix time = ");
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long unixTime = secsSince1900 - seventyYears;

      setTime(unixTime);
      //Serial.println(minute());

    }
  }

}

// send an NTP request to the time server at the given address
unsigned long sendNTPpacket(IPAddress& address)
{
  //Serial.println("sending NTP packet...");
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;
 
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  udp.beginPacket(address, 123); //NTP requests are to port 123
  udp.write(packetBuffer, NTP_PACKET_SIZE);
  udp.endPacket();
}

