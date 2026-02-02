#include "sonic.h"

sbit tx = P1 ^ 0;
sbit rx = P1 ^ 1;

extern void sonic_send()
{
    uint8_t i;
    for (i = 0;i < 6;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}

uint8_t sonic_measure_mode1()
{
    uint8_t distance;

    TR1 = 0;
    TL1 = 0; TH1 = 0;
    TF1 = 0;

    sonic_send();
    while (rx == 0);

    TR1 = 1;

    while (rx == 1 && TF1 == 0);
    TR1 = 0;

    if (TF1 == 1)
    {
        distance = 255;
    }
    else
    {
        distance = (uint8_t) ((TH1 << 8) | TL1)* 0.017;
    }

    return distance;
    
}


uint8_t sonic_measure_mode2()
{
    uint8_t distance;

    TR1 = 0;
    TL1 = 0; TH1 = 0;
    TF1 = 0;

    tx = 1;
    Delay14us();
    tx = 0;
    Delay14us();

    while (rx == 0);

    TR1 = 1;

    while (rx == 1 && TF1 == 0);
    TR1 = 0;

    if (TF1 == 1)
    {
        distance = 255;
    }
    else
    {
        distance = (uint8_t) ((TH1 << 8) | TL1)* 0.017;
    }

    return distance;
    
}