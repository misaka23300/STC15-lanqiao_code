#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int32_t;

void boot_init();
void Timer2_Init(void);
void Uart1_Init(void);
void latch(uint8_t i);
void Delay14us(void);

#endif