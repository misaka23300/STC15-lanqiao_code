#ifndef __SYS_H__
#define __SYS_H__
#include "main.h"
void Delay(u16 xms);		//@12.000MHz
void NE555_Init(void);		//NE555��ʼ��
void Sys_Init();
void Timer1Init(void);		//1����@12.000MHz
#endif