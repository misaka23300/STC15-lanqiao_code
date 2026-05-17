#include "sonic.h"

sbit tx = P1^0;
sbit rx = P1^1;


void Delay14us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}


uint8_t sonic_measure()
{
    uint8_t distance = 0;

    CMOD = 0x00;
    CCON = 0x00;
    CH = 0x00;
    CL = 0x00;

    tx = 1;
    Delay14us();
    tx = 0;
    Delay14us();

    while(rx == 0);
    CR = 1;
    while(rx == 1 && CH < 0x40);
    CR = 0;

    if (CH >= 0x40) {
        distance = 255;
    }
    else {
        distance = (CH << 8 | CL) * 0.017;
    }
 
    return distance;
}


