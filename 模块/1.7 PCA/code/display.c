#include "display.h"


uchar led_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};



void led_display()
{
    static uchar i;
    static uchar temp;
    static uchar last;

    if (led_array[i])
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
        latch(4);

        last = temp;
    }


    i += 1;
    if (i == 8) { i = 0;}
}