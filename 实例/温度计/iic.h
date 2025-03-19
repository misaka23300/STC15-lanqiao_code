#ifndef __IIC_H__
#define __IIC_H__

#include "boot.h"

uchar at2402_read(uchar address);
void at2402_write(uchar address,uchar Data);

uchar pcf8591_ADC(uchar channel);
void pcf8591_DA(uchar v);

#endif