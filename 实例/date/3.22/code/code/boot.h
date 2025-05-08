#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15f2k60s2.h"
#include "intrins.h"

#define uchar unsigned char
#define uint unsigned int

void boot_init(void);
void timer_0(void);
void timer_1(void);
void batch(uchar i);

#endif