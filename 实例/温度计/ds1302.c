#include "ds1302.h"

sbit SCK = P1^7;
sbit SDA = P2^3;
sbit RST = P1^3;


// 秒 分 时 日 月 星期 年
uchar write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8C};
uchar read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8D};

uchar send_time[7] = {45, 23, 7, 21, 7, 5, 25};
uchar now_time[7] = {0, 0, 0, 0, 0, 0, 0};

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


uchar hex_to_BCD(uchar HEX)
{
	uchar BCD;
	BCD = ((HEX / 10) << 4) + (HEX % 10);
	return BCD;
}

uchar BCD_to_hex(uchar BCD)
{
	uchar HEX;
	HEX = ((BCD >> 4) * 10) + (BCD & 0x0F);
	return HEX;
}


void init_time()
{
	uchar i;

	// 关闭写保护
	Write_Ds1302_Byte(0x8E, 0x00);

	for (i = 0; i < 7;i++)
	{
		Write_Ds1302_Byte(write_address[i], send_time[i]);
	}

	Write_Ds1302_Byte(0x8E, 0x80);
	
}

void read_time()
{
	uchar i;
	
	for (i = 0;i < 7;i++)
	{
		now_time[i] = Read_Ds1302_Byte(read_address[i]);
	}

	for (i = 0;i < 7;i++)
	{
		now_time[i] = BCD_to_hex(now_time[i]);
	}
}

void write_time(uchar* time)
{	
	uchar i;	
	for (i = 0;i < 7;i++)
		send_time[i] = hex_to_BCD(time[i]);
	init_time();
}




