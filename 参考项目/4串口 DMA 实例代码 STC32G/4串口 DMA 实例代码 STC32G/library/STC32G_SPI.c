/**
 * @file STC32G_SPI.c
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

#include	"STC32G_SPI.h"

u8 	SPI_RxTimerOut;
u8 	SPI_BUF_type SPI_RxBuffer[SPI_BUF_LENTH];
bit B_SPI_Busy; //æ־

//========================================================================
// : void	SPI_Init( SPI_InitTypeDef *SPIx )
// : SPIʼ.
// : SPIx: ṹ,οspi.hĶ.
// : none.
// 汾: V1.0, 2012 - 1 - 2
//========================================================================
void	SPI_Init( SPI_InitTypeDef *SPIx )
{
	if ( SPIx->SPI_SSIG == ENABLE )			SSIG = 0; 	//enable SS, conform Master or Slave by SS pin.
	else									SSIG = 1; 	//disable SS, conform Master or Slave by SPI_Mode
	SPI_Start( SPIx->SPI_Enable );
	SPI_FirstBit_Set( SPIx->SPI_FirstBit );
	SPI_Mode_Set( SPIx->SPI_Mode );
	SPI_CPOL_Set( SPIx->SPI_CPOL );
	SPI_CPHA_Set( SPIx->SPI_CPHA );
	SPI_Clock_Select( SPIx->SPI_Speed );
	
	SPI_RxTimerOut = 0;
	B_SPI_Busy = 0;
}

//========================================================================
// : void SPI_SetMode( u8 mode )
// : SPIģʽ.
// : mode: ָģʽ, ȡֵ SPI_Mode_Master  SPI_Mode_Slave.
// : none.
// 汾: V1.0, 2012 - 1 - 2
//========================================================================
void SPI_SetMode( u8 mode )
{
	if ( mode == SPI_Mode_Slave )
	{
		MSTR = 0; 	//Ϊӻ
		SSIG = 0; 	//SSȷ
	}
	else
	{
		MSTR = 1; 	//ʹ SPI ģʽ
		SSIG = 1; 	//SSŹ
	}
}

//========================================================================
// : void SPI_WriteByte( u8 dat )
// : SPIһֽ.
// : dat: Ҫ͵.
// : none.
// 汾: V1.0, 2020 - 9 - 4
//========================================================================
void SPI_WriteByte( u8 dat )		//SPIһֽ
{
	if ( ESPI )
	{
		B_SPI_Busy = 1;
		SPDAT = dat;
		while ( B_SPI_Busy );  //жģʽ
	}
	else
	{
		SPDAT = dat;
		while ( SPIF == 0 ); //ѯģʽ
		SPI_ClearFlag();   //SPIFWCOL־
	}
}

//========================================================================
// : void SPI_ReadByte( u8 dat )
// : SPIѯģʽȡһֽ.
// : none.
// : ȡ.
// 汾: V1.0, 2020 - 9 - 4
//========================================================================
u8 SPI_ReadByte( void )
{
	SPDAT = 0xff;
	while ( SPIF == 0 ) ;
	SPI_ClearFlag();   //0 SPIFWCOL־
	return ( SPDAT );
}
