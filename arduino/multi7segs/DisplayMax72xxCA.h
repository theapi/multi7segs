
#ifndef DisplayMax72xxCA_NUM_DIGITS
#define DisplayMax72xxCA_NUM_DIGITS 24
#endif


#ifndef DisplayMax72xxCA_h
#define DisplayMax72xxCA_h

#include "Max72xx.h"

class DisplayMax72xxCA {
    private :

      uint8_t _numDigits;
      uint8_t _numChips;
      uint8_t _buffer[DisplayMax72xxCA_NUM_DIGITS];

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
      void setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin);

      void setDigit(uint8_t digit, uint8_t value);
      uint8_t getRegister(uint8_t bit);

      void update();

};

#endif

