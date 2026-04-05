#include "led.h"

uint8_t randz = 0;
uint8_t last_randz = 0xff;

void led_display(uint8_t i, bit_t state)
{
    static uint8_t last = 0xff;
    static uint8_t temp;

    if (state) {
        temp = temp | (0x01 << i);
    }
    else {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp) {
        last = temp;
        P0 = ~temp;
        latch(4);
        latch(0);
    }
}


void set_led(uint8_t i, bit_t state)
{
    if (i < 8) {
        led_display(i, state);
    }
}


void relay(bit state)
{
    if (state) {
        randz = randz | (0x10);
    }
    else {
        randz = randz & ~(0x10);
    }

    if (randz != last_randz) {
        last_randz = randz;
        P0 = randz;
        latch(5);
        latch(0);
    }
}

void buzz(bit state)
{
    if (state) {
        randz = randz | (0x30);
    }
    else {
        randz = randz & ~(0x30);
    }

    if (randz != last_randz) {
        last_randz = randz;
        P0 = randz;
        latch(5);
        latch(0);
    }
}