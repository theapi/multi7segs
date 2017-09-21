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
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>

//Max72xxCA_NUM_DIGITS 24
#include "Max72xxCA.h"

#include "Payload.h"
#include "GardenPayload.h"

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;


#define DRIVER_SCK  D6 // 12
#define DRIVER_DIN  D5 // 14
#define DRIVER_LOAD D7 // 13

theapi::GardenPayload rx_payload = theapi::GardenPayload();

WiFiUDP Udp;
// Multicast declarations
IPAddress ipMulti(239, 0, 0, 57);
unsigned int portMulti = 12345;      // local port to listen on
char incomingPacket[255];  // buffer for incoming packets

const byte DEBUG_LED = 16;

int display_status = 0;

 
const long seconds_interval = 1000;
unsigned long seconds_last = seconds_interval + 1;

Max72xxCA display = Max72xxCA();
ESP8266WebServer server = ESP8266WebServer(80);


void setup() {

  Serial.begin(115200);
  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

  display.setDigit(5, display.number_0);
  display.setDigit(6, display.char_L);
  display.setDigit(7, display.char_E);
  display.setDigit(8, display.char_H);

  display.update();
  
  display.displaysOn();
  display_status = 1;
  
  // Start the Over The Air programming.
  denbit.OTAsetup();

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Udp.beginMulticast(WiFi.localIP(), ipMulti, portMulti);
  Serial.printf("Now listening to IP %s, UDP port %d\n", ipMulti.toString().c_str(), portMulti);
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON


  server.on("/data.json", []() {
    // Set the digits.
    for (uint8_t i = 0; i < server.args(); i++ ) {
      if (server.argName(i).indexOf('d') == 0) {
         String d = server.argName(i).substring(1);
         display.setDigitToNumber(d.toInt(), server.arg(i).toInt());
      } else if (server.argName(i).indexOf("mode") == 0) {
         if (server.arg(i) == "on") {
           display_status = 1;
           display.displaysOn();
         } else if (server.arg(i) == "off") {
           display_status = 2; // So the ldr does not turn it back on.
           display.displaysOff();
         }
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

  // Check light level, and turn off the display if dark.
  unsigned long now = millis();
  if (now - seconds_last >= seconds_interval) {
    seconds_last = now;
    int ldr = analogRead(A0);
    if (ldr < 10) {
      display_status = 0;
      display.displaysOff();
    } else if (display_status == 0 && ldr > 20) {
      display_status = 1;
      display.displaysOn();
    }
  }

  // Check for udp data. 
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)  {
      incomingPacket[len] = 0;
    }
    //Serial.printf("UDP packet contents: %s\n", incomingPacket);
    // Check for payload signifier;
    if (incomingPacket[0] == '\t') {
      uint8_t payload_buf[rx_payload.size()];
      memcpy(payload_buf, incomingPacket+1, rx_payload.size());
      rx_payload.unserialize(payload_buf);
      if (rx_payload.getMsgType() == theapi::Payload::GARDEN) {
        Serial.print("GARDEN: ");
        Serial.print(rx_payload.getMsgType()); Serial.print(", ");
        Serial.print(rx_payload.getMsgId()); Serial.print(", ");
        Serial.print(rx_payload.getVcc()); Serial.print(", ");
        Serial.print(rx_payload.getChargeMv()); Serial.print(", ");
        Serial.print(rx_payload.getChargeMa()); Serial.print(", ");
        Serial.print(rx_payload.getLight()); Serial.print(", ");
        Serial.print(rx_payload.getCpuTemperature()); Serial.print(", ");
        // Convert the temperature to a float.
        float deg = (float) rx_payload.getTemperature() / 10.0;
        Serial.println(deg);
        Serial.println();
  
  
        displayBlock(6, rx_payload.getChargeMa());
        displayBlock(4, rx_payload.getChargeMv());
        displayBlock(2, rx_payload.getVcc());
      
        displayBlockTemperature(5, deg);
        displayBlock(3, rx_payload.getMsgId());
        displayBlock(1, rx_payload.getLight());
        display.update();
      }
    }
  }

}


void displayBlock(int block, int i) {
  // Each block has 4 digits.
  
  if (i > 999) {
    display.setDigitToNumber((block * 4), i / 1000);
  } else {
    display.setDigitToNumber((block * 4), 10);
  }

  if (i > 99) {
    display.setDigitToNumber((block * 4) - 1, (i % 1000) / 100);
  } else {
    display.setDigitToNumber((block * 4) - 1, 10);
  }
  
  if (i > 9) {
    display.setDigitToNumber((block * 4) - 2, (i / 10) % 10);
  } else {
    display.setDigitToNumber((block * 4) - 2, 10);
  }
  
  display.setDigitToNumber((block * 4) - 3, i % 10);
}

void displayBlockTemperature(int block, float f) {

  // Tens
  if (f > 9) {
    display.setDigitToNumber((block * 4), (int) f / 10);
  } else {
    display.setDigitToNumber((block * 4), 10);
  }

  // Ones, with a decimal point.
  int ones = f / 10;
  display.setDigitToNumber((block * 4) - 1, ones % 10, 1);

  // Decimal
  int fraction = f * 10;
  display.setDigitToNumber((block * 4) - 2, fraction % 10);
  
  // Show degrees symbol.
  display.setDigit((block * 4) - 3, display.degrees);
}

