#ifndef __BOOT_H_
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"

/* typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed int int16_t; */
#define uint8_t unsigned char
#define int8_t signed char
#define uint16_t unsigned int
#define int16_t signed int

void boot_init();
void latch(uint8_t i);
void Delay14us(void);
void Timer2_Init(void);

void Timer1_Init(void);	
#endif