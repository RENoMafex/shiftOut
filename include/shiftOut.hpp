#ifndef _SHIFTOUT_HPP_
#define _SHIFTOUT_HPP_ 1

#include <Arduino.h>

// bigger shiftOut()

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint16_t val);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint32_t val);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint64_t val);

// latched shiftOut()

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint8_t val);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint16_t val);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint32_t val);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint64_t val);

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length);
void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length);

#endif

