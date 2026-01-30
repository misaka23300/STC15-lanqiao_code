
/*
 * FreeRTOS STC port V1.0.2
 * 
 * STC32G12K128功能简介：
 *    2组 CAN, 3组Lin, USB, 32位 8051, RMB5,
 *    高精准12位ADC, DMA 支持(TFT彩屏, ADC, 4组串口, SPI, I2C )
 *  
 *  各位用户在后续的使用过程中，如果发现有不正确的地方或者
 *  有可改善的地方，请和STC联系，由STC官方进行统一修改并更新版本
 *
 *  若您的代码或文章中需要引用本程序包中的部分移植代码，请在您的
 *  代码或文章中注明参考或使用了STC的FreeRTOS的移植代码
*/

#include "FreeRTOS.h"
#include "task.h"

#include "display.h"
#include "rtc.h"
#include "ntc.h"
#include "adckey.h"
#include "uart2_3.h"
#include "MatrixKey.h"
#include "DebugPrintf.h"

void vSystemInit( void );

void main( void )
{
    /* 系统初始化 */
    vSystemInit();

	/* 创建任务 */
    xTaskCreate((TaskFunction_t )vDisplayTask,
                (const char*    )"DISPLAY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vRtcTask,
                (const char*    )"RTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES + 1),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vAdcKeyTask,
                (const char*    )"ADCKEY",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vNtcTask,
                (const char*    )"NTC",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vUart2_3Task,
                (const char*    )"UART2_3",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )1000,  //注意pvParameters参数传地址或者立即数时只有低24位是有效位，最高8位编译时会自动填0. 可通过变量或者常量传送32字节数据.
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);
    xTaskCreate((TaskFunction_t )vMatrixKeyTask,
                (const char*    )"MatrixKey",
                (uint16_t       )configDEFAULT_STACK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )(configDEFAULT_PRIORITIES),
                (TaskHandle_t*  )NULL);

    /* 启动任务调度器开始任务调度 */
    vTaskStartScheduler();

    /* 正常情况下不会运行到此处 */
    while (1);
}

/* 系统初始化代码 */
void vSystemInit( void )
{
    WTST = 0;     //设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
    EAXFR = 1;    //扩展寄存器(XFR)访问使能
    CKCON = 0;    //提高访问XRAM速度

    P0M1 = 0x00;   P0M0 = 0x00;     //设置为准双向口
    P1M1 = 0x00;   P1M0 = 0x00;     //设置为准双向口
    P2M1 = 0x00;   P2M0 = 0x00;     //设置为准双向口
    P3M1 = 0x00;   P3M0 = 0x00;     //设置为准双向口
    P4M1 = 0x00;   P4M0 = 0x00;     //设置为准双向口
    P5M1 = 0x00;   P5M0 = 0x00;     //设置为准双向口
    P6M1 = 0x00;   P6M0 = 0x00;     //设置为准双向口
    P7M1 = 0x00;   P7M0 = 0x00;     //设置为准双向口
    
//    DebugPrintfInit();
//    printf("STC32G FreeRTOS 测试程序!\r\n");
}
