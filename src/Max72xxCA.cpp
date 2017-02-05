
#include "Max72xxCA.h"

Max72xxCA::Max72xxCA() {}

void Max72xxCA::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin) {
   Serial.println(" setup");
  _numDigits = Max72xxCA_NUM_DIGITS; // Num digits is set as a #define so as to avoid dynamically sized buffer.
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
    driver.setIntensity(i, 10);
    driver.decodeMode(i, 0x00);
  }

  Serial.println(" end setup");
}

/**
 * Give the binary/hex representation of the 7 segment digit.
 * e.g., 4, B11111111 = 8 displayed on digit 4
 */
void Max72xxCA::setDigit(uint8_t digit, uint8_t data) {
  // Need to set 8 registers for a digit, BUT do not clober existing digit values.
  // So OR the value for this digit with those of the other digits for the chip the digit is on.
  // Which bit is used for the digit is determined by the wiring.
  // digits are grouped in 8, due the 8 registers.
  // buffer indexes for this digit start at digit-1 / 8
  // digit numbers start at 1 not 0.
  uint8_t reg_base = ((digit -1) / 8) * 8;
  uint8_t reg;
  uint8_t col;
  uint8_t bit_value;

  col = getColumn(digit);
  Serial.println(" setDigit");
  Serial.print(" digit:"); Serial.print(digit);
  Serial.print(" col:"); Serial.print(col);
  Serial.print(" reg_base:"); Serial.print(reg_base);
  Serial.print(" data:"); Serial.print(data, BIN);
  Serial.println();

  for (uint8_t i = 0; i < 8; i++)  {
    // Read each bit in the data and put it in the buffer for its register.
    reg = reg_base + getRegister(i);
    bit_value = bitRead(data, i);
    Serial.print(" reg:"); Serial.print(reg);
    Serial.print(" bit_value:"); Serial.print( bit_value , BIN); Serial.print(" "); 
    bitWrite(_buffer[reg], col, bit_value);
    Serial.print(" buffer:");  Serial.println( _buffer[reg], BIN);
  }
  
  Serial.println();
}

/**
 * Get the "column" in the 8 registers this digits bits are set.
 * 
 * This is effected by the wiring.
 */
uint8_t Max72xxCA::getColumn(uint8_t digit) {
  switch (digit % 8) {
    case 0: return 6;
    case 1: return 3;
    case 2: return 7;
    case 3: return 2;
    case 4: return 4;
    case 5: return 0;
    case 6: return 5;
    case 7: return 1;
  }

  // Shouldn't get here.
  return 0;
}

/**
 * Translate the data bit to the register it should be set in.
 * 
 * This is effected by the wiring.
 */
uint8_t Max72xxCA::getRegister(uint8_t bit) {
  switch (bit) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
  }

  // Shouldn't get here.
  return 0;
}

void Max72xxCA::update() {
  //...
  Serial.println(" Update");
  uint8_t j = 0;
  uint8_t chip = 1;
  uint8_t address = 0;
  for (uint8_t i = 0; i < Max72xxCA_NUM_DIGITS; i++) {
    address = j + 1;
    

    Serial.print(chip);
    Serial.print(" : ");
    Serial.print(address, HEX);
    Serial.print(" : ");
    Serial.print( _buffer[i], BIN);
    Serial.println();
    driver.sendPacketToChip(chip, address, _buffer[i]);

    if (j == 7) {
      chip++;
      j = 0;
    } else {
      j++;
    }
    
  }
  
  
  //...
}

