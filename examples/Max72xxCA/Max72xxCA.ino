
/** 
 *  6 X 4 seven segment displays.
 *
 * COMMON ANODE displays driven by MAX7219
 *  
 */

//Max72xxCA_NUM_DIGITS 24
#include "Max72xxCA.h"

#define DRIVER_DIN  14 // D5 on NodeMcu
#define DRIVER_SCK  12 // D6 on NodeMcu
#define DRIVER_LOAD 13 // D7 on NodeMcu

const byte DEBUG_LED = 16;
byte colon1 = false;

Max72xxCA display = Max72xxCA();

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("-----------------");
  Serial.println();
  
  pinMode(DEBUG_LED, OUTPUT);
  digitalWrite(DEBUG_LED, HIGH);  // LOW = ON


  display.setup(DRIVER_DIN, DRIVER_SCK, DRIVER_LOAD);

  display.setDigitToNumber(1, 4);
  display.setDigitToNumber(2, 3);
  
//  display.setDigit(1, display.number_4);
//  display.setDigit(2, display.number_3);
//  display.setDigit(3, display.number_2 | display.colon);
  display.setDigitToNumber(3, 2, colon1);

  display.setDigit(4, display.number_1);
  display.setDigit(5, display.number_0);
  display.setDigit(6, display.char_L);
  display.setDigit(7, display.char_E);
  display.setDigit(8, display.char_H);

  display.setDigit(9, display.number_1);
  display.setDigit(10, display.number_2);
  display.setDigit(11, display.number_3);
  display.setDigit(12, display.number_4);

  display.setDigitToNumber(16, 5);
  display.setDigitToNumber(15, 6);
  display.setDigitToNumber(14, 7);
  display.setDigitToNumber(13, 8);

  display.setDigit(17, display.number_8);
  display.setDigit(18, display.number_7);
  display.setDigit(19, display.number_6);
  display.setDigit(20, display.number_5);
  display.setDigit(21, display.number_4);
  display.setDigit(22, display.number_3);
  display.setDigit(23, display.number_2);
  display.setDigit(24, display.number_1);
  
  display.update();
  
  display.displaysOn();
}

void loop() {
  Serial.println(colon1);
  delay(1000);

  display.setDigitToNumber(3, 2, colon1);
  if (colon1) {
    colon1 = false;
  }
  else {
    colon1 = true;
  }
  
  display.setDigitToNumber(9, random(0, 8));
  display.setDigitToNumber(10, random(0, 8));
  display.setDigitToNumber(11, random(0, 8));
  display.setDigitToNumber(12, random(0, 8));
  
  display.update();
}

