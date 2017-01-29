
/** 
 *  6 X 4 seven segment displays.
 *
 * COMMON ANODE displays driven by MAX7219
 *  
 */

//DisplayMax72xxCA_NUM_DIGITS 24
#include "DisplayMax72xxCA.h"

#define DRIVER_DIN  D5
#define DRIVER_SCK  D6
#define DRIVER_LOAD D7

const byte DEBUG_LED = 16;

DisplayMax72xxCA display = DisplayMax72xxCA();

void setup() {
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, LOW);  // LOW = ON


  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);
  
  


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

  
  display.driver.setRegister(1, 0x01, B10000000);
  display.driver.setRegister(1, 0x02, B10000001);
  display.driver.setRegister(1, 0x03, B10000001);
  display.driver.setRegister(1, 0x04, B10000000);
  display.driver.setRegister(1, 0x05, B10000000);
  display.driver.setRegister(1, 0x06, B10000000);
  display.driver.setRegister(1, 0x07, B10000000);
  display.driver.setRegister(1, 0x08, B10000000);

  display.setDigit(4, B11111111);

  display.update();
  display.driver.displayOn(1);
  
}

void loop() {
 
}

