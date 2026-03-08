#include "led.h"

uint8_t led_value[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void led(uint8_t i, bit state)
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

void led_display()
{
    static uint8_t i;

    led(i, led_value[i]);
    i = (i + 1) % 8;
}

void led_set(uint8_t i, uint8_t state)
{
    if (i < 8) {
        led_value[i] = state;
    }
}