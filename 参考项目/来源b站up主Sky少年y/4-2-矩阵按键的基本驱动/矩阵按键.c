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
	uint Key_New;
	uchar key_value=0;
	
	P44=0;P42=1;P35=1;P34=1;  //扫描第一列
	Key_New = P3 & 0x0f;      //获取第一列的四行的位置的二进制数值
	
	P44=1;P42=0;P35=1;P34=1;  //扫描第2列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=0;P34=1;  //扫描第3列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	P44=1;P42=1;P35=1;P34=0;  //扫描第4列
	Key_New = (Key_New<<4) | (P3 & 0x0f);
	
	switch(~Key_New)
	{
		case 0x8000:key_value=4;break;  //S4
		case 0x4000:key_value=5;break;  //S5
		case 0x2000:key_value=6;break;  //S6
		case 0x1000:key_value=7;break;  //S7
		
		case 0x0800:key_value=8;break;  //S8
		case 0x0400:key_value=9;break;  //S9
		case 0x0200:key_value=10;break;  //S10
		case 0x0100:key_value=11;break;  //S11
		
		case 0x0080:key_value=12;break;  //S12
		case 0x0040:key_value=13;break;  //S13
		case 0x0020:key_value=14;break;  //S14
		case 0x0010:key_value=15;break;  //S15
		
		case 0x0008:key_value=16;break;  //S16
		case 0x0004:key_value=17;break;  //S17
		case 0x0002:key_value=18;break;  //S18
		case 0x0001:key_value=19;break;  //S19
		
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
	
	switch(ucKey_Down)
	{
		case 4:shu=4;break;
		case 5:shu=5;break;
		case 6:shu=6;break;
		case 7:shu=7;break;
		
		case 8:shu=8;break;
		case 9:shu=9;break;
		case 10:shu=10;break;
		case 11:shu=11;break;
		
		case 12:shu=12;break;
		case 13:shu=13;break;
		case 14:shu=14;break;
		case 15:shu=15;break;
		
		case 16:shu=16;break;
		case 17:shu=17;break;
		case 18:shu=18;break;
		case 19:shu=19;break;
		
	}
	
}


//主函数
void main()
{
	while(1)
	{
		if(shu>=10)
		{
			aloneSMG(6,shu/10);
		}
		else aloneSMG(6,11);
		aloneSMG(7,shu%10);
		
		Key_pro();
	}
}
