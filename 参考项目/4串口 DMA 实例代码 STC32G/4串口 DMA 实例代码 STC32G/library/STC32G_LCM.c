/**
 * @file STC32G_LCM.c
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

#include "STC32G_LCM.h"

//========================================================================
// : void LCM_Inilize( LCM_InitTypeDef *LCM )
// : LCM ʼ.
// : LCM: ṹ,οLCM.hĶ.
// : none.
// 汾: V1.0, 2021 - 6 - 2
//========================================================================
void LCM_Inilize( LCM_InitTypeDef *LCM )
{
	LCMIFSTA = 0x00;
	if ( LCM->LCM_Mode == MODE_M6800 )		LCMIFCFG |= MODE_M6800;	//LCMӿģʽM6800
	else LCMIFCFG &= ~MODE_M6800;	//LCMӿģʽI8080
	
	if ( LCM->LCM_Bit_Wide == BIT_WIDE_16 )		LCMIFCFG |= BIT_WIDE_16;	//LCMݿȣ16λ
	else LCMIFCFG &= ~BIT_WIDE_16;	//LCMݿȣ8λ
	
	if ( LCM->LCM_Setup_Time <= 7 ) LCMIFCFG2 = ( LCMIFCFG2 & ~0x1c ) | ( LCM->LCM_Setup_Time << 2 );	//LCMͨݽʱ䣺0~7
	if ( LCM->LCM_Hold_Time <= 3 ) LCMIFCFG2 = ( LCMIFCFG2 & ~0x03 ) | LCM->LCM_Hold_Time;	//LCMͨݽʱ䣺0~7
	
	if ( LCM->LCM_Enable == ENABLE )		LCMIFCR |= 0x80;	//ʹLCMӿڹ
	else LCMIFCR &= ~0x80;	//ֹLCMӿڹ
}
