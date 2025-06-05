#ifndef __IIC_H__
#define __IIC_H__

#include "machine.h"

// 传入地址 返回ADC数据 地址为 0x01 0x03
uchar PCF8591_ADC(uchar address);

// 传入0-255,转换为电压
void PCF8591_DAC(uchar value);

// 传入地址和数据,进行写入
void AT24C02_write(uchar address, Data);

// 传入地址, 返回数据
uchar AT24C02_read(uchar address);


#endif