//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: timer.c
// 文件描述: 
// 文件版本: V1.0
// 修改记录:
//   1. (2026-03-05) 创建文件
////////////////////////////////////////
//<<AICUBE_USER_HEADER_REMARK_END>>


#include "config.h"


//<<AICUBE_USER_INCLUDE_BEGIN>>
// 在此添加用户头文件包含  
//<<AICUBE_USER_INCLUDE_END>>


//<<AICUBE_USER_GLOBAL_DEFINE_BEGIN>>
// 在此添加用户全局变量定义、用户宏定义以及函数声明  
//<<AICUBE_USER_GLOBAL_DEFINE_END>>



////////////////////////////////////////
// 定时器2初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void TIMER2_Init(void)
{
#ifdef BAUDRATE
#undef BAUDRATE
#endif
#define BAUDRATE                (9600)
#define T2_RELOAD               (65536 - (SYSCLK / BAUDRATE + 2) / 4)

    TIMER2_TimerMode();                 //设置定时器2为定时模式
    TIMER2_1TMode();                    //设置定时器2为1T模式
    TIMER2_EnableInt();                 //使能定时器2中断
    TIMER2_SetReload16(T2_RELOAD);      //设置定时器2的16位重载值
    TIMER2_Run();                       //定时器2开始运行

    //<<AICUBE_USER_TIMER2_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_TIMER2_INITIAL_END>>
}


////////////////////////////////////////
// 定时器2中断服务程序
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void TIMER2_ISR(void) interrupt TMR2_VECTOR
{
    //<<AICUBE_USER_TIMER2_ISR_CODE1_BEGIN>>
    // 在此添加中断函数用户代码  
    //<<AICUBE_USER_TIMER2_ISR_CODE1_END>>
}


//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


