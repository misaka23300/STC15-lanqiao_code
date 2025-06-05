#include "led.h"


uchar led_value[8] = {0, 0, 0, 0, 0 ,0 ,0 ,0};

void led(uchar i, bit state)
{
    static uchar temp;
    static uchar last = 0xFF;

    if (state)
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (temp != last)
    {
        P0 = ~temp;
        batch(4);
        batch(0);

        last = temp;
    }
}

void led_display()
{
    static uchar i;

    led(i, led_value[i]);
    i = (i + 1) % 8;
}