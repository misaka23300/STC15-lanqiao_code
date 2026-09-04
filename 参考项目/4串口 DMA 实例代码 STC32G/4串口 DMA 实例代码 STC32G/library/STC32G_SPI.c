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

#include	"STC32G_SPI.h"

u8 	SPI_RxTimerOut;
u8 	SPI_BUF_type SPI_RxBuffer[SPI_BUF_LENTH];
bit B_SPI_Busy; //·¢ËÍÃ¦±êÖ¾


//========================================================================
// º¯Êý: void	SPI_Init(SPI_InitTypeDef *SPIx)
// ÃèÊö: SPI³õÊ¼»¯³ÌÐò.
// ²ÎÊý: SPIx: ½á¹¹²ÎÊý,Çë²Î¿¼spi.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2012-11-22
//========================================================================
void	SPI_Init(SPI_InitTypeDef *SPIx)
{
	if(SPIx->SPI_SSIG == ENABLE)			SSIG = 0; 	//enable SS, conform Master or Slave by SS pin.
	else									SSIG = 1; 	//disable SS, conform Master or Slave by SPI_Mode
	SPI_Start(SPIx->SPI_Enable);
	SPI_FirstBit_Set(SPIx->SPI_FirstBit);
	SPI_Mode_Set(SPIx->SPI_Mode);
	SPI_CPOL_Set(SPIx->SPI_CPOL);
	SPI_CPHA_Set(SPIx->SPI_CPHA);
	SPI_Clock_Select(SPIx->SPI_Speed);
	
	SPI_RxTimerOut = 0;
	B_SPI_Busy = 0;
}

//========================================================================
// º¯Êý: void SPI_SetMode(u8 mode)
// ÃèÊö: SPIÉèÖÃÖ÷´ÓÄ£Ê½º¯Êý.
// ²ÎÊý: mode: Ö¸¶¨Ä£Ê½, È¡Öµ SPI_Mode_Master »ò SPI_Mode_Slave.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2012-11-22
//========================================================================
void SPI_SetMode(u8 mode)
{
	if(mode == SPI_Mode_Slave)
	{
		MSTR = 0; 	//ÖØÐÂÉèÖÃÎª´Ó»ú´ý»ú
		SSIG = 0; 	//SSÒý½ÅÈ·¶¨Ö÷´Ó
	}
	else
	{
		MSTR = 1; 	//Ê¹ÄÜ SPI Ö÷»úÄ£Ê½
		SSIG = 1; 	//ºöÂÔSSÒý½Å¹¦ÄÜ
	}
}

//========================================================================
// º¯Êý: void SPI_WriteByte(u8 dat)
// ÃèÊö: SPI·¢ËÍÒ»¸ö×Ö½ÚÊý¾Ý.
// ²ÎÊý: dat: Òª·¢ËÍµÄÊý¾Ý.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2020-09-14
//========================================================================
void SPI_WriteByte(u8 dat)		//SPI·¢ËÍÒ»¸ö×Ö½ÚÊý¾Ý
{
	if(ESPI)
	{
		B_SPI_Busy = 1;
		SPDAT = dat;
		while(B_SPI_Busy);  //ÖÐ¶ÏÄ£Ê½
	}
	else
	{
		SPDAT = dat;
		while(SPIF == 0); //²éÑ¯Ä£Ê½
		SPI_ClearFlag();   //Çå³ýSPIFºÍWCOL±êÖ¾
	}
}

//========================================================================
// º¯Êý: void SPI_ReadByte(u8 dat)
// ÃèÊö: SPI²éÑ¯Ä£Ê½¶ÁÈ¡Ò»¸ö×Ö½ÚÊý¾Ý.
// ²ÎÊý: none.
// ·µ»Ø: ¶ÁÈ¡µÄÊý¾Ý.
// °æ±¾: V1.0, 2020-09-14
//========================================================================
u8 SPI_ReadByte(void)
{
	SPDAT = 0xff;
	while(SPIF == 0) ;
	SPI_ClearFlag();   //Çå0 SPIFºÍWCOL±êÖ¾
	return (SPDAT);
}
