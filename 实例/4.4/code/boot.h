#ifndef __BOOT_H__
#define __BOOT_H__

#define uchar unsigned char
#define uint unsigned int

#define iuchar idata unsigned char 

#include "STC15F2K60S2.H"
#include "intrins.h"


void boot_init();
void batch(uchar i);
void timer_1();


#endif