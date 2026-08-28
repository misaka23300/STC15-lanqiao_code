#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_RTC_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_RTC_H_

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Ҫڳʹô˴,ڳעʹSTCϼ            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_RTC_H
#define	__STC32G_RTC_H

#include	"config.h"

//========================================================================
//                              
//========================================================================

#define RTC_IRC32KCR		0		//RTCʱԴʹڲ32Kʱ
#define RTC_X32KCR			1		//RTCʱԴʹⲿ32K

//жʹ, 0x80:ж, 0x40:ж, 0x20:Сʱж, 0x10:ж, 0x08:ж, 0x04:1/2ж, 0x02:1/8ж, 0x01:1/32ж
#define RTC_ALARM_INT		0x80		//RTC ж
#define RTC_DAY_INT			0x40		//RTC ж
#define RTC_HOUR_INT		0x20		//RTC Сʱж
#define RTC_MIN_INT			0x10		//RTC ж
#define RTC_SEC_INT			0x08		//RTC ж
#define RTC_SEC2_INT		0x04		//RTC 1/2ж
#define RTC_SEC8_INT		0x02		//RTC 1/8ж
#define RTC_SEC32_INT		0x01		//RTC 1/32ж

typedef struct
{
	u8	RTC_Enable;		//RTC ʹ, ENABLE, DISABLE
	u8	RTC_Clock;		//RTC ʱ, RTC_IRC32KCR, RTC_X32KCR
	u8	RTC_Year;			//RTC , 00~99, Ӧ2000~2099
	u8	RTC_Month;		//RTC , 01~12
	u8	RTC_Day;			//RTC , 01~31
	u8	RTC_Hour;			//RTC ʱ, 00~23
	u8	RTC_Min;			//RTC , 00~59
	u8	RTC_Sec;			//RTC , 00~59
	u8	RTC_Ssec;			//RTC 1/128, 00~127

	u8	RTC_ALAHour;	//RTC ʱ, 00~23
	u8	RTC_ALAMin;		//RTC ӷ, 00~59
	u8	RTC_ALASec;		//RTC , 00~59
	u8	RTC_ALASsec;	//RTC 1/128, 00~127
} RTC_InitTypeDef;

u8	RTC_Inilize(RTC_InitTypeDef *RTCx);

#endif

#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_RTC_H_ */
