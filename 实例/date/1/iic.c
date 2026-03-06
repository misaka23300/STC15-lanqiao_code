/*
  ﺏﮊﺷﮨﺯﭖﺣﺊ: IICﻉﻎﺵﻑﮄﮮﭘﺁﺏﮊﺷﮨ
  ﺫﻥﺙﹼﭨﺓﺝﺏ: Keil uVision 4.10 
  ﺽﺎﺙﹼﭨﺓﺝﺏ: CT107ﭖ۴ﺩ؛ﭨﻲﻉﻍﭦﺵﮌﭖﺹﭖﺩﺛﮊ۷ 8051۲؛12MHz
  ﺫﻁ    ﺩﻌ: 2011-8-9
*/

#include "sys.h"
#include "iic.h"
#include "intrins.h"

#define DELAY_TIME 5

#define SlaveAddrW 0xA0
#define SlaveAddrR 0xA1

//ﻉﻎﺵﻑﺻﮮﺛﺧﭘ۷ﺻﮒ
sbit SDA = P2^1;  /* ﮌﮮﺝﻏﺵﻑ */
sbit SCL = P2^0;  /* ﮌﺎﻅﺽﺵﻑ */

void IIC_Delay(unsigned char i)
{
    do{_nop_();}
    while(i--);        
}
//ﻉﻎﺵﻑﺩﮪﭘﺁﮊﺀﺙﹼ
void IIC_Start(void)
{
    SDA = 1;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDA = 0;
    IIC_Delay(DELAY_TIME);
    SCL = 0;	
}

//ﻉﻎﺵﻑﺱ۲ﻅﺗﮊﺀﺙﹼ
void IIC_Stop(void)
{
    SDA = 0;
    SCL = 1;
    IIC_Delay(DELAY_TIME);
    SDA = 1;
    IIC_Delay(DELAY_TIME);
}

//ﺓ۱ﺯﺱﺽ۵ﺑﻭ
void IIC_SendAck(bit ackbit)
{
    SCL = 0;
    SDA = ackbit;  					// 0۲ﭦﺽ۵ﺑﻭ۲؛1۲ﭦﺓﮄﺽ۵ﺑﻭ
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

//ﺱ۷ﺗﮮI2Cﻉﻎﺵﻑﺓ۱ﺯﺱﮌﮮﺝﻏ
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

//ﺑﺽI2Cﻉﻎﺵﻑﺭﺵﺛﺽﮌﻁﮌﮮﺝﻏ
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

void  IIC_Writedat(unsigned char addr,unsigned char dat)
{
	IIC_Start();
	IIC_SendByte(SlaveAddrW );
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop();
	delay_ms(5);
}
unsigned char IIC_Readdat(unsigned char addr)
{
	unsigned char dat;
	IIC_Start();
	IIC_SendByte(SlaveAddrW );
	IIC_WaitAck();
	IIC_SendByte(addr);
	IIC_WaitAck();
	
	IIC_Start();
	IIC_SendByte(SlaveAddrR );
	IIC_WaitAck();
	dat=IIC_RecByte();
	IIC_SendAck(1);
	IIC_Stop();

	return dat;
}

/*PCF8591ﮌﮮﺝﻏﺎﺭﺙﺁﭦﺁﮌﮮ
unsigned char PCF8591_AD(unsigned char channel)         // ﺥ۲ﺥﻗﭖﺛﮌﮮﻉﻅ
{
	unsigned char dat;
	IIC_Start();
	IIC_SendByte(0x90);	
	IIC_WaitAck();
	IIC_SendByte(channel);	
	IIC_WaitAck();
	
	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();
	dat=IIC_RecByte();
	IIC_SendAck(1);
	IIC_Stop();
	
	return dat;
}
void PCF8591_DA(unsigned char dat)    //ﮌﮮﻉﻅﭖﺛﺥ۲ﺥﻗ
{
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(0x40);
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop();
	delay_ms(10);	
}
	*/
	