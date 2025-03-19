#ifndef __IIC_H__
#define __IIC_H__

#include "boot.h"

uchar ADC(uchar channel);
uchar read_2k(uchar address);
void write_2k(uchar address,uchar Data);


#endif