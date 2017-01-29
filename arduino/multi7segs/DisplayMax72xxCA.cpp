
#include "DisplayMax72xxCA.h"

DisplayMax72xxCA::DisplayMax72xxCA() {
  
}

void DisplayMax72xxCA::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin, uint8_t numChips) {
  driver.setup(dataPin, clkPin, latchPin, numChips);
}



