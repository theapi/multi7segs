
/** 
 *  6 X 4 seven segment displays.
 *
 * COMMON ANODE displays driven by MAX7219
 *  
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


/**
 * Map of common anode wiring:
 * 
 *    Bit    : Digit
 * B00000001 : 5 
 * B00000010 : 7
 * B00000100 : 3
 * B00001000 : 1
 * B00010000 : 4
 * B00100000 : 6
 * B01000000 : 8
 * B10000000 : 2
 * 
 */

  
  driver.setDigit(1, B10000000, false);
  driver.setDigit(2, B10000001, false);
  driver.setDigit(3, B10000001, false);
  driver.setDigit(4, B10000000, false);
  driver.setDigit(5, B10000000, false);
  driver.setDigit(6, B10000000, false);
  driver.setDigit(7, B10000000, false);
  driver.setDigit(8, B10000000, false);

  driver.displayOn();
  
}

void loop() {
 
}

