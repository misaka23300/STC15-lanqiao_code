/**
 * @file boot.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __BOOT_H__
#define __BOOT_H__

#include "STC15F2K60S2.H"
#include "intrins.h"
#include <stdint.h>

void boot_init();
void latch( uint8_t i );
void Timer1_Init( void );
void Delay14us( void );
void timer_0_sonic();
void timer_0_ne555();

#endif