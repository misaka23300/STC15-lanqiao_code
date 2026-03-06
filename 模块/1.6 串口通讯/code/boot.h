#ifndef __BOOT_H__
#define __BOOT_H__

#include "intrins.h"
#include "stc15f2k60s2.h"


#define uint8_t unsigned char
#define uint16_t unsigned int

void boot_init();
void timer_2();
void Timer1_Init(void);

#endif