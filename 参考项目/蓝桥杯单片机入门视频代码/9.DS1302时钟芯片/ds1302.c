#include "ds1302.h"  									

//д�ֽ�
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

//��DS1302�Ĵ���д������
void Write_Ds1302_Byte( unsigned char address,unsigned char dat )     
{
 	RST=0;	_nop_();
 	SCK=0;	_nop_();
 	RST=1; 	_nop_();  
 	Write_Ds1302(address);	
 	Write_Ds1302(dat);		
 	RST=0; 
}

//��DS1302�Ĵ�����������
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

void Ds1302_Settime(u8 nian,yue,ri,zhou,shi,fen,miao){
	Write_Ds1302_Byte(0x8e,0);
	Write_Ds1302_Byte(0x80,miao);
	Write_Ds1302_Byte(0x82,fen);
	Write_Ds1302_Byte(0x84,shi);
	Write_Ds1302_Byte(0x86,ri);
	Write_Ds1302_Byte(0x88,yue);
	Write_Ds1302_Byte(0x8a,zhou);
	Write_Ds1302_Byte(0x8c,nian);
	Write_Ds1302_Byte(0x8e,0x80);
}
	
u8 Ds1302_Readtime(unsigned char address){
	u8 a;
	a = Read_Ds1302_Byte(address);//�õ�BCD��
	a = a/16*10+a%16;
	return a;
}
