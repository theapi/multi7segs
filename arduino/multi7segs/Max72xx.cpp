
#include "Max72xx.h"

Max72xx::Max72xx() {}

void Max72xx::setup(uint8_t dataPin, uint8_t clkPin, uint8_t latchPin) {
  _din = dataPin;
  _clk = clkPin;
  _load = latchPin;
  
  pinMode(_din, OUTPUT);
  pinMode(_clk, OUTPUT);
  pinMode(_load, OUTPUT);

}

/**
 * Sends the serial data to the target chip.
 * 
 * For example, if
 * four MAX7219s are cascaded, then to write to the 
 * fourth chip, sent the desired 16-bit word, followed by
 * three no-op codes (hex 0xXX0X, see Table 2). When
 * LOAD/CS goes high, data is latched in all devices. The
 * first three chips receive no-op commands, and the
 * fourth receives the intended data.
 */
void Max72xx::sendPacketToChip(int8_t chip, int8_t address, int8_t data) {
  digitalWrite(_load, LOW);

  //@todo make this smarter
  switch (chip) {
    case 1:
      sendPacket(0x00, 0x00);
      sendPacket(0x00, 0x00);
      sendPacket(address, data);
      break;
    case 2:
      sendPacket(0x00, 0x00);
      sendPacket(address, data);
      sendPacket(0x00, 0x00);
      break;
    case 3:
      sendPacket(address, data);
      sendPacket(0x00, 0x00);
      sendPacket(0x00, 0x00);
      break;
  }

  digitalWrite(_load, HIGH);
}

/**
 * Sends the 16 bit serial packet to the driver
 */
void Max72xx::sendPacket(int8_t address, int8_t data) {
  // shift out highbyte
  shiftOut(_din, _clk, MSBFIRST, address);
  // shift out lowbyte
  shiftOut(_din, _clk, MSBFIRST, data);
}

void Max72xx::setScanLimit(int8_t chip, uint8_t limit) {
  sendPacketToChip(chip, 0x0B, limit);
}

void Max72xx::setIntensity(int8_t chip, uint8_t intensity) {
  sendPacketToChip(chip, 0x0A, intensity);
}

/**
 * Set the display mode on.
 */
void Max72xx::testOn(int8_t chip) {
  sendPacketToChip(chip, 0x0F, B00000001);
}

/**
 * Set the display mode off.
 */
void Max72xx::testOff(int8_t chip) {
  sendPacketToChip(chip, 0x0F, B00000000);
}

void Max72xx::shutdown(int8_t chip, bool b) {
  if (b) {
    sendPacketToChip(chip, 0x0C, 0);
  } else {
    sendPacketToChip(chip, 0x0C, 1);
  }
}

void Max72xx::displayOn(int8_t chip) {
  shutdown(chip, false);
}

void Max72xx::displayOff(int8_t chip) {
  shutdown(chip, true);
}

void Max72xx::decodeMode(int8_t chip, int8_t data) {
  sendPacketToChip(chip, 0x09, data);
}

/**
 * Send data to the register.
 */
void Max72xx::setRegister(int8_t chip, int8_t address, int8_t data) {
    sendPacketToChip(chip, address, data);
}

