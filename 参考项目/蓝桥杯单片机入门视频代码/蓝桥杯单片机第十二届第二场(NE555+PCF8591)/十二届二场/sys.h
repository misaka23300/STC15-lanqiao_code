#ifndef __SYS_H__
#define __SYS_H__

#include "main.h"
void Sys_Init();
void Delay(u16 xms)		;//@12.000MHz
void Timer1Init(void);		//1����@12.000MHz
void Timer2Init(void)	;	//800΢��@12.000MHz



#endif