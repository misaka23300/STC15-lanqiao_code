#include <STC15F2K60S2.H>
#include "intrins.h"

//P2 _ _ _ X X X X X

void control(char x,y)
{
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;   //Y4C为高电平
		case 5:P2=(P2 & 0x1f)|0xa0;break;
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
}

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	char i=0;
	
	control(5,0x00);  //关闭无关器件
	while(1)
	{
		for(i=0;i<=8;i++)
		{
			control(4,0xff<<i);
			Delay500ms();
		}
//		control(5,0xaf);
//		Delay500ms();
		
		control(5,0xff);
		Delay500ms();
	}
}
