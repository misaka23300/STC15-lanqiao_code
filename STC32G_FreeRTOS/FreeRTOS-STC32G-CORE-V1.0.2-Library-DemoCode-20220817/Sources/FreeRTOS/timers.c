/*
 * FreeRTOS 内核 V10.4.6
 * Copyright (C) 2021 Amazon.com, Inc. 或其关联公司。保留所有权利。
 *
 * SPDX-License-Identifier: MIT
 *
 * 特此免费授予任何获得本软件及相关文档文件（"软件"）副本的人无限制处置该软件的权利，包含但不限于使用、复制、修改、合并、发布、分发、再许可和/或销售软件的副本，并允许向其提供软件的人在符合以下条件的情况下如法使用：
 *
 * 上述版权声明和本许可声明应包含在软件的所有副本或重要部分中。
 *
 * 本软件按“原样”提供，不提供任何形式的明示或暗示担保，包括但不限于对适销性、特定用途适用性及非侵权性的担保。在任何情况下，作者或版权持有人均不对因本软件或其使用或其他交易所引起的任何索赔、损害或其他责任承担责任，无论是在合同诉讼中、侵权或其他方面。
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/* 标准包含文件。 */
#include <stdlib.h>

/* 定义 MPU_WRAPPERS_INCLUDED_FROM_API_FILE 可防止 task.h 将所有 API 函数重定义为使用 MPU 包装器。仅当从应用程序文件包含 task.h 时才应这样做。 */
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#if ( INCLUDE_xTimerPendFunctionCall == 1 ) && ( configUSE_TIMERS == 0 )
    #error configUSE_TIMERS must be set to 1 to make the xTimerPendFunctionCall() function available.
#endif

/* 将 lint 的 e9021、e961 和 e750 抑制为 MISRA 例外，理由是 MPU 端口要求在上面的头文件中定义 MPU_WRAPPERS_INCLUDED_FROM_API_FILE，但在此文件中不需要定义，以便生成正确的特权/非特权链接和放置。 */
#undef MPU_WRAPPERS_INCLUDED_FROM_API_FILE /*lint !e9021 !e961 !e750. */


/* 如果应用程序未配置包含软件定时器功能，则整个源文件将被跳过。此 #if 在文件底部结束。如果希望包含软件定时器功能，请在 FreeRTOSConfig.h 中将 configUSE_TIMERS 设置为 1。 */
#if ( configUSE_TIMERS == 1 )

/* 杂项定义。 */
    #define tmrNO_DELAY                    ( ( TickType_t ) 0U )
    #define tmrMAX_TIME_BEFORE_OVERFLOW    ( ( TickType_t ) -1 )

/* 分配给定时器服务任务的名称。可通过在 FreeRTOSConfig.h 中定义 trmTIMER_SERVICE_TASK_NAME 来覆盖此名称。 */
    #ifndef configTIMER_SERVICE_TASK_NAME
        #define configTIMER_SERVICE_TASK_NAME    "Tmr Svc"
    #endif

/* 用于定时器结构 ucStatus 成员的位定义。 */
    #define tmrSTATUS_IS_ACTIVE                  ( ( uint8_t ) 0x01 )
    #define tmrSTATUS_IS_STATICALLY_ALLOCATED    ( ( uint8_t ) 0x02 )
    #define tmrSTATUS_IS_AUTORELOAD              ( ( uint8_t ) 0x04 )

/* 定时器本身的定义。 */
    typedef struct tmrTimerControl                  /* 为了避免破坏内核感知调试器，保留了旧的命名约定。 */
    {
        const char * pcTimerName;                   /*<< 文本名称。内核不使用此名称，仅用于便于调试。 */ /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
        ListItem_t xTimerListItem;                  /*<< 标准链表项，供所有内核特性用于事件管理。 */
        TickType_t xTimerPeriodInTicks;             /*<< 定时器到期的快慢及频率。 */
        void * pvTimerID;                           /*<< 用于标识定时器的 ID。当多个定时器共享相同回调时，可用此 ID 区分定时器。 */
        TimerCallbackFunction_t pxCallbackFunction; /*<< 定时器到期时将被调用的函数。 */
        #if ( configUSE_TRACE_FACILITY == 1 )
            UBaseType_t uxTimerNumber;              /*<< 由跟踪工具（例如 FreeRTOS+Trace）分配的 ID。 */
        #endif
        uint8_t ucStatus;                           /*<< 包含位标志，指示定时器是否为静态分配，以及是否处于活动状态。 */
    } xTIMER;

/* 保留旧的 xTIMER 名称（见上）并在下面将其 typedef 为新的 Timer_t 名称，以便兼容较旧的内核感知调试器。 */
    typedef xTIMER Timer_t;

/* 定时器队列上可发送和接收的消息定义。
 * 可排队的消息有两种类型：操作软件定时器的消息，和请求执行与定时器无关回调的消息。
 * 这两种消息类型分别在两个独立结构体 xTimerParametersType 和 xCallbackParametersType 中定义。 */
    typedef struct tmrTimerParameters
    {
        TickType_t xMessageValue; /*<< 在部分命令中使用的可选值，例如在更改定时器周期时使用。 */
        Timer_t * pxTimer;        /*<< 命令将应用到的定时器。 */
    } TimerParameter_t;


    typedef struct tmrCallbackParameters
    {
        PendedFunction_t pxCallbackFunction; /* << 要执行的回调函数。 */
        void * pvParameter1;                 /* << 将作为回调函数第一个参数使用的值。 */
        uint32_t ulParameter2;               /* << 将作为回调函数第二个参数使用的值。 */
    } CallbackParameters_t;

/* 此结构包含上述两种消息类型，以及用于确定哪种消息类型有效的标识符。 */
    typedef struct tmrTimerQueueMessage
    {
        BaseType_t xMessageID; /*<< The command being sent to the timer service task. */
        union
        {
            TimerParameter_t xTimerParameters;

            /* Don't include xCallbackParameters if it is not going to be used as
             * it makes the structure (and therefore the timer queue) larger. */
            #if ( INCLUDE_xTimerPendFunctionCall == 1 )
                CallbackParameters_t xCallbackParameters;
            #endif /* INCLUDE_xTimerPendFunctionCall */
        } u;
    } DaemonTaskMessage_t;

/*lint -save -e956 A manual analysis and inspection has been used to determine
 * which static variables must be declared volatile. */

/* 用于存放活动定时器的列表。定时器按到期时间排序，最先到期的定时器在列表前端。只有定时器服务任务可以访问这些列表。
 * xActiveTimerList1 和 xActiveTimerList2 本可放在函数作用域，但那样会破坏某些内核感知调试器，以及依赖移除 static 限定符的调试器。 */
    PRIVILEGED_DATA static List_t xActiveTimerList1;
    PRIVILEGED_DATA static List_t xActiveTimerList2;
    PRIVILEGED_DATA static List_t * pxCurrentTimerList;
    PRIVILEGED_DATA static List_t * pxOverflowTimerList;

/* 用于向定时器服务任务发送命令的队列。 */
    PRIVILEGED_DATA static QueueHandle_t xTimerQueue = NULL;
    PRIVILEGED_DATA static TaskHandle_t xTimerTaskHandle = NULL;

/*lint -restore */

/*-----------------------------------------------------------*/

/*
 * 初始化定时器服务任务使用的基础设施（如果尚未初始化）。
 */
    static void prvCheckForValidListAndQueue( void ) PRIVILEGED_FUNCTION;

/*
 * 定时器服务任务（守护任务）。定时器功能由此任务控制，其它任务通过 xTimerQueue 与定时器服务任务通信。
 */
    static portTASK_FUNCTION_PROTO( prvTimerTask, pvParameters ) PRIVILEGED_FUNCTION;

/*
 * 由定时器服务任务调用，用于解释并处理在定时器队列上接收到的命令。
 */
    static void prvProcessReceivedCommands( void ) PRIVILEGED_FUNCTION;

/*
 * Insert the timer into either xActiveTimerList1, or xActiveTimerList2,
 * depending on if the expire time causes a timer counter overflow.
 */
    static BaseType_t prvInsertTimerInActiveList( Timer_t * const pxTimer,
                                                  const TickType_t xNextExpiryTime,
                                                  const TickType_t xTimeNow,
                                                  const TickType_t xCommandTime ) PRIVILEGED_FUNCTION;

/*
 * Reload the specified auto-reload timer.  If the reloading is backlogged,
 * clear the backlog, calling the callback for each additional reload.  When
 * this function returns, the next expiry time is after xTimeNow.
 */
    static void prvReloadTimer( Timer_t * const pxTimer,
                                TickType_t xExpiredTime,
                                const TickType_t xTimeNow ) PRIVILEGED_FUNCTION;

/*
 * An active timer has reached its expire time.  Reload the timer if it is an
 * auto-reload timer, then call its callback.
 */
    static void prvProcessExpiredTimer( const TickType_t xNextExpireTime,
                                        const TickType_t xTimeNow ) PRIVILEGED_FUNCTION;

/*
 * The tick count has overflowed.  Switch the timer lists after ensuring the
 * current timer list does not still reference some timers.
 */
    static void prvSwitchTimerLists( void ) PRIVILEGED_FUNCTION;

/*
 * Obtain the current tick count, setting *pxTimerListsWereSwitched to pdTRUE
 * if a tick count overflow occurred since prvSampleTimeNow() was last called.
 */
    static TickType_t prvSampleTimeNow( BaseType_t * const pxTimerListsWereSwitched ) PRIVILEGED_FUNCTION;

/*
 * If the timer list contains any active timers then return the expire time of
 * the timer that will expire first and set *pxListWasEmpty to false.  If the
 * timer list does not contain any timers then return 0 and set *pxListWasEmpty
 * to pdTRUE.
 */
    static TickType_t prvGetNextExpireTime( BaseType_t * const pxListWasEmpty ) PRIVILEGED_FUNCTION;

/*
 * If a timer has expired, process it.  Otherwise, block the timer service task
 * until either a timer does expire or a command is received.
 */
    static void prvProcessTimerOrBlockTask( const TickType_t xNextExpireTime,
                                            BaseType_t xListWasEmpty ) PRIVILEGED_FUNCTION;

/*
 * Called after a Timer_t structure has been allocated either statically or
 * dynamically to fill in the structure's members.
 */
    static void prvInitialiseNewTimer( const char * const pcTimerName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t xTimerPeriodInTicks,
                                       const UBaseType_t uxAutoReload,
                                       void * const pvTimerID,
                                       TimerCallbackFunction_t pxCallbackFunction,
                                       Timer_t * pxNewTimer ) PRIVILEGED_FUNCTION;
/*-----------------------------------------------------------*/

    BaseType_t xTimerCreateTimerTask( void )
    {
        BaseType_t xReturn = pdFAIL;

        /* This function is called when the scheduler is started if
         * configUSE_TIMERS is set to 1.  Check that the infrastructure used by the
         * timer service task has been created/initialised.  If timers have already
         * been created then the initialisation will already have been performed. */
        prvCheckForValidListAndQueue();

        if( xTimerQueue != NULL )
        {
            #if ( configSUPPORT_STATIC_ALLOCATION == 1 )
                {
                    StaticTask_t * pxTimerTaskTCBBuffer = NULL;
                    StackType_t * pxTimerTaskStackBuffer = NULL;
                    uint32_t ulTimerTaskStackSize;

                    vApplicationGetTimerTaskMemory( &pxTimerTaskTCBBuffer, &pxTimerTaskStackBuffer, &ulTimerTaskStackSize );
                    xTimerTaskHandle = xTaskCreateStatic( prvTimerTask,
                                                          configTIMER_SERVICE_TASK_NAME,
                                                          ulTimerTaskStackSize,
                                                          NULL,
                                                          ( ( UBaseType_t ) configTIMER_TASK_PRIORITY ) | portPRIVILEGE_BIT,
                                                          pxTimerTaskStackBuffer,
                                                          pxTimerTaskTCBBuffer );

                    if( xTimerTaskHandle != NULL )
                    {
                        xReturn = pdPASS;
                    }
                }
            #else /* if ( configSUPPORT_STATIC_ALLOCATION == 1 ) */
                {
                    xReturn = xTaskCreate( prvTimerTask,
                                           configTIMER_SERVICE_TASK_NAME,
                                           configTIMER_TASK_STACK_DEPTH,
                                           NULL,
                                           ( ( UBaseType_t ) configTIMER_TASK_PRIORITY ) | portPRIVILEGE_BIT,
                                           &xTimerTaskHandle );
                }
            #endif /* configSUPPORT_STATIC_ALLOCATION */
        }
        else
        {
            mtCOVERAGE_TEST_MARKER();
        }

        configASSERT( xReturn );
        return xReturn;
    }
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_DYNAMIC_ALLOCATION == 1 )

        TimerHandle_t xTimerCreate( const char * const pcTimerName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                    const TickType_t xTimerPeriodInTicks,
                                    const UBaseType_t uxAutoReload,
                                    void * const pvTimerID,
                                    TimerCallbackFunction_t pxCallbackFunction )
        {
            Timer_t * pxNewTimer;

            pxNewTimer = ( Timer_t * ) pvPortMalloc( sizeof( Timer_t ) ); /*lint !e9087 !e9079 All values returned by pvPortMalloc() have at least the alignment required by the MCU's stack, and the first member of Timer_t is always a pointer to the timer's mame. */

            if( pxNewTimer != NULL )
            {
                /* Status is thus far zero as the timer is not created statically
                 * and has not been started.  The auto-reload bit may get set in
                 * prvInitialiseNewTimer. */
                pxNewTimer->ucStatus = 0x00;
                prvInitialiseNewTimer( pcTimerName, xTimerPeriodInTicks, uxAutoReload, pvTimerID, pxCallbackFunction, pxNewTimer );
            }

            return pxNewTimer;
        }

    #endif /* configSUPPORT_DYNAMIC_ALLOCATION */
/*-----------------------------------------------------------*/

    #if ( configSUPPORT_STATIC_ALLOCATION == 1 )

        TimerHandle_t xTimerCreateStatic( const char * const pcTimerName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                          const TickType_t xTimerPeriodInTicks,
                                          const UBaseType_t uxAutoReload,
                                          void * const pvTimerID,
                                          TimerCallbackFunction_t pxCallbackFunction,
                                          StaticTimer_t * pxTimerBuffer )
        {
            Timer_t * pxNewTimer;

            #if ( configASSERT_DEFINED == 1 )
                {
                    /* Sanity check that the size of the structure used to declare a
                     * variable of type StaticTimer_t equals the size of the real timer
                     * structure. */
                    volatile size_t xSize = sizeof( StaticTimer_t );
                    configASSERT( xSize == sizeof( Timer_t ) );
                    ( void ) xSize; /* Keeps lint quiet when configASSERT() is not defined. */
                }
            #endif /* configASSERT_DEFINED */

            /* A pointer to a StaticTimer_t structure MUST be provided, use it. */
            configASSERT( pxTimerBuffer );
            pxNewTimer = ( Timer_t * ) pxTimerBuffer; /*lint !e740 !e9087 StaticTimer_t is a pointer to a Timer_t, so guaranteed to be aligned and sized correctly (checked by an assert()), so this is safe. */

            if( pxNewTimer != NULL )
            {
                /* Timers can be created statically or dynamically so note this
                 * timer was created statically in case it is later deleted.  The
                 * auto-reload bit may get set in prvInitialiseNewTimer(). */
                pxNewTimer->ucStatus = tmrSTATUS_IS_STATICALLY_ALLOCATED;

                prvInitialiseNewTimer( pcTimerName, xTimerPeriodInTicks, uxAutoReload, pvTimerID, pxCallbackFunction, pxNewTimer );
            }

            return pxNewTimer;
        }

    #endif /* configSUPPORT_STATIC_ALLOCATION */
/*-----------------------------------------------------------*/

    static void prvInitialiseNewTimer( const char * const pcTimerName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
                                       const TickType_t xTimerPeriodInTicks,
                                       const UBaseType_t uxAutoReload,
                                       void * const pvTimerID,
                                       TimerCallbackFunction_t pxCallbackFunction,
                                       Timer_t * pxNewTimer )
    {
        /* 0 is not a valid value for xTimerPeriodInTicks. */
        configASSERT( ( xTimerPeriodInTicks > 0 ) );

        /* Ensure the infrastructure used by the timer service task has been
         * created/initialised. */
        prvCheckForValidListAndQueue();

        /* Initialise the timer structure members using the function
         * parameters. */
        pxNewTimer->pcTimerName = pcTimerName;
        pxNewTimer->xTimerPeriodInTicks = xTimerPeriodInTicks;
        pxNewTimer->pvTimerID = pvTimerID;
        pxNewTimer->pxCallbackFunction = pxCallbackFunction;
        vListInitialiseItem( &( pxNewTimer->xTimerListItem ) );

        if( uxAutoReload != pdFALSE )
        {
            pxNewTimer->ucStatus |= tmrSTATUS_IS_AUTORELOAD;
        }

        traceTIMER_CREATE( pxNewTimer );
    }
/*-----------------------------------------------------------*/

    BaseType_t xTimerGenericCommand( TimerHandle_t xTimer,
                                     const BaseType_t xCommandID,
                                     const TickType_t xOptionalValue,
                                     BaseType_t * const pxHigherPriorityTaskWoken,
                                     const TickType_t xTicksToWait )
    {
        BaseType_t xReturn = pdFAIL;
        DaemonTaskMessage_t xMessage;

        configASSERT( xTimer );

        /* Send a message to the timer service task to perform a particular action
         * on a particular timer definition. */
        if( xTimerQueue != NULL )
        {
            /* Send a command to the timer service task to start the xTimer timer. */
            xMessage.xMessageID = xCommandID;
            xMessage.u.xTimerParameters.xMessageValue = xOptionalValue;
            xMessage.u.xTimerParameters.pxTimer = xTimer;

            if( xCommandID < tmrFIRST_FROM_ISR_COMMAND )
            {
                if( xTaskGetSchedulerState() == taskSCHEDULER_RUNNING )
                {
                    xReturn = xQueueSendToBack( xTimerQueue, &xMessage, xTicksToWait );
                }
                else
                {
                    xReturn = xQueueSendToBack( xTimerQueue, &xMessage, tmrNO_DELAY );
                }
            }
            else
            {
                xReturn = xQueueSendToBackFromISR( xTimerQueue, &xMessage, pxHigherPriorityTaskWoken );
            }

            traceTIMER_COMMAND_SEND( xTimer, xCommandID, xOptionalValue, xReturn );
        }
        else
        {
            mtCOVERAGE_TEST_MARKER();
        }

        return xReturn;
    }
/*-----------------------------------------------------------*/

    TaskHandle_t xTimerGetTimerDaemonTaskHandle( void )
    {
        /* If xTimerGetTimerDaemonTaskHandle() is called before the scheduler has been
         * started, then xTimerTaskHandle will be NULL. */
        configASSERT( ( xTimerTaskHandle != NULL ) );
        return xTimerTaskHandle;
    }
/*-----------------------------------------------------------*/

    TickType_t xTimerGetPeriod( TimerHandle_t xTimer )
    {
        Timer_t * pxTimer = xTimer;

        configASSERT( xTimer );
        return pxTimer->xTimerPeriodInTicks;
    }
/*-----------------------------------------------------------*/

    void vTimerSetReloadMode( TimerHandle_t xTimer,
                              const UBaseType_t uxAutoReload )
    {
        Timer_t * pxTimer = xTimer;

        configASSERT( xTimer );
        taskENTER_CRITICAL();
        {
            if( uxAutoReload != pdFALSE )
            {
                pxTimer->ucStatus |= tmrSTATUS_IS_AUTORELOAD;
            }
            else
            {
                pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_AUTORELOAD );
            }
        }
        taskEXIT_CRITICAL();
    }
/*-----------------------------------------------------------*/

    UBaseType_t uxTimerGetReloadMode( TimerHandle_t xTimer )
    {
        Timer_t * pxTimer = xTimer;
        UBaseType_t uxReturn;

        configASSERT( xTimer );
        taskENTER_CRITICAL();
        {
            if( ( pxTimer->ucStatus & tmrSTATUS_IS_AUTORELOAD ) == 0 )
            {
                /* Not an auto-reload timer. */
                uxReturn = ( UBaseType_t ) pdFALSE;
            }
            else
            {
                /* Is an auto-reload timer. */
                uxReturn = ( UBaseType_t ) pdTRUE;
            }
        }
        taskEXIT_CRITICAL();

        return uxReturn;
    }
/*-----------------------------------------------------------*/

    TickType_t xTimerGetExpiryTime( TimerHandle_t xTimer )
    {
        Timer_t * pxTimer = xTimer;
        TickType_t xReturn;

        configASSERT( xTimer );
        xReturn = listGET_LIST_ITEM_VALUE( &( pxTimer->xTimerListItem ) );
        return xReturn;
    }
/*-----------------------------------------------------------*/

    const char * pcTimerGetName( TimerHandle_t xTimer ) /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
    {
        Timer_t * pxTimer = xTimer;

        configASSERT( xTimer );
        return pxTimer->pcTimerName;
    }
/*-----------------------------------------------------------*/

    static void prvReloadTimer( Timer_t * const pxTimer,
                                TickType_t xExpiredTime,
                                const TickType_t xTimeNow )
    {
        /* Insert the timer into the appropriate list for the next expiry time.
         * If the next expiry time has already passed, advance the expiry time,
         * call the callback function, and try again. */
        while( prvInsertTimerInActiveList( pxTimer, ( xExpiredTime + pxTimer->xTimerPeriodInTicks ), xTimeNow, xExpiredTime ) != pdFALSE )
        {
            /* Advance the expiry time. */
            xExpiredTime += pxTimer->xTimerPeriodInTicks;

            /* Call the timer callback. */
            traceTIMER_EXPIRED( pxTimer );
            pxTimer->pxCallbackFunction( ( TimerHandle_t ) pxTimer );
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessExpiredTimer( const TickType_t xNextExpireTime,
                                        const TickType_t xTimeNow )
    {
        Timer_t * const pxTimer = ( Timer_t * ) listGET_OWNER_OF_HEAD_ENTRY( pxCurrentTimerList ); /*lint !e9087 !e9079 void * is used as this macro is used with tasks and co-routines too.  Alignment is known to be fine as the type of the pointer stored and retrieved is the same. */

        /* Remove the timer from the list of active timers.  A check has already
         * been performed to ensure the list is not empty. */

        ( void ) uxListRemove( &( pxTimer->xTimerListItem ) );

        /* If the timer is an auto-reload timer then calculate the next
         * expiry time and re-insert the timer in the list of active timers. */
        if( ( pxTimer->ucStatus & tmrSTATUS_IS_AUTORELOAD ) != 0 )
        {
            prvReloadTimer( pxTimer, xNextExpireTime, xTimeNow );
        }
        else
        {
            pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE );
        }

        /* Call the timer callback. */
        traceTIMER_EXPIRED( pxTimer );
        pxTimer->pxCallbackFunction( ( TimerHandle_t ) pxTimer );
    }
/*-----------------------------------------------------------*/

    static portTASK_FUNCTION( prvTimerTask, pvParameters )
    {
        TickType_t xNextExpireTime;
        BaseType_t xListWasEmpty;

        /* Just to avoid compiler warnings. */
        ( void ) pvParameters;

        #if ( configUSE_DAEMON_TASK_STARTUP_HOOK == 1 )
            {
                extern void vApplicationDaemonTaskStartupHook( void );

                /* Allow the application writer to execute some code in the context of
                 * this task at the point the task starts executing.  This is useful if the
                 * application includes initialisation code that would benefit from
                 * executing after the scheduler has been started. */
                vApplicationDaemonTaskStartupHook();
            }
        #endif /* configUSE_DAEMON_TASK_STARTUP_HOOK */

        for( ; ; )
        {
            /* Query the timers list to see if it contains any timers, and if so,
             * obtain the time at which the next timer will expire. */
            xNextExpireTime = prvGetNextExpireTime( &xListWasEmpty );

            /* If a timer has expired, process it.  Otherwise, block this task
             * until either a timer does expire, or a command is received. */
            prvProcessTimerOrBlockTask( xNextExpireTime, xListWasEmpty );

            /* Empty the command queue. */
            prvProcessReceivedCommands();
        }
    }
/*-----------------------------------------------------------*/

    static void prvProcessTimerOrBlockTask( const TickType_t xNextExpireTime,
                                            BaseType_t xListWasEmpty )
    {
        TickType_t xTimeNow;
        BaseType_t xTimerListsWereSwitched;

        vTaskSuspendAll();
        {
            /* Obtain the time now to make an assessment as to whether the timer
             * has expired or not.  If obtaining the time causes the lists to switch
             * then don't process this timer as any timers that remained in the list
             * when the lists were switched will have been processed within the
             * prvSampleTimeNow() function. */
            xTimeNow = prvSampleTimeNow( &xTimerListsWereSwitched );

            if( xTimerListsWereSwitched == pdFALSE )
            {
                /* The tick count has not overflowed, has the timer expired? */
                if( ( xListWasEmpty == pdFALSE ) && ( xNextExpireTime <= xTimeNow ) )
                {
                    ( void ) xTaskResumeAll();
                    prvProcessExpiredTimer( xNextExpireTime, xTimeNow );
                }
                else
                {
                    /* The tick count has not overflowed, and the next expire
                     * time has not been reached yet.  This task should therefore
                     * block to wait for the next expire time or a command to be
                     * received - whichever comes first.  The following line cannot
                     * be reached unless xNextExpireTime > xTimeNow, except in the
                     * case when the current timer list is empty. */
                    if( xListWasEmpty != pdFALSE )
                    {
                        /* The current timer list is empty - is the overflow list
                         * also empty? */
                        xListWasEmpty = listLIST_IS_EMPTY( pxOverflowTimerList );
                    }

                    vQueueWaitForMessageRestricted( xTimerQueue, ( xNextExpireTime - xTimeNow ), xListWasEmpty );

                    if( xTaskResumeAll() == pdFALSE )
                    {
                        /* Yield to wait for either a command to arrive, or the
                         * block time to expire.  If a command arrived between the
                         * critical section being exited and this yield then the yield
                         * will not cause the task to block. */
                        portYIELD_WITHIN_API();
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER();
                    }
                }
            }
            else
            {
                ( void ) xTaskResumeAll();
            }
        }
    }
/*-----------------------------------------------------------*/

    static TickType_t prvGetNextExpireTime( BaseType_t * const pxListWasEmpty )
    {
        TickType_t xNextExpireTime;

        /* Timers are listed in expiry time order, with the head of the list
         * referencing the task that will expire first.  Obtain the time at which
         * the timer with the nearest expiry time will expire.  If there are no
         * active timers then just set the next expire time to 0.  That will cause
         * this task to unblock when the tick count overflows, at which point the
         * timer lists will be switched and the next expiry time can be
         * re-assessed.  */
        *pxListWasEmpty = listLIST_IS_EMPTY( pxCurrentTimerList );

        if( *pxListWasEmpty == pdFALSE )
        {
            xNextExpireTime = listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxCurrentTimerList );
        }
        else
        {
            /* Ensure the task unblocks when the tick count rolls over. */
            xNextExpireTime = ( TickType_t ) 0U;
        }

        return xNextExpireTime;
    }
/*-----------------------------------------------------------*/

    static TickType_t prvSampleTimeNow( BaseType_t * const pxTimerListsWereSwitched )
    {
        TickType_t xTimeNow;
        PRIVILEGED_DATA static TickType_t xLastTime = ( TickType_t ) 0U; /*lint !e956 Variable is only accessible to one task. */

        xTimeNow = xTaskGetTickCount();

        if( xTimeNow < xLastTime )
        {
            prvSwitchTimerLists();
            *pxTimerListsWereSwitched = pdTRUE;
        }
        else
        {
            *pxTimerListsWereSwitched = pdFALSE;
        }

        xLastTime = xTimeNow;

        return xTimeNow;
    }
/*-----------------------------------------------------------*/

    static BaseType_t prvInsertTimerInActiveList( Timer_t * const pxTimer,
                                                  const TickType_t xNextExpiryTime,
                                                  const TickType_t xTimeNow,
                                                  const TickType_t xCommandTime )
    {
        BaseType_t xProcessTimerNow = pdFALSE;

        listSET_LIST_ITEM_VALUE( &( pxTimer->xTimerListItem ), xNextExpiryTime );
        listSET_LIST_ITEM_OWNER( &( pxTimer->xTimerListItem ), pxTimer );

        if( xNextExpiryTime <= xTimeNow )
        {
            /* Has the expiry time elapsed between the command to start/reset a
             * timer was issued, and the time the command was processed? */
            if( ( ( TickType_t ) ( xTimeNow - xCommandTime ) ) >= pxTimer->xTimerPeriodInTicks ) /*lint !e961 MISRA exception as the casts are only redundant for some ports. */
            {
                /* The time between a command being issued and the command being
                 * processed actually exceeds the timers period.  */
                xProcessTimerNow = pdTRUE;
            }
            else
            {
                vListInsert( pxOverflowTimerList, &( pxTimer->xTimerListItem ) );
            }
        }
        else
        {
            if( ( xTimeNow < xCommandTime ) && ( xNextExpiryTime >= xCommandTime ) )
            {
                /* If, since the command was issued, the tick count has overflowed
                 * but the expiry time has not, then the timer must have already passed
                 * its expiry time and should be processed immediately. */
                xProcessTimerNow = pdTRUE;
            }
            else
            {
                vListInsert( pxCurrentTimerList, &( pxTimer->xTimerListItem ) );
            }
        }

        return xProcessTimerNow;
    }
/*-----------------------------------------------------------*/

    static void prvProcessReceivedCommands( void )
    {
        DaemonTaskMessage_t xMessage;
        Timer_t * pxTimer;
        BaseType_t xTimerListsWereSwitched;
        TickType_t xTimeNow;

        while( xQueueReceive( xTimerQueue, &xMessage, tmrNO_DELAY ) != pdFAIL ) /*lint !e603 xMessage does not have to be initialised as it is passed out, not in, and it is not used unless xQueueReceive() returns pdTRUE. */
        {
            #if ( INCLUDE_xTimerPendFunctionCall == 1 )
                {
                    /* Negative commands are pended function calls rather than timer
                     * commands. */
                    if( xMessage.xMessageID < ( BaseType_t ) 0 )
                    {
                        const CallbackParameters_t * const pxCallback = &( xMessage.u.xCallbackParameters );

                        /* The timer uses the xCallbackParameters member to request a
                         * callback be executed.  Check the callback is not NULL. */
                        configASSERT( pxCallback );

                        /* Call the function. */
                        pxCallback->pxCallbackFunction( pxCallback->pvParameter1, pxCallback->ulParameter2 );
                    }
                    else
                    {
                        mtCOVERAGE_TEST_MARKER();
                    }
                }
            #endif /* INCLUDE_xTimerPendFunctionCall */

            /* Commands that are positive are timer commands rather than pended
             * function calls. */
            if( xMessage.xMessageID >= ( BaseType_t ) 0 )
            {
                /* The messages uses the xTimerParameters member to work on a
                 * software timer. */
                pxTimer = xMessage.u.xTimerParameters.pxTimer;

                if( listIS_CONTAINED_WITHIN( NULL, &( pxTimer->xTimerListItem ) ) == pdFALSE ) /*lint !e961. The cast is only redundant when NULL is passed into the macro. */
                {
                    /* The timer is in a list, remove it. */
                    ( void ) uxListRemove( &( pxTimer->xTimerListItem ) );
                }
                else
                {
                    mtCOVERAGE_TEST_MARKER();
                }

                traceTIMER_COMMAND_RECEIVED( pxTimer, xMessage.xMessageID, xMessage.u.xTimerParameters.xMessageValue );

                /* In this case the xTimerListsWereSwitched parameter is not used, but
                 *  it must be present in the function call.  prvSampleTimeNow() must be
                 *  called after the message is received from xTimerQueue so there is no
                 *  possibility of a higher priority task adding a message to the message
                 *  queue with a time that is ahead of the timer daemon task (because it
                 *  pre-empted the timer daemon task after the xTimeNow value was set). */
                xTimeNow = prvSampleTimeNow( &xTimerListsWereSwitched );

                switch( xMessage.xMessageID )
                {
                    case tmrCOMMAND_START:
                    case tmrCOMMAND_START_FROM_ISR:
                    case tmrCOMMAND_RESET:
                    case tmrCOMMAND_RESET_FROM_ISR:
                        /* Start or restart a timer. */
                        pxTimer->ucStatus |= tmrSTATUS_IS_ACTIVE;

                        if( prvInsertTimerInActiveList( pxTimer, xMessage.u.xTimerParameters.xMessageValue + pxTimer->xTimerPeriodInTicks, xTimeNow, xMessage.u.xTimerParameters.xMessageValue ) != pdFALSE )
                        {
                            /* The timer expired before it was added to the active
                             * timer list.  Process it now. */
                            if( ( pxTimer->ucStatus & tmrSTATUS_IS_AUTORELOAD ) != 0 )
                            {
                                prvReloadTimer( pxTimer, xMessage.u.xTimerParameters.xMessageValue + pxTimer->xTimerPeriodInTicks, xTimeNow );
                            }
                            else
                            {
                                pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE );
                            }

                            /* Call the timer callback. */
                            traceTIMER_EXPIRED( pxTimer );
                            pxTimer->pxCallbackFunction( ( TimerHandle_t ) pxTimer );
                        }
                        else
                        {
                            mtCOVERAGE_TEST_MARKER();
                        }

                        break;

                    case tmrCOMMAND_STOP:
                    case tmrCOMMAND_STOP_FROM_ISR:
                        /* The timer has already been removed from the active list. */
                        pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE );
                        break;

                    case tmrCOMMAND_CHANGE_PERIOD:
                    case tmrCOMMAND_CHANGE_PERIOD_FROM_ISR:
                        pxTimer->ucStatus |= tmrSTATUS_IS_ACTIVE;
                        pxTimer->xTimerPeriodInTicks = xMessage.u.xTimerParameters.xMessageValue;
                        configASSERT( ( pxTimer->xTimerPeriodInTicks > 0 ) );

                        /* The new period does not really have a reference, and can
                         * be longer or shorter than the old one.  The command time is
                         * therefore set to the current time, and as the period cannot
                         * be zero the next expiry time can only be in the future,
                         * meaning (unlike for the xTimerStart() case above) there is
                         * no fail case that needs to be handled here. */
                        ( void ) prvInsertTimerInActiveList( pxTimer, ( xTimeNow + pxTimer->xTimerPeriodInTicks ), xTimeNow, xTimeNow );
                        break;

                    case tmrCOMMAND_DELETE:
                        #if ( configSUPPORT_DYNAMIC_ALLOCATION == 1 )
                            {
                                /* The timer has already been removed from the active list,
                                 * just free up the memory if the memory was dynamically
                                 * allocated. */
                                if( ( pxTimer->ucStatus & tmrSTATUS_IS_STATICALLY_ALLOCATED ) == ( uint8_t ) 0 )
                                {
                                    vPortFree( pxTimer );
                                }
                                else
                                {
                                    pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE );
                                }
                            }
                        #else /* if ( configSUPPORT_DYNAMIC_ALLOCATION == 1 ) */
                            {
                                /* If dynamic allocation is not enabled, the memory
                                 * could not have been dynamically allocated. So there is
                                 * no need to free the memory - just mark the timer as
                                 * "not active". */
                                pxTimer->ucStatus &= ( ( uint8_t ) ~tmrSTATUS_IS_ACTIVE );
                            }
                        #endif /* configSUPPORT_DYNAMIC_ALLOCATION */
                        break;

                    default:
                        /* Don't expect to get here. */
                        break;
                }
            }
        }
    }
/*-----------------------------------------------------------*/

    static void prvSwitchTimerLists( void )
    {
        TickType_t xNextExpireTime;
        List_t * pxTemp;

        /* The tick count has overflowed.  The timer lists must be switched.
         * If there are any timers still referenced from the current timer list
         * then they must have expired and should be processed before the lists
         * are switched. */
        while( listLIST_IS_EMPTY( pxCurrentTimerList ) == pdFALSE )
        {
            xNextExpireTime = listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxCurrentTimerList );

            /* Process the expired timer.  For auto-reload timers, be careful to
             * process only expirations that occur on the current list.  Further
             * expirations must wait until after the lists are switched. */
            prvProcessExpiredTimer( xNextExpireTime, tmrMAX_TIME_BEFORE_OVERFLOW );
        }

        pxTemp = pxCurrentTimerList;
        pxCurrentTimerList = pxOverflowTimerList;
        pxOverflowTimerList = pxTemp;
    }
/*-----------------------------------------------------------*/

    static void prvCheckForValidListAndQueue( void )
    {
        /* Check that the list from which active timers are referenced, and the
         * queue used to communicate with the timer service, have been
         * initialised. */
        taskENTER_CRITICAL();
        {
            if( xTimerQueue == NULL )
            {
                vListInitialise( &xActiveTimerList1 );
                vListInitialise( &xActiveTimerList2 );
                pxCurrentTimerList = &xActiveTimerList1;
                pxOverflowTimerList = &xActiveTimerList2;

                #if ( configSUPPORT_STATIC_ALLOCATION == 1 )
                    {
                        /* The timer queue is allocated statically in case
                         * configSUPPORT_DYNAMIC_ALLOCATION is 0. */
                        PRIVILEGED_DATA static StaticQueue_t xStaticTimerQueue;                                                                          /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */
                        PRIVILEGED_DATA static uint8_t ucStaticTimerQueueStorage[ ( size_t ) configTIMER_QUEUE_LENGTH * sizeof( DaemonTaskMessage_t ) ]; /*lint !e956 Ok to declare in this manner to prevent additional conditional compilation guards in other locations. */

                        xTimerQueue = xQueueCreateStatic( ( UBaseType_t ) configTIMER_QUEUE_LENGTH, ( UBaseType_t ) sizeof( DaemonTaskMessage_t ), &( ucStaticTimerQueueStorage[ 0 ] ), &xStaticTimerQueue );
                    }
                #else
                    {
                        xTimerQueue = xQueueCreate( ( UBaseType_t ) configTIMER_QUEUE_LENGTH, sizeof( DaemonTaskMessage_t ) );
                    }
                #endif /* if ( configSUPPORT_STATIC_ALLOCATION == 1 ) */

                #if ( configQUEUE_REGISTRY_SIZE > 0 )
                    {
                        if( xTimerQueue != NULL )
                        {
                            vQueueAddToRegistry( xTimerQueue, "TmrQ" );
                        }
                        else
                        {
                            mtCOVERAGE_TEST_MARKER();
                        }
                    }
                #endif /* configQUEUE_REGISTRY_SIZE */
            }
            else
            {
                mtCOVERAGE_TEST_MARKER();
            }
        }
        taskEXIT_CRITICAL();
    }
/*-----------------------------------------------------------*/

    BaseType_t xTimerIsTimerActive( TimerHandle_t xTimer )
    {
        BaseType_t xReturn;
        Timer_t * pxTimer = xTimer;

        configASSERT( xTimer );

        /* Is the timer in the list of active timers? */
        taskENTER_CRITICAL();
        {
            if( ( pxTimer->ucStatus & tmrSTATUS_IS_ACTIVE ) == 0 )
            {
                xReturn = pdFALSE;
            }
            else
            {
                xReturn = pdTRUE;
            }
        }
        taskEXIT_CRITICAL();

        return xReturn;
    } /*lint !e818 Can't be pointer to const due to the typedef. */
/*-----------------------------------------------------------*/

    void * pvTimerGetTimerID( const TimerHandle_t xTimer )
    {
        Timer_t * const pxTimer = xTimer;
        void * pvReturn;

        configASSERT( xTimer );

        taskENTER_CRITICAL();
        {
            pvReturn = pxTimer->pvTimerID;
        }
        taskEXIT_CRITICAL();

        return pvReturn;
    }
/*-----------------------------------------------------------*/

    void vTimerSetTimerID( TimerHandle_t xTimer,
                           void * pvNewID )
    {
        Timer_t * const pxTimer = xTimer;

        configASSERT( xTimer );

        taskENTER_CRITICAL();
        {
            pxTimer->pvTimerID = pvNewID;
        }
        taskEXIT_CRITICAL();
    }
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall == 1 )

        BaseType_t xTimerPendFunctionCallFromISR( PendedFunction_t xFunctionToPend,
                                                  void * pvParameter1,
                                                  uint32_t ulParameter2,
                                                  BaseType_t * pxHigherPriorityTaskWoken )
        {
            DaemonTaskMessage_t xMessage;
            BaseType_t xReturn;

            /* Complete the message with the function parameters and post it to the
             * daemon task. */
            xMessage.xMessageID = tmrCOMMAND_EXECUTE_CALLBACK_FROM_ISR;
            xMessage.u.xCallbackParameters.pxCallbackFunction = xFunctionToPend;
            xMessage.u.xCallbackParameters.pvParameter1 = pvParameter1;
            xMessage.u.xCallbackParameters.ulParameter2 = ulParameter2;

            xReturn = xQueueSendFromISR( xTimerQueue, &xMessage, pxHigherPriorityTaskWoken );

            tracePEND_FUNC_CALL_FROM_ISR( xFunctionToPend, pvParameter1, ulParameter2, xReturn );

            return xReturn;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall */
/*-----------------------------------------------------------*/

    #if ( INCLUDE_xTimerPendFunctionCall == 1 )

        BaseType_t xTimerPendFunctionCall( PendedFunction_t xFunctionToPend,
                                           void * pvParameter1,
                                           uint32_t ulParameter2,
                                           TickType_t xTicksToWait )
        {
            DaemonTaskMessage_t xMessage;
            BaseType_t xReturn;

            /* This function can only be called after a timer has been created or
             * after the scheduler has been started because, until then, the timer
             * queue does not exist. */
            configASSERT( xTimerQueue );

            /* Complete the message with the function parameters and post it to the
             * daemon task. */
            xMessage.xMessageID = tmrCOMMAND_EXECUTE_CALLBACK;
            xMessage.u.xCallbackParameters.pxCallbackFunction = xFunctionToPend;
            xMessage.u.xCallbackParameters.pvParameter1 = pvParameter1;
            xMessage.u.xCallbackParameters.ulParameter2 = ulParameter2;

            xReturn = xQueueSendToBack( xTimerQueue, &xMessage, xTicksToWait );

            tracePEND_FUNC_CALL( xFunctionToPend, pvParameter1, ulParameter2, xReturn );

            return xReturn;
        }

    #endif /* INCLUDE_xTimerPendFunctionCall */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY == 1 )

        UBaseType_t uxTimerGetTimerNumber( TimerHandle_t xTimer )
        {
            return ( ( Timer_t * ) xTimer )->uxTimerNumber;
        }

    #endif /* configUSE_TRACE_FACILITY */
/*-----------------------------------------------------------*/

    #if ( configUSE_TRACE_FACILITY == 1 )

        void vTimerSetTimerNumber( TimerHandle_t xTimer,
                                   UBaseType_t uxTimerNumber )
        {
            ( ( Timer_t * ) xTimer )->uxTimerNumber = uxTimerNumber;
        }

    #endif /* configUSE_TRACE_FACILITY */
/*-----------------------------------------------------------*/

/* 如果应用程序未配置包含软件定时器功能，则整个源文件将被跳过。若要包含软件定时器功能，请在 FreeRTOSConfig.h 中将 configUSE_TIMERS 设置为 1。 */
#endif /* configUSE_TIMERS == 1 */
