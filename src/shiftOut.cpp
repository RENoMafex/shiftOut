#include "../include/shiftOut.hpp"
#include <shiftOut.hpp>

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint16_t val) {
    uint8_t highByte = (val >> 8) & 0xFF;
    uint8_t lowByte = val & 0xFF;

    if (bitOrder == LSBFIRST) {
        shiftOut(dataPin, clockPin, LSBFIRST, lowByte);
        shiftOut(dataPin, clockPin, LSBFIRST, highByte);
    } else {
        shiftOut(dataPin, clockPin, MSBFIRST, highByte);
        shiftOut(dataPin, clockPin, MSBFIRST, lowByte);
    }
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint32_t val) {
    uint16_t highWord = (val >> 16) & 0xFFFF;
    uint16_t lowWord = val & 0xFFFF;

    if (bitOrder == LSBFIRST) {
        shiftOut(dataPin, clockPin, LSBFIRST, lowWord);
        shiftOut(dataPin, clockPin, LSBFIRST, highWord);
    } else {
        shiftOut(dataPin, clockPin, MSBFIRST, highWord);
        shiftOut(dataPin, clockPin, MSBFIRST, lowWord);
    }
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint64_t val) {
    uint32_t highWord = (val >> 32) & 0xFFFFFFFF;
    uint32_t lowWord = val & 0xFFFFFFFF;

    if (bitOrder == LSBFIRST) {
        shiftOut(dataPin, clockPin, LSBFIRST, lowWord);
        shiftOut(dataPin, clockPin, LSBFIRST, highWord);
    } else {
        shiftOut(dataPin, clockPin, MSBFIRST, highWord);
        shiftOut(dataPin, clockPin, MSBFIRST, lowWord);
    }
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint8_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, val);
    digitalWrite(latchPin, HIGH);
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint16_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, val);
    digitalWrite(latchPin, HIGH);
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint32_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, val);
    digitalWrite(latchPin, HIGH);
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint64_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, val);
    digitalWrite(latchPin, HIGH);
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length) {
    for (size_t i = 0; i < vals_length; ++i) {
        shiftOut(dataPin, clockPin, bitOrder, vals[i]);
    }
}

void shiftOut(pin_size_t dataPin, pin_size_t clockPin, pin_size_t latchPin, BitOrder bitOrder, uint8_t vals[], size_t vals_length) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, vals, vals_length);
    digitalWrite(latchPin, HIGH);
}
