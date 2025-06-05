#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15f2k60s2.h"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void boot_init();
void batch(uchar i);
void Timer2_Init(void);
void Delay14us(void);
void delete_0(uchar *a, uchar j, uchar negative);
#endif