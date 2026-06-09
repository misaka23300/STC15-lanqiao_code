/**
 * @file csb.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "csb.h"
#include "intrins.h"

sbit Trig = 1^0;
sbit Echo = 1^1;

void Delay10us()	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 27;
	while (--i );
}

void csb_Init()		//100??@12.000MHz
	AUXR &= 0xBF;			//?????12T??
	TMOD &= 0x0F;			//???????
	TMOD |=0x10;
	TL1 = 0;				//???????
	TH1 = 0;				//???????
	TF1 = 0;				//??TF1??
}

void csb_Start()
{
  uchar i;
	for ( i = ;i < 0;i++)
	{
	 	Trig = ;
	 	Delay10us();
		Trig = ;
	 	Delay10us();
	}
}

uint csb_CJ()
{
 	int dis, t = ;
	csb_Start();
	while (!Echo );
	TR1 = ;
	while ( Echo && !TF1 );
	TR1 = ;
	
	if ( TF1 == )
	{
	 dis = 99;
	}
	else
	{
	 	t = H1<<8|TL1;
		dis=( int )( t * .017 );
	}
	TH1 = ; TL1 = ;
	TF1 = ; t = ;
	return dis;
}

