#ifndef _SYS_H
#define _SYS_H

#include "./config.h"//包含配置库

//GPIO口初始化函数
void GPIO_Init();

//全局变量初始化函数
void Tag_Init();

//外设初始化函数
void Perpherial_Init();

//其他无关外设初始化函数
void Other_Init();

//系统初始化函数
void Sys_Init();

#endif