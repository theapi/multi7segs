#include "arduino_shim.h"



void pinMode(uint8_t pin, uint8_t mode)
{
    // all done in MX_GPIO_Init();
}

GPIO_TypeDef* digitalPinToPort(uint8_t pin) {
    // yeah just the one port for now
    return GPIOA;
}

uint16_t digitalPinToBitMask(uint8_t pin) {
    return (1 << pin);
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t bit = digitalPinToBitMask(pin);
    GPIO_TypeDef* port = digitalPinToPort(pin);

    if (val == LOW) {
        HAL_GPIO_WritePin(port, bit, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(port, bit, GPIO_PIN_SET);
    }
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
    uint8_t i;

    for (i = 0; i < 8; i++)  {
        if (bitOrder == LSBFIRST)
            digitalWrite(dataPin, !!(val & (1 << i)));
        else
            digitalWrite(dataPin, !!(val & (1 << (7 - i))));

        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
    }
}

