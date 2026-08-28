#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_ADC_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_ADC_H_

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

#ifndef	__STC32G_ADC_H
#define	__STC32G_ADC_H

#include	"config.h"

//========================================================================
//                              ADC
//========================================================================

#define 	ADC_PowerOn(n)			(n==0?(ADC_POWER = 0):(ADC_POWER = 1))	/* ADCԴ */
#define 	ADC_Justify(n)			(n==0?(RESFMT = 0):(RESFMT = 1))				/* ADCתʽ, /Ҷ */

//========================================================================
//                              
//========================================================================

#define	ADC_P10		0x01	//IO Px.0
#define	ADC_P11		0x02	//IO Px.1
#define	ADC_P12		0x04	//IO Px.2
#define	ADC_P13		0x08	//IO Px.3
#define	ADC_P14		0x10	//IO Px.4
#define	ADC_P15		0x20	//IO Px.5
#define	ADC_P16		0x40	//IO Px.6
#define	ADC_P17		0x80	//IO Px.7
#define	ADC_P1_All	0xFF	//IO

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
	u8	ADC_SMPduty;		//ADC ģźŲʱ, 0~31ע⣺ SMPDUTY һС 10
	u8	ADC_Speed;			// ADC ʱƵ	ADC_SPEED_2X1T~ADC_SPEED_2X16T
	u8	ADC_AdjResult;	//ADC,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
	u8	ADC_CsSetup;		//ADC ͨѡʱ 0(Ĭ),1
	u8	ADC_CsHold;			//ADC ͨѡ񱣳ʱ 0,1(Ĭ),2,3
} ADC_InitTypeDef;

u8		ADC_Inilize(ADC_InitTypeDef *ADCx);
void	ADC_PowerControl(u8 pwr);
u16		Get_ADCResult(u8 channel);	//channel = 0~15

#endif

#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_ADC_H_ */
