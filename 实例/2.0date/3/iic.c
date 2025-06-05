#include "iic.h"

sbit scl = P2 ^ 0;
sbit sda = P2 ^ 1;

#define DELAY_TIME	10

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



uchar ADC(uchar channel)
{
    uchar v;
    I2CStart();

    I2CSendByte(0x90);
    I2CWaitAck();

    I2CSendByte(channel);
    I2CWaitAck();

    I2CStart();

    I2CSendByte(0x91);
    I2CWaitAck();

    v = I2CReceiveByte();
    I2CSendAck(1);

    I2CStop();

    return v;
}

uchar read_2k(uchar address)
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

void write_2k(uchar address,uchar Data)
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