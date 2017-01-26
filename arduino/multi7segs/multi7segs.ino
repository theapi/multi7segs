
/** 
   6 X 4 seven segment displays.

   Driven by MAX7219
*/

#include "Max72xx.h"

#define DRIVER_DIN  D5
#define DRIVER_SCK  D6
#define DRIVER_LOAD D7

const byte DEBUG_LED = 16;

Max72xx driver = Max72xx(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

void setup() {
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, LOW);  // LOW = ON


  driver.setup();
  
  driver.decodeMode(0x00);
  
  driver.setDigit(1, B00000001, false);
  driver.setDigit(2, B00000010, false);
  driver.setDigit(3, B00000100, false);
  driver.setDigit(4, B00001000, false);
  
  driver.setDigit(5, B00010000, false);
  driver.setDigit(6, B00100000, false);
  driver.setDigit(7, B01000000, false);
  driver.setDigit(8, B10000000, false);

  driver.displayOn();
  
}

void loop() {
 
}

