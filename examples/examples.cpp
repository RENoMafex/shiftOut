#include "../include/shiftOut.hpp"

#include <Arduino.h>
#include <shiftOut.hpp>

constexpr pin_size_t dataPin = 5;
constexpr pin_size_t clockPin = 6;
constexpr pin_size_t latchPin = 7;

constexpr uint8_t myArray[3] = {12,13,15};
constexpr uint64_t longNum = 0xffffffffffffffff;

void setup() {
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

void loop() {
    // shifts the values 12, 13, 15 out to 3 shift registers.
    shiftOut(dataPin, clockPin, MSBFIRST, myArray, 3);

    // shifts the value 18446744073709551615 out to 8 shift registers.
    shiftOut(dataPin, clockPin, latchPin, LSBFIRST, longNum);
}