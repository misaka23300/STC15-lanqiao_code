#ifndef __SYS_H__
#define __SYS_H__
#include "main.h"
void Delay(u16 xms);		//@12.000MHz
void Timer0Init(void);		//1∫¡√Î@12.000MHz
void Sys_Init();
void UartInit(void);		//4800bps@12.000MHz
void Uart_SendString(u8 *str);
#endif