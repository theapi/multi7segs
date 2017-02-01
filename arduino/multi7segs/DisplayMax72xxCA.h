
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

      static const uint8_t number_0 = B01111011;
      static const uint8_t number_1 = B00001001;
      static const uint8_t number_2 = B01100111;
      static const uint8_t number_3 = B01101101;
      static const uint8_t number_4 = B00011101;
      static const uint8_t number_5 = B01111100;
      static const uint8_t number_6 = B00111110;
      static const uint8_t number_7 = B01001001;
      static const uint8_t number_8 = B01111111;
      static const uint8_t colon    = B10000000;
      static const uint8_t blank    = B00000000;
      static const uint8_t char_H   = B00011111;
      static const uint8_t char_E   = B01110110;
      static const uint8_t char_L   = B00110010;
      
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
      uint8_t getColumn(uint8_t digit);

      void update();

};

#endif

