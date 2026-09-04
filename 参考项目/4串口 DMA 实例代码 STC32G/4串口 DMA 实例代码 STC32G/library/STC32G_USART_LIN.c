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

#include "STC32G_UART.h"
#include "STC32G_USART_LIN.h"

//========================================================================
//                               ±¾µØ±äÁ¿ÉùÃ÷
//========================================================================

//========================================================================
// º¯Êý: void UsartLinSendByte(u8 USARTx, u8 dat)
// ÃèÊö: ·¢ËÍÒ»¸ö×Ö½Úº¯Êý¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: dat: ·¢ËÍµÄÊý¾Ý.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2021-10-28
// ±¸×¢: 
//========================================================================
void UsartLinSendByte(u8 USARTx, u8 dat)
{
	if(USARTx == USART1)
	{
		COM1.B_TX_busy = 1;
		SBUF = dat;
		while(COM1.B_TX_busy);
	}
	else if(USARTx == USART2)
	{
		COM2.B_TX_busy = 1;
		S2BUF = dat;
		while(COM2.B_TX_busy);
	}
}

//========================================================================
// º¯Êý: void UsartLinSendData(u8 USARTx, u8 *pdat, u8 len)
// ÃèÊö: Lin·¢ËÍÊý¾Ýº¯Êý¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: *pdat: ·¢ÉúÊý¾Ý»º³åÇø
// ²ÎÊý: len: Êý¾Ý³¤¶È.
// ·µ»Ø: Lin ID.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2023-4-15
// ±¸×¢: 
//========================================================================
void UsartLinSendData(u8 USARTx, u8 *pdat, u8 len)
{
	u8 i;

    if(len > 8) return; 
	for(i=0;i<len;i++)
	{
		UsartLinSendByte(USARTx,pdat[i]);
	}
}

//========================================================================
// º¯Êý: void UsartLinSendChecksum(u8 USARTx, u8 *dat, u8 len)
// ÃèÊö: ¼ÆËãÐ£ÑéÂë²¢·¢ËÍ¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: *dat: Êý¾Ý³¡´«ÊäµÄÊý¾Ý
// ²ÎÊý: len: Êý¾Ý³¤¶È.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2023-4-15
// ±¸×¢: 
//========================================================================
void UsartLinSendChecksum(u8 USARTx, u8 *dat, u8 len)
{
    u16 sum = 0;
    u8 i;

    if(len > 8) return; 
    for(i = 0; i < len; i++)
    {
        sum += dat[i];
        if(sum & 0xFF00)
        {
            sum = (sum & 0x00FF) + 1;
        }
    }
    sum ^= 0x00FF;
	UsartLinSendByte(USARTx,(u8)sum);
}

//========================================================================
// º¯Êý: void UsartSendBreak(u8 USARTx)
// ÃèÊö: Ö÷Ä£Ê½·¢ËÍLin×ÜÏßBreakº¯Êý¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2021-10-28
// ±¸×¢: 
//========================================================================
void UsartSendBreak(u8 USARTx)
{
	if(USARTx == USART1)
	{
		USARTCR5 |= 0x04;		//Ö÷Ä£Ê½ Send Break
	}
	else if(USARTx == USART2)
	{
		USART2CR5 |= 0x04;		//Ö÷Ä£Ê½ Send Break
	}
	UsartLinSendByte(USARTx,0x00);
}

//========================================================================
// º¯Êý: void UsartLinSendPID(u8 USARTx, u8 id)
// ÃèÊö: IDÂë¼ÓÉÏÐ£Ñé·û£¬×ª³ÉPIDÂë²¢·¢ËÍ¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: IDÂë.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2020-12-2
// ±¸×¢: 
//========================================================================
void UsartLinSendPID(u8 USARTx, u8 id)
{
	u8 P0 ;
	u8 P1 ;
	
	P0 = (((id)^(id>>1)^(id>>2)^(id>>4))&0x01)<<6 ;
	P1 = ((~((id>>1)^(id>>3)^(id>>4)^(id>>5)))&0x01)<<7 ;
	
	UsartLinSendByte(USARTx,id|P0|P1);
}

//========================================================================
// º¯Êý: void UsartLinSendHeader(u8 USARTx, u8 lid)
// ÃèÊö: LinÖ÷»ú·¢ËÍÖ¡Í·º¯Êý¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: IDÂë.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2021-10-28
// ±¸×¢: 
//========================================================================
void UsartLinSendHeader(u8 USARTx, u8 lid)
{
	UsartSendBreak(USARTx);						//Send Break
	UsartLinSendByte(USARTx,0x55);		//Send Sync Field
	UsartLinSendPID(USARTx,lid);			//ÉèÖÃ×ÜÏßID
}

//========================================================================
// º¯Êý: void UsartLinSendFrame(u8 USARTx, u8 lid, u8 *pdat, u8 len)
// ÃèÊö: LinÖ÷»ú·¢ËÍÍêÕûÖ¡º¯Êý¡£
// ²ÎÊý: USARTx: USART×éºÅ£¬È¡Öµ£ºUSART1»òÕßUSART2
// ²ÎÊý: lid: Lin ID
// ²ÎÊý: *pdat: ·¢ËÍÊý¾Ý»º³åÇø
// ²ÎÊý: len: Êý¾Ý³¤¶È
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2021-10-28
// ±¸×¢: 
//========================================================================
void UsartLinSendFrame(u8 USARTx, u8 lid, u8 *pdat, u8 len)
{
	UsartSendBreak(USARTx);						//Send Break
	UsartLinSendByte(USARTx,0x55);		//Send Sync Field

	UsartLinSendPID(USARTx,lid);			//ÉèÖÃ×ÜÏßID
	UsartLinSendData(USARTx,pdat,len);
	UsartLinSendChecksum(USARTx,pdat,len);
}

//========================================================================
// º¯Êý: void UsartLinBaudrate(u8 USARTx, u16 brt)
// ÃèÊö: Lin×ÜÏß²¨ÌØÂÊÉèÖÃº¯Êý¡£
// ²ÎÊý: brt: ²¨ÌØÂÊ.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2021-10-28
// ±¸×¢: 
//========================================================================
void UsartLinBaudrate(u8 USARTx, u16 brt)
{
	u16 tmp;
	
	tmp = (MAIN_Fosc >> 4) / brt;
	if(USARTx == USART1)
	{
		USARTBRH = (u8)(tmp>>8);
		USARTBRL = (u8)tmp;
	}
	else if(USARTx == USART2)
	{
		USART2BRH = (u8)(tmp>>8);
		USART2BRL = (u8)tmp;
	}
}

//========================================================================
// º¯Êý: UASRT_LIN_Configuration
// ÃèÊö: USART LIN³õÊ¼»¯³ÌÐò.
// ²ÎÊý: USARTx: UART×éºÅ, USART LIN½á¹¹²ÎÊý,Çë²Î¿¼STC32G_USART_LIN.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-30
//========================================================================
u8 UASRT_LIN_Configuration(u8 USARTx, USARTx_LIN_InitDefine *USART)
{
	if(USARTx == USART1)
	{
		SCON = (SCON & 0x3f) | 0x40;    //USART1Ä£Ê½, 0x00: Í¬²½ÒÆÎ»Êä³ö, 0x40: 8Î»Êý¾Ý,¿É±ä²¨ÌØÂÊ, 0x80: 9Î»Êý¾Ý,¹Ì¶¨²¨ÌØÂÊ, 0xc0: 9Î»Êý¾Ý,¿É±ä²¨ÌØÂÊ
		SMOD = 1;
		TI = 0;
		REN = 1;    //ÔÊÐí½ÓÊÕ
		ES  = 1;    //ÔÊÐíÖÐ¶Ï

		if(USART->LIN_Enable == ENABLE)	USARTCR1 |= 0x80;		//Ê¹ÄÜLINÄ£¿é
		else								USARTCR1 &= ~0x80;		//¹Ø±ÕLINÄ£¿é
		if(USART->LIN_Mode == LinSlaveMode)	USARTCR5 |= 0x20;		//LINÄ£¿é´Ó»úÄ£Ê½
		else								USARTCR5 &= ~0x20;		//LINÄ£¿éÖ÷»úÄ£Ê½
		if(USART->LIN_AutoSync == ENABLE)	USARTCR5 |= 0x10;		//Ê¹ÄÜ×Ô¶¯Í¬²½
		else								USARTCR5 &= ~0x10;		//¹Ø±Õ×Ô¶¯Í¬²½

		UsartLinBaudrate(USART1,USART->LIN_Baudrate);			//ÉèÖÃ²¨ÌØÂÊ

		return SUCCESS;
	}

	if(USARTx == USART2)
	{
		S2CON = (S2CON & 0x3f) | 0x50;
		T2x12 = 1;   //¶¨Ê±Æ÷2Ê±ÖÓ1TÄ£Ê½
		T2R = 1;     //¿ªÊ¼¼ÆÊ±
		ES2 = 1;     //ÔÊÐíÖÐ¶Ï
		S2CFG |= 0x80;				//S2MOD = 1

		if(USART->LIN_Enable == ENABLE)	USART2CR1 |= 0x80;		//Ê¹ÄÜLINÄ£¿é
		else								USART2CR1 &= ~0x80;		//¹Ø±ÕLINÄ£¿é
		if(USART->LIN_Mode == LinSlaveMode)	USART2CR5 |= 0x20;		//LINÄ£¿é´Ó»úÄ£Ê½
		else								USART2CR5 &= ~0x20;		//LINÄ£¿éÖ÷»úÄ£Ê½
		if(USART->LIN_AutoSync == ENABLE)	USART2CR5 |= 0x10;		//Ê¹ÄÜ×Ô¶¯Í¬²½
		else								USART2CR5 &= ~0x10;		//¹Ø±Õ×Ô¶¯Í¬²½

		UsartLinBaudrate(USART2,USART->LIN_Baudrate);			//ÉèÖÃ²¨ÌØÂÊ

		return SUCCESS;
	}
	return FAIL;	//´íÎó
}

/*********************************************************/
