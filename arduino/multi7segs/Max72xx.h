
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

    public:
    
      /**
       * Constructor
       */
      Max72xx();

      /**
       * Initialise the driver.
       * 
       * dataPin    shifts the data out
       * clockPin   the clock
       * latchPin   the data latch
       */
      void setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin);

      /**
       * Sends the serial data to the target chip.
       */
      void sendPacketToChip(uint8_t chip, uint8_t address, uint8_t data);

      /**
       * Sends the 16 bit serial packet to the driver
       */
      void sendPacket(uint8_t address, uint8_t data);

      /**
       * Set the number of digits (or rows) to be displayed.
       * See datasheet for side effects of the scanlimit on the brightness
       * of the display.
       * @param limit  The number of digits to be displayed (1..8)
       */
      void setScanLimit(uint8_t chip, uint8_t limit);

      /**
       * 0 - 15
       */
      void setIntensity(uint8_t chip, uint8_t intensity);

      void testOn(uint8_t chip);

      void testOff(uint8_t chip);

      void shutdown(uint8_t chip, bool b);

      void displayOn(uint8_t chip);

      void displayOff(uint8_t chip);
      
      void decodeMode(uint8_t chip, uint8_t data);

      void setRegister(uint8_t chip, uint8_t address, uint8_t data);
};

#endif

