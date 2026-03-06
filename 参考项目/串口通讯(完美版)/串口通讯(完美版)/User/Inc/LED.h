#ifndef _LED_H
#define _LED_H

#include "./config.h"//包含配置库

//定义串口数据高4位对应的高低位
#define LED_High 1 //对应的是LED5~LED8
#define LED_Low  0 //对应的是LED1~LED4

//LED配置数据结构体
typedef struct{
	//LED暂存变量,存储LED状态,不能对端口直接进行逻辑操作,
	//否则将会造成不可预估的后果
	uchar LED_Temp;
	
	//LED暂存变量高低位变量,分别存储高4位和低4位的LED状态
	uchar LED_TempH;
	uchar LED_TempL;
	
	//位状态变量,取值串口接收字节高4位判断对应LED的低4位还是高4位
	uchar Bit_Sta;
	
	//LED状态控制变量,取值串口接收字节低4位判断LED状态
	uchar LED_Sta;
}LED_ConfigTypeDef;

extern LED_ConfigTypeDef led_config;//定义句柄

//LED变量初始化函数
void LED_Tag_Init();

//LED位状态判断函数
bit LED_Bit_Handler();

//LED状态判断函数
void LED_Sta_Handler();

//LED运行状态指示函数
void LED_Running();

#endif