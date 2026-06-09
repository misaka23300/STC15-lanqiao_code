/**
 * @file ds1302.c
 * @brief DS1302实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "ds1302.h"

sbit SCK = P1^7;
sbit SDA = P2^3;
sbit RST = P1^3;

const uchar code write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8C};
const uchar code read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8D};

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

//
void Write_Ds1302_Byte( unsigned char address, unsigned char dat )     
{
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ; 	_nop_();  
 	Write_Ds1302( address );	
 	Write_Ds1302( dat );		
 	RST = ; 
}

//
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

uchar bcd_to_hex( uchar BCD )
{
	return ( ( BCD >> 4 )* 10 ) | ( BCD & 0x0F );
}

uchar hex_to_bcd( uchar HEX )
{
	return (( HEX / 10 ) << 4 ) | ( HEX % 10 );
}

void read_datetime( uchar *time )
{
	uchar i;
	for ( i = 0;i < 3;i++)
	{
		time[i] = Read_Ds1302_Byte( read_address[i]);
	}

	for ( i = 0;i < 3;i++)
	{
		time[i] = bcd_to_hex( time[i]);
	}
}

void write_datetime( uchar *time )
{
	uchar i;
	
	for ( i = 0;i < 3;i++)
	{
		time[i] = hex_to_bcd( time[i]);
	}

	for ( i = 0;i < 3;i++)
	{
		Write_Ds1302_Byte( write_address[i], time[i]);
	}
}

