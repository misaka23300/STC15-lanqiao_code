/**
 * @file STC32G_RTC.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86 )13922805190 ----------------------------------------*/
/* --- Fax: 86 - 513 - 5012956, 55012947, 55012969 ------------------------*/
/* --- Tel: 86 - 513 - 5012928, 55012929, 55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_RTC_H
#define	__STC32G_RTC_H

#include	"FreeRTOS.h"

//========================================================================
//                              定义声明
//========================================================================

#define RTC_IRC32KCR		0		//RTC时钟源使用内部32K时钟
#define RTC_X32KCR			1		//RTC时钟源使用外部32K晶振

//中断使能, 0x80:闹钟中断, 0x40:日中断, 0x20:小时中断, 0x10:分钟中断, 0x08:秒中断, 0x04:1 / 秒中断, 0x02:1 / 秒中断, 0x01:1 / 2秒中断
#define RTC_ALARM_INT		0x80		//RTC 闹钟中断
#define RTC_DAY_INT			0x40		//RTC 日中断
#define RTC_HOUR_INT		0x20		//RTC 小时中断
#define RTC_MIN_INT			0x10		//RTC 分钟中断
#define RTC_SEC_INT			0x08		//RTC 秒中断
#define RTC_SEC2_INT		0x04		//RTC 1 / 秒中断
#define RTC_SEC8_INT		0x02		//RTC 1 / 秒中断
#define RTC_SEC32_INT		0x01		//RTC 1 / 2秒中断

typedef struct
{
	uint8_t	RTC_Enable;		//RTC 使能, ENABLE, DISABLE
	uint8_t	RTC_Clock;		//RTC 时钟, RTC_IRC32KCR, RTC_X32KCR
	uint8_t	RTC_Year;			//RTC 年, 00~99, 对应2000~2099年
	uint8_t	RTC_Month;		//RTC 月, 01~12
	uint8_t	RTC_Day;			//RTC 日, 01~31
	uint8_t	RTC_Hour;			//RTC 时, 00~23
	uint8_t	RTC_Min;			//RTC 分, 00~59
	uint8_t	RTC_Sec;			//RTC 秒, 00~59
	uint8_t	RTC_Ssec;			//RTC 1 / 28秒, 00~127

	uint8_t	RTC_ALAHour;	//RTC 闹钟时, 00~23
	uint8_t	RTC_ALAMin;		//RTC 闹钟分, 00~59
	uint8_t	RTC_ALASec;		//RTC 闹钟秒, 00~59
	uint8_t	RTC_ALASsec;	//RTC 闹钟1 / 28秒, 00~127
} RTC_InitTypeDef;

uint8_t	RTC_Inilize( RTC_InitTypeDef *RTCx );

#endif
