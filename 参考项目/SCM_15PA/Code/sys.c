#include "sys.h"

//
unsigned int frq = 0;
static unsigned int ms[7];
bdata unsigned char flag = 0;



//
void buzOff(void)
{
    LED(0xFF);
    BUZ(0x00);
}

void delay10Ms(void)
{
	unsigned char i, j;

	i = 108;
	j = 145;
	do
	{
		while (--j);
	} while (--i);
}

//Timer0 as frquency timer
void initFrqTimer(void)
{
	AUXR &= 0x7F;

	TMOD |= 0x04;
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	TF0 = 0;
}

void calFrq(void)
{
	
	TR0 = 0;	//暂停计数器
	frq = ((TH0 << 8) | TL0);
	frq *= 5;

	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
}

//Timer2 as system tick timer
void initSysTick(void)
{
    AUXR |= 0x04;
    T2L = 0x20;
	T2H = 0xD1;
	AUXR |= 0x10;
    IE2 |= 0x04;
	EA = 1;
}

//
void isrSysTick(void)    interrupt 12
{
	segDsp();

    //KEY
	if(++ms[0] == 10){
		ms[0] = 0;  flag |= 0x01;	
	}
    //DSP update
	if(++ms[1] == 100){
		ms[1] = 0;  flag |= 0x02;
	}
    //LED update
	if(++ms[2] == 200){
		ms[2] = 0;  flag |= 0x04;
	}
    //
	if(++ms[3] == 200){
		ms[3] = 0;  flag |= 0x08;
	}
    //FRQ-CAL
	if(++ms[4] == 200){
		ms[4] = 0;
        calFrq();
	}
    //RTC-FRQ Data
	if(++ms[5] == 200){
		ms[5] = 0;  flag |= 0x20;
	}
}