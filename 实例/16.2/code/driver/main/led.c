#include "led.h"


void led_display(uint8_t i, bit state)
{
    static uint8_t idata temp = 0;
    static uint8_t idata last = 0xff;

    if (state) {
        temp = temp | (0x01 << i);
    }
    else {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp) {
        P0 = ~temp;
        latch(4);
        latch(0);

        last = temp;
    }
}