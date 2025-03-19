#ifndef _IIC_H__
#define _IIC_H__

#include "sys.h"

void IIC_Start(void); 
void IIC_Stop(void);  
bit IIC_WaitAck(void);  
void IIC_SendAck(bit ackbit); 
void IIC_SendByte(unsigned char byt); 
unsigned char IIC_RecByte(void); 
//void outDA(uchar dat);
//uchar getAD(uchar chn);
void  IIC_Writedat(unsigned char pos,unsigned char dat);
unsigned char IIC_Readdat(unsigned char addr);
//unsigned char PCF8591_AD(unsigned char channel)  ;
//void PCF8591_DA(unsigned char dat);
#endif