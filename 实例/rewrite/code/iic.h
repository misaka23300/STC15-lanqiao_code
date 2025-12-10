#ifndef __IIC_H__
#define __IIC_H__

#include "machine.h"

// 传入地址 返回ADC数据 地址为 0x01 0x03
uint8_t PCF8591_ADC(uint8_t address);

// 传入0-255,转换为电压
void PCF8591_DAC(uint8_t value);

// 传入地址和数据,进行写入
void AT24C02_write(uint8_t address, Data);

// 传入地址, 返回数据
uint8_t AT24C02_read(uint8_t address);


#endif