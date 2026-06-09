/**
 * @file STC32G_Compare.c
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

#include	"STC32G_Compare.h"

//========================================================================
// :void	CMP_Inilize( CMP_InitDefine *CMPx )
// : Ƚʼ.
// : CMPx: ṹ,οcompare.hĶ.
// : none.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
void	CMP_Inilize( CMP_InitDefine *CMPx )
{
	CMPCR1 &= 0x30;
	CMPCR2 = CMPx->CMP_OutDelayDuty & 0x3f;							//ȽϽ仯ʱ, 0~63
	if ( CMPx->CMP_EN == ENABLE )				CMPEN = 1;				//Ƚ		ENABLE, DISABLE
	if ( CMPx->CMP_Outpt_En == ENABLE )		CMPOE = 1;			//ȽϽP3.4 / 4.1,   ENABLE, DISABLE
	if ( CMPx->CMP_InvCMPO     == ENABLE )		INVCMPO = 1;	//Ƚȡ, 	ENABLE, DISABLE
	if ( CMPx->CMP_100nsFilter == DISABLE )	DISFLT = 1;		//ڲ0.1us˲,  	ENABLE, DISABLE

	if ( CMPx->CMP_P_Select  <= CMP_P_ADC )	CMPEXCFG = ( CMPEXCFG & ~0x03 ) | ( CMPx->CMP_P_Select );			//Ƚѡ, CMP_P_P37 / MP_P_P50 / MP_P_P51, CMP_P_ADC: ADCģ.
	if ( CMPx->CMP_N_Select  <= CMP_N_GAP )	CMPEXCFG = ( CMPEXCFG & ~0x04 ) | ( CMPx->CMP_N_Select << 2 );	//Ƚ븺ѡ, CMP_N_GAP: ѡڲBandGapOPĵѹ, CMP_N_P36: ѡP3.6.
}
