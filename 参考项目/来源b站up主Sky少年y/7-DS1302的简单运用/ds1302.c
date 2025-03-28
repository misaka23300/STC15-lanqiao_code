/*	# 	DS1302代码片段说明
	1. 	本文件夹中提供的驱动代码供参赛选手完成程序设计参考。
	2. 	参赛选手可以自行编写相关代码或以该代码为基础，根据所选单片机类型、运行速度和试题
		中对单片机时钟频率的要求，进行代码调试和修改。
*/	
						
//

#include <STC15F2K60S2.H>
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int
//秒、分、时、日、月、星期、年
code uchar DS1302_Write_adr[7]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c}; //DS1302_Write_adr[6]
code uchar DS1302_Read_adr[7]={0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
uchar DS1302_Time_Reset[7]={0x55,0x05,0x23,0x09,0x02,0x07,0x25}; //初始时间
unsigned char Time10[7]={0,0,0,0,0,0,0};

sbit SCK = P1^7;            //位定义
sbit SDA = P2^3;
sbit RST = P1^3;

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

uchar i=0;
void DS1302_Write_Time()    //初始值配置好了
{
	Write_Ds1302_Byte(0x8e,0x00);
	for(i=0;i<=6;i++)
	{
		Write_Ds1302_Byte(DS1302_Write_adr[i],DS1302_Time_Reset[i]);
	}
	Write_Ds1302_Byte(0x8e,0x80);
}

void DS1302_Read_Time()
{
	for(i=0;i<=6;i++)
	{
		DS1302_Time_Reset[i] = Read_Ds1302_Byte(DS1302_Read_adr[i]);
	}
	//0x35  ==  35           
	//3*16+5*1  / 16  =  3
	//3*16+5*1  % 16  =  5
	//3*10 + 5   
	for(i=0;i<=6;i++)
	{
		Time10[i] = DS1302_Time_Reset[i]/16*10 + DS1302_Time_Reset[i]%16;
	}
}


