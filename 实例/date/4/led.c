#include "led.h"

uchar led_value[8] = {0, 0, 0, 0 ,0, 0, 0, 0};

void led(uchar i, bit state)
{
    static uchar last = 0xFF, tmp;
    if (state)
    {
        tmp = tmp | (0x01 << i);
    }
    else
    {
        tmp = tmp & ~(0x01 << i);
    }

    if (last != tmp)
    {
        P0 = ~tmp;
        batch(4);
        batch(0);

        last = tmp;
    }
}


void led_display()
{
    static uchar i;
    led(i, led_value[i]);  
    i = (i + 1) % 8;
}

void s4_state(uchar j)
{
    uchar i;
    for (i = 0; i < 3;i++)
    {
        if (i != j)
        {
            led_value[i] = 0;
        }
        else
        {
            led_value[i] = 1;
        }
    }
}

