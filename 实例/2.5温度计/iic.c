#include "iic.h"

sbit scl = P2 ^ 0;
sbit sda = P2 ^ 1;


//
#define DELAY_TIME	5

//
static void I2C_Delay(unsigned char n)
{
    do
    {
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();		
    }
    while(n--);      	
}

void Delay15ms()	//@12.000MHz
{
	unsigned char data i, j;

	i = 176;
	j = 21;
	do
	{
		while (--j);
	} while (--i);
}


//
void I2CStart(void)
{
    sda = 1;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 0;
	I2C_Delay(DELAY_TIME);
    scl = 0;    
}

//
void I2CStop(void)
{
    sda = 0;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 1;
	I2C_Delay(DELAY_TIME);
}

//
void I2CSendByte(unsigned char byt)
{
    unsigned char i;
	
    for(i=0; i<8; i++){
        scl = 0;
		I2C_Delay(DELAY_TIME);
        if(byt & 0x80){
            sda = 1;
        }
        else{
            sda = 0;
        }
		I2C_Delay(DELAY_TIME);
        scl = 1;
        byt <<= 1;
		I2C_Delay(DELAY_TIME);
    }
	
    scl = 0;  
}

//
unsigned char I2CReceiveByte(void)
{
	unsigned char da;
	unsigned char i;
	for(i=0;i<8;i++){   
		scl = 1;
		I2C_Delay(DELAY_TIME);
		da <<= 1;
		if(sda) 
			da |= 0x01;
		scl = 0;
		I2C_Delay(DELAY_TIME);
	}
	return da;    
}

//
unsigned char I2CWaitAck(void)
{
	unsigned char ackbit;
	
    scl = 1;
	I2C_Delay(DELAY_TIME);
    ackbit = sda; 
    scl = 0;
	I2C_Delay(DELAY_TIME);
	
	return ackbit;
}

//
void I2CSendAck(unsigned char ackbit)
{
    scl = 0;
    sda = ackbit; 
	I2C_Delay(DELAY_TIME);
    scl = 1;
	I2C_Delay(DELAY_TIME);
    scl = 0; 
	sda = 1;
	I2C_Delay(DELAY_TIME);
}




uchar at2402_read(uchar address)
{
    uchar Data;

    I2CStart();

    I2CSendByte(0xA0);
    I2CWaitAck();

    I2CSendByte(address);
    I2CWaitAck();

    I2CStart();

    I2CSendByte(0xA1);
    I2CWaitAck();

    Data = I2CReceiveByte();
    I2CSendAck(1);

    I2CStop();
    Delay15ms();

    return Data;
}

void at2402_write(uchar address,uchar Data)
{
    I2CStart();

    I2CSendByte(0xA0);
    I2CWaitAck();

    I2CSendByte(address);
    I2CWaitAck();

    I2CSendByte(Data);
    I2CWaitAck();

    I2CStop();
    Delay15ms();
}

/*
//0-255 0x00 0xff
void AT24C02_Write(uchar *dat,uchar addr,uchar num)    //1.数据 2.地址 3.多少个数据
{
	I2CStart();

	I2CSendByte(0xa0);
	I2CWaitAck();

	I2CSendByte(addr);
	I2CWaitAck();

	while(num--)
	{
		I2CSendByte(*dat++);
		I2CWaitAck();

		I2C_Delay(200);Delay15ms();
}

void AT24C02_Read(uchar *dat,uchar addr,uchar num)
{
	I2CStart();

	I2CSendByte(0xa0);
	I2CWaitAck();

	I2CSendByte(addr);
	I2CWaitAck();
	
	I2CStart();

	I2CSendByte(0xa1);
	I2CWaitAck();

	while(num--)
	{
		*dat++=I2CReceiveByte();
		if(num)
            I2CSendAck(0);
		else 
            I2CSendAck(1);
	}
	I2CStop();
}
*/
uchar pcf8591_ADC(uchar channel)
{
    uchar adc;

    I2CStart();

    I2CSendByte(0x90);
    I2CWaitAck();

    I2CSendByte(channel);
    I2CWaitAck();

    I2CStart();

    I2CSendByte(0x91);
    I2CWaitAck();

    adc = I2CReceiveByte();
    I2CSendAck(1);

    I2CStop();

    return adc;
}

void pcf8591_DA(uchar v)
{
    I2CStart();

    I2CSendByte(0x91);
    I2CWaitAck();

    I2CSendByte(0x40);
    I2CWaitAck();

    I2CSendByte(v);
    I2CWaitAck();

    I2CStop();

}