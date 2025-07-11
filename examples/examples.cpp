#include "../include/shiftOut.hpp"

#include <Arduino.h>
#include <shiftOut.hpp>

constexpr uint8_t dataPin = 5;
constexpr uint8_t clockPin = 6;
constexpr uint8_t latchPin = 7;

constexpr uint8_t myArray[3] = {12,13,15};
constexpr uint64_t longNum = 0xffffffffffffffff;

void setup() {
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

void loop() {
    // The "static_cast<unsigned char>()" is used, because on some platforms LSBFIRST is set with
    // #define LSBFIRST 0, which could lead to errors, as a 0 can be interpreted as nullptr.
    // The static cast makes sure, that the argument is casted into something, which isnt a
    // pointer, so that the overload isn't ambigous!

    // shifts the values 12, 13, 15 out to 3 shift registers.
    shiftOut(dataPin, clockPin, MSBFIRST, myArray, 3);

    // shifts the value 18446744073709551615 out to 8 shift registers.
    shiftOut(dataPin, clockPin, latchPin, LSBFIRST, longNum);
}