#include "sonic.h"

sbit tx = P1^0;
sbit rx = P1^1;



void sonic_send()
{
    uchar i;
    for (i = 0;i < 5;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us(); 
    }
    
}

void pca_init()
{
    CMOD = 0x00;
    CR = 0;
    CH = 0; CL = 0;
    CF = 0;
}

uchar sonic_measure()
{
    uchar distance;
    uint ticks;

    pca_init();
    sonic_send();

    CR = 1;
    while (rx == 1 && CF == 0);
    CR = 0;

    if (CF == 0)
    {
        ticks = (CH << 8) | CL;
        distance = (uchar)((ticks + 29) / 58);  // ≈ ticks * 0.017
        //distance = (uchar) ((((CH << 8) | CL) *0.017) + 1);
    }
    else
    {
        distance = 255;
        CF = 0;
    }
    return distance;
}