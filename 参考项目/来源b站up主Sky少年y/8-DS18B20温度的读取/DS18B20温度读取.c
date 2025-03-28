#include <STC15F2K60S2.H>
#include "onewire.h"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

code unsigned char DuanMa[]={
0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,  //0-9
0xbf,0xff,
0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10
};
//对应着0-9和-共11个字符加上全灭

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
uchar Read_Delay=0;
void T0_Server() interrupt 1    //每次执行函数就是1ms
{
	aloneSMG(SMGi,SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if(++SMGi==8)SMGi=0;
	if(++Read_Delay==101)Read_Delay=0;
}

void Delay750ms(void)	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 35;
	j = 51;
	k = 182;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


uint SMG_temp=0;   //2 16   5     1 3. 0 5   1.05C   0105
void main()
{
	Read_temp();
	Delay750ms();
	T0_Reset();
	while(1)
	{
		if(Read_Delay==100)SMG_temp=Read_temp()*100;
		SMGa[0] = 11;
		SMGa[1] = 11;
		SMGa[2] = 11;
		SMGa[3] = 11;
		if(SMG_temp>=1000)SMGa[4] = SMG_temp/1000%10;
		else SMGa[4] = 11;
		SMGa[5] = SMG_temp/100%10+12;
		SMGa[6] = SMG_temp/10%10;
		SMGa[7] = SMG_temp%10;
	}
}


