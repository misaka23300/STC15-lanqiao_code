#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_I2C_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_I2C_H_

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

#ifndef	__STC32G_I2C_H
#define	__STC32G_I2C_H

#include	"config.h"

//========================================================================
//                               I2C
//========================================================================

#define		I2C_Function(n)	(n==0?(I2CCFG &= ~0x80):(I2CCFG |= 0x80))	//0ֹ I2C ܣ1ʹ I2C 
#define		I2C_ENABLE()	I2CCFG |= 0x80		/* ʹ I2C  */
#define		I2C_DISABLE()	I2CCFG &= ~0x80		/* ֹ I2C  */
#define		I2C_Master()	I2CCFG |=  0x40		/* 1: Ϊ	*/
#define		I2C_Slave()		I2CCFG &= ~0x40		/* 0: Ϊӻ	*/
#define		I2C_SetSpeed(n)	I2CCFG = (I2CCFG & ~0x3f) | (n & 0x3f)	/* ٶ=Fosc/2/(Speed*2+4) */

#define		I2C_WDTA_EN()		I2CMSAUX |= 0x01		/* ʹԶ */
#define		I2C_WDTA_DIS()	I2CMSAUX &= ~0x01		/* ֹԶ */

#define		I2C_Address(n)	I2CSLADR = (I2CSLADR & 0x01) | (n << 1)	/* ӻַ */
#define		I2C_MATCH_EN()	I2CSLADR &= ~0x01	/* ʹܴӻַȽϹܣֻƥַ */
#define		I2C_MATCH_DIS()	I2CSLADR |= 0x01	/* ֹӻַȽϹܣ豸ַ */

#define		I2C_ESTAI_EN(n)		I2CSLCR = (I2CSLCR & ~0x40) | (n << 6)		/* ʹܴӻSTARTźж */
#define		I2C_ERXI_EN(n)		I2CSLCR = (I2CSLCR & ~0x20) | (n << 5)		/* ʹܴӻ1ֽж */
#define		I2C_ETXI_EN(n)		I2CSLCR = (I2CSLCR & ~0x10) | (n << 4)		/* ʹܴӻ1ֽж */
#define		I2C_ESTOI_EN(n)		I2CSLCR = (I2CSLCR & ~0x08) | (n << 3)		/* ʹܴӻSTOPźж */
#define		I2C_SLRET()				I2CSLCR |= 0x01			/* λӻģʽ */

#define		I2C_MSCMD(n)		I2CMSCR = (n)		/*  */

//========================================================================
//                              
//========================================================================

#define	I2C_CMD_IDLE			0
#define	I2C_CMD_START			1
#define	I2C_CMD_SEND			2
#define	I2C_CMD_RACK			3
#define	I2C_CMD_RDATA			4
#define	I2C_CMD_SACK			5
#define	I2C_CMD_STOP			6

#define	I2C_BUF_LENTH	8
#define	I2C_BUF_type	edata

#define	I2C_Mode_Master			1
#define	I2C_Mode_Slave			0

#define		I2C_ESTAI					0x40		/* ӻSTARTźж */
#define		I2C_ERXI					0x20		/* ӻ1ֽж */
#define		I2C_ETXI					0x10		/* ӻ1ֽж */
#define		I2C_ESTOI					0x08		/* ӻSTOPźж */

typedef struct
{
	u8	I2C_Speed;				//ٶ=Fosc/2/(Speed*2+4),      0~63
	u8	I2C_Enable;				//I2Cʹ,   ENABLE, DISABLE
	u8	I2C_Mode;					//ģʽѡ,  I2C_Mode_Master,I2C_Mode_Slave
	u8	I2C_MS_WDTA;				//ʹԶ,  ENABLE, DISABLE

	u8	I2C_SL_ADR;				//ӻ豸ַ,  0~127
	u8	I2C_SL_MA;				//ӻ豸ַȽʹ,  ENABLE, DISABLE
} I2C_InitTypeDef;

typedef struct
{
	u8	isma;				//MEMORY ADDRESS жϱ־
	u8	isda;				//DEVICE ADDRESS жϱ־
	u8	addr;				//ADDRESS 
} I2C_IsrTypeDef;


extern u8 I2C_BUF_type I2C_Buffer[I2C_BUF_LENTH];
extern bit DisplayFlag;

void I2C_Init(I2C_InitTypeDef *I2Cx);
void I2C_WriteNbyte(u8 dev_addr, u8 mem_addr, u8 *p, u8 number);
void I2C_ReadNbyte(u8 dev_addr, u8 mem_addr, u8 *p, u8 number);
u8 Get_MSBusy_Status(void);
void SendCmdData(u8 cmd, u8 dat);

#endif


#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_I2C_H_ */
