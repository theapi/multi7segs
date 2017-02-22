/*
 * arduino_shim.h
 *
 *  Absolute bare minimum needed to pretend to be arduino code.
 */

#ifndef ARDUINO_SHIM_H_
#define ARDUINO_SHIM_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32l0xx_hal.h"
#include "main.h"
#include "stdint.h"

#define HIGH 0x1
#define LOW  0x0

#define LSBFIRST 0
#define MSBFIRST 1

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

void pinMode(uint8_t, uint8_t);
void digitalWrite(uint8_t, uint8_t);
void shiftOut(uint8_t, uint8_t, uint8_t, uint8_t);
GPIO_TypeDef* digitalPinToPort(uint8_t);
uint16_t digitalPinToBitMask(uint8_t);


#ifdef __cplusplus
}
#endif
#endif
