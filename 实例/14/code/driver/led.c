#include "led.h"



void led(uint8_t i,uint8_t state)
{
    static uint8_t temp;
    static uint8_t last = 0xFF;

    if (state) {
        temp = temp | (0x01 << i);
    } else {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last) {
        P0 = ~temp;
        latch(4);
        latch(0);

        last = temp;
    }
}



