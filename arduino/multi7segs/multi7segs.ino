
/** 
 *  6 X 4 seven segment displays.
 *
 * COMMON ANODE displays driven by MAX7219
 *  
 */

#include "DisplayMax72xxCA.h"

#define DRIVER_DIN  D5
#define DRIVER_SCK  D6
#define DRIVER_LOAD D7
#define DRIVER_NUM_DIGITS 24 // 3 Max7219 ICs used

const byte DEBUG_LED = 16;

DisplayMax72xxCA display = DisplayMax72xxCA();

void setup() {
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, LOW);  // LOW = ON


  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD, DRIVER_NUM_DIGITS);
  
  


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

  /*
  driver.setDigit(1, B10000000, false);
  driver.setDigit(2, B10000001, false);
  driver.setDigit(3, B10000001, false);
  driver.setDigit(4, B10000000, false);
  driver.setDigit(5, B10000000, false);
  driver.setDigit(6, B10000000, false);
  driver.setDigit(7, B10000000, false);
  driver.setDigit(8, B10000000, false);

  driver.displayOn();
  */
}

void loop() {
 
}

