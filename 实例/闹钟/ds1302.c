#include "ds1302.h"

sbit SCK = P1^7;
sbit RST = P1^3;
sbit SDA = P2^3;

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

void hex_to_bcd(uchar HEX)
{
    uchar BCD;
    BCD = (HEX / 10) << 4 + (HEX % 10);
    return BCD;
}

void bcd_to_hex(uchar BCD)
{
    uchar HEX;
    HEX = (BCD << 4 )*10 + (BCD & 0x0F);
    return HEX;
}

void init_ds1302(uchar *time)
{
    uchar temp;
    Write_Ds1302_Byte(0x8E, 0x00);

    temp = 
}

void ds1302_proc()
{

}


void init_ds1302(uchar hour, minute, second)
{
    uchar tmp;

    Write_Ds1302_Byte(0x8E, 0x00);

	
    

    Write_Ds1302_Byte(0x8E, 0x80);
}