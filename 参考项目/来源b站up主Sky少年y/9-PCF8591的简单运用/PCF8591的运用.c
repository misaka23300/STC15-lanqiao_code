#include <STC15F2K60S2.H>
#include "iic.h"

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

uchar SMGi=0;  uchar t=0;       //100ms读取一次
void T0_Server() interrupt 1    //每次执行函数就是1ms
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0; 
	if(++t==101)t=0;
}

uchar AIN1=0;
void main()
{
	control(4,0xff);
	control(5,0x00);
	T0_Reset();
	while(1)
	{
		if(t==100) AIN1=AD_Read(0x03); //读取的是电位器的参数 0xff 255
		
		SMGa[0] = 11;
		SMGa[1] = 11;
		SMGa[2] = 11;
		SMGa[3] = 11;
		
		SMGa[4] = 11;
		SMGa[5] = AIN1/100%10;
		SMGa[6] = AIN1/10%10;
		SMGa[7] = AIN1%10;
	}
}

