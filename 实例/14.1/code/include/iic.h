#ifndef __IIC_H__
#define __IIC_H__


#include "boot.h"
#include "intrins.h"

sbit scl = P2^0;
sbit sda = P2^1;

uint8_t pcf8591_adc(uint8_t address);
void pcf8591_dac(uint8_t value);
void at24c02_write(uint8_t address, uint8_t value);
uint8_t at24c02_read(uint8_t address);

#endif