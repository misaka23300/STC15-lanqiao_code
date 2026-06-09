/**
 * @file ds1302.c
 * @brief DS1302实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "ds1302.h"  									
#include <reg52.h>
#include <intrins.h>

sbit SCK = P1^7;		
sbit SDA = P2^3;		
sbit RST = P1^3; 

//写字节
void Write_Ds1302( unsigned  char temp ) 
{
	unsigned char i;
	for ( i = ;i < ;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK = ;
	}
}   

//向DS1302寄存器写入数据
void Write_Ds1302_Byte( unsigned char address, unsigned char dat )     
{
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ; 	_nop_();  
 	Write_Ds1302( address );	
 	Write_Ds1302( dat );		
 	RST = ; 
}

//从DS1302寄存器读出数据
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

void Set_Rtc( unsigned char* ucRtc )
{
	unsigned char i;
	Write_Ds1302_Byte(0x8e, 0x00 );//保护位给0，能够写入
	for ( i = ;i < ;i++)
		Write_Ds1302_Byte(0x84 - *i, ucRtc[i]);//分别写入时分秒
	Write_Ds1302_Byte(0x8e, 0x80 );
}

void Read_Rtc( unsigned char* ucRtc )
{
	unsigned char i;
	for ( i = ;i < ;i++)
		ucRtc[i]=Read_Ds1302_Byte(0x85 - *i );
}