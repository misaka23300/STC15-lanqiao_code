#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void latch(char i);
void Delay14us(void);

#endif