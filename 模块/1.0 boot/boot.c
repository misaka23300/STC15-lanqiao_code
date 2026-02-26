#include "boot.h"

void boot_init();
void timer_0();
void latch(uint8_t i);

void boot_init()
{
    P0M1 = 0;   P0M0 = 0;   
    P1M1 = 0;   P1M0 = 0;   
    P2M1 = 0;   P2M0 = 0;   
    P3M1 = 0;   P3M0 = 0;   
    P4M1 = 0;   P4M0 = 0;   
    P5M1 = 0;   P5M0 = 0;   
    P6M1 = 0;   P6M0 = 0;   
    P7M1 = 0;   P7M0 = 0;   

    P0 = 0xFF;
    latch(4);
    latch(7);
    latch(0);

    P0 = 0xAF;
    latch(5);

    P0 = 0x00;
    latch(6);

    timer_0();
}

void timer_0()
{

}

void latch(uint8_t i)
{
    switch (i)
    {
        case 0:{P2 = P2 & 0x1F; break; }
        case 4: {P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: {P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: {P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: {P2 = (P2 & 0x1F) | 0xE0; break; }
    }
}

void Delay14us(void)	//@12.000MHz
{
	uint8_t i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}
