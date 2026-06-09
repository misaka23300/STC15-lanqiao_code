/**
 * @file STC32G_Compare.h
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

#ifndef	__STC32G_COMPARE_H
#define	__STC32G_COMPARE_H

#include	"config.h"

//========================================================================
//                              
//========================================================================

#define	CMP_P_P37	0x00	//ѡ, 0: ѡڲP3.7
#define	CMP_P_P50	0x01	//ѡ, 1: ѡڲP5.0
#define	CMP_P_P51	0x02	//ѡ, 2: ѡڲP5.1
#define	CMP_P_ADC	0x03	//ѡ, 3: ADC_CHS[3:0]ѡADC.
#define	CMP_N_P36	0x00	//븺ѡ, 0: ѡⲿP3.6.
#define	CMP_N_GAP	0x01	//븺ѡ, 1: ѡڲBandGapѹBGv.

#define	CMPO_P34()	CMPO_S = 0	//P3.4.
#define	CMPO_P41()	CMPO_S = 1	//P4.1.

typedef struct
{ 
	u8	CMP_EN;					//Ƚֹ, 			ENABLE, DISABLE
	u8	CMP_P_Select;		//Ƚѡ, CMP_P_P37: ѡP3.7, CMP_P_ADC: ADCģ.
	u8	CMP_N_Select;		//Ƚ븺ѡ, CMP_N_GAP: ѡڲBandGapOPĵѹ, CMP_N_P36: ѡP3.6.
	u8	CMP_Outpt_En;		//ȽϽ,   ENABLE, DISABLE
	u8	CMP_InvCMPO;		//Ƚȡ, ENABLE, DISABLE
	u8	CMP_100nsFilter;	//ڲ0.1us˲,  ENABLE, DISABLE
	u8	CMP_OutDelayDuty;	//0~63, ȽϽ仯ʱ
} CMP_InitDefine; 

void	CMP_Inilize( CMP_InitDefine *CMPx );

#endif
