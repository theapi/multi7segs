
#include "DisplayMax72xxCA.h"

DisplayMax72xxCA::DisplayMax72xxCA() {}

void DisplayMax72xxCA::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin) {

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

  uint8_t bit;
  switch (digit) {
    case 1: bit = 3; break;
    case 2: bit = 7; break;
    case 3: bit = 2; break;
    case 4: bit = 4; break;
    case 5: bit = 0; break;
    case 6: bit = 5; break;
    case 7: bit = 1; break;
    case 8: bit = 6; break;
  }

  // digits are grouped in 8, due the 8 registers.
  // buffer indexes for this digit start at digit / 8
  uint8_t i = digit / 8;
  for (i; i < 8; i++)  {
    _buffer[i] |= (val & (1 << bit));
  }
  
}

void DisplayMax72xxCA::update() {
  //...
  uint8_t j = 0;
  uint8_t chip = 0;
  uint8_t address = 0;
  for (uint8_t i = 0; i < DisplayMax72xxCA_NUM_DIGITS; i++) {
    
    if (j == 8) {
      chip++;
      j = 0;
    } else {
      j++;
    }

    address = j + 1;
    
    driver.sendPacketToChip(chip, address, _buffer[i]);
    
  }
  
  
  //...
}

