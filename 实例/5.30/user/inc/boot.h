#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15f2k60s2.h"
#include "stdio.h"
#include "intrins.h"

#include "string.h"
#include "ctype.h"

typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned int uint16_t;
typedef signed int int16_t;


typedef int8_t stc_err_t;

void boot_init();
void latch(uint8_t i);

#endif