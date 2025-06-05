#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"


typedef unsigned char uchar;
typedef unsigned int uint;

void boot_init();
void batch(uchar i);
void Timer1_Init(void);
void Delay14us(void);
void timer_0_sonic();
void timer_0_ne555();
#endif