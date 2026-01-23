#include "display.h"

uchar led_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void led(uchar i,bit state)
{
    static uchar temp, last = 0xFF;
    if (state)
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp)
    {
        P0 = ~temp;
        latch(4);
        latch(0);

        last = temp;
    }
}


void led_display()
{
    static uchar i;
    led(i, led_value[i]);

    i = (i + 1) % 8;
}

void sandy(uchar i, bit state)
{
    static uchar temp,last = 0xFF;
    if (state)
    {
        temp = temp | (0x01 << i);
    }
    else
    {
        temp = temp & ~(0x01 << i);
    }

    if (state != last)
    {
        P0 = temp;
        latch(5);
        latch(0);

        last = temp;
    }
}