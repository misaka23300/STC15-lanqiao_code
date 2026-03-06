/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺫﻝﺗﻳﺻ۹ﺿﻌﺏﮊﺷﮨﻅﺷﮌﺗﺽﺣﺑﺯﺑﻲﺡﻣ,ﮄﻣﺿﻌﺏﮊﺷﮨﻅﺷﻉ۱ﺣﺊﮌﺗﺽﺣﭼﺯSTCﭖﺥﻉﮌﭼﺵﺙﺍﺏﮊﺷﮨ            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_SPI_H
#define	__STC32G_SPI_H

#include	"FreeRTOS.h"

//========================================================================
//                               SPIﺭﻟﻅﺣ
//========================================================================

#define		SPI_SSIG_Set(n)					SSIG = n		/* SSﺻﮮﺛﺧﺗ۵ﺥﻎﺟﻊﻅﺩ */
#define		SPI_Start(n)						SPEN = n		/* SPIﮌﺗﺥﻎﺟﻊﻅﺩﺳﭨ */
#define		SPI_FirstBit_Set(n)			DORD = n		/* ﮌﮮﺝﻏﺓ۱ﺯﺱ/ﺛﺽﮌﻁﺯﺏﺷﮨ MSB/LSB */
#define		SPI_Mode_Set(n)					MSTR = n		/* SPIﻅﺊﺑﺽﺥ۲ﮌﺛﺭﻟﻅﺣ */
#define		SPI_CPOL_Set(n)					CPOL = n		/* SPIﮌﺎﻅﺽﺙ،ﺷﺿﺟﻊﻅﺩ */
#define		SPI_CPHA_Set(n)					CPHA = n		/* SPIﮌﺎﻅﺽﺵﻓﺳﭨﺟﻊﻅﺩ */
#define		SPI_Clock_Select(n)			SPCTL = (SPCTL & ~0x03) | (n)					/* SPIﮌﺎﻅﺽﺩﭖﺡﮌﺹ۰ﺿﮦ */

#define		SPI_ClearFlag()					{SPIF = 1; WCOL = 1;}		/* ﺷﺑ 1 ﮄﮒﺏﮮ SPIFﭦﺱWCOL ﺎﻡﻅﺝ */

#define		HSSPI_Enable(n)					HSSPI_CFG2 |= 0x20       //ﮌﺗﺥﻎSPIﺕﻑﺯﻋﺥ۲ﮌﺛ
#define		HSSPI_Disable(n)				HSSPI_CFG2 &= ~0x20      //ﺗﻊﺎﻁSPIﺕﻑﺯﻋﺥ۲ﮌﺛ

//========================================================================
//                              ﭘ۷ﺻﮒﺭﻱﺣﺊ
//========================================================================

#define	SPI_BUF_LENTH	64
#define	SPI_BUF_type	edata

sbit  SPI_SS    = P1^2;
sbit  SPI_MOSI  = P1^3;
sbit  SPI_MISO  = P1^4;
sbit  SPI_SCLK  = P1^5;

sbit  SPI_SS_2    = P2^2;
sbit  SPI_MOSI_2  = P2^3;
sbit  SPI_MISO_2  = P2^4;
sbit  SPI_SCLK_2  = P2^5;

sbit  SPI_SS_3    = P7^4;
sbit  SPI_MOSI_3  = P7^5;
sbit  SPI_MISO_3  = P7^6;
sbit  SPI_SCLK_3  = P7^7;

sbit  SPI_SS_4    = P3^5;
sbit  SPI_MOSI_4  = P3^4;
sbit  SPI_MISO_4  = P3^3;
sbit  SPI_SCLK_4  = P3^2;

#define	SPI_Mode_Master		1
#define	SPI_Mode_Slave		0
#define	SPI_CPOL_High		1
#define	SPI_CPOL_Low		0
#define	SPI_CPHA_1Edge		0
#define	SPI_CPHA_2Edge		1
#define	SPI_Speed_4			0
#define	SPI_Speed_8			1
#define	SPI_Speed_16		2
#define	SPI_Speed_32		3
#define	SPI_Speed_2			3
#define	SPI_MSB				0
#define	SPI_LSB				1

typedef struct
{
	uint8_t	SPI_Enable;		//SPIﺩﮪﭘﺁ, ENABLE,DISABLE
	uint8_t	SPI_SSIG;		//ﺩ؛ﺹ۰ﺳﭨ, ENABLE(SSﺫﺓﭘ۷ﻅﺊﭨﻲﺑﺽﭨﻲ), DISABLE(ﭦﺉﺡﺿSSﺻﮮﺛﺧﺗ۵ﺥﻎ)
	uint8_t	SPI_FirstBit;	//SPI_MSB, SPI_LSB
	uint8_t	SPI_Mode;		//SPI_Mode_Master, SPI_Mode_Slave
	uint8_t	SPI_CPOL;		//SPI_CPOL_High,   SPI_CPOL_Low
	uint8_t	SPI_CPHA;		//SPI_CPHA_1Edge,  SPI_CPHA_2Edge
	uint8_t	SPI_Speed;		//SPI_Speed_4,SPI_Speed_16,SPI_Speed_64,SPI_Speed_128
} SPI_InitTypeDef;


extern	bit B_SPI_Busy; //ﺓ۱ﺯﺱﺣ۵ﺎﻡﻅﺝ
extern	uint8_t 	SPI_RxCnt;
extern	uint8_t 	SPI_RxTimerOut;
extern	uint8_t 	SPI_BUF_type SPI_RxBuffer[SPI_BUF_LENTH];


void	SPI_Init(SPI_InitTypeDef *SPIx);
void	SPI_SetMode(uint8_t mode);
void	SPI_WriteByte(uint8_t dat);
uint8_t SPI_ReadByte(void);

#endif

