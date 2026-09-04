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

#include	"STC32G_GPIO.h"

//========================================================================
// º¯Êý: u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
// ÃèÊö: ³õÊ¼»¯IO¿Ú.
// ²ÎÊý: GPIOx: ½á¹¹²ÎÊý,Çë²Î¿¼timer.hÀïµÄ¶¨Òå.
// ·µ»Ø: ³É¹¦·µ»Ø SUCCESS, ´íÎó·µ»Ø FAIL.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx)
{
	if(GPIO > GPIO_P7)				return FAIL;	//´íÎó
	if(GPIOx->Mode > GPIO_OUT_PP)	return FAIL;	//´íÎó
	if(GPIO == GPIO_P0)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P0M1 &= ~GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P0M1 |=  GPIOx->Pin,	P0M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P0M1 |=  GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P0M1 &= ~GPIOx->Pin,	P0M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P1)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P1M1 &= ~GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P1M1 |=  GPIOx->Pin,	P1M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P1M1 |=  GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P1M1 &= ~GPIOx->Pin,	P1M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P2)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P2M1 &= ~GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P2M1 |=  GPIOx->Pin,	P2M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P2M1 |=  GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P2M1 &= ~GPIOx->Pin,	P2M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P3)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P3M1 &= ~GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P3M1 |=  GPIOx->Pin,	P3M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P3M1 |=  GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P3M1 &= ~GPIOx->Pin,	P3M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P4)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P4M1 &= ~GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P4M1 |=  GPIOx->Pin,	P4M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P4M1 |=  GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P4M1 &= ~GPIOx->Pin,	P4M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P5)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P5M1 &= ~GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P5M1 |=  GPIOx->Pin,	P5M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P5M1 |=  GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P5M1 &= ~GPIOx->Pin,	P5M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P6)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P6M1 &= ~GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P6M1 |=  GPIOx->Pin,	P6M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P6M1 |=  GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P6M1 &= ~GPIOx->Pin,	P6M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	if(GPIO == GPIO_P7)
	{
		if(GPIOx->Mode == GPIO_PullUp)		P7M1 &= ~GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //ÉÏÀ­×¼Ë«Ïò¿Ú
		if(GPIOx->Mode == GPIO_HighZ)			P7M1 |=  GPIOx->Pin,	P7M0 &= ~GPIOx->Pin;	 //¸¡¿ÕÊäÈë
		if(GPIOx->Mode == GPIO_OUT_OD)		P7M1 |=  GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //¿ªÂ©Êä³ö
		if(GPIOx->Mode == GPIO_OUT_PP)		P7M1 &= ~GPIOx->Pin,	P7M0 |=  GPIOx->Pin;	 //ÍÆÍìÊä³ö
	}
	return SUCCESS;	//³É¹¦
}
