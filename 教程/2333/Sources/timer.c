//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: timer.c
// 文件描述: 
// 文件版本: V1.0
// 修改记录:
//   1. (2026-01-24) 创建文件
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
// 定时器1初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void TIMER1_Init(void)
{
#ifdef BAUDRATE
#undef BAUDRATE
#endif
#define BAUDRATE                (115200)
#define T1_RELOAD               (65536 - (SYSCLK / BAUDRATE + 2) / 4)

    TIMER1_TimerMode();                 //设置定时器1为定时模式
    TIMER1_1TMode();                    //设置定时器1为1T模式
    TIMER1_Mode0();                     //设置定时器1为模式0 (16位自动重载模式)
    TIMER1_EnableGateINT1();            //使能定时器1门控(INT1/P3.3)
    TIMER1_SetIntPriority(1);           //设置中断为高优先级
    TIMER1_EnableInt();                 //使能定时器1中断
    TIMER1_SetReload16(T1_RELOAD);      //设置定时器1的16位重载值
    TIMER1_Run();                       //定时器1开始运行

    //<<AICUBE_USER_TIMER1_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_TIMER1_INITIAL_END>>
}


////////////////////////////////////////
// 定时器1中断服务程序
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void TIMER1_ISR(void) interrupt TMR1_VECTOR
{
    //<<AICUBE_USER_TIMER1_ISR_CODE1_BEGIN>>
    // 在此添加中断函数用户代码  
    //<<AICUBE_USER_TIMER1_ISR_CODE1_END>>
}


//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


