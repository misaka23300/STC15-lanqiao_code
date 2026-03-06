/*
  ٣ﺟﺫﻥﺛ٥ﺃﻐ: DS1302ﺍﻱ٦ﺥ٣ﺟﺫﻥ
  ﺑﻎﺱ■؛٧ﺹ٣: Keil uVision 4.10 
  ﺳ٢ﺱ■؛٧ﺹ٣: CT107٥ﺄﺋ،؛ﻶﻁ¦ﻑﺩﺗ٥ﺭ٥ﺋﺵﺟﺎ 8051£،12MHz
  ﺑﺻ    ﺋﻏ: 2011-8-9
*/

#include "ds1302.h"
#include <intrins.h>

sbit SCK=P1^7;		
sbit SDA=P2^3;		
sbit RST = P1^3;   // DS1302٨٤ﺧ؛												

void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK=0;
		SDA=temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

unsigned char Read_Ds1302_Byte ( unsigned char address )
{
 	unsigned char i,temp=0x00;
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1;	_nop_();
 	Write_Ds1302(address);
 	for (i=0;i<8;i++) 	
 	{		
		SCK=0;
		temp>>=1;	
 		if(SDA)
 		temp|=0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
	SCK=1;	_nop_();
	SDA=0;	_nop_();
	SDA=1;	_nop_();
	return (temp);			
}

void DS1302_Settime(u8 hour,min,sec){
	Write_Ds1302_Byte(0x8e,0);
	Write_Ds1302_Byte(0x84,hour/10*16+hour٪10);
	Write_Ds1302_Byte(0x82,min/10*16+min٪10);
	Write_Ds1302_Byte(0x80,sec/10*16+sec٪10);
	Write_Ds1302_Byte(0x8e,1);
}
