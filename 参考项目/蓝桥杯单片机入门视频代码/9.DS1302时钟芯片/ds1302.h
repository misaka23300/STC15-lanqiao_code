#ifndef __DS1302_H
#define __DS1302_H

#include "main.h"
#include <intrins.h>

sbit SCK = P1^7;		
sbit SDA = P2^3;		
sbit RST = P1^3; 

void Write_Ds1302(unsigned char temp);
void Write_Ds1302_Byte( unsigned char address,unsigned char dat );
unsigned char Read_Ds1302_Byte( unsigned char address );
void Ds1302_Settime(u8 nian,yue,ri,zhou,shi,fen,miao);
u8 Ds1302_Readtime(unsigned char address);
#endif
