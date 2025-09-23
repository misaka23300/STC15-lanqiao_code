#include "display.h"




void led_display()
{
    static uchar i;
    static uchar temp;
    static uchar last = 0xFF;

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
        batch(4);

        last = temp;
    }

    i = i + 1;
    if (i == 8) { i = 0; }
}

void seg_display()
{
    static uchar i;
    P0 = 0xFF;
    batch(7);

    P0 = 0x01 << i;
    batch(6);

    P0 = ~letter[seg_array[i]];
    batch(7);

    i = i + 1;
    if (i == 8) { i = 0; }
}

void buzz_display(uchar state)
{
    if (state)
    {
        randz = randz | 0x10;
    }
    else
    {
        randz = ranz & ~(0x10);
    }

    P0 = randz;
    batch(5);
}


void relay_display(uchar state)
{
    if (state)
    {
        randz = randz | 0x40;
    }
    else
    {
        randz = ranz & ~(0x40);
    }

    P0 = randz;
    batch(5);
}