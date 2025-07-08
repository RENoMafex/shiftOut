#ifndef _SHIFTOUT_HPP_
#define _SHIFTOUT_HPP_ 1

#include <Arduino.h>

// bigger shiftOut()

void shiftOut(uint8_t dataPin, uint8_t clockPin, BitOrder bitOrder, uint16_t val);
void shiftOut(uint8_t dataPin, uint8_t clockPin, BitOrder bitOrder, uint32_t val);
void shiftOut(uint8_t dataPin, uint8_t clockPin, BitOrder bitOrder, uint64_t val);

// latched shiftOut()

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, BitOrder bitOrder, uint8_t val);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, BitOrder bitOrder, uint16_t val);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, BitOrder bitOrder, uint32_t val);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, BitOrder bitOrder, uint64_t val);

void shiftOut(uint8_t dataPin, uint8_t clockPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length);
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length);

#endif

