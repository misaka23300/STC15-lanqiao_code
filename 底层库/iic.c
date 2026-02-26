#include "iic.h"
#include "intrins.h"

sbit scl = P2^0;
sbit sda = P2^1;

#define DELAY_TIME	10

static void I2C_Delay(uint8_t n)
{
    do
    {
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();_nop_();		
    }
    while(n--);      	
}

void I2CStart(void)
{
    sda = 1;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 0;
	I2C_Delay(DELAY_TIME);
    scl = 0;    
}

void I2CStop(void)
{
    sda = 0;
    scl = 1;
	I2C_Delay(DELAY_TIME);
    sda = 1;
	I2C_Delay(DELAY_TIME);
}

void I2CSendByte(uint8_t byt)
{
    uint8_t i;
	
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

uint8_t I2CReceiveByte(void)
{
	uint8_t da;
	uint8_t i;
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

uint8_t I2CWaitAck(void)
{
	uint8_t ackbit;
	
    scl = 1;
	I2C_Delay(DELAY_TIME);
    ackbit = sda; 
    scl = 0;
	I2C_Delay(DELAY_TIME);
	
	return ackbit;
}

void I2CSendAck(uint8_t ackbit)
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

uint8_t ADC(uint8_t address)
{
    uint8_t adc;
    I2CStart();

    I2CSendByte(0x90);
    I2CWaitAck();

    I2CSendByte(address);
    I2CWaitAck();

    I2CStart();

    I2CSendByte(0x91);
    I2CWaitAck();

    adc = I2CReceiveByte();
    I2CSendAck(1);

    I2CStop();
}

void DAC(uint8_t value)
{
    I2CStart();

    I2CSendByte(0x90);
    I2CWaitAck();

    I2CSendByte(0x43);
    I2CWaitAck();

    I2CSendByte(value);
    I2CWaitAck();

    I2CStop();
}

void write_2k(uint8_t address, uint8_t Data)
{
    I2CStart();

    I2CSendByte(0xA0);
    I2CWaitAck();

    I2CSendByte(address);
    I2CWaitAck();

    I2CSendByte(Data);
    I2CWaitAck();

    I2CStop();

}

uint8_t Read_2k(uint8_t address)
{
    uint8_t Data;

    I2CStart();
    I2CWaitAck();

    I2CSendByte(address);
    I2CWaitAck();

    I2CStart();

    I2CSendByte(0xA1);
    I2CWaitAck();

    Data = I2CReceiveByte();
    I2CSendAck(1);

    I2CStop();
    return Data;
}
