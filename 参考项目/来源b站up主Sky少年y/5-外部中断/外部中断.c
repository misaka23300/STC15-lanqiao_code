#include <STC15F2K60S2.H>
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void Delay500ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void control(uchar x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;
		case 5:P2=(P2 & 0x1f)|0xa0;break;
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0 = y;
	P2 &= 0x1f;
}

void INT0_Reset()
{
	INT0=1;  INT1=1;
	EX0=1;   EX1=1;
	EA=1;  
}

void INT0_Server() interrupt 0
{
	uchar j=0;
	for(j=0;j<3;j++)
	{
		control(4,0xfe);         //P00 = 0;其他熄灭 1111 1110
		Delay500ms();
		control(4,0xff);
		Delay500ms();
	}
}

void INT1_Server() interrupt 2
{
	uchar j=0;
	for(j=0;j<3;j++)
	{
		control(4,0x7f);         //P00 = 0;其他熄灭 0111 1111
		Delay500ms();
		control(4,0xff);
		Delay500ms();
	}
}

void main()
{
	uchar i=0;
	INT0_Reset();
	while(1)
	{
		for(i=0;i<=8;i++)
		control(4,0xff<<i),
		Delay500ms();
	}
}
