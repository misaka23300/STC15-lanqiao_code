#include "sonic.h"

sbit tx = P1 ^ 0;
sbit rx = P1 ^ 1;

void sonic_send()
{
    uchar i;
    for (i = 0;i < 2;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}


uchar sonic_measure()
{
    uchar distance;

    TR1 = 0;
    TH1 = 0; TL1 = 0;
    TF1 = 0;
   
    sonic_send();
    while (rx == 0);
    TR1 = 1;

    while (rx == 1 && TF1 == 0);
    TR1 = 0;

    if (TF1 == 1)
    {
        distance = 255;
        TF1 = 0;
    }
    else
    {
        distance =  (uchar)((TH1 << 8) | TL1) * 0.017;
    }
    return distance;
}