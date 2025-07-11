#include "../include/shiftOut.hpp"
#include <shiftOut.hpp>

#ifndef TEENSYDUINO
void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val){
	for (uint8_t i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST) {
			digitalWrite(dataPin, val & 1);
			val >>= 1;
		} else {
			digitalWrite(dataPin, (val & 128) != 0);
			val <<= 1;
		}
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);
	}
}
#endif

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint16_t val) {
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

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint32_t val) {
    uint16_t highWord = (val >> 16) & 0xFFFF;
    uint16_t lowWord = val & 0xFFFF;

    if (bitOrder == LSBFIRST) {
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(LSBFIRST), static_cast<uint16_t>(lowWord));
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(LSBFIRST), static_cast<uint16_t>(highWord));
    } else {
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(MSBFIRST), static_cast<uint16_t>(highWord));
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(MSBFIRST), static_cast<uint16_t>(lowWord));
    }
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint64_t val) {
    uint32_t highWord = (val >> 32) & 0xFFFFFFFF;
    uint32_t lowWord = val & 0xFFFFFFFF;

    if (bitOrder == LSBFIRST) {
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(LSBFIRST), static_cast<uint32_t>(lowWord));
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(LSBFIRST), static_cast<uint32_t>(highWord));
    } else {
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(MSBFIRST), static_cast<uint32_t>(highWord));
        shiftOut(dataPin, clockPin, static_cast<uint8_t>(MSBFIRST), static_cast<uint32_t>(lowWord));
    }
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder, uint8_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, val);
    digitalWrite(latchPin, HIGH);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder, uint16_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, static_cast<uint16_t>(val));
    digitalWrite(latchPin, HIGH);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder, uint32_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, static_cast<uint32_t>(val));
    digitalWrite(latchPin, HIGH);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder, uint64_t val) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, static_cast<uint64_t>(val));
    digitalWrite(latchPin, HIGH);
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, const uint8_t vals[], size_t vals_length) {
    for (size_t i = 0; i < vals_length; ++i) {
        shiftOut(dataPin, clockPin, bitOrder, static_cast<uint8_t>(vals[i]));
    }
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t bitOrder, const uint8_t vals[], size_t vals_length) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, bitOrder, vals, vals_length);
    digitalWrite(latchPin, HIGH);
}
