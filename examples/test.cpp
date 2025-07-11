#include <Arduino.h>
#include <shiftOut.hpp>

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFF
#endif

const uint8_t DATAPIN = 5;
const uint8_t CLOCKPIN = 6;
const uint8_t BLANKPIN = 7;
uint8_t BITORDER = LSBFIRST;
uint16_t bigvar = 0;

const uint8_t arrSize = 2;

void setup(){
	pinMode(DATAPIN, OUTPUT);
    pinMode(CLOCKPIN, OUTPUT);
    pinMode(BLANKPIN, OUTPUT);
}

void loop(){
    uint8_t arr[arrSize] = {254, 254};

    while (bigvar != UINT16_MAX){
        shiftOut(DATAPIN, CLOCKPIN, BLANKPIN, BITORDER, bigvar++);
    }
    bigvar++;

    shiftOut(DATAPIN, CLOCKPIN, BLANKPIN, BITORDER, arr, arrSize);
    arr[0]+=3;
    arr[1]+=3;
    delay(1000);
    shiftOut(DATAPIN, CLOCKPIN, BLANKPIN, BITORDER, arr, arrSize);
    delay(1000);

    BITORDER = !BITORDER;
}

/*
platformio.ini:

[env]
lib_deps = RENoMafex/shiftOut@1.0.0
framework = arduino

[env:arduino_uno_r3]
board = uno
platform = atmelavr

[env:arduino_uno_r4]
board = uno_r4_wifi
platform = renesas-ra

[env:arduino_mega2650]
board = megaatmega2560
platform = atmelavr

[env:arduino_giga_m4]
board = giga_r1_m4
platform = ststm32

[env:arduino_giga_m7]
board = giga_r1_m4
platform = ststm32

[env:arduino_nano_every]
board = nano_every
platform = atmelmegaavr

[env:arduino_due]
board = due
platform = atmelsam

[env:arduino_m0]
board = mzeroUSB
platform = atmelsam

[env:arduino_nano33ble]
board = nano33ble
platform = nordicnrf52

[env:arduino_nanorp2040connect]
board = nanorp2040connect
platform = raspberrypi

[env:arduino_genuino101]
board = genuino101
platform = intel_arc32

[env:arduino_portenta_c33]
board = portenta_c33
platform = renesas-ra

[env:adafruit_gemma]
board = gemma
platform = atmelavr

[env:adafruit_feather_esp32_v2]
board = adafruit_feather_esp32_v2
platform = espressif32

[env:sparkfun_esp32_thing_plus]
board = esp32thing_plus
platform = espressif32

[env:sparkfun_blynk_board]
board = sparkfunBlynk
platform = espressif8266

[env:wemos_d1_mini]
board = d1_mini
platform = espressif8266

[env:heltec_cubecell_board_pro]
board = cubecell_board_pro
platform = heltec-cubecell

[env:pic32]
board = cui32
platform = microchippic32

[env:bbc_microbit]
board = bbcmicrobit
platform = nordicnrf51

[env:bbc_microbit_v2]
board = bbcmicrobit_v2
platform = nordicnrf52

[env:seeedstudio_TinyBLE]
board = seeedTinyBLE
platform = nordicnrf51

[env:rapspberrypi_rp2040]
board = pico
platform = raspberrypi

[env:nucleo_l476rg]
board = nucleo_l476rg
platform = ststm32

[env:teensymm]
board = teensymm
platform = teensy

[env:teensy2]
board = teensy2
platform = teensy

[env:teensy30]
board = teensy30
platform = teensy

[env:teensy31]
board = teensy31
platform = teensy

[env:teensy35]
board = teensy35
platform = teensy

[env:teensy36]
board = teensy36
platform = teensy

[env:teensy40]
board = teensy40
platform = teensy

[env:teensy41]
board = teensy41
platform = teensy

[env:teensylc]
board = teensylc
platform = teensy

[env:teensy2pp]
board = teensy2pp
platform = teensy

[env:ti_launcpad_lpmsp430fr4133]
board = lpmsp430fr4133
platform = timsp430

[env:ti_launchpad_lptm4c1294ncpdt]
platform = titiva
board = lptm4c1294ncpdt

*/