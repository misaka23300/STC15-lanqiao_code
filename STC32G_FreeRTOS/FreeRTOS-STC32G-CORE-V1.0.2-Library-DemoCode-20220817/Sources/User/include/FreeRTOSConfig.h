/*
 * FreeRTOS V202112.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "stc32g.h"
#include "intrins.h"

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/*-----------------------------------------------------------
 * ﺍﮔﺎﺝﺕﮰﺷﺡﭺﻲﮌﺓ
 *
 * V1.0.2 (2022-4-27)
 *     ﺷﻐﻁﮮﺫﺳﺳﮦﺎﺳﮌﮮpvParametersﺏﺀﮌﺙﺹﺗﻁﭨﺑﻥﺳﮩﭖﺥﺳﮌﮊﻗ
 *     (ﻉ۱ﺻﻗpvParametersﺎﺳﮌﮮﺑ،ﭖﻊﻅﺓﭨﮨﻁﻑﭼ۱ﺙﺑﮌﮮﮌﺎﻅﭨﺽﺷﭖﺱ24ﺳﭨﮌﮄﺽﺷﺷ۶ﺳﭨ۲؛ﻉﻧﺕﻑ8ﺳﭨﺎﻓﺻﻣﮌﺎﭨﻕﻉﺿﭘﺁﮊﻧ0)
 *
 * V1.0.1 (2022-4-26)
 *     ﺷﻐﻁﮮﺳﻐﺓ۷ﻁﮮﺏ۲ﮌﺗﺽﺣxdataﭖﺥﺳﮌﮊﻗ
 *
 * V1.0.0 (2022-4-24)
 *     ﺻﺩﻅﺎﺏﺭﺗ۵ﺎ۱ﺓ۱ﺎﺙﺏﺀﺍﮔ
 *----------------------------------------------------------*/


/***************************************************************************************************************/
/*                                        STC32-251ﭨﻱﺑ۰ﺧﻛﻅﺣﺧﻛﻅﺣﺹ۰ﺵﻧ                                            */
/***************************************************************************************************************/
#define configPORT_VERSION_NUMBER               "V1.0.2"                //STCﺻﺩﻅﺎﺑﻲﺡﻣﺍﮔﺎﺝ

#define configUSE_ROMHUGE                       0                       //1 ROMﮌﺗﺽﺣHUGEﺥ۲ﮌﺛ۲؛0ﮌﺗﺽﺣLARGEﺥ۲ﮌﺛ
#define MAIN_Fosc                               ( 24000000UL )          //ﺵﭖﺱﺏﺗ۳ﻉﺊﺩﭖﺡﮌ

#if ( configUSE_ROMHUGE == 0 )
    #pragma ROM ( LARGE )
#else
    #pragma ROM ( HUGE )
#endif

#pragma WARNING DISABLE = 47                                            //ﺗﻊﺎﻁ47ﭦﺧﺝﺁﺕﮔ: unreferenced local variable
#pragma WARNING DISABLE = 138                                           //ﺗﻊﺎﻁ138ﭦﺧﺝﺁﺕﮔ: expression with possibly no effect
#pragma WARNING DISABLE = 183                                           //ﺗﻊﺎﻁ183ﭦﺧﺝﺁﺕﮔ: dead assignment eliminated

#ifndef configUSE_ROMHUGE
    #error Missing definition:  configUSE_ROMHUGE must be defined in FreeRTOSConfig.h as either 1 or 0.
#endif

//#define UNUSED(expr)      (void)(expr)
#define UNUSED(expr)        if ((expr) == 0)


/***************************************************************************************************************/
/*                                        FreeRTOSﭨﻱﺑ۰ﺧﻛﻅﺣﺧﻛﻅﺣﺹ۰ﺵﻧ                                             */
/***************************************************************************************************************/

#define configUSE_PREEMPTION                    1                       //1ﮌﺗﺽﺣﮄﭺﻁﺙﮌﺛﺥﻌﭦﺯ۲؛0ﮌﺗﺽﺣﺷ­ﺏﮊ
#define configUSE_TIME_SLICING                  1                       //1ﮌﺗﺥﻎﮌﺎﺙﻛﺩ؛ﭖﺊﭘﺫ(ﺥ؛ﺫﺵﮌﺛﮌﺗﺥﻎﭖﺥ)
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	0                       //1ﺩﮪﺽﺣﮊﻊﮌﻗﺓﺛﺓ۷ﭺﺑﺹ۰ﺿﮦﺵﺡﺻﭨﺕﺉﺻ۹ﺿﺯﺷﺷﭖﺥﺫﺳﺳﮦ
                                                                        //ﺻﭨﺍﻙﮌﮄﺽﺎﺙﹼﺙﺩﺯﻙﮄﺍﭖﺙﭼﻙﻅﺕﭼﻧ۲؛ﺫﻝﺗﻳﺯﻱﮌﺗﺽﺣﭖﺥ
                                                                        //MCUﺣﭨﺽﺷﻁﻗﺷ۸ﺽﺎﺙﹼﻅﺕﭼﻧﭖﺥﭨﺍﺑﺯﭦﻡﺽ۵ﺕﺣﺭﻟﻅﺣﺳ۹0۲۰
#define configUSE_TICKLESS_IDLE                 0                       //1ﺩﮪﺽﺣﭖﺱﺗ۵ﭦﺥticklessﺥ۲ﮌﺛ
#define configUSE_QUEUE_SETS                    0                       //ﺳ۹1ﮌﺎﺩﮪﺽﺣﭘﺽﭼﺷ
#define configCPU_CLOCK_HZ                      (MAIN_Fosc)             //CPUﺩﭖﺡﮌ
#define configTICK_RATE_HZ                      ((TickType_t)1000)      //ﮌﺎﻅﺽﺛﻌﺧﺥﺩﭖﺡﮌ۲؛ﻁﻗﭺﺅﺭﻟﻅﺣﺳ۹1000,ﻅﻎﺩﻌﺝﺱﮌﮄ1ms
#define configMAX_PRIORITIES                    (32)                    //ﺟﺭﮌﺗﺽﺣﭖﺥﻉﻧﺑﮩﺽﺧﺵﺫﺙﭘ
#define configDEFAULT_PRIORITIES                (tskIDLE_PRIORITY + 1)  //ﺫﺳﺳﮦﺥ؛ﺫﺵﺽﺧﺵﺫﺙﭘ
#define configMINIMAL_STACK_SIZE                ((unsigned short)256)   //ﺟﻁﺵﺷﺫﺳﺳﮦﮌﺗﺽﺣﭖﺥﭘﺹﻁﭨﺑﮩﺷ۰
#define configDEFAULT_STACK_SIZE                ((unsigned short)128)   //ﺫﺳﺳﮦﺥ؛ﺫﺵﭘﺹﻁﭨﺑﮩﺷ۰
#define configMAX_TASK_NAME_LEN                 (8)                     //ﺫﺳﺳﮦﺣﻳﻉﻅﻉﻅﺓﻳﺑ؟ﺏ۳ﭘﺫ
#define configUSE_IDLE_HOOK						0                       //1ﮌﺗﺽﺣﺟﻁﺵﺷﺗﺏﻉﺽ,0ﺎﭨﮌﺗﺽﺣ /*void vApplicationIdleHook( void );*/
#define configUSE_TICK_HOOK						0                       //1ﮌﺗﺽﺣﮌﺎﺙﻛﺩ؛ﺗﺏﻉﺽ,0ﺎﭨﮌﺗﺽﺣ /*void vApplicationTickHook( void );*/
#define configSUPPORT_DYNAMIC_ALLOCATION        1                       //ﻅ۶ﺏﻅﭘﺁﮊ؛ﺥﻌﺑﮔﺭﻡﮄﻣ
#define configTOTAL_HEAP_SIZE					((size_t)(2*1024))     // ﺵﭖﺱﺏﺯﻱﺽﺷﻉﻎﭖﺥﭘﺹﺑﮩﺷ۰

#define configUSE_16_BIT_TICKS                  0                       //ﺵﭖﺱﺏﺛﻌﺧﺥﺙﺩﮌﮮﺩﺊﺎﻛﭼﺟﮌﮮﺝﻏﭺﻓﺷﺱ۲؛
                                                                        //1ﺎﻥﮌﺝﺳ۹16ﺳﭨﺳﻐﺓﻳﭦﺧﻁﻳﺷﺳ۲؛0ﺎﻥﮌﺝﺳ۹32ﺳﭨﺳﻐﺓﻳﭦﺧﻁﻳﺷﺳ
#define configIDLE_SHOULD_YIELD                 1                       //ﺳ۹1ﮌﺎﺟﻁﺵﺷﺫﺳﺳﮦﺓﺧﺩﻲCPUﮌﺗﺽﺣﺫ۷ﺕﺋﺩﻛﺯﻳﺱ؛ﺽﺧﺵﺫﺙﭘﭖﺥﺽﺣﭨ۶ﺫﺳﺳﮦ
#define configUSE_TASK_NOTIFICATIONS            1                       //ﺳ۹1ﮌﺎﺟ۹ﺩﮪﺫﺳﺳﮦﺱ۷ﻅ۹ﺗ۵ﺥﻎ۲؛ﺥ؛ﺫﺵﺟ۹ﺩﮪ
#define configUSE_MUTEXES                       1                       //ﺳ۹1ﮌﺎﮌﺗﺽﺣﭨ۴ﺏﻗﺷﺧﭦﺧﭼﺟ
#define configQUEUE_REGISTRY_SIZE               0                       //ﺎﭨﺳ۹0ﮌﺎﺎﻥﮌﺝﺩﮪﺽﺣﭘﺽﭼﺷﺙﮄﺡﺙ۲؛ﺝﻑﮊﮒﭖﺥﻅﭖﮌﮄﺟﺭﺻﺿ
                                                                        //ﺙﮄﺡﺙﭖﺥﭘﺽﭼﺷﭦﺱﺷﺧﭦﺧﭼﺟﻉﻧﺑﮩﮌﮮﺥﺟ۰۲
#define configCHECK_FOR_STACK_OVERFLOW          0                       //ﺑﮩﺽﻌ0ﮌﺎﺩﮪﺽﺣﭘﺹﻁﭨﺻﻝﺏﺉﺙﮞﺎﻗﺗ۵ﺥﻎ۲؛ﺫﻝﺗﻳﮌﺗﺽﺣﺑﺯﺗ۵ﺥﻎ
                                                                        //ﺽﺣﭨ۶ﺎﻊﺷﻣﮊﻕﺗ۸ﺻﭨﺕﺉﻁﭨﺻﻝﺏﺉﺗﺏﻉﺽﭦﺁﮌﮮ۲؛ﺫﻝﺗﻳﮌﺗﺽﺣﭖﺥﭨﺍ
                                                                        //ﺑﺯﻅﭖﺟﺭﺻﺿﺳ۹1ﭨﮨﻁﻑ2۲؛ﺻﮨﺳ۹ﺽﺷﭼﺛﻅﻅﻁﭨﺻﻝﺏﺉﺙﮞﺎﻗﺓﺛﺓ۷۰۲
#define configUSE_RECURSIVE_MUTEXES             0                       //ﺳ۹1ﮌﺎﮌﺗﺽﺣﭖﻏﺗﻠﭨ۴ﺏﻗﺷﺧﭦﺧﭼﺟ
#define configUSE_MALLOC_FAILED_HOOK            0                       //1ﮌﺗﺽﺣﺥﻌﺑﮔﺭﻡﮄﻣﮌ۶ﺍﻎﺗﺏﻉﺽﭦﺁﮌﮮ
#define configUSE_APPLICATION_TASK_TAG          0
#define configUSE_COUNTING_SEMAPHORES           0                       //ﺳ۹1ﮌﺎﮌﺗﺽﺣﺙﺩﮌﮮﺷﺧﭦﺧﭼﺟ

#define configGENERATE_RUN_TIME_STATS	        0                       //ﺳ۹1ﮌﺎﺩﮪﺽﺣﺿﺯﺷﺷﮌﺎﺙﻛﺱﺏﺙﺩﺗ۵ﺥﻎ
#define configUSE_TRACE_FACILITY				0                       //ﺳ۹1ﺩﮪﺽﺣﺟﺭﮌﺽﭨﺁﺕﻲﻉﻋﭖﺊﮌﺿ
#define configUSE_STATS_FORMATTING_FUNCTIONS	0                       //ﺽﻣﭦﻡconfigUSE_TRACE_FACILITYﺱ؛ﮌﺎﺳ۹1ﮌﺎﭨﻕﺎﻓﺻﻣﺵﺡﺣﮔ3ﺕﺉﭦﺁﮌﮮ
                                                                        //prvWriteNameToBuffer(),vTaskList(),
                                                                        //vTaskGetRunTimeStats()
/* Co-routine definitions. */
#define configUSE_CO_ROUTINES 			        0                       //ﺳ۹1ﮌﺎﺩﮪﺽﺣﺷ­ﺏﮊ۲؛ﺩﮪﺽﺣﺷ­ﺏﮊﺻﺿﭦﮩﺎﻊﺷﻣﮊﻥﺙﺽﺳﺥﺙﹼcroutine.c
#define configMAX_CO_ROUTINE_PRIORITIES         (2)                     //ﺷ­ﺏﮊﭖﺥﺽﺷﺷ۶ﺽﺧﺵﺫﺙﭘﮌﮮﺥﺟ

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_xTaskGetSchedulerState          0
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           0
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xTimerPendFunctionCall          0



#endif /* FREERTOS_CONFIG_H */
