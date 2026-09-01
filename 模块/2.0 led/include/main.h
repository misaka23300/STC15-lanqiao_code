#ifndef __MAIN_H__
#define __MAIN_H__

#include "STC15F2K60S2.H"

typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed int int16_t;

#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

uint8_t latch(uint8_t i);
uint8_t led_display(uint8_t i);

#endif
