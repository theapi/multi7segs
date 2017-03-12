
#ifndef Max72xxCA_NUM_DIGITS
#define Max72xxCA_NUM_DIGITS 24
#endif


#ifndef Max72xxCA_h
#define Max72xxCA_h

#include "Max72xx.h"

#define Max72xxCA_NUM_CHARS 15

class Max72xxCA {
    private :

      uint8_t _numDigits;
      uint8_t _numChips;
      uint8_t _buffer[Max72xxCA_NUM_DIGITS];
      uint8_t _chars[Max72xxCA_NUM_CHARS] = {
        B01111011,
        B00001001,
        B01100111,
        B01101101,
        B00011101,
        B01111100,
        B00111110,
        B01001001,
        B01111111,
        B01011101,

        B00000000, // blank
        B00011111, // H
        B01110110, // E
        B00110010, // L
        B10000000, // colon
      };

    public:

        uint8_t number_0 = _chars[0];
        uint8_t number_1 = _chars[1];
        uint8_t number_2 = _chars[2];
        uint8_t number_3 = _chars[3];
        uint8_t number_4 = _chars[4];
        uint8_t number_5 = _chars[5];
        uint8_t number_6 = _chars[6];
        uint8_t number_7 = _chars[7];
        uint8_t number_8 = _chars[8];
        uint8_t number_9 = _chars[9];

        uint8_t blank    = _chars[10];
        uint8_t char_H   = _chars[11];
        uint8_t char_E   = _chars[12];
        uint8_t char_L   = _chars[13];
        uint8_t colon    = _chars[14];

      /**
       * The Max7219 driver
       */
      Max72xx driver;

      /**
       * Constructor
       *
       */
      Max72xxCA();

      /**
       * Initialise the driver.
       *
       * dataPin    shifts the data out
       * clockPin   the clock
       * latchPin   the data latch
       */
      void setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin);
      void displaysOn();
      void setDigit(uint8_t digit, uint8_t value);
      void setDigitToNumber(uint8_t digit, uint8_t index);
      void setDigitToNumber(uint8_t digit, uint8_t index, uint8_t colon);
      uint8_t getDigit(uint8_t digit);
      uint8_t getDigitValue(uint8_t digit);
      uint8_t getRegister(uint8_t bit);
      uint8_t getColumn(uint8_t digit);

      void update();

};

#endif

