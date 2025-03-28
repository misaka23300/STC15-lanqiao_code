#include <STC15F2K60S2.H>
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

uchar shu=0;

code unsigned char DuanMa[]={0xc0,0xf9,0xa4,0xb0,0x99,
0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};   //对应着0-9和-共11个字符加上全灭

//延时1ms的函数
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



void delay(uint t)
{
	while(t--)Delay1ms();
}


//573锁存器的控制
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





//单个数码管显示函数
void aloneSMG(char pos,value)     
{
	control(7,0xff);         //消影
	control(6,0x01<<pos);    //位选 x=0 x=7
	control(7,DuanMa[value]);//段码
	delay(1);
}

//独立按键操作2
uchar Key_Read()       //读取键值的函数
{
	uchar Key_new,key_value=0;
	P3 |= 0x0f;
	Key_new = P3 & 0x0f;  //0000 1110 0x0e    //0x0f
	switch(Key_new)
	{
		case 0x07:key_value=4;break;   //S4
		case 0x0b:key_value=5;break;   //S5
 		case 0x0d:key_value=6;break;   //S6
		case 0x0e:key_value=7;break;   //S7
		default :key_value=0;break;
	}
	return key_value;
}

void Key_pro()
{
	uchar ucKey_Val,ucKey_Down,ucKey_Up,ucKey_old;
	ucKey_Val = Key_Read();                         //7
	ucKey_Down = ucKey_Val & (ucKey_old ^ ucKey_Val);
	ucKey_Up = ~ucKey_Val & (ucKey_old ^ ucKey_Val);
	ucKey_old = ucKey_Val;
	
	switch(ucKey_Up)
	{
		case 4:shu=4;break;
		case 5:shu=5;break;
		case 6:shu=6;break;
		case 7:shu=7;break;
	}
	
}


//主函数
void main()
{
	while(1)
	{
		aloneSMG(0,shu);
		Key_pro();
	}
}
