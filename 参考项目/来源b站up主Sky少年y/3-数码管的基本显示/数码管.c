#include <STC15F2K60S2.H>
#include "intrins.h"

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //ﭘﺿﺽ۵ﻉﺧ0-9ﭦﺱ-ﺗﺎ11ﺕﺉﻉﻅﺓﻳﺙﺽﺭﺵﺫ،ﺣﻭ

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}



void delay(int t)
{
	while(t--)Delay1ms();
}

void control(char x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;   //Y4Cﺳ۹ﺕﻑﭖﻝﺩﺛ
		case 5:P2=(P2 & 0x1f)|0xa0;break;   //5
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}

void aloneSMG(char pos,value)     
{
	control(7,0xff);         //ﺵﻳﺽﺍ
	control(6,0x01<<pos);    //ﺳﭨﺹ۰ x=0 x=7
	control(7,DuanMa[value]);//ﭘﺳﺡﻣ
	delay(1);
}

void main()
{
	while(1)
	{
		aloneSMG(0,2);
		aloneSMG(1,3);
		aloneSMG(2,4);
		aloneSMG(3,5);
		
		aloneSMG(4,6);
		aloneSMG(5,7);
		aloneSMG(6,8);
		aloneSMG(7,9);
	}
}

