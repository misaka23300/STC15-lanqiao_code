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

#ifndef	__STC32G_ADC_H
#define	__STC32G_ADC_H

#include	"config.h"

//========================================================================
//                              ADCÉèÖÃ
//========================================================================

#define 	ADC_PowerOn(n)			(n==0?(ADC_POWER = 0):(ADC_POWER = 1))	/* ADCµçÔ´¿ª¹Ø */
#define 	ADC_Justify(n)			(n==0?(RESFMT = 0):(RESFMT = 1))				/* ADC×ª»»½á¹û¸ñÊ½¿ØÖÆ, ×ó¶ÔÆë/ÓÒ¶ÔÆë */

//========================================================================
//                              ¶¨ÒåÉùÃ÷
//========================================================================

#define	ADC_P10		0x01	//IOÒý½Å Px.0
#define	ADC_P11		0x02	//IOÒý½Å Px.1
#define	ADC_P12		0x04	//IOÒý½Å Px.2
#define	ADC_P13		0x08	//IOÒý½Å Px.3
#define	ADC_P14		0x10	//IOÒý½Å Px.4
#define	ADC_P15		0x20	//IOÒý½Å Px.5
#define	ADC_P16		0x40	//IOÒý½Å Px.6
#define	ADC_P17		0x80	//IOÒý½Å Px.7
#define	ADC_P1_All	0xFF	//IOËùÓÐÒý½Å

#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7
#define ADC_CH8		8
#define ADC_CH9		9
#define ADC_CH10	10
#define ADC_CH11	11
#define ADC_CH12	12
#define ADC_CH13	13
#define ADC_CH14	14
#define ADC_CH15	15

#define ADC_SPEED_2X1T		0			//SYSclk/2/1
#define ADC_SPEED_2X2T		1			//SYSclk/2/2
#define ADC_SPEED_2X3T		2			//SYSclk/2/3
#define ADC_SPEED_2X4T		3			//SYSclk/2/4
#define ADC_SPEED_2X5T		4			//SYSclk/2/5
#define ADC_SPEED_2X6T		5			//SYSclk/2/6
#define ADC_SPEED_2X7T		6			//SYSclk/2/7
#define ADC_SPEED_2X8T		7			//SYSclk/2/8
#define ADC_SPEED_2X9T		8			//SYSclk/2/9
#define ADC_SPEED_2X10T		9			//SYSclk/2/10
#define ADC_SPEED_2X11T		10		//SYSclk/2/11
#define ADC_SPEED_2X12T		11		//SYSclk/2/12
#define ADC_SPEED_2X13T		12		//SYSclk/2/13
#define ADC_SPEED_2X14T		13		//SYSclk/2/14
#define ADC_SPEED_2X15T		14		//SYSclk/2/15
#define ADC_SPEED_2X16T		15		//SYSclk/2/16

#define ADC_LEFT_JUSTIFIED		0		//ADC Result left-justified
#define ADC_RIGHT_JUSTIFIED		1		//ADC Result right-justified


typedef struct
{
	u8	ADC_SMPduty;		//ADC Ä£ÄâÐÅºÅ²ÉÑùÊ±¼ä¿ØÖÆ, 0~31£¨×¢Òâ£º SMPDUTY Ò»¶¨²»ÄÜÉèÖÃÐ¡ÓÚ 10£©
	u8	ADC_Speed;			//ÉèÖÃ ADC ¹¤×÷Ê±ÖÓÆµÂÊ	ADC_SPEED_2X1T~ADC_SPEED_2X16T
	u8	ADC_AdjResult;	//ADC½á¹ûµ÷Õû,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
	u8	ADC_CsSetup;		//ADC Í¨µÀÑ¡ÔñÊ±¼ä¿ØÖÆ 0(Ä¬ÈÏ),1
	u8	ADC_CsHold;			//ADC Í¨µÀÑ¡Ôñ±£³ÖÊ±¼ä¿ØÖÆ 0,1(Ä¬ÈÏ),2,3
} ADC_InitTypeDef;

u8		ADC_Inilize(ADC_InitTypeDef *ADCx);
void	ADC_PowerControl(u8 pwr);
u16		Get_ADCResult(u8 channel);	//channel = 0~15

#endif
