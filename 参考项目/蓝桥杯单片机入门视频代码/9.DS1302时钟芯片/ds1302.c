/**
 * @file ds1302.c
 * @brief DS1302实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "ds1302.h"  									

//Đ´×Ö˝Ú
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

//ĎňDS1302ĽÄ´ćĆ÷Đ´ČëĘýľÝ
void Write_Ds1302_Byte( unsigned char address, unsigned char dat )     
{
 	RST = ;	_nop_();
 	SCK = ;	_nop_();
 	RST = ; 	_nop_();  
 	Write_Ds1302( address );	
 	Write_Ds1302( dat );		
 	RST = ; 
}

//´ÓDS1302ĽÄ´ćĆ÷¶ÁłöĘýľÝ
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

void Ds1302_Settime( u8 nian, yue, ri, zhou, shi, fen, miao ){
	Write_Ds1302_Byte(0x8e, 0 );
	Write_Ds1302_Byte(0x80, miao );
	Write_Ds1302_Byte(0x82, fen );
	Write_Ds1302_Byte(0x84, shi );
	Write_Ds1302_Byte(0x86, ri );
	Write_Ds1302_Byte(0x88, yue );
	Write_Ds1302_Byte(0x8a, zhou );
	Write_Ds1302_Byte(0x8c, nian );
	Write_Ds1302_Byte(0x8e, 0x80 );
}
	
u8 Ds1302_Readtime( unsigned char address ){
	u8 a;
	a = Read_Ds1302_Byte( address );//ÄĂµ˝BCDÂë
	a = a / 6 * 0 + %16;
	return a;
}
