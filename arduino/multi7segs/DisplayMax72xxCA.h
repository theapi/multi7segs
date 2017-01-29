
#ifndef DisplayMax72xxCA_h
#define DisplayMax72xxCA_h

#include "Max72xx.h"

class DisplayMax72xxCA {
    private :

      uint8_t _numDigits;
      uint8_t _numChips;
        

    public:

      /** 
       * The Max7219 driver 
       */
      Max72xx driver;
    
      /**
       * Constructor
       *
       */
      DisplayMax72xxCA();

      /**
       * Initialise the driver.
       * 
       * dataPin    shifts the data out
       * clockPin   the clock
       * latchPin   the data latch
       */
      void setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin, uint8_t numDigits);

};

#endif

