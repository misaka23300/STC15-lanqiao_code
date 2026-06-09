/**
 * @file boot.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __BOOT_H__
#define __BOOT_H__

#define uchar unsigned char
#define uint unsigned int

#define iuchar idata unsigned char 

#include "STC15F2K60S2.H"
#include "intrins.h"

void boot_init();
void latch( uchar i );
void Timer2_Init( void );

#endif