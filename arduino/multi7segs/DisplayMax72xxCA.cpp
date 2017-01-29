
#include "DisplayMax72xxCA.h"

DisplayMax72xxCA::DisplayMax72xxCA() {
  
}

void DisplayMax72xxCA::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin, uint8_t numDigits) {

  _numDigits = numDigits;
  _numChips = _numDigits / 8; // 8 digits per Max72xx
  
  driver.setup(dataPin, clkPin, latchPin);

  // @todo Initialise all chips
  driver.shutdown(1);
  driver.setScanLimit(7);
  driver.setIntensity(5);
  driver.decodeMode(0x00);
}



