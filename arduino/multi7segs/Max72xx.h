
#ifndef Max72xx_h
#define Max72xx_h

#include "Arduino.h"

class Max72xx {
    private :

        // Data is shifted out of this pin
        uint8_t _din;
        // The clock is signaled on this pin
        uint8_t _clk;
        // Driven LOW to latch the data
        uint8_t _load;
        // How many MAX72xx ICs are used
        uint8_t _numChips;

    public:
    
      /**
       * Constructor
       * dataPin    shifts the data out
       * clockPin   the clock
       * latchPin   the data latch
       */
      Max72xx(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin, uint8_t numChips);

      /**
       * Initialise the driver.
       */
      void setup();

      /**
       * Sends the serial data to the target chip.
       */
      void sendPacketToChip(int8_t chip, int8_t address, int8_t data);

      /**
       * Sends the 16 bit serial packet to the driver
       */
      void sendPacket(int8_t address, int8_t data);

      /**
       * Set the number of digits (or rows) to be displayed.
       * See datasheet for sideeffects of the scanlimit on the brightness
       * of the display.
       * @param limit  The number of digits to be displayed (1..8)
       */
      void setScanLimit(uint8_t limit);

      /**
       * 0 - 15
       */
      void setIntensity(uint8_t intensity);

      void testOn();

      void testOff();

      void shutdown(bool b);

      void displayOn();

      void displayOff();
      
      void decodeMode(int8_t data);

      void setDigit(int8_t address, int8_t data, boolean dp);
};

#endif

