/**
 * @file ds1302.c
 * @brief DS1302实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*
  ٣ﺟﺫﻥﺛ٥ﺃﻐ: DS1302ﺍﻱ٦ﺥ٣ﺟﺫﻥ
  ﺑﻎﺱ■؛٧ﺹ٣: Keil uVision 4.10 
  ﺳ٢ﺱ■؛٧ﺹ٣: CT107٥ﺄﺋ،؛ﻶﻁ¦ﻑﺩﺗ٥ﺭ٥ﺋﺵﺟﺎ 8051£،12MHz
  ﺑﺻ    ﺋﻏ: 2011 - -9
*/

#include "ds1302.h"
#include <intrins.h>

sbit SCK = 1^7;		
sbit SDA = 2^3;		
sbit RST = P1^3;   // DS1302٨٤ﺧ؛												

void Write_Ds1302( unsigned  char temp ) 
{
	unsigned char i;
	for ( i = ;i < ;i++)     	
	{ 
		SCK = ;
		SDA = emp&0x01;
		temp>>=1; 
		SCK = ;
	}
}   

void Write_Ds1302_Byte( unsigned char address, unsigned char dat )     
{
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ; 	_nop_();  
 	Write_Ds1302( address );	
 	Write_Ds1302( dat );		
 	RST = ; 
}

unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i, temp = x00;
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ;	_nop_();
 	Write_Ds1302( address );
 	for ( i = ;i < ;i++) 	
 	{		
		SCK = ;
		temp>>=1;	
 		if ( SDA )
 		temp|=0x80;	
 		SCK = ;
	} 
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
	SCK = ;	_nop_();
	SDA = ;	_nop_();
	SDA = ;	_nop_();
	return ( temp );			
}

void DS1302_Settime( u8 hour, min, sec ){
	Write_Ds1302_Byte(0x8e, 0 );
	Write_Ds1302_Byte(0x84, hour / 0 * 6 + our٪10 );
	Write_Ds1302_Byte(0x82, min / 0 * 6 + in٪10 );
	Write_Ds1302_Byte(0x80, sec / 0 * 6 + ec٪10 );
	Write_Ds1302_Byte(0x8e, 1 );
}
