#include "ds1302.h"


sbit SCK = P1^7;
sbit SDA = P2^3;
sbit RST = P1^3;

uint8_t code write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};
uint8_t code read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d};

uint8_t set_time[7] = {0x50, 0x59, 0x23, 0x01, 0x01, 0x01, 0x26};
uint8_t now_time[3];


//
void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK = 0;
		SDA = temp&0x01;
		temp>>=1; 
		SCK=1;
	}
}   

//
void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

//
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


uint8_t bcd_to_hex(uint8_t bcd) 
{
	return bcd / 16 * 10 + bcd % 16;
}

void ds1302_write()
{
	uint8_t i;
	Write_Ds1302_Byte(0x8e, 0x00);
	for (i = 0; i < 7;i++) {
		Write_Ds1302_Byte(write_address[i], set_time[i]);	
	}	
	Write_Ds1302_Byte(0x8e, 0x80);	
}


void ds1302_read()
{
	uint8_t i;
	for (i = 0; i< 3; i++) {
		now_time[i] = Read_Ds1302_Byte(read_address[i]);
		
	}

	for (i = 0; i< 3; i++) {
		now_time[i] = bcd_to_hex(now_time[i]);
		
	}
}