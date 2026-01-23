#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15f2k60s2.h"
#include "intrins.h"
#include "stdio.h"

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned int uint16_t;
typedef signed int int16_t;

void boot_init();
void latch(uint8_t i);
void Timer1_Init(void);


#endif