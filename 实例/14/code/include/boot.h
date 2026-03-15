#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15.h"
#include "intrins.h"


typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed char int16_t;

void boot_init();
void latch(uint8_t i);
void Timer0_Init(void);
void Timer2_Init(void);


#endif