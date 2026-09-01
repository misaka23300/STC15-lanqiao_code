#include "sonic.h"

sbit tx = P3^0;
sbit rx = P3^1;

void Delay14us(void);

void sonic_send()
{
    uint8_t i;
    for (i = 0; i < 6; i++) {
        tx = 0;
        Delay14us();
        tx = 1;
        Delay14us();
    }
}

uint8_t sonic_measure()
{
    uint8_t distance;
    CMOD = 0x00;
    CCON = 0x00;
    CH = 0x00;
    CL = 0x00;

    sonic_send();

    while(rx == 0);
    CR = 1;

    while(rx == 1 && CF == 0);
    CR = 0;

    if (CH > 0x40) {
        return 255;
    }
    else {
        uint16_t time_val = ((uint16_t)CH << 8) | CL;
        distance = (uint8_t)(time_val * 0.017);
    }

    return distance;
}