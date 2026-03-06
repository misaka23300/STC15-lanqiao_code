#include <STC15F2K60S2.H>

#define uchar unsigned char
#define uint unsigned int

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //ﭘﺿﺽ۵ﻉﺧ0-9ﭦﺱ-ﺗﺎ11ﺕﺉﻉﻅﺓﻳﺙﺽﺭﺵﺫ،ﺣﻭ

uchar SMGa[8]={11,11,11,11,11,11,11,11};  //SMGa[0]

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

void aloneSMG(char pos,value)   //ﭖ۴ﺕﺉﮌﮮﺡﻣﺗﻎﺵﺿﮌﺝ   
{
	control(7,0xff);         //ﺵﻳﺽﺍ
	control(6,0x01<<pos);    //ﺳﭨﺹ۰ x=0 x=7
	control(7,DuanMa[value]);//ﭘﺳﺡﻣ
}

void T0_Reset()
{
	AUXR &= 0x7f;     //0111 1111
	TMOD &= 0xf0;     //TMOD = TMOD & 0xf0;
	TH0 = 0xfc;       //ﺏﺀﻅﭖ64536۲؛1000ﺑﺳﭦﮩﺝﺱﺻﻝﺏﺉ
	TL0 = 0x18;
	TF0 = 0;
	
	ET0 = 1;
	EA = 1;
	
	TR0 = 1;
}

uchar SMGi=0;   //0-7
uint t=0,time=0;
void T0_Server() interrupt 1    //ﺣﺟﺑﺳﻅﺑﺷﺷﭦﺁﮌﮮﺝﺱﮌﮄ1ms
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0; 
	if(++t==1000)
	{
		t=0;
		time++;
	}
}

void main()
{
	T0_Reset();
	while(1)
	{
		SMGa[0] = 2;
		SMGa[1] = 0;
		SMGa[2] = 2;
		SMGa[3] = 5;
		
		SMGa[4] = 10;
		if(time>=100)SMGa[5] = time/100%10;
		else SMGa[5]=11;
		if(time>=10)SMGa[6] = time/10%10;
		else SMGa[6]=11;
		SMGa[7] = time%10;
	}
}
