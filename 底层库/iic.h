#ifndef __IIC_H__
#define __IIC_H__

#include <stdint.h>

uint8_t ADC(uint8_t address);
void DAC(uint8_t value);
void write_2k(uint8_t address, uint8_t Data);
uint8_t Read_2k(uint8_t address);



#endif