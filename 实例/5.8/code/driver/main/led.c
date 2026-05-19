#include "led.h"


uint8_t randz = 0;
uint8_t randz_last = 0xff;


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
        latch(0);
        last = temp;
    }
}


void buzz(uint8_t state)
{
    if (state) {
        randz = randz | 0x40;
    }
    else {
        randz = randz & ~(0x40);
    }

    if (randz != randz_last) {
        P0 = randz;
        latch(5);
        latch(0);

        randz_last = randz;
    } 
}

void relay(uint8_t state)
{
    if (state) {
        randz = randz | 0x10;
    }
    else {
        randz = randz & ~(0x10);
    }

    if (randz != randz_last) {
        P0 = randz;
        latch(5);
        latch(0);

        randz_last = randz;
    } 
}