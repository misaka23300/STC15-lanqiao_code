#include "iic.h"

#define DELAY_TIME 5

//I2Cﻉﻎﺵﻑﺥﻌﺎﺟﺹﺽﮌﺎﭦﺁﮌﮮ
void IIC_Delay(unsigned char i)
{
    do{_nop_();}
    while(i--);        
}

//I2Cﻉﻎﺵﻑﺩﮪﭘﺁﺷﺧﭦﺧ
void IIC_Start(void)
{
    SDA = 1;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDA = 0;
    IIC_Delay(DELAY_TIME);
    SCL = 0;	
}

//I2Cﻉﻎﺵﻑﺱ۲ﻅﺗﺷﺧﭦﺧ
void IIC_Stop(void)
{
    SDA = 0;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//ﺓ۱ﺯﺱﺽ۵ﺑﻭﭨﮨﺓﮄﺽ۵ﺑﻭﺷﺧﭦﺧ
void IIC_SendAck(bit ackbit)
{
    SCL = 0;
    SDA = ackbit;  					
    IIC_Delay(DELAY_TIME);
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SCL = 0; 
    SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//ﭖﺫﺑﮮﺽ۵ﺑﻭ
bit IIC_WaitAck(void)
{
    bit ackbit;
	
    SCL  = 1;
    IIC_Delay(DELAY_TIME);
    ackbit = SDA;
    SCL = 0;
    IIC_Delay(DELAY_TIME);
    return ackbit;
}

//I2Cﻉﻎﺵﻑﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺛﻌﮌﮮﺝﻏ
void IIC_SendByte(unsigned char byt)
{
    unsigned char i;

    for(i=0; i<8; i++)
    {
        SCL  = 0;
        IIC_Delay(DELAY_TIME);
        if(byt & 0x80) SDA  = 1;
        else SDA  = 0;
        IIC_Delay(DELAY_TIME);
        SCL = 1;
        byt <<= 1;
        IIC_Delay(DELAY_TIME);
    }
    SCL  = 0;  
}

//I2Cﻉﻎﺵﻑﺛﺽﮌﻁﺻﭨﺕﺉﻉﻅﺛﻌﮌﮮﺝﻏ
unsigned char IIC_RecByte(void)
{
    unsigned char i, da;
    for(i=0; i<8; i++)
    {   
    	SCL = 1;
	IIC_Delay(DELAY_TIME);
	da <<= 1;
	if(SDA) da |= 1;
	SCL = 0;
	IIC_Delay(DELAY_TIME);
    }
    return da;    
}

//void IIC_Start(void); IICﺟ۹ﮌﺙﺷﺧﭦﺧ
//void IIC_Stop(void);  IICﺱ۲ﻅﺗﺷﺧﭦﺧ
//bit IIC_WaitAck(void);  IICﭖﺫﺑﮮﺽ۵ﺑﻭ
//void IIC_SendAck(bit ackbit); IICﺑﺽﭨﻲﮌﮄﺓﮦﺽ۵ﺑﻭ
//void IIC_SendByte(unsigned char byt); IICﺓ۱ﺯﺱﮌﮮﺝﻏ
//unsigned char IIC_RecByte(void); IICﺛﺽﮌﻁﺑﺽﭨﻲﮌﮮﺝﻏ


void AT24C02_Write(u8 addr,u8 Data){
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_SendByte(Data);
	IIC_WaitAck();
	IIC_Stop();
	Delay(5);
}

u8 AT24C02_Read(u8 addr){
	u8 Data;
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	
	IIC_Start();
	IIC_SendByte(0xa1);
	IIC_WaitAck();
	Data=IIC_RecByte();
	IIC_SendAck(1);//ﺎﭨﺽ۵ﺑﻭ
	IIC_Stop();
	Delay(5);
	return Data;
}
