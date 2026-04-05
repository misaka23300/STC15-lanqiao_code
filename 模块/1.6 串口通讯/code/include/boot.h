#ifndef __BOOT_H__
#define __BOOT_H__

#include "stc15.h"
typedef unsigned char uint8_t;
typedef signed char int8_t;

typedef unsigned int uint16_t;
typedef signed int int16_t;

void boot_init();
void Timer2_Init(void);
void Uart1_Init(void);


#endif