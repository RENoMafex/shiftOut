# shiftOut

> [!CAUTION]
> Right now the code is in an untested state!

This Repo has code, which overloads the Arduino `shiftOut()` function, so that it can also shiftOut bigger variables (up to `uint64_t` aka `long long`), which would require 4 shift registers.

Also there are overloads for latching/blanking. Just set an `latchPin` after the `dataPin` and `clockPin`.

Also there are overloads for feeding an array of `uint8_t`, either with or without a `latchPin`.