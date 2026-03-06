#ifndef _TIMER_H
#define _TIMER_H

#include "./config.h"//包含配置库

//定义定时器2重装载值
#define Timer2_Reload (65536-(MAIN_FOSC/1000))

//定时器延时数据结构体
typedef struct {
	volatile ulong Msecflag1;
	volatile ulong Msecflag2;
	volatile ulong Msecflag3;
	volatile ulong Msecflag4;
	volatile ulong Msecflag5;
	volatile ulong Msecflag6;
	volatile ulong Msecflag7;
	volatile ulong Msecflag8;
}Timer_Delay_TypeDef;
extern Timer_Delay_TypeDef timer_delay; 

//定时器变量初始化函数
void Timer_Tag_Init();

//定时器0初始化函数
void Timer2_Init();

#endif