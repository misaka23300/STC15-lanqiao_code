#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"


typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed int int16_t;

void boot_init();
void latch(uint8_t i);
void Timer1_Init(void);
void Delay14us(void);
void loop_0to8(uint8_t *i)

#endif