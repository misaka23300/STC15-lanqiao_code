#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"


#define uint8_t unsigned char
#define uint16_t unsigned int
#define int8_t signed char
#define int16_t signed int
	
	

void boot_init();
void Timer1_Init(void);


void latch(uint8_t i);


void Delay14us(void);

#endif