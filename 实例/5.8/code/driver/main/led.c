#include "led.h"




void led_display(uint8_t i,uint8_t state)
{
    static uint8_t temp = 0;
    static uint8_t last = 0xFF;

    if (state) {
        temp = temp | (0x01 << i);
    }
    else {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp) {
        P0 = ~temp;
        latch(4);

        last = temp;
    }
}