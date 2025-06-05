#include "sonic.h"

sbit rx = P3 ^ 0;
sbit tx = P3 ^ 1;

void sonic_send()
{
    uchar i;
    for (i = 0;i < 14;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}

uint sonic_measure()
{
    uint distance;

    TR0 = 0; TF0 = 0;
    TF0 = 0; TH0 = 0;
    
    sonic_send();

    while (rx == 0);
    TR0 = 1;

    while (rx == 1 && TF0 == 0);
    TR0 = 0;

    if (TF0 == 1)
    {
        TF0 = 0;
        distance = 999;
    }
    else
    {
        distance = (TH0 << 8 | TL0)* 0.017;
    }

    return distance;
}