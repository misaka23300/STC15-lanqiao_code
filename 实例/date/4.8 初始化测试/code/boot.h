#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15f2k60s2.h"
#include "intrins.h"

typedef unsigned char uint8_t;
#define uint unsigned int

void boot_init();
void timer_1();
void latch(uchar i);

#endif