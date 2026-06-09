/**
 * @file 矩阵按键.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include <STC15F2K60S2.H>
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

uchar shu = ;

code unsigned char DuanMa[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99,
0x92, 0x82, 0xf8, 0x80, 0x90, 0xbf, 0xff};   //对应着0 - 和-共11个字符加上全灭

//延时1ms的函数
void Delay1ms( void )	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j );
	} while (--i );
}

void delay( uint t )
{
	while ( t--)Delay1ms();
}

//573锁存器的控制
void control( char x, y )
{
	switch( x )
	{
		case 4:P2=( P2 & 0x1f )|0x80;break;   //Y4C为高电平
		case 5:P2=( P2 & 0x1f )|0xa0;break;   //5
		case 6:P2=( P2 & 0x1f )|0xc0;break;
		case 7:P2=( P2 & 0x1f )|0xe0;break;
	}
	P0 = ;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}

//单个数码管显示函数
void aloneSMG( char pos, value )     
{
	control(7, 0xff );         //消影
	control(6, 0x01<<pos );    //位选 x =  x = 
	control(7, DuanMa[value]);//段码
	delay(1 );
}

//独立按键操作2
uchar Key_Read()       //读取键值的函数
{
	uint Key_New;
	uchar key_value = ;
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第一列
	Key_New = P3 & 0x0f;      //获取第一列的四行的位置的二进制数值
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第2列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第3列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //扫描第4列
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	switch(~Key_New )
	{
		case 0x8000:key_value = ;break;  //S4
		case 0x4000:key_value = ;break;  //S5
		case 0x2000:key_value = ;break;  //S6
		case 0x1000:key_value = ;break;  //S7
		
		case 0x0800:key_value = ;break;  //S8
		case 0x0400:key_value = ;break;  //S9
		case 0x0200:key_value = 0;break;  //S10
		case 0x0100:key_value = 1;break;  //S11
		
		case 0x0080:key_value = 2;break;  //S12
		case 0x0040:key_value = 3;break;  //S13
		case 0x0020:key_value = 4;break;  //S14
		case 0x0010:key_value = 5;break;  //S15
		
		case 0x0008:key_value = 6;break;  //S16
		case 0x0004:key_value = 7;break;  //S17
		case 0x0002:key_value = 8;break;  //S18
		case 0x0001:key_value = 9;break;  //S19
		
		default :key_value = ;break;
	}
	return key_value;
}

void Key_pro()
{
	uchar ucKey_Val, ucKey_Down, ucKey_Up, ucKey_old;
	ucKey_Val = Key_Read();                         //7
	ucKey_Down = ucKey_Val & ( ucKey_old ^ ucKey_Val );
	ucKey_Up = ~ucKey_Val & ( ucKey_old ^ ucKey_Val );
	ucKey_old = ucKey_Val;
	
	switch( ucKey_Down )
	{
		case 4:shu = ;break;
		case 5:shu = ;break;
		case 6:shu = ;break;
		case 7:shu = ;break;
		
		case 8:shu = ;break;
		case 9:shu = ;break;
		case 10:shu = 0;break;
		case 11:shu = 1;break;
		
		case 12:shu = 2;break;
		case 13:shu = 3;break;
		case 14:shu = 4;break;
		case 15:shu = 5;break;
		
		case 16:shu = 6;break;
		case 17:shu = 7;break;
		case 18:shu = 8;break;
		case 19:shu = 9;break;
		
	}
	
}

//主函数
void main()
{
	while (1 )
	{
		if ( shu >= 0 )
		{
			aloneSMG(6, shu / 0 );
		}
		else aloneSMG(6, 11 );
		aloneSMG(7, shu % 0 );
		
		Key_pro();
	}
}
