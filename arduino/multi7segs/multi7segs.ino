
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
  Serial.begin(115200);
  Serial.println();
  Serial.println("-----------------");
  Serial.println();
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON


  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

  
  display.setDigit(1, display.number_4);
  display.setDigit(2, display.number_3);
  display.setDigit(3, display.number_2 | display.colon);
  display.setDigit(4, display.number_1);
  display.setDigit(5, display.number_0);
  display.setDigit(6, display.char_L);
  display.setDigit(7, display.char_E);
  display.setDigit(8, display.char_H);

  display.setDigit(9, display.number_4);
  display.setDigit(10, display.number_3);
  display.setDigit(11, display.number_2 | display.colon);
  display.setDigit(12, display.number_1);
  display.setDigit(13, display.number_0);
  display.setDigit(14, display.char_L);
  display.setDigit(15, display.char_E);
  display.setDigit(16, display.char_H);
  
  //display.setDigit(23, display.number_8);
  display.update();
  
  display.driver.displayOn(1);
  
}

void loop() {
 //delay(1);
 //display.update();
}

