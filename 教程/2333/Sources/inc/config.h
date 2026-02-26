//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: config.h
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#ifndef __CONFIG_H__
#define __CONFIG_H__


//<<AICUBE_USER_DEFINE_BEGIN>>
// 在此添加用户宏定义  
//<<AICUBE_USER_DEFINE_END>>


#define __ENCODING              "UTF-8" //DO NOT DELETE or MODIFY


#define FOSC                    12000000UL
#define SYSCLK                  FOSC
#define MAIN_Fosc               FOSC

#include <stc15.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <intrins.h>

#include "def.h"
#include "stc15f_def.h"


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
//<<AICUBE_USER_INCLUDE_END>>


#include "port.h"
#include "clock.h"
#include "timer.h"
#include "uart.h"

void SYS_Init(void);
void delay_us(uint16_t us);
void delay_ms(uint16_t ms);



//<<AICUBE_USER_EXTERNAL_DECLARE_BEGIN>>
// 在此添加用户外部函数和外部变量声明  
//<<AICUBE_USER_EXTERNAL_DECLARE_END>>


#endif
