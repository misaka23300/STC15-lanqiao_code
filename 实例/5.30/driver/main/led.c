#include "led.h"


uint8_t randz = 0;
void led_display(uint8_t i, uint8_t state) 
{
    static uint8_t temp = 0; 
	static uint8_t last = 0xff;
    if (state) {
        temp = temp | (0x01 << i);
    }
    else {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last) {
        P0 = ~temp;
        last = temp;
    }
}


void buzz(uint8_t state)
{
    if (state) {
        randz = randz | 0x10;
    }
    else {
        randz = randz & ~0x10;
    }

    P0 = randz;
    latch(5);
}

void relay(uint8_t state)
{
    if (state) {
        randz = randz | 0x40;
    }
    else {
        randz = randz & ~0x40;
    }

    P0 = randz;
    latch(5);
}