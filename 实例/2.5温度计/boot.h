#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void boot_init();
void batch(uchar i);
void Timer2_Init();
void Delay500ms();

#endif