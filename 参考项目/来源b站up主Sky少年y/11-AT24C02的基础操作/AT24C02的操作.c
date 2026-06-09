/**
 * @file AT24C02的操作.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include <STC15F2K60S2.H>
#include "iic.h"

#define uchar unsigned char
#define uint unsigned int

uchar AT24C02_Data[2]={0, 0};
uchar shua = 0, shub = 0;
code unsigned char DuanMa[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99,
0x92, 0x82, 0xf8, 0x80, 0x90, 0xbf, 0xff};   //ﭘﺿﺽ۵ﻉﺧ0 - ﭦﺱ-ﺗﺎ11ﺕﺉﻉﻅﺓﻳﺙﺽﺭﺵﺫ،ﺣﻭ

uchar SMGa[8]={11, 11, 11, 11, 11, 11, 11, 11};  //SMGa[0]

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

void aloneSMG( char pos, value )   //ﭖ۴ﺕﺉﮌﮮﺡﻣﺗﻎﺵﺿﮌﺝ   
{
	control(7, 0xff );         //ﺵﻳﺽﺍ
	control(6, 0x01<<pos );    //ﺳﭨﺹ۰ x =  x = 
	control(7, DuanMa[value]);//ﭘﺳﺡﻣ
}

void T_Reset()
{
	AUXR &= 0x7F;			//ﭘ۷ﮌﺎﺩﺊﮌﺎﻅﺽ12Tﺥ۲ﮌﺛ
	TMOD &= 0xF0;			//ﺭﻟﻅﺣﭘ۷ﮌﺎﺩﺊﺥ۲ﮌﺛ
	TL0 = 0x18;				//ﺭﻟﻅﺣﭘ۷ﮌﺎﺏﺀﮌﺙﻅﭖ
	TH0 = 0xFC;				//ﺭﻟﻅﺣﭘ۷ﮌﺎﺏﺀﮌﺙﻅﭖ				//ﺭﻟﻅﺣﭘ۷ﮌﺎﺏﺀﮌﺙﻅﭖ
  TF0 = 0;
	TR0 = 1;
	ET0 = 1;//ﺑﮨﺟ۹ﭘﺿﺽ۵ﭖﺥﻅﺷﭘﺵ
	EA = 1;
}

uchar SMGi = ;   //0 -      

//ﺝﻊﻁﮩﺍﺑﺙﮰﺎﻋﻉﺊ
uchar Key_Delay = ;
uchar Key_Read()       //ﭘﭼﺫ۰ﺙﮰﻅﭖﭖﺥﭦﺁﮌﮮ
{
	uint Key_New;
	uchar key_value = ;
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //ﺭ۷ﺣﻟﭖﻌﺻﭨﭼﺷ
	Key_New = P3 & 0x0f;      //ﭨﮦﺫ۰ﭖﻌﺻﭨﭼﺷﭖﺥﺯﺥﺷﺷﭖﺥﺳﭨﻅﺣﭖﺥﭘﹼﺛﺋﻅﺩﮌﮮﻅﭖ
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //ﺭ۷ﺣﻟﭖﻌ2ﭼﺷ
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //ﺭ۷ﺣﻟﭖﻌ3ﭼﺷ
	Key_New = ( Key_New<<4 ) | ( P3 & 0x0f );
	
	P44 = ;P42 = ;P35 = ;P34 = ;  //ﺭ۷ﺣﻟﭖﻌ4ﭼﺷ
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
	if ( Key_Delay < )return;
	ucKey_Val = Key_Read();                         //7
	ucKey_Down = ucKey_Val & ( ucKey_old ^ ucKey_Val );
	ucKey_Up = ~ucKey_Val & ( ucKey_old ^ ucKey_Val );
	ucKey_old = ucKey_Val;
	
	switch( ucKey_Down )
	{
		case 4:shua--;break;
		case 5:shua++;break;
		case 8:shub--;break;
		case 9:shub++;break;
		case 13:              //ﺑﮔﺑ۱
		{
			AT24C02_Data[0]=shua;
			AT24C02_Data[1]=shub;
			AT24C02_Write( AT24C02_Data, 0, 2 ); //0 1
			break;
		}
		case 12:              //ﭘﭼﺫ۰ﮌﮮﺝﻏ
		{
			AT24C02_Read( AT24C02_Data, 0, 2 );  //0 1
			shua = AT24C02_Data[0];
			shub = AT24C02_Data[1];
			break;
		}
	}
}

void T1_Server() interrupt 1    //ﺣﺟﺑﺳﻅﺑﺷﺷﭦﺁﮌﮮﺝﺱﮌﮄ1ms  		T1
{
	aloneSMG( SMGi, SMGa[SMGi]);    //SMGa[0] SMGa[1]   ----   SMGa[7]
	if (++SMGi == )SMGi = ; 
	if (++Key_Delay == 0 )Key_Delay = ;
}

void Delay10ms( void )	//@12.000MHz
{
	unsigned char data i, j;

	i = 117;
	j = 184;
	do
	{
		while (--j );
	} while (--i );
}

void main()
{
	T_Reset();
	Delay10ms();
	AT24C02_Read( AT24C02_Data, 0, 2 );  //0 1
	shua = AT24C02_Data[0];
	shub = AT24C02_Data[1];
	while (1 )
	{
		Key_pro();
		SMGa[0] = shua / 00 % 0;
		SMGa[1] = shua / 0 % 0;
		SMGa[2] = shua % 0;
		SMGa[3] = 11;
		SMGa[4] = 11;
		SMGa[5] = shub / 00 % 0;
		SMGa[6] = shub / 0 % 0;
		SMGa[7] = shub % 0;
	}
}
