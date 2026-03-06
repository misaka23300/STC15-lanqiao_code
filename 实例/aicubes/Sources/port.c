//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: port.c
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
// P0口初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void PORT0_Init(void)
{
    SetP0nInitLevelHigh(PIN_ALL);       //设置P0初始化电平
    SetP0nQuasiMode(PIN_ALL);           //设置P0为准双向口模式

    //<<AICUBE_USER_PORT0_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_PORT0_INITIAL_END>>
}

////////////////////////////////////////
// P1口初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void PORT1_Init(void)
{
    SetP1nInitLevelHigh(PIN_ALL);       //设置P1初始化电平
    SetP1nQuasiMode(PIN_ALL);           //设置P1为准双向口模式

    //<<AICUBE_USER_PORT1_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_PORT1_INITIAL_END>>
}

////////////////////////////////////////
// P3口初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void PORT3_Init(void)
{
    SetP3nInitLevelHigh(PIN_ALL);       //设置P3初始化电平
    SetP3nQuasiMode(PIN_ALL);           //设置P3为准双向口模式

    //<<AICUBE_USER_PORT3_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_PORT3_INITIAL_END>>
}



//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


