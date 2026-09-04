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

#include "STC32G_PWM.h"

//========================================================================
// º¯Êý: PWM_Configuration
// ÃèÊö: PWM³õÊ¼»¯³ÌÐò.
// ²ÎÊý: PWMx: ½á¹¹²ÎÊý,Çë²Î¿¼PWM.hÀïµÄ¶¨Òå.
// ·µ»Ø: ³É¹¦·µ»Ø SUCCESS, ´íÎó·µ»Ø FAIL.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
u8 PWM_Configuration(u8 PWM, PWMx_InitDefine *PWMx)
{
	if(PWM == PWM1)
	{
		PWMA_CC1E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMA_CC1NE_Disable();		//¹Ø±Õ±È½ÏÊä³ö
		PWMA_CC1S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMA_OC1ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO1P)
		{
			PWMA_CC1E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO1P;
		}
		else
		{
			PWMA_CC1E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO1P;
		}
		if(PWMx->PWM_EnoSelect & ENO1N)
		{
			PWMA_CC1NE_Enable();		//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO1N;
		}
		else
		{
			PWMA_CC1NE_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO1N;
		}
		
		PWMA_Duty1(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM2)
	{
		PWMA_CC2E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMA_CC2NE_Disable();		//¹Ø±Õ±È½ÏÊä³ö
		PWMA_CC2S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMA_OC2ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO2P)
		{
			PWMA_CC2E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO2P;
		}
		else
		{
			PWMA_CC2E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO2P;
		}
		if(PWMx->PWM_EnoSelect & ENO2N)
		{
			PWMA_CC2NE_Enable();		//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO2N;
		}
		else
		{
			PWMA_CC2NE_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO2N;
		}
		
		PWMA_Duty2(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM3)
	{
		PWMA_CC3E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMA_CC3NE_Disable();		//¹Ø±Õ±È½ÏÊä³ö
		PWMA_CC3S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMA_OC3ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO3P)
		{
			PWMA_CC3E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO3P;
		}
		else
		{
			PWMA_CC3E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO3P;
		}
		if(PWMx->PWM_EnoSelect & ENO3N)
		{
			PWMA_CC3NE_Enable();		//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO3N;
		}
		else
		{
			PWMA_CC3NE_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO3N;
		}
		
		PWMA_Duty3(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM4)
	{
		PWMA_CC4E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMA_CC4NE_Disable();		//¹Ø±Õ±È½ÏÊä³ö
		PWMA_CC4S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMA_OC4ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO4P)
		{
			PWMA_CC4E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO4P;
		}
		else
		{
			PWMA_CC4E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO4P;
		}
		if(PWMx->PWM_EnoSelect & ENO4N)
		{
			PWMA_CC4NE_Enable();		//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO |= ENO4N;
		}
		else
		{
			PWMA_CC4NE_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMA_ENO &= ~ENO4N;
		}
		
		PWMA_Duty4(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWMA)
	{
//		PWMA_OC1_ReloadEnable(PWMx->PWM_Reload);	//Êä³ö±È½ÏµÄÔ¤×°ÔØÊ¹ÄÜ
//		PWMA_OC1_FastEnable(PWMx->PWM_Fast);		//Êä³ö±È½Ï¿ìËÙ¹¦ÄÜÊ¹ÄÜ
//		PWMA_CCPCAPreloaded(PWMx->PWM_PreLoad);	//²¶»ñ/±È½ÏÔ¤×°ÔØ¿ØÖÆÎ»(¸ÃÎ»Ö»¶Ô¾ßÓÐ»¥²¹Êä³öµÄÍ¨µÀÆð×÷ÓÃ)
//		PWMA_BrakeEnable(PWMx->PWM_BrakeEnable);	//¿ªÆô/½ûÖ¹É²³µÊäÈë

		PWMA_DeadTime(PWMx->PWM_DeadTime);	//ËÀÇø·¢ÉúÆ÷ÉèÖÃ
		PWMA_AutoReload(PWMx->PWM_Period);	//ÖÜÆÚÉèÖÃ
		PWMA_BrakeOutputEnable(PWMx->PWM_MainOutEnable);	//Ö÷Êä³öÊ¹ÄÜ
		PWMA_CEN_Enable(PWMx->PWM_CEN_Enable);	//Ê¹ÄÜ¼ÆÊýÆ÷
		return	SUCCESS;
	}

	if(PWM == PWM5)
	{
		PWMB_CC5E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMB_CC5S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMB_OC5ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO5P)
		{
			PWMB_CC5E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO |= ENO5P;
		}
		else
		{
			PWMB_CC5E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO &= ~ENO5P;
		}
		
		PWMB_Duty5(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM6)
	{
		PWMB_CC6E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMB_CC6S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMB_OC6ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO6P)
		{
			PWMB_CC6E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO |= ENO6P;
		}
		else
		{
			PWMB_CC6E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO &= ~ENO6P;
		}
		
		PWMB_Duty6(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM7)
	{
		PWMB_CC7E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMB_CC7S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMB_OC7ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO7P)
		{
			PWMB_CC7E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO |= ENO7P;
		}
		else
		{
			PWMB_CC7E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO &= ~ENO7P;
		}
		
		PWMB_Duty7(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWM8)
	{
		PWMB_CC8E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
		PWMB_CC8S_Direction(CCAS_OUTPUT);		//CCnS½öÔÚÍ¨µÀ¹Ø±ÕÊ±²ÅÊÇ¿ÉÐ´µÄ
		PWMB_OC8ModeSet(PWMx->PWM_Mode);		//ÉèÖÃÊä³ö±È½ÏÄ£Ê½

		if(PWMx->PWM_EnoSelect & ENO8P)
		{
			PWMB_CC8E_Enable();			//¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO |= ENO8P;
		}
		else
		{
			PWMB_CC8E_Disable();		//¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
			PWMB_ENO &= ~ENO8P;
		}
		
		PWMB_Duty8(PWMx->PWM_Duty);
		return	SUCCESS;
	}
	
	if(PWM == PWMB)
	{
//		PWMB_OC5_ReloadEnable(PWMx->PWM_Reload);	//Êä³ö±È½ÏµÄÔ¤×°ÔØÊ¹ÄÜ
//		PWMB_OC5_FastEnable(PWMx->PWM_Fast);		//Êä³ö±È½Ï¿ìËÙ¹¦ÄÜÊ¹ÄÜ
//		PWMB_CCPCBPreloaded(PWMx->PWM_PreLoad);	//²¶»ñ/±È½ÏÔ¤×°ÔØ¿ØÖÆÎ»(¸ÃÎ»Ö»¶Ô¾ßÓÐ»¥²¹Êä³öµÄÍ¨µÀÆð×÷ÓÃ)
//		PWMB_BrakeEnable(PWMx->PWM_BrakeEnable);	//¿ªÆô/½ûÖ¹É²³µÊäÈë

		PWMB_DeadTime(PWMx->PWM_DeadTime);	//ËÀÇø·¢ÉúÆ÷ÉèÖÃ
		PWMB_AutoReload(PWMx->PWM_Period);	//ÖÜÆÚÉèÖÃ
		PWMB_BrakeOutputEnable(PWMx->PWM_MainOutEnable);	//Ö÷Êä³öÊ¹ÄÜ
		PWMB_CEN_Enable(PWMx->PWM_CEN_Enable);	//Ê¹ÄÜ¼ÆÊýÆ÷
		return	SUCCESS;
	}

	return	FAIL;	//´íÎó
}

//========================================================================
// º¯Êý: UpdatePwm
// ÃèÊö: PWMÕ¼¿Õ±È¸üÐÂ³ÌÐò.
// ²ÎÊý: PWM: PWMÍ¨µÀ/×éºÅ, PWMx½á¹¹²ÎÊý,Çë²Î¿¼PWM.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
void UpdatePwm(u8 PWM, PWMx_Duty *PWMx)
{
	switch(PWM)
	{
		case PWM1:
			PWMA_Duty1(PWMx->PWM1_Duty);
		break;

		case PWM2:
			PWMA_Duty2(PWMx->PWM2_Duty);
		break;

		case PWM3:
			PWMA_Duty3(PWMx->PWM3_Duty);
		break;

		case PWM4:
			PWMA_Duty4(PWMx->PWM4_Duty);
		break;

		case PWM5:
			PWMB_Duty5(PWMx->PWM5_Duty);
		break;

		case PWM6:
			PWMB_Duty6(PWMx->PWM6_Duty);
		break;

		case PWM7:
			PWMB_Duty7(PWMx->PWM7_Duty);
		break;

		case PWM8:
			PWMB_Duty8(PWMx->PWM8_Duty);
		break;

		case PWMA:
			PWMA_Duty1(PWMx->PWM1_Duty);
			PWMA_Duty2(PWMx->PWM2_Duty);
			PWMA_Duty3(PWMx->PWM3_Duty);
			PWMA_Duty4(PWMx->PWM4_Duty);
		break;

		case PWMB:
			PWMB_Duty5(PWMx->PWM5_Duty);
			PWMB_Duty6(PWMx->PWM6_Duty);
			PWMB_Duty7(PWMx->PWM7_Duty);
			PWMB_Duty8(PWMx->PWM8_Duty);
		break;
	}
}

//========================================================================
// º¯Êý: ReadPWMA(void)
// ÃèÊö: Òì²½¶ÁÈ¡PWMAÌØÊâ¹¦ÄÜ¼Ä´æÆ÷º¯Êý. 
// ²ÎÊý: addr: ¶ÁÈ¡ÌØÊâ¹¦ÄÜ¼Ä´æÆ÷µØÖ·.
// ·µ»Ø: dat:  ¶ÁÈ¡ÌØÊâ¹¦ÄÜ¼Ä´æÆ÷ÄÚÈÝ.
// °æ±¾: V1.0, 2022-03-16
//========================================================================
u8 ReadPWMA(u8 addr)
{
	u8 dat;
	
	while (HSPWMA_ADR &	0x80); //µÈ´ýÇ°Ò»¸öÒì²½¶ÁÐ´Íê³É
	HSPWMA_ADR = addr |	0x80;  //ÉèÖÃ¼ä½Ó·ÃÎÊµØÖ·,Ö»ÐèÒªÉèÖÃÔ­XFRµØÖ·µÄµÍ7Î»
								//HSPWMA_ADDR¼Ä´æÆ÷µÄ×î¸ßÎ»Ð´1,±íÊ¾¶ÁÊý¾Ý
	while (HSPWMA_ADR &	0x80); //µÈ´ýµ±Ç°Òì²½¶ÁÈ¡Íê³É
	dat	= HSPWMA_DAT;		   //¶ÁÈ¡Òì²½Êý¾Ý
	
	return dat;
}

//========================================================================
// º¯Êý: ReadPWMB(void)
// ÃèÊö: Òì²½¶ÁÈ¡PWMBÌØÊâ¹¦ÄÜ¼Ä´æÆ÷º¯Êý. 
// ²ÎÊý: addr: ¶ÁÈ¡ÌØÊâ¹¦ÄÜ¼Ä´æÆ÷µØÖ·.
// ·µ»Ø: dat:  ¶ÁÈ¡ÌØÊâ¹¦ÄÜ¼Ä´æÆ÷ÄÚÈÝ.
// °æ±¾: V1.0, 2022-03-16
//========================================================================
u8 ReadPWMB(u8 addr)
{
	u8 dat;
	
	while (HSPWMB_ADR &	0x80); //µÈ´ýÇ°Ò»¸öÒì²½¶ÁÐ´Íê³É
	HSPWMB_ADR = addr |	0x80;  //ÉèÖÃ¼ä½Ó·ÃÎÊµØÖ·,Ö»ÐèÒªÉèÖÃÔ­XFRµØÖ·µÄµÍ7Î»
								//HSPWMB_ADDR¼Ä´æÆ÷µÄ×î¸ßÎ»Ð´1,±íÊ¾¶ÁÊý¾Ý
	while (HSPWMB_ADR &	0x80); //µÈ´ýµ±Ç°Òì²½¶ÁÈ¡Íê³É
	dat	= HSPWMB_DAT;		   //¶ÁÈ¡Òì²½Êý¾Ý
	
	return dat;
}

//========================================================================
// º¯Êý: WritePWMA(void)
// ÃèÊö: Òì²½¶ÁÈ¡PWMAÌØÊâ¹¦ÄÜ¼Ä´æÆ÷º¯Êý. 
// ²ÎÊý: addr: Ð´ÈëÌØÊâ¹¦ÄÜ¼Ä´æÆ÷µØÖ·.
// ²ÎÊý: dat:  Ð´ÈëÌØÊâ¹¦ÄÜ¼Ä´æÆ÷ÄÚÈÝ.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-16
//========================================================================
void WritePWMA(u8	addr, u8 dat)
{
	while (HSPWMA_ADR &	0x80); //µÈ´ýÇ°Ò»¸öÒì²½¶ÁÐ´Íê³É
	HSPWMA_DAT = dat;		   //×¼±¸ÐèÒªÐ´ÈëµÄÊý¾Ý
	HSPWMA_ADR = addr &	0x7f;  //ÉèÖÃ¼ä½Ó·ÃÎÊµØÖ·,Ö»ÐèÒªÉèÖÃÔ­XFRµØÖ·µÄµÍ7Î»
								//HSPWMA_ADDR¼Ä´æÆ÷µÄ×î¸ßÎ»Ð´0,±íÊ¾Ð´Êý¾Ý
}

//========================================================================
// º¯Êý: WritePWMB(void)
// ÃèÊö: Òì²½¶ÁÈ¡PWMBÌØÊâ¹¦ÄÜ¼Ä´æÆ÷º¯Êý. 
// ²ÎÊý: addr: Ð´ÈëÌØÊâ¹¦ÄÜ¼Ä´æÆ÷µØÖ·.
// ²ÎÊý: dat:  Ð´ÈëÌØÊâ¹¦ÄÜ¼Ä´æÆ÷ÄÚÈÝ.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-16
//========================================================================
void WritePWMB(u8	addr, u8 dat)
{
	while (HSPWMB_ADR &	0x80); //µÈ´ýÇ°Ò»¸öÒì²½¶ÁÐ´Íê³É
	HSPWMB_DAT = dat;		   //×¼±¸ÐèÒªÐ´ÈëµÄÊý¾Ý
	HSPWMB_ADR = addr &	0x7f;  //ÉèÖÃ¼ä½Ó·ÃÎÊµØÖ·,Ö»ÐèÒªÉèÖÃÔ­XFRµØÖ·µÄµÍ7Î»
								//HSPWMB_ADDR¼Ä´æÆ÷µÄ×î¸ßÎ»Ð´0,±íÊ¾Ð´Êý¾Ý
}

//========================================================================
// º¯Êý: HSPWM_Configuration
// ÃèÊö: HSPWM³õÊ¼»¯³ÌÐò.
// ²ÎÊý: PWMx: ½á¹¹²ÎÊý,Çë²Î¿¼PWM.hÀïµÄ¶¨Òå.
// ·µ»Ø: ³É¹¦·µ»Ø SUCCESS, ´íÎó·µ»Ø FAIL.
// °æ±¾: V1.0, 2022-04-05
//========================================================================
void HSPWM_Configuration(u8 PWM, HSPWMx_InitDefine *PWMx, PWMx_Duty *DUTYx)
{
	u8 tmpENO,tmpCCER1,tmpCCER2;
	
	if(PWM == PWMA)
	{
		HSPWMA_CFG = 0x03;			//Ê¹ÄÜPWMAÏà¹Ø¼Ä´æÆ÷Òì²½·ÃÎÊ¹¦ÄÜ

		if(PWMx->PWM_EnoSelect & ENO1P)
		{
			tmpENO |= ENO1P;
			tmpCCER1 |= 0x01;
		}
		else
		{
			tmpENO &= ~ENO1P;
			tmpCCER1 &= ~0x01;
		}
		if(PWMx->PWM_EnoSelect & ENO1N)
		{
			tmpENO |= ENO1N;
			tmpCCER1 |= 0x04;
		}
		else
		{
			tmpENO &= ~ENO1N;
			tmpCCER1 &= ~0x04;
		}
		if(PWMx->PWM_EnoSelect & ENO2P)
		{
			tmpENO |= ENO2P;
			tmpCCER1 |= 0x10;
		}
		else
		{
			tmpENO &= ~ENO2P;
			tmpCCER1 &= ~0x10;
		}
		if(PWMx->PWM_EnoSelect & ENO2N)
		{
			tmpENO |= ENO2N;
			tmpCCER1 |= 0x40;
		}
		else
		{
			tmpENO &= ~ENO2N;
			tmpCCER1 &= ~0x40;
		}
		if(PWMx->PWM_EnoSelect & ENO3P)
		{
			tmpENO |= ENO3P;
			tmpCCER2 |= 0x01;
		}
		else
		{
			tmpENO &= ~ENO3P;
			tmpCCER2 &= ~0x01;
		}
		if(PWMx->PWM_EnoSelect & ENO3N)
		{
			tmpENO |= ENO3N;
			tmpCCER2 |= 0x04;
		}
		else
		{
			tmpENO &= ~ENO3N;
			tmpCCER2 &= ~0x04;
		}
		if(PWMx->PWM_EnoSelect & ENO4P)
		{
			tmpENO |= ENO4P;
			tmpCCER2 |= 0x10;
		}
		else
		{
			tmpENO &= ~ENO4P;
			tmpCCER2 &= ~0x10;
		}
		if(PWMx->PWM_EnoSelect & ENO4N)
		{
			tmpENO |= ENO4N;
			tmpCCER2 |= 0x40;
		}
		else
		{
			tmpENO &= ~ENO4N;
			tmpCCER2 &= ~0x40;
		}
		
		//Í¨¹ýÒì²½·½Ê½ÉèÖÃPWMAµÄÏà¹Ø¼Ä´æÆ÷
		WritePWMA((u8)&PWMA_CCER1, 0x00);
		WritePWMA((u8)&PWMA_CCER2, 0x00);
		WritePWMA((u8)&PWMA_CCMR1, CCMRn_PWM_MODE1);			//Í¨µÀÄ£Ê½ÅäÖÃ
		WritePWMA((u8)&PWMA_CCMR2, CCMRn_PWM_MODE1);
		WritePWMA((u8)&PWMA_CCMR3, CCMRn_PWM_MODE1);
		WritePWMA((u8)&PWMA_CCMR4, CCMRn_PWM_MODE1);
		WritePWMA((u8)&PWMA_CCER1, tmpCCER1);			//ÅäÖÃÍ¨µÀÊä³öÊ¹ÄÜºÍ¼«ÐÔ
		WritePWMA((u8)&PWMA_CCER2, tmpCCER2);
		WritePWMA((u8)&PWMA_ENO, tmpENO);	//Ê¹ÄÜPWMÐÅºÅÊä³ö¶Ë¿Ú
		WritePWMA((u8)&PWMA_CCR1H, (u8)(DUTYx->PWM1_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMA((u8)&PWMA_CCR1L, (u8)DUTYx->PWM1_Duty);
		WritePWMA((u8)&PWMA_CCR2H, (u8)(DUTYx->PWM2_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMA((u8)&PWMA_CCR2L, (u8)DUTYx->PWM2_Duty);
		WritePWMA((u8)&PWMA_CCR3H, (u8)(DUTYx->PWM3_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMA((u8)&PWMA_CCR3L, (u8)DUTYx->PWM3_Duty);
		WritePWMA((u8)&PWMA_CCR4H, (u8)(DUTYx->PWM4_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMA((u8)&PWMA_CCR4L, (u8)DUTYx->PWM4_Duty);
		WritePWMA((u8)&PWMA_ARRH,	(u8)(PWMx->PWM_Period >> 8));	//ÉèÖÃÊä³öPWMµÄÖÜÆÚ
		WritePWMA((u8)&PWMA_ARRL,	(u8)(PWMx->PWM_Period));
		WritePWMA((u8)&PWMA_DTR, PWMx->PWM_DeadTime);					//ÉèÖÃ»¥²¹¶Ô³ÆÊä³öPWMµÄËÀÇø
		WritePWMA((u8)&PWMA_BKR, PWMx->PWM_MainOutEnable<<7);	//Ê¹ÄÜÖ÷Êä³ö
		WritePWMA((u8)&PWMA_CR1, PWMx->PWM_CEN_Enable);				//¿ªÊ¼PWM¼ÆÊý
	}
	else if(PWM == PWMB)
	{
		HSPWMB_CFG = 0x03;			//Ê¹ÄÜPWMBÏà¹Ø¼Ä´æÆ÷Òì²½·ÃÎÊ¹¦ÄÜ

		if(PWMx->PWM_EnoSelect & ENO5P)
		{
			tmpENO |= ENO5P;
			tmpCCER1 |= 0x01;
		}
		else
		{
			tmpENO &= ~ENO5P;
			tmpCCER1 &= ~0x01;
		}
		if(PWMx->PWM_EnoSelect & ENO6P)
		{
			tmpENO |= ENO6P;
			tmpCCER1 |= 0x10;
		}
		else
		{
			tmpENO &= ~ENO6P;
			tmpCCER1 &= ~0x10;
		}
		if(PWMx->PWM_EnoSelect & ENO7P)
		{
			tmpENO |= ENO7P;
			tmpCCER2 |= 0x01;
		}
		else
		{
			tmpENO &= ~ENO7P;
			tmpCCER2 &= ~0x01;
		}
		if(PWMx->PWM_EnoSelect & ENO8P)
		{
			tmpENO |= ENO8P;
			tmpCCER2 |= 0x10;
		}
		else
		{
			tmpENO &= ~ENO8P;
			tmpCCER2 &= ~0x10;
		}
		
		//Í¨¹ýÒì²½·½Ê½ÉèÖÃPWMAµÄÏà¹Ø¼Ä´æÆ÷
		WritePWMB((u8)&PWMB_CCER1, 0x00);
		WritePWMB((u8)&PWMB_CCER2, 0x00);
		WritePWMB((u8)&PWMB_CCMR1, CCMRn_PWM_MODE1);			//Í¨µÀÄ£Ê½ÅäÖÃ
		WritePWMB((u8)&PWMB_CCMR2, CCMRn_PWM_MODE1);
		WritePWMB((u8)&PWMB_CCMR3, CCMRn_PWM_MODE1);
		WritePWMB((u8)&PWMB_CCMR4, CCMRn_PWM_MODE1);
		WritePWMB((u8)&PWMB_CCER1, tmpCCER1);			//ÅäÖÃÍ¨µÀÊä³öÊ¹ÄÜºÍ¼«ÐÔ
		WritePWMB((u8)&PWMB_CCER2, tmpCCER2);
		WritePWMB((u8)&PWMB_ENO, tmpENO);	//Ê¹ÄÜPWMÐÅºÅÊä³ö¶Ë¿Ú
		WritePWMB((u8)&PWMB_CCR5H, (u8)(DUTYx->PWM5_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMB((u8)&PWMB_CCR5L, (u8)DUTYx->PWM5_Duty);
		WritePWMB((u8)&PWMB_CCR6H, (u8)(DUTYx->PWM6_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMB((u8)&PWMB_CCR6L, (u8)DUTYx->PWM6_Duty);
		WritePWMB((u8)&PWMB_CCR7H, (u8)(DUTYx->PWM7_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMB((u8)&PWMB_CCR7L, (u8)DUTYx->PWM7_Duty);
		WritePWMB((u8)&PWMB_CCR8H, (u8)(DUTYx->PWM8_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
		WritePWMB((u8)&PWMB_CCR8L, (u8)DUTYx->PWM8_Duty);
		WritePWMB((u8)&PWMB_ARRH,	(u8)(PWMx->PWM_Period >> 8));	//ÉèÖÃÊä³öPWMµÄÖÜÆÚ
		WritePWMB((u8)&PWMB_ARRL,	(u8)(PWMx->PWM_Period));
		WritePWMB((u8)&PWMB_DTR, PWMx->PWM_DeadTime);					//ÉèÖÃ»¥²¹¶Ô³ÆÊä³öPWMµÄËÀÇø
		WritePWMB((u8)&PWMB_BKR, PWMx->PWM_MainOutEnable<<7);	//Ê¹ÄÜÖ÷Êä³ö
		WritePWMB((u8)&PWMB_CR1, PWMx->PWM_CEN_Enable);				//¿ªÊ¼PWM¼ÆÊý
	}
}

//========================================================================
// º¯Êý: UpdateHSPwm
// ÃèÊö: HSPWMÕ¼¿Õ±È¸üÐÂ³ÌÐò.
// ²ÎÊý: PWM: PWMÍ¨µÀ/×éºÅ, PWMx½á¹¹²ÎÊý,Çë²Î¿¼PWM.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-04-05
//========================================================================
void UpdateHSPwm(u8 PWM, PWMx_Duty *PWMx)
{
	switch(PWM)
	{
		case PWM1:
			WritePWMA((u8)&PWMA_CCR1H, (u8)(PWMx->PWM1_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR1L, (u8)PWMx->PWM1_Duty);
		break;

		case PWM2:
			WritePWMA((u8)&PWMA_CCR2H, (u8)(PWMx->PWM2_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR2L, (u8)PWMx->PWM2_Duty);
		break;

		case PWM3:
			WritePWMA((u8)&PWMA_CCR3H, (u8)(PWMx->PWM3_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR3L, (u8)PWMx->PWM3_Duty);
		break;

		case PWM4:
			WritePWMA((u8)&PWMA_CCR4H, (u8)(PWMx->PWM4_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR4L, (u8)PWMx->PWM4_Duty);
		break;

		case PWM5:
			WritePWMB((u8)&PWMB_CCR5H, (u8)(PWMx->PWM5_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR5L, (u8)PWMx->PWM5_Duty);
		break;

		case PWM6:
			WritePWMB((u8)&PWMB_CCR6H, (u8)(PWMx->PWM6_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR6L, (u8)PWMx->PWM6_Duty);
		break;

		case PWM7:
			WritePWMB((u8)&PWMB_CCR7H, (u8)(PWMx->PWM7_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR7L, (u8)PWMx->PWM7_Duty);
		break;

		case PWM8:
			WritePWMB((u8)&PWMB_CCR8H, (u8)(PWMx->PWM8_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR8L, (u8)PWMx->PWM8_Duty);
		break;

		case PWMA:
			WritePWMA((u8)&PWMA_CCR1H, (u8)(PWMx->PWM1_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR1L, (u8)PWMx->PWM1_Duty);
			WritePWMA((u8)&PWMA_CCR2H, (u8)(PWMx->PWM2_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR2L, (u8)PWMx->PWM2_Duty);
			WritePWMA((u8)&PWMA_CCR3H, (u8)(PWMx->PWM3_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR3L, (u8)PWMx->PWM3_Duty);
			WritePWMA((u8)&PWMA_CCR4H, (u8)(PWMx->PWM4_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMA((u8)&PWMA_CCR4L, (u8)PWMx->PWM4_Duty);
		break;

		case PWMB:
			WritePWMB((u8)&PWMB_CCR5H, (u8)(PWMx->PWM5_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR5L, (u8)PWMx->PWM5_Duty);
			WritePWMB((u8)&PWMB_CCR6H, (u8)(PWMx->PWM6_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR6L, (u8)PWMx->PWM6_Duty);
			WritePWMB((u8)&PWMB_CCR7H, (u8)(PWMx->PWM7_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR7L, (u8)PWMx->PWM7_Duty);
			WritePWMB((u8)&PWMB_CCR8H, (u8)(PWMx->PWM8_Duty >> 8));	//ÉèÖÃÊä³öPWMµÄÕ¼¿Õ±È
			WritePWMB((u8)&PWMB_CCR8L, (u8)PWMx->PWM8_Duty);
		break;
	}
}

/*********************************************************/
