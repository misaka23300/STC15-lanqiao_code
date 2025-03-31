#include "sonic.h"

sbit rx = P1 ^ 1;
sbit tx = P1 ^ 0;



void sonic_send()
{
    tx = 1;
    Delay14us();
    tx = 0;
}


uchar sonic_measure()
{
    uchar distance;

    TR0 = 0; TF0 = 0;
    TH0 = 0; TL0 = 0;

    sonic_send();
    while (rx == 0);

    TR0 = 1;

    while (rx == 1 && TF0 == 0);

    TR0 = 0;

    if (TF0)
    {
        distance = 256;
        TF0 = 0;
    }
    else
    {
        distance = (uchar) (TH0 << 8 | TL0) * 0.017;
    }
    TH0 = 0; TL0 = 0;

    return distance;
}