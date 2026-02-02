#include "sonic.h"

sbit tx = P1^0;
sbit rx = P1^1; 



void Delay14us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}


void pca_init()
{
    CMOD = 0x00;
    CR = 0;
    CL = 0; CH = 0;
    CF = 0;
}

void sonic_send()
{
    uint8_t i;
    for (i = 0;i < 10;i++)
    {
        tx = 1;
        Delay14us();
        tx = 0;
        Delay14us();
    }
}


uint8_t sonic_measure()
{
    uint16_t temp;
    uint8_t distance;

    pca_init();

    sonic_send();

    CR = 1;
    while (rx == 1 && CF == 0);
    CR = 0;

    if (CF == 1)
    {
        distance = 255;
    }
    else
    {
        temp = CH << 8 | CL;
        distance = (uint8_t) (temp * 0.017 + 1);
        //distance = (uchar) (temp + 29) / 58;
    }
    return distance;
}
