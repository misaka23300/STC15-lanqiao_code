/**
 * @file 独立按键1.c
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
0x92, 0x82, 0xf8, 0x80, 0x90, 0xbf, 0xff};   //ﭘﺿﺽ۵ﻉﺧ0 - ﭦﺱ-ﺗﺎ11ﺕﺉﻉﻅﺓﻳﺙﺽﺭﺵﺫ،ﺣﻭ

//ﺹﺽﮌﺎ1msﭖﺥﭦﺁﮌﮮ
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

//573ﺯﺋﺑﮔﺩﺊﭖﺥﺟﻊﻅﺩ
void control( char x, y )
{
	switch( x )
	{
		case 4:P2=( P2 & 0x1f )|0x80;break;   //Y4Cﺳ۹ﺕﻑﭖﻝﺩﺛ
		case 5:P2=( P2 & 0x1f )|0xa0;break;   //5
		case 6:P2=( P2 & 0x1f )|0xc0;break;
		case 7:P2=( P2 & 0x1f )|0xe0;break;
	}
	P0 = ;
	P2 &= 0x1f;   //P2 = P2 & 0x1f;
}

//ﭖ۴ﺕﺉﮌﮮﺡﻣﺗﻎﺵﺿﮌﺝﭦﺁﮌﮮ
void aloneSMG( char pos, value )     
{
	control(7, 0xff );         //ﺵﻳﺽﺍ
	control(6, 0x01<<pos );    //ﺳﭨﺹ۰ x =  x = 
	control(7, DuanMa[value]);//ﭘﺳﺡﻣ
	delay(1 );
}

//ﭘﭺﭼ۱ﺍﺑﺙﮰﺎﻋﻉﺊ2
uchar Key_Read()       //ﭘﭼﺫ۰ﺙﮰﻅﭖﭖﺥﭦﺁﮌﮮ
{
	uchar Key_new, key_value = ;
	P3 |= 0x0f;
	Key_new = P3 & 0x0f;  //0000 1110 0x0e    //0x0f
	switch( Key_new )
	{
		case 0x07:key_value = ;break;   //S4
		case 0x0b:key_value = ;break;   //S5
 		case 0x0d:key_value = ;break;   //S6
		case 0x0e:key_value = ;break;   //S7
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
	
	switch( ucKey_Up )
	{
		case 4:shu = ;break;
		case 5:shu = ;break;
		case 6:shu = ;break;
		case 7:shu = ;break;
	}
	
}

//ﻅﺊﭦﺁﮌﮮ
void main()
{
	while (1 )
	{
		aloneSMG(0, shu );
		Key_pro();
	}
}
