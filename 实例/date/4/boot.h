#ifndef __BOOT_H_
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void boot_init();
void latch(uchar i);
void Timer1_Init();

#endif