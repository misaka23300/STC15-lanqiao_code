#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

#define uchar unsigned char;
#define uchar unsigned char;

void boot_init();
void batch(uchar i);
void Timer0_Init(void);

#endif