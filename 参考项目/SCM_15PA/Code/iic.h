#ifndef __IIC_H
#define __IIC_H

#include "main.h"

sbit scl = P2^0;
sbit sda = P2^1;

void I2CStop();
void I2CStart();
void I2CSendByte(unsigned char byt);
void I2CSendAck(unsigned char ackbit);
unsigned char I2CWaitAck(void);
unsigned char I2CReceiveByte(void);

#endif
