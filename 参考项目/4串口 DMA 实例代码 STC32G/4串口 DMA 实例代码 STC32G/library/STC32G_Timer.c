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

#include	"STC32G_Timer.h"

//========================================================================
// º¯Êý: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// ÃèÊö: ¶¨Ê±Æ÷³õÊ¼»¯³ÌÐò.
// ²ÎÊý: TIMx: ½á¹¹²ÎÊý,Çë²Î¿¼timer.hÀïµÄ¶¨Òå.
// ·µ»Ø: ³É¹¦·µ»Ø SUCCESS, ´íÎó·µ»Ø FAIL.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
{
	if(TIM == Timer0)
	{
		Timer0_Stop();		//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return FAIL;	//´íÎó
		TMOD = (TMOD & ~0x03) | TIMx->TIM_Mode;	//¹¤×÷Ä£Ê½,0: 16Î»×Ô¶¯ÖØ×°, 1: 16Î»¶¨Ê±/¼ÆÊý, 2: 8Î»×Ô¶¯ÖØ×°, 3: ²»¿ÉÆÁ±Î16Î»×Ô¶¯ÖØ×°
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return FAIL;
		Timer0_CLK_Select(TIMx->TIM_ClkSource);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ, ¶¨Ê±12T/1T
		Timer0_CLK_Output(TIMx->TIM_ClkOut);		//Êä³öÊ±ÖÓÊ¹ÄÜ
		T0_Load(TIMx->TIM_Value);
		Timer0_Run(TIMx->TIM_Run);
		return	SUCCESS;		//³É¹¦
	}

	if(TIM == Timer1)
	{
		Timer1_Stop();		//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return FAIL;	//´íÎó
		TMOD = (TMOD & ~0x30) | (TIMx->TIM_Mode << 4);	//¹¤×÷Ä£Ê½,0: 16Î»×Ô¶¯ÖØ×°, 1: 16Î»¶¨Ê±/¼ÆÊý, 2: 8Î»×Ô¶¯ÖØ×°, 3: Í£Ö¹¹¤×÷
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return FAIL;
		Timer1_CLK_Select(TIMx->TIM_ClkSource);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ, ¶¨Ê±12T/1T
		Timer1_CLK_Output(TIMx->TIM_ClkOut);		//Êä³öÊ±ÖÓÊ¹ÄÜ
		T1_Load(TIMx->TIM_Value);
		Timer1_Run(TIMx->TIM_Run);
		return	SUCCESS;		//³É¹¦
	}

	if(TIM == Timer2)		//Timer2,¹Ì¶¨Îª16Î»×Ô¶¯ÖØ×°, ÖÐ¶ÏÎÞÓÅÏÈ¼¶
	{
		Timer2_Stop();	//Í£Ö¹¼ÆÊý
		Timer2_CLK_Select(TIMx->TIM_ClkSource);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ, ¶¨Ê±12T/1T
		Timer2_CLK_Output(TIMx->TIM_ClkOut);		//Êä³öÊ±ÖÓÊ¹ÄÜ

		T2_Load(TIMx->TIM_Value);
		Timer2_Run(TIMx->TIM_Run);
		return	SUCCESS;		//³É¹¦
	}

	if(TIM == Timer3)		//Timer3,¹Ì¶¨Îª16Î»×Ô¶¯ÖØ×°, ÖÐ¶ÏÎÞÓÅÏÈ¼¶
	{
		Timer3_Stop();	//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return FAIL;
		Timer3_CLK_Select(TIMx->TIM_ClkSource);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ, ¶¨Ê±12T/1T
		Timer3_CLK_Output(TIMx->TIM_ClkOut);		//Êä³öÊ±ÖÓÊ¹ÄÜ

		T3_Load(TIMx->TIM_Value);
		Timer3_Run(TIMx->TIM_Run);
		return	SUCCESS;		//³É¹¦
	}

	if(TIM == Timer4)		//Timer3,¹Ì¶¨Îª16Î»×Ô¶¯ÖØ×°, ÖÐ¶ÏÎÞÓÅÏÈ¼¶
	{
		Timer4_Stop();	//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return FAIL;
		Timer4_CLK_Select(TIMx->TIM_ClkSource);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ, ¶¨Ê±12T/1T
		Timer4_CLK_Output(TIMx->TIM_ClkOut);		//Êä³öÊ±ÖÓÊ¹ÄÜ

		T4_Load(TIMx->TIM_Value);
		Timer4_Run(TIMx->TIM_Run);
		return	SUCCESS;		//³É¹¦
	}
	return FAIL;	//´íÎó
}
