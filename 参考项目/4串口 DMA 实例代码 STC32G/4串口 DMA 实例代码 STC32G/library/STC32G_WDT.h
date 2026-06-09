/**
 * @file STC32G_WDT.h
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
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Ҫڳʹô˴,ڳעʹSTCϼ            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_WDT_H
#define	__STC32G_WDT_H

#include	"config.h"

#define D_WDT_FLAG			(1<<7 )
#define D_EN_WDT			(1<<5 )
#define D_CLR_WDT			(1<<4 )	/* auto clear	*/
#define D_IDLE_WDT			(1<<3 )	/* WDT counter when Idle	*/

#define WDT_IDLE_STOP		0
#define WDT_IDLE_RUN		1

#define WDT_SCALE_2			0		/* WDT Timeout=(12 * 2768 * CALE )/SYSclk */
#define WDT_SCALE_4			1
#define WDT_SCALE_8			2
#define WDT_SCALE_16		3
#define WDT_SCALE_32		4
#define WDT_SCALE_64		5
#define WDT_SCALE_128		6
#define WDT_SCALE_256		7

#define	WDT_PS_Set( n )	WDT_CONTR = ( WDT_CONTR & ~0x07 ) | ( n & 0x07 )		/* ŹʱʱӷƵϵ */
#define	WDT_reset( n )	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + ( n )		/* ʼWDTι */

typedef struct
{
	u8	WDT_Enable;				//Źʹ  	ENABLE, DISABLE
	u8	WDT_IDLE_Mode;		//IDLEģʽֹͣ		WDT_IDLE_STOP, WDT_IDLE_RUN
	u8	WDT_PS;						//ŹʱʱӷƵϵ		WDT_SCALE_2, WDT_SCALE_4, WDT_SCALE_8, WDT_SCALE_16, WDT_SCALE_32, WDT_SCALE_64, WDT_SCALE_128, WDT_SCALE_256
} WDT_InitTypeDef;

void WDT_Inilize( WDT_InitTypeDef *WDT );
void WDT_Clear ( void );

#endif
