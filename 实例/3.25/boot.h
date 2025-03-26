#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void boot_init(void);
void timer_0(void);
void timer_1(void);
void timer_2(void);
void batch(uchar i);
void Delay14us(void);

#endif