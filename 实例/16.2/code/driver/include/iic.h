#ifndef __IIC_H__
#define __IIC_H__

#include "boot.h"


void pcf8591_adc(uint8_t channel);
void pcf8591_dac(uint8_t value);
void at24c02_write(uint8_t address, uint8_t value);
uint8_t at24c02_read(uint8_t address);

#endif