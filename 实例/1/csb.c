#include "csb.h"
#include "intrins.h"

sbit Trig=P1^0;
sbit Echo=P1^1;

void Delay10us()	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 27;
	while (--i);
}

void csb_Init()		//100??@12.000MHz
{
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
	for(i=0;i<10;i++)
	{
	 	Trig=1;
	 	Delay10us();
		Trig=0;
	 	Delay10us();
	}
}

uint csb_CJ()
{
 	int dis,t=0;
	csb_Start();
	while(!Echo);
	TR1=1;
	while(Echo && !TF1);
	TR1=0;
	
	if(TF1==1)
	{
	 dis=999;
	}
	else
	{
	 	t=TH1<<8|TL1;
		dis=(int)(t*0.017);
	}
	TH1=0; TL1=0;
	TF1=0; t=0;
	return dis;
}