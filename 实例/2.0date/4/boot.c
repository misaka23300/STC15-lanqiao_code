#include "boot.h"

void boot_init()
{
    P0M0 = 0x00; P0M1 = 0x00; 
    P1M0 = 0x00; P1M1 = 0x00; 
    P2M0 = 0x00; P2M1 = 0x00; 
    P3M0 = 0x00; P3M1 = 0x00; 
    P4M0 = 0x00; P4M1 = 0x00; 
    P5M0 = 0x00; P5M1 = 0x00; 
    P6M0 = 0x00; P6M1 = 0x00; 
    P7M0 = 0x00; P7M1 = 0x00; 

    P0 = 0x00;
    batch(4);
    batch(0);

    P0 = 0xFF;
    batch(7);
    batch(0);

    batch(6);
    batch(0);
    
    P0 = 0xAF;
    batch(5);
    batch(0);
	Timer1_Init();
    EA = 1;
}

void batch(uchar i)
{
    switch (i)
    {
        case 4: P2 = (P2 & 0x1F) | 0x80; break;
        case 5: P2 = (P2 & 0x1F) | 0xA0; break;
        case 6: P2 = (P2 & 0x1F) | 0xC0; break;
        case 7: P2 = (P2 & 0x1F) | 0xE0; break;
        case 0: P2 = (P2 & 0x1F); break;
    }
}



void Timer1_Init()		//1??@12.000MHz
{
	AUXR &= 0xBF;			//?????12T??
	TMOD &= 0x0F;			//???????
	TL1 = 0x18;				//???????
	TH1 = 0xFC;				//???????
	TF1 = 0;				//??TF1??
	TR1 = 1;				//???1????
	ET1 = 1;				//?????1??
}
