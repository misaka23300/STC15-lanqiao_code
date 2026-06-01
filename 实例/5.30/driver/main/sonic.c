#include "sonic.h"

sbit tx = ;
sbit rx = ;



void sonic_send()
{
    tx = 0;

    tx = 1;

}

uint8_t sonic_measure()
{
    CMOD = 0x00;
    CCON = 0x00;
    CH = 0x00;
    CL = 0x00;

    sonic_send();

    while(rx == 0);
    CR = 1;

    while(rx == 1&& CF == 0);
    CR = 0;

    if (CH > 0x40) {
        return 255;   
    }
    else {
        distance = CH << 8 | CL * 0.017;
    }

    return distance;



}