//<<AICUBE_USER_HEADER_REMARK_BEGIN>>
////////////////////////////////////////
// 在此添加用户文件头说明信息  
// 文件名称: pca.c
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
// PCA初始化函数
// 入口参数: 无
// 函数返回: 无
////////////////////////////////////////
void PCA_Init(void)
{
    PCA_SwitchP3n();                    //选择PCA数据口: ECI(P3.4), CCP0(P3.5), CCP1(P3.6), CCP2(P3.7)
    PCA_CLK_SYSCLKD12();                //选择PCA模组的时钟源: 系统时钟SYSCLK/12
    PCA_IdleContinue();                 //IDLE模式时PCA模组继续计数

    PCA_SetC0As16BitTimerMode();        //设置PCA模块0为16位软件定时器模式
    PCA_SetC0Match(0);                  //设置PCA模块0的16位比较匹配值

    PCA_DisableC1();                    //关闭PCA模块1

    PCA_DisableC2();                    //关闭PCA模块2

    PCA_SetCounter(0);                  //设置PCA模组计数初始值
    PCA_Run();                          //PCA模组开始计数

    //<<AICUBE_USER_PCA_INITIAL_BEGIN>>
    // 在此添加用户初始化代码  
    //<<AICUBE_USER_PCA_INITIAL_END>>
}



//<<AICUBE_USER_FUNCTION_IMPLEMENT_BEGIN>>
// 在此添加用户函数实现代码  
//<<AICUBE_USER_FUNCTION_IMPLEMENT_END>>


