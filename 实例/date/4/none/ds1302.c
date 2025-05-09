#inlcude "ds1302.h"

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
 			temp |= 0x80;	
 		SCK=1;
	} 
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
	SCK=1;	_nop_();
	SDA=0;	_nop_();
	SDA=1;	_nop_();
	return (temp);			
}

uchar hex_to_bcd(uchar HEX)
{
	uchar BCD;
	BCD = (HEX / 10) << 4 + (HEX % 10);
	return BCD;
}

uchar bcd_to_hex(uchar BCD)
{
	uchar HEX;
	HEX = (BCD << 4)* 10 + (BCD & 0x0F);
	return HEX;
}

void init_DS1302(uchar hour, min, sec)
{
	uchar tmp;

	Write_Ds1302_Byte(0x8E, 0x00);

	tmp = hex_to_bcd(sec);
	Write_Ds1302_Byte(0x80, tmp);

	tmp = hex_to_bcd(min);
	Write_Ds1302_Byte(0x82, tmp);

	tmp = hex_to_bcd(hour);
	Write_Ds1302_Byte(0x84, tmp);

	Write_Ds1302_Byte(0x8E,0x80);

} 

//

uchar code write_address[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8A, 0x8C};
uchar code read_address[7] = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8D};

void write_ds1302(uchar *time)
{
	// 如果要用for循环 就要传入数组
	uchar i;

	Write_Ds1302_Byte(0x8E, 0x00);
	for(i = 0;i < 3;i++)
	{
		Write_Ds1302_Byte(write_address[i], hex_to_bcd(time[i]));
	}
	Write_Ds1302_Byte(0x8E, 0x80);
}


uchar read_ds1302(uchar i)
{
	uchar time;
	time = Read_Ds1302_Byte(read_address[i]);
	return time;
}


