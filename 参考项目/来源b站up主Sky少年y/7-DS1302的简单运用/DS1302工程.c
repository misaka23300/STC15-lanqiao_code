#include <STC15F2K60S2.H>
#include "ds1302.h"
#define uchar unsigned char
#define uint unsigned int

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //对应着0-9和-共11个字符加上全灭

uchar SMGa[8]={11,11,11,11,11,11,11,11};  //SMGa[0]

void control(char x,y)
{
	switch(x)
	{
		case 4:P2=(P2 & 0x1f)|0x80;break;   //Y4C为高电平
		case 5:P2=(P2 & 0x1f)|0xa0;break;   //5
		case 6:P2=(P2 & 0x1f)|0xc0;break;
		case 7:P2=(P2 & 0x1f)|0xe0;break;
	}
	P0=y;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}

void aloneSMG(char pos,value)   //单个数码管显示   
{
	control(7,0xff);         //消影
	control(6,0x01<<pos);    //位选 x=0 x=7
	control(7,DuanMa[value]);//段码
}

void T0_Reset()
{
	AUXR &= 0x7f;     //0111 1111
	TMOD &= 0xf0;     //TMOD = TMOD & 0xf0;
	TH0 = 0xfc;       //初值64536，1000次后就溢出
	TL0 = 0x18;
	TF0 = 0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

uchar SMGi=0;   //0-7
void T0_Server() interrupt 1    //每次执行函数就是1ms
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0; 
}

void main()
{
	T0_Reset();
	DS1302_Write_Time();
	while(1)
	{
		DS1302_Read_Time();
		SMGa[0] = Time10[2]/10;
		SMGa[1] = Time10[2]%10;
		SMGa[2] = 10;
		SMGa[3] = Time10[1]/10;
		SMGa[4] = Time10[1]%10;
		SMGa[5] = 10;
		SMGa[6] = Time10[0]/10;
		SMGa[7] = Time10[0]%10;
	}
}

