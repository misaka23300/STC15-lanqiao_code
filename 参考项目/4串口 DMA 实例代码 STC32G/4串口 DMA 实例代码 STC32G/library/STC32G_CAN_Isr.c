/**
 * @file STC32G_CAN_Isr.c
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

#include	"STC32G_CAN.h"

bit B_Can1Read;     //CAN1 յݱ־
bit B_Can2Read;     //CAN2 յݱ־

//========================================================================
// : CAN1_ISR_Handler
// : CAN1жϺ.
// : none.
// : none.
// 汾: V1.0, 2022 - 3 - 7
//========================================================================
void CAN1_ISR_Handler ( void ) interrupt CAN1_VECTOR
{
	u8 isr;
	u8 store;
	u8 arTemp;

	arTemp = CANAR;     //CANARֳ棬ѭд CANAR жϣж޸ CANAR 
	store = AUXR2;      //AUXR2ֳ
	
	AUXR2 &= ~0x08;		//ѡCAN1ģ
	isr = CanReadReg( ISR );

	if (( isr & 0x04 ) == 0x04 )  //TI
	{
		CANAR = ISR;
		CANDR = 0x04;    //CLR FLAG
  }	
	if (( isr & 0x08 ) == 0x08 )  //RI
	{
		CANAR = ISR;
		CANDR = 0x08;    //CLR FLAG
	
		B_Can1Read = 1;
	}

	if (( isr & 0x40 ) == 0x40 )  //ALI
	{
		CANAR = ISR;
		CANDR = 0x40;    //CLR FLAG
	}	

	if (( isr & 0x20 ) == 0x20 )  //EWI
	{
		CANAR = MR;
		CANDR &= ~0x04;  // Reset Mode, BUS - FF״̬˳
		
		CANAR = ISR;
		CANDR = 0x20;    //CLR FLAG
	}	

	if (( isr & 0x10 ) == 0x10 )  //EPI
	{
		CANAR = ISR;
		CANDR = 0x10;    //CLR FLAG
	}	

	if (( isr & 0x02 ) == 0x02 )  //BEI
	{
		CANAR = ISR;
		CANDR = 0x02;    //CLR FLAG
	}	

	if (( isr & 0x01 ) == 0x01 )  //DOI
	{
		CANAR = ISR;
		CANDR = 0x01;    //CLR FLAG
	}	

	AUXR2 = store;     //AUXR2ֳָ
	CANAR = arTemp;    //CANARֳָ
}

//========================================================================
// : CAN2_ISR_Handler
// : CAN2жϺ.
// : none.
// : none.
// 汾: V1.0, 2022 - 3 - 7
//========================================================================
void CAN2_ISR_Handler ( void ) interrupt CAN2_VECTOR
{
	u8 isr;
	u8 store;
	u8 arTemp;

	arTemp = CANAR;     //CANARֳ棬ѭд CANAR жϣж޸ CANAR 
	store = AUXR2;      //AUXR2ֳ
	
	AUXR2 |= 0x08;		//ѡCAN2ģ
	isr = CanReadReg( ISR );

	if (( isr & 0x04 ) == 0x04 )  //TI
	{
		CANAR = ISR;
		CANDR = 0x04;    //CLR FLAG
  }	
	if (( isr & 0x08 ) == 0x08 )  //RI
	{
		CANAR = ISR;
		CANDR = 0x08;    //CLR FLAG
	
		B_Can2Read = 1;
	}

	if (( isr & 0x40 ) == 0x40 )  //ALI
	{
		CANAR = ISR;
		CANDR = 0x40;    //CLR FLAG
	}	

	if (( isr & 0x20 ) == 0x20 )  //EWI
	{
		CANAR = MR;
		CANDR &= ~0x04;  // Reset Mode, BUS - FF״̬˳
		
		CANAR = ISR;
		CANDR = 0x20;    //CLR FLAG
	}	

	if (( isr & 0x10 ) == 0x10 )  //EPI
	{
		CANAR = ISR;
		CANDR = 0x10;    //CLR FLAG
	}	

	if (( isr & 0x02 ) == 0x02 )  //BEI
	{
		CANAR = ISR;
		CANDR = 0x02;    //CLR FLAG
	}	

	if (( isr & 0x01 ) == 0x01 )  //DOI
	{
		CANAR = ISR;
		CANDR = 0x01;    //CLR FLAG
	}	

	AUXR2 = store;     //AUXR2ֳָ
	CANAR = arTemp;    //CANARֳָ
}

