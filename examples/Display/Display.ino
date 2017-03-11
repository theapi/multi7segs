
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

//Max72xxCA_NUM_DIGITS 24
#include "Max72xxCA.h"

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;

#define DRIVER_DIN  14 // D5 on NodeMcu
#define DRIVER_SCK  12 // D6 on NodeMcu
#define DRIVER_LOAD 13 // D7 on NodeMcu

const byte DEBUG_LED = 16;


Max72xxCA display = Max72xxCA();
ESP8266WebServer server = ESP8266WebServer(80);

void setup() {

  Serial.begin(115200);
  
  // Start the Over The Air programming.
  denbit.OTAsetup();

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON

  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);


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

  display.setDigit(5, display.number_0);
  display.setDigit(6, display.char_L);
  display.setDigit(7, display.char_E);
  display.setDigit(8, display.char_H);

  display.update();
  
  display.displaysOn();
  
}

void loop() {
  server.handleClient();
  // Check for any Over The Air updates.
  denbit.OTAhandle();
}

