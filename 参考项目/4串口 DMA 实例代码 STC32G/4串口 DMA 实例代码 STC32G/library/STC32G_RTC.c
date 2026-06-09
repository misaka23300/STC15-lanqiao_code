/**
 * @file STC32G_RTC.c
 * @brief 实时时钟驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86 )13922805190 ----------------------------------------*/
/* --- Fax: 86 - 513 - 5012956, 55012947, 55012969 ------------------------*/
/* --- Tel: 86 - 513 - 5012928, 55012929, 55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Ҫڳʹô˴,ڳעʹSTCϼ            */
/*---------------------------------------------------------------------*/

#include	"STC32G_RTC.h"

//========================================================================
// : u8	ADC_Inilize( ADC_InitTypeDef *ADCx )
// : ADCʼ.
// : ADCx: ṹ,οadc.hĶ.
// : none.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
u8	RTC_Inilize( RTC_InitTypeDef *RTCx )
{
	if ( RTCx->RTC_Year > 99 )	return FAIL;	//
	if ( RTCx->RTC_Month > 12 )	return FAIL;	//
	if ( RTCx->RTC_Day > 31 )	return FAIL;	//
	if ( RTCx->RTC_Hour > 23 )	return FAIL;	//
	if ( RTCx->RTC_Min > 59 )	return FAIL;	//
	if ( RTCx->RTC_Sec > 59 )	return FAIL;	//
	if ( RTCx->RTC_Ssec > 127 )	return FAIL;	//
	if ( RTCx->RTC_ALAHour > 23 )	return FAIL;	//
	if ( RTCx->RTC_ALAMin > 59 )	return FAIL;	//
	if ( RTCx->RTC_ALASec > 59 )	return FAIL;	//
	if ( RTCx->RTC_ALASsec > 127 )	return FAIL;	//

	INIYEAR = RTCx->RTC_Year;
	INIMONTH = RTCx->RTC_Month;
	INIDAY = RTCx->RTC_Day;
	INIHOUR = RTCx->RTC_Hour;
	INIMIN = RTCx->RTC_Min;
	INISEC = RTCx->RTC_Sec;
	INISSEC = RTCx->RTC_Ssec;

	ALAHOUR = RTCx->RTC_ALAHour;	//Сʱ
	ALAMIN  = RTCx->RTC_ALAMin;		//ӷ
	ALASEC  = RTCx->RTC_ALASec;		//
	ALASSEC = RTCx->RTC_ALASsec;	//1 / 28

	if ( RTCx->RTC_Clock == RTC_IRC32KCR )
	{
    //STC32G оƬʹڲ32Kʱӣ޷
		IRC32KCR = 0x80;   //ڲ32K.
		while (!( IRC32KCR & 1 ));  //ȴʱȶ
		RTCCFG = 0x03;    //ѡڲ32KʱԴRTCĴʼ
	}
	else
	{
		X32KCR = 0x80 + 0x40;   //ⲿ32K, +0x00, +0x40.
		while (!( X32KCR & 1 ));  //ȴʱȶ
		RTCCFG = 0x01;    //ѡⲿ32KʱԴRTCĴʼ
	}

	if ( RTCx->RTC_Enable == ENABLE )
	{
		RTCCR = 0x01;     //RTCʹ
		while ( RTCCFG & 0x01 );	//ȴʼ,Ҫ "RTCʹ" ֮ж. 
		//RTCʱҪ32768Hz1ʱ,Լ30.5us. ͬ, ʵʵȴʱ0~30.5us.
		//ȴɾ˯, RTCû, ֹͣ, Ѻżò.
	}
	else
	{
		RTCCR = 0x00;     //RTCر
	}
	
	return SUCCESS;
}

