#ifndef __MAIN_H__
#define __MAIN_H__

#include "STC15F2K60S2.H"

// stdint.h
typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned int uint16t;
typedef signed int int16_t;

// stdbool.h
#define true 1
#define false 0


uint8_t latch(uint8_t i);
uint8_t led_display(uint8_t i);

#endif