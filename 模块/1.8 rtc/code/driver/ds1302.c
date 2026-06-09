/**
 * @file ds1302.c
 * @brief DS1302实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "ds1302.h"
#include "intrins.h"

sbit SDA = P2^3;
sbit SCK = P1^7;
sbit RST = P1^3;

const uint8_t write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8C};
const uint8_t read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8D};

uint8_t time_now[3] = {0, 0, 0};
const uint8_t time_init[7] = {0x50, 0x59, 0x23, 0x09, 0x04, 0x03, 0x25};	

void Write_Ds1302( uint8_t temp ) 
{
	uint8_t i;
	for ( i = ;i < ;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK = ;
	}
}   

void Write_Ds1302_Byte( uint8_t address, uint8_t dat )     
{
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ; 	_nop_();  
 	Write_Ds1302( address );	
 	Write_Ds1302( dat );		
 	RST = ; 
}

uint8_t Read_Ds1302_Byte ( uint8_t address )
{
 	uint8_t i, temp = x00;
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

/* uint8_t hex_to_bcd( uint8_t hex )
{
	return ( hex / 10 * 16 ) + ( hex % 10 );
} */

uint8_t bcd_to_hex( uint8_t bcd )
{
	return ( bcd / 16 * 10 ) + ( bcd % 16 );
}

void datetime_write()
{
	uint8_t i;
	Write_Ds1302_Byte(0x8E, 0x00 );
	
	for ( i = 0;i < 7;i++)
	{
		Write_Ds1302_Byte( write_address[i], time_init[i]);
	}
	
	Write_Ds1302_Byte(0x8E, 0x80 );
}

void datetime_read()
{
	uint8_t i;
	for ( i = 0;i < 3;i++)
	{
		time_now[i] = Read_Ds1302_Byte( read_address[i]);
	}

	for ( i = 0;i < 3;i++)
	{
		time_now[i] = bcd_to_hex( time_now[i]);
	}
}
