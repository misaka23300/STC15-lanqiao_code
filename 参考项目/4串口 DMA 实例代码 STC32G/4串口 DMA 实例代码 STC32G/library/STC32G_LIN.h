#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_LIN_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_LIN_H_

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

#ifndef	__STC32G_LIN_H
#define	__STC32G_LIN_H

#include	"config.h"

//========================================================================
//                              
//========================================================================

#define LIN_MODE        1    //0: LIN2.1(ǿУ);  1: LIN1.3
#define FRAME_LEN       8    //ݳ: 8 ֽ

//========================================================================
//                              
//========================================================================

#define LIN_LIDE     0x01  //Headж
#define LIN_RDYE     0x02  //Readyж
#define LIN_ERRE     0x04  //ж
#define LIN_ABORTE   0x08  //ֹж
#define LIN_ALLIE    0x0F  //ж

//========================================================================
//                              
//========================================================================

typedef struct
{
	u8	LIN_Enable;         //LINʹ  	ENABLE,DISABLE
	u16	LIN_Baudrate;       //LIN
	u8	LIN_IE;             //LINжʹ  	LIN_LIDE/LIN_RDYE/LIN_ERRE/LIN_ABORTE/LIN_ALLIE,DISABLE
	u8	LIN_HeadDelay;      //֡ͷʱ  	0~(65535*1000)/MAIN_Fosc
	u8	LIN_HeadPrescaler;  //֡ͷʱƵ  	0~63
} LIN_InitTypeDef;


//========================================================================
//                              ⲿ
//========================================================================

void LIN_Inilize(LIN_InitTypeDef *LIN);
u8 LinReadReg(u8 addr);
void LinReadFrame(u8 *pdat);
void LinSendFrame(u8 lid, u8 *pdat);
void LinSendHeaderRead(u8 lid, u8 *pdat);
void LinTxResponse(u8 *pdat);
void LinSetBaudrate(u16 brt);

#endif

#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_LIN_H_ */
