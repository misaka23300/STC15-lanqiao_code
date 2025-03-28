#ifndef _IIC_H
#define _IIC_H

#include "main.h"
#include "intrins.h"

sbit SDA = P2^1;
sbit SCL = P2^0;

void IIC_Start(void); 
void IIC_Stop(void);  
bit IIC_WaitAck(void);  
void IIC_SendAck(bit ackbit); 
void IIC_SendByte(unsigned char byt); 
unsigned char IIC_RecByte(void); 
void AT24C02_Write(u8 addr,u8 Data);
u8 AT24C02_Read(u8 addr);
#endif