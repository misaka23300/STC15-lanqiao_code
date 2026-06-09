/**
 * @file STC32G_CAN.h
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

#ifndef	__STC32G_CAN_H
#define	__STC32G_CAN_H

#include	"config.h"

//========================================================================
//                              
//========================================================================

#define	CAN1	0
#define	CAN2	1

#define	STANDARD_FRAME   0     //֡ʽ׼֡
#define	EXTENDED_FRAME   1     //֡ʽչ֡

//========================================================================
//                              
//========================================================================

#define CAN_DOIM     0x01  //ж
#define CAN_BEIM     0x02  //ߴλж
#define CAN_TIM      0x04  //ж
#define CAN_RIM      0x08  //ж
#define CAN_EPIM     0x10  //λж
#define CAN_EWIM     0x20  //λж
#define CAN_ALIM     0x40  //ٲöʧж
#define CAN_ALLIM    0x7F  //ж

//========================================================================
//                              
//========================================================================

typedef struct
{
	u8	CAN_Enable;					//CANʹ  	ENABLE, DISABLE
	u8	CAN_IMR;						//CANжϼĴ 	CAN_DOIM, CAN_BEIM, CAN_TIM, CAN_RIM, CAN_EPIM, CAN_EWIM, CAN_ALIM, CAN_ALLIM, DISABLE
	u8	CAN_SJW;						//ͬԾ  0~3
	u8	CAN_BRP;						//ʷƵϵ    0~63
	u8	CAN_SAM;						//ߵƽ  0:1; 1:3
	u8	CAN_TSG1;						//ͬ1       0~15
	u8	CAN_TSG2;						//ͬ2       1~7 ( TSG2 Ϊ0 )

	u8	CAN_ACR0;						//մĴ 0~0xFF
	u8	CAN_ACR1;						//մĴ 0~0xFF
	u8	CAN_ACR2;						//մĴ 0~0xFF
	u8	CAN_ACR3;						//մĴ 0~0xFF
	u8	CAN_AMR0;						//μĴ 0~0xFF
	u8	CAN_AMR1;						//μĴ 0~0xFF
	u8	CAN_AMR2;						//μĴ 0~0xFF
	u8	CAN_AMR3;						//μĴ 0~0xFF
} CAN_InitTypeDef;

typedef struct
{
	u8	DLC:4;          //ݳ, bit0~bit3
	u8	:2;             //, bit4~bit5
	u8	RTR:1;          //֡, bit6
	u8	FF:1;           //֡ʽ, bit7
	u32	ID;             //CAN ID
	u8	DataBuffer[8];  //ݻ
}CAN_DataDef;

//========================================================================
//                              ⲿ
//========================================================================
extern bit B_Can1Read;     //CAN յݱ־
extern bit B_Can2Read;     //CAN յݱ־

extern CAN_DataDef CAN1_Tx;
extern CAN_DataDef CAN1_Rx[8];
extern CAN_DataDef CAN2_Tx;
extern CAN_DataDef CAN2_Rx[8];

u8 CanReadReg( u8 addr );
void CAN_Inilize( u8 CANx, CAN_InitTypeDef *CAN );
u8 CanReadMsg( CAN_DataDef *CAN );
void CanSendMsg( CAN_DataDef *CAN );

#endif
