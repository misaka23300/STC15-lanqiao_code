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
/* Èç¹ûÒªÔÚ³ÌÐòÖÐÊ¹ÓÃ´Ë´úÂë,ÇëÔÚ³ÌÐòÖÐ×¢Ã÷Ê¹ÓÃÁËSTCµÄ×ÊÁÏ¼°³ÌÐò            */
/*---------------------------------------------------------------------*/

#include	"STC32G_CAN.h"

bit B_Can1Read;     //CAN1 ÊÕµ½Êý¾Ý±êÖ¾
bit B_Can2Read;     //CAN2 ÊÕµ½Êý¾Ý±êÖ¾

//========================================================================
// º¯Êý: CAN1_ISR_Handler
// ÃèÊö: CAN1ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-27
//========================================================================
void CAN1_ISR_Handler (void) interrupt CAN1_VECTOR
{
	u8 isr;
	u8 store;
	u8 arTemp;

	arTemp = CANAR;     //ÏÈCANARÏÖ³¡±£´æ£¬±ÜÃâÖ÷Ñ­»·ÀïÐ´Íê CANAR ºó²úÉúÖÐ¶Ï£¬ÔÚÖÐ¶ÏÀïÐÞ¸ÄÁË CANAR ÄÚÈÝ
	store = AUXR2;      //ºóAUXR2ÏÖ³¡±£´æ
	
	AUXR2 &= ~0x08;		//Ñ¡ÔñCAN1Ä£¿é
	isr = CanReadReg(ISR);

	if((isr & 0x04) == 0x04)  //TI
	{
		CANAR = ISR;
		CANDR = 0x04;    //CLR FLAG
  }	
	if((isr & 0x08) == 0x08)  //RI
	{
		CANAR = ISR;
		CANDR = 0x08;    //CLR FLAG
	
		B_Can1Read = 1;
	}

	if((isr & 0x40) == 0x40)  //ALI
	{
		CANAR = ISR;
		CANDR = 0x40;    //CLR FLAG
	}	

	if((isr & 0x20) == 0x20)  //EWI
	{
		CANAR = MR;
		CANDR &= ~0x04;  //Çå³ý Reset Mode, ´ÓBUS-OFF×´Ì¬ÍË³ö
		
		CANAR = ISR;
		CANDR = 0x20;    //CLR FLAG
	}	

	if((isr & 0x10) == 0x10)  //EPI
	{
		CANAR = ISR;
		CANDR = 0x10;    //CLR FLAG
	}	

	if((isr & 0x02) == 0x02)  //BEI
	{
		CANAR = ISR;
		CANDR = 0x02;    //CLR FLAG
	}	

	if((isr & 0x01) == 0x01)  //DOI
	{
		CANAR = ISR;
		CANDR = 0x01;    //CLR FLAG
	}	

	AUXR2 = store;     //ÏÈAUXR2ÏÖ³¡»Ö¸´
	CANAR = arTemp;    //ºóCANARÏÖ³¡»Ö¸´
}

//========================================================================
// º¯Êý: CAN2_ISR_Handler
// ÃèÊö: CAN2ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-27
//========================================================================
void CAN2_ISR_Handler (void) interrupt CAN2_VECTOR
{
	u8 isr;
	u8 store;
	u8 arTemp;

	arTemp = CANAR;     //ÏÈCANARÏÖ³¡±£´æ£¬±ÜÃâÖ÷Ñ­»·ÀïÐ´Íê CANAR ºó²úÉúÖÐ¶Ï£¬ÔÚÖÐ¶ÏÀïÐÞ¸ÄÁË CANAR ÄÚÈÝ
	store = AUXR2;      //ºóAUXR2ÏÖ³¡±£´æ
	
	AUXR2 |= 0x08;		//Ñ¡ÔñCAN2Ä£¿é
	isr = CanReadReg(ISR);

	if((isr & 0x04) == 0x04)  //TI
	{
		CANAR = ISR;
		CANDR = 0x04;    //CLR FLAG
  }	
	if((isr & 0x08) == 0x08)  //RI
	{
		CANAR = ISR;
		CANDR = 0x08;    //CLR FLAG
	
		B_Can2Read = 1;
	}

	if((isr & 0x40) == 0x40)  //ALI
	{
		CANAR = ISR;
		CANDR = 0x40;    //CLR FLAG
	}	

	if((isr & 0x20) == 0x20)  //EWI
	{
		CANAR = MR;
		CANDR &= ~0x04;  //Çå³ý Reset Mode, ´ÓBUS-OFF×´Ì¬ÍË³ö
		
		CANAR = ISR;
		CANDR = 0x20;    //CLR FLAG
	}	

	if((isr & 0x10) == 0x10)  //EPI
	{
		CANAR = ISR;
		CANDR = 0x10;    //CLR FLAG
	}	

	if((isr & 0x02) == 0x02)  //BEI
	{
		CANAR = ISR;
		CANDR = 0x02;    //CLR FLAG
	}	

	if((isr & 0x01) == 0x01)  //DOI
	{
		CANAR = ISR;
		CANDR = 0x01;    //CLR FLAG
	}	

	AUXR2 = store;     //ÏÈAUXR2ÏÖ³¡»Ö¸´
	CANAR = arTemp;    //ºóCANARÏÖ³¡»Ö¸´
}


