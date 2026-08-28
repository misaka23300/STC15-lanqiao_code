#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_USART_LIN_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_USART_LIN_H_

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

#ifndef __STC32G_USART_LIN_H
#define __STC32G_USART_LIN_H	 

#include	"config.h"

//========================================================================
//                              
//========================================================================

#define	USART1	1
#define	USART2	2

#define FRAME_LEN       8    //ݳ: 8 ֽ

#define	LinMasterMode		0
#define	LinSlaveMode		1

//========================================================================
//                              USART
//========================================================================


//========================================================================
//                              
//========================================================================

typedef struct
{ 
	u8	LIN_Enable;				//LINʹ  	ENABLE,DISABLE
	u8	LIN_Mode;				//LINģʽ  	LinMasterMode,LinSlaveMode
	u8	LIN_AutoSync;			//Զͬʹ  	ENABLE,DISABLE
	u16	LIN_Baudrate;			//LIN
} USARTx_LIN_InitDefine; 

//========================================================================
//                              ⲿ
//========================================================================

u8 UASRT_LIN_Configuration(u8 USARTx, USARTx_LIN_InitDefine *USART);
void UsartLinSendChecksum(u8 USARTx, u8 *dat, u8 len);
void UsartLinSendData(u8 USARTx, u8 *pdat, u8 len);
void UsartLinSendFrame(u8 USARTx, u8 lid, u8 *pdat, u8 len);
void UsartLinSendHeader(u8 USARTx, u8 lid);

#endif


#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_USART_LIN_H_ */
