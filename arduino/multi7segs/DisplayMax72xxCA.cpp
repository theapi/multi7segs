
#include "DisplayMax72xxCA.h"

DisplayMax72xxCA::DisplayMax72xxCA() {}

void DisplayMax72xxCA::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin) {
   Serial.println(" setup");
  _numDigits = DisplayMax72xxCA_NUM_DIGITS; // Num digits is set as a #define so as to avoid dynamically sized buffer.
  _numChips = _numDigits / 8; // 8 digits per Max72xx
  if (_numDigits % 8 > 0) {
    // Not exactly divisable by 8, so add another chip.
    _numChips++;
  }
  
  driver.setup(dataPin, clkPin, latchPin);

  // Initialise all chips
  for (uint8_t i = 1; i <= _numChips; i++) {
    driver.shutdown(i, 1);
    driver.setScanLimit(i, 7);
    driver.setIntensity(i, 5);
    driver.decodeMode(i, 0x00);
  }

  Serial.println(" end setup");
}

/**
 * Give the binary/hex representation of the 7 segment digit.
 * e.g., 4, B11111111 = 8 displayed on digit 4
 */
void DisplayMax72xxCA::setDigit(uint8_t digit, uint8_t val) {
  // Need to set 8 registers for a digit, BUT do not clober existing digit values.
  // So OR the value for this digit with those of the other digits for the chip the digit is on.
  // Which bit is used for the digit is determined by the wiring.
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

  uint8_t wire;
  uint8_t bit;
  // Each digit is on one of 8 wires.
  wire = digit % 8;
  switch (wire) {
    case 0: bit = 3; break;
    case 1: bit = 7; break;
    case 2: bit = 2; break;
    case 3: bit = 4; break;
    case 4: bit = 0; break;
    case 5: bit = 5; break;
    case 6: bit = 1; break;
    case 7: bit = 6; break;
  }
  
  // digits are grouped in 8, due the 8 registers.
  // buffer indexes for this digit start at digit / 8
  Serial.println(" setDigit");
  Serial.print(" digit:"); Serial.print(digit);
  Serial.print(" val:"); Serial.print(val, BIN);
  Serial.print(" wire:"); Serial.print(wire);
  Serial.print(" bit:"); Serial.print(bit);

    Serial.println(" buffer:"); 
  uint8_t i = digit / 8;
  for (i; i < 8; i++)  {
    Serial.print(" bitshift:"); Serial.print((val & (1 << bit)), BIN); Serial.print(" "); 
    _buffer[i] |= (val & (1 << bit)); //@todo fix this
    Serial.println( _buffer[i], BIN);
  }
  
  Serial.println();
}

void DisplayMax72xxCA::update() {
  //...
  Serial.println(" Update");
  uint8_t j = 0;
  uint8_t chip = 1;
  uint8_t address = 0;
  for (uint8_t i = 0; i < DisplayMax72xxCA_NUM_DIGITS; i++) {
    address = j + 1;
    if (j == 7) {
      chip++;
      j = 0;
    } else {
      j++;
    }

    Serial.print(chip);
    Serial.print(" : ");
    Serial.print(address, HEX);
    Serial.print(" : ");
    Serial.print( _buffer[i], BIN);
    Serial.println();
    driver.sendPacketToChip(chip, address, _buffer[i]);
    
  }
  
  
  //...
}

