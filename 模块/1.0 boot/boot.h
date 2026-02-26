#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"
#include <stdint.h>

#define uchar uint8_t
#define uint uint16_t

void latch(uint8_t i);
void Delay14us(void);

#endif