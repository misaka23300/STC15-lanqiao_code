/**
 * @file sys.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef __SYS_H__
#define __SYS_H__

#include "main.h"
void Sys_Init();
void Delay( u16 xms )		;//@12.000MHz
void Timer1Init( void );		//1ºÁÃë@12.000MHz
void Timer2Init( void )	;	//800Î¢Ãë@12.000MHz

#endif