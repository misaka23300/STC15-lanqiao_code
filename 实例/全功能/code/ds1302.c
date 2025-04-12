#include "ds1302.h"

sbit SCK = P1^7;
sbit SDA = P2^3;
sbit RST = P1^3;

// 秒 分 时 天 月 星期 年
code uchar read_address[7] = {0x81, 0x83, 0X85, 0X87, 0X89, 0X8B, 0x8D};
code uchar write_address[7] = {0x80, 0x82, 0X84, 0X86, 0X88, 0X8A, 0x8C};

uchar time_now[3] = {0, 0, 0};

code uchar time_init[7] = {0x50, 0x59, 0x23, 0x09, 0x04, 0x03, 0x25};


void Write_Ds1302(unsigned  char temp) 
{
	unsigned char i;
	for (i=0;i<8;i++)     	
	{ 
		SCK = 0;
		SDA = temp & 0x01;
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


uchar bcd_to_hex(uchar bcd)
{
	return (bcd / 16 * 10) + (bcd % 16);
}


void date_write()
{
	uchar i;
	Write_Ds1302_Byte(0X8E, 0X00);

	for (i = 0; i < 7;i++)
	{
		Write_Ds1302_Byte(write_address[i], time_init[i]);
	}

	Write_Ds1302_Byte(0X8E, 0X80);
}


void date_read()
{
	uchar i;
	for (i = 0; i < 3;i++)
	{
		time_now[i] = Read_Ds1302_Byte(read_address[i]);
	}

	for (i = 0;i < 3;i++)
	{
		time_now[i] = bcd_to_hex(time_now[i]);
	}
}


