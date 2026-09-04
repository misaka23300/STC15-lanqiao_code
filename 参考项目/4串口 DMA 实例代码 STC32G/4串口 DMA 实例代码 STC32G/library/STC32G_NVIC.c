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

#include "STC32G_NVIC.h"

//========================================================================
// º¯Êý: NVIC_Timer0_Init
// ÃèÊö: Timer0Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer0_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer0_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) Timer0_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_Timer1_Init
// ÃèÊö: Timer1Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer1_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) Timer1_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_Timer2_Init
// ÃèÊö: Timer2Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer2_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_Timer3_Init
// ÃèÊö: Timer3Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer3_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_Timer4_Init
// ÃèÊö: Timer4Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_Timer4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) Timer4_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_INT0_Init
// ÃèÊö: INT0Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT0_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT0_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) INT0_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_INT1_Init
// ÃèÊö: INT1Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT1_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) INT1_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_INT2_Init
// ÃèÊö: INT2Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT2_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_INT3_Init
// ÃèÊö: INT3Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT3_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_INT4_Init
// ÃèÊö: INT4Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, NULL.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_INT4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) INT4_Interrupt(State); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_ADC_Init
// ÃèÊö: ADCÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_ADC_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) ADC_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) ADC_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_CMP_Init
// ÃèÊö: ±È½ÏÆ÷Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, RISING_EDGE/FALLING_EDGE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_CMP_Init(u8 State, u8 Priority)
{
	if(State & RISING_EDGE)	PIE = 1;			//ÔÊÐíÉÏÉýÑØÖÐ¶Ï
	else	PIE = 0;			//½ûÖ¹ÉÏÉýÑØÖÐ¶Ï
	if(State & FALLING_EDGE)	NIE = 1;		//ÔÊÐíÏÂ½µÑØÖÐ¶Ï
	else	NIE = 0;			//½ûÖ¹ÉÏÉýÑØÖÐ¶Ï
	if(Priority <= Priority_3) CMP_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_I2C_Init
// ÃèÊö: I2CÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: Mode:     Ä£Ê½, I2C_Mode_Master/I2C_Mode_Slave.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, I2C_Mode_Master: ENABLE/DISABLE.
//                              I2C_Mode_Slave: I2C_ESTAI/I2C_ERXI/I2C_ETXI/I2C_ESTOI/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_I2C_Init(u8 Mode, u8 State, u8 Priority)
{
	if(Mode > 1) return FAIL;
	if(Mode == 1)	//I2C_Mode_Master
	{
		I2C_Master_Inturrupt(State);
	}
	else if(Mode == 0)	//I2C_Mode_Slave
	{
		I2CSLCR = (I2CSLCR & ~0x78) | State;
	}
	if(Priority <= Priority_3) CMP_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_UART1_Init
// ÃèÊö: UART1Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART1_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART1_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) UART1_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_UART2_Init
// ÃèÊö: UART2Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART2_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART2_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) UART2_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_UART3_Init
// ÃèÊö: UART3Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART3_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART3_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) UART3_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_UART4_Init
// ÃèÊö: UART4Ç¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_UART4_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) UART4_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) UART4_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_SPI_Init
// ÃèÊö: SPIÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_SPI_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) SPI_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) SPI_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_RTC_Init
// ÃèÊö: SPIÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ÖÐ¶ÏÊ¹ÄÜ, 0x80:ÄÖÖÓÖÐ¶Ï, 0x40:ÈÕÖÐ¶Ï, 0x20:Ð¡Ê±ÖÐ¶Ï, 0x10:·ÖÖÓÖÐ¶Ï, 0x08:ÃëÖÐ¶Ï, 0x04:1/2ÃëÖÐ¶Ï, 0x02:1/8ÃëÖÐ¶Ï, 0x01:1/32ÃëÖÐ¶Ï /DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_RTC_Init(u8 State, u8 Priority)
{
	if(Priority <= Priority_3) RTC_Priority(Priority); else  return FAIL;
	RTC_Interrupt(State); 
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_PWM_Init
// ÃèÊö: PWMÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: Channel:  Í¨µÀ, PWMA/PWMB.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, PWM_BIE/PWM_TIE/PWM_COMIE/PWM_CC8IE~PWM_CC1IE/PWM_UIE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
#ifndef PWMA
#define	PWMA	9
#endif
#ifndef PWMB
#define	PWMB	10
#endif
u8 NVIC_PWM_Init(u8 Channel, u8 State, u8 Priority)
{
	if(Channel > PWMB) return FAIL;
	if(Priority > Priority_3) return FAIL;
	switch(Channel)
	{
		case PWMA:
			PWMA_IER = State;
			PWMA_Priority(Priority);
		break;

		case PWMB:
			PWMB_IER = State;
			PWMB_Priority(Priority);
		break;

		default:
			PWMB_IER = State;
			Priority = NULL;
		break;
	}
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_ADC_Init
// ÃèÊö: DMA ADCÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_ADC_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_ADC_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_ADC_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_ADC_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_ADC_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_ADC_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_M2M_Init
// ÃèÊö: DMA M2MÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_M2M_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_M2M_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_M2M_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_M2M_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_M2M_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_M2M_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_SPI_Init
// ÃèÊö: DMA SPIÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-27
//========================================================================
u8 NVIC_DMA_SPI_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_SPI_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_SPI_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_SPI_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_SPI_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_SPI_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART1_Tx_Init
// ÃèÊö: DMA UART1 TxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART1_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR1T_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR1T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR1T_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR1T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR1T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART1_Rx_Init
// ÃèÊö: DMA UART1 RxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART1_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR1R_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR1R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR1R_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR1R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR1R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART2_Tx_Init
// ÃèÊö: DMA UART2 TxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART2_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR2T_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR2T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR2T_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR2T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR2T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART2_Rx_Init
// ÃèÊö: DMA UART2 RxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART2_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR2R_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR2R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR2R_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR2R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR2R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART3_Tx_Init
// ÃèÊö: DMA UART3 TxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART3_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR3T_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR3T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR3T_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR3T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR3T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART3_Rx_Init
// ÃèÊö: DMA UART3 RxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART3_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR3R_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR3R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR3R_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR3R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR3R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART4_Tx_Init
// ÃèÊö: DMA UART4 TxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART4_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR4T_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR4T_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR4T_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR4T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR4T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_UART4_Rx_Init
// ÃèÊö: DMA UART4 RxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_UART4_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_UR4R_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_UR4R_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_UR4R_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_UR4R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR4R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_LCM_Init
// ÃèÊö: DMA LCMÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_DMA_LCM_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_LCM_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_LCM_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_LCM_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_LCM_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_LCM_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_LCM_Init
// ÃèÊö: LCMÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2021-05-21
//========================================================================
u8 NVIC_LCM_Init(u8 State, u8 Priority)
{
	LCMIFCFG &= ~0x30;
	if(Priority <= Priority_3) LCMIFCFG |= Priority << 4;
	if(State == ENABLE)
		LCMIFCFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		LCMIFCFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_I2CT_Init
// ÃèÊö: DMA I2C TxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2022-03-25
//========================================================================
u8 NVIC_DMA_I2CT_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_I2CT_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_I2CT_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_I2CT_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_I2CT_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_I2CT_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_DMA_I2CR_Init
// ÃèÊö: DMA I2C RxÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ²ÎÊý: Bus_Priority: Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2022-03-25
//========================================================================
u8 NVIC_DMA_I2CR_Init(u8 State, u8 Priority, u8 Bus_Priority)
{
	DMA_I2CR_CFG &= ~0x0f;
	if(Priority <= Priority_3) DMA_I2CR_CFG |= Priority << 2;
	if(Bus_Priority <= Priority_3) DMA_I2CR_CFG |= Bus_Priority;	//Êý¾Ý×ÜÏß·ÃÎÊÓÅÏÈ¼¶
	if(State == ENABLE)
		DMA_I2CR_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_I2CR_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_CAN_Init
// ÃèÊö: CANÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: Channel:  Í¨µÀ, CAN1/CAN2.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2023-03-27
//========================================================================
#ifndef CAN1
#define	CAN1	0
#endif
#ifndef CAN2
#define	CAN2	1
#endif
u8 NVIC_CAN_Init(u8 Channel, u8 State, u8 Priority)
{
	if(Channel > CAN2) return FAIL;
	if(Priority > Priority_3) return FAIL;
	switch(Channel)
	{
		case CAN1:
			if(State == ENABLE)
				CANIE = 1;		//bit7 1:Enable Interrupt
			else
				CANIE = 0;		//bit7 0:Disable Interrupt
			CAN1_Priority(Priority);
		break;

		case CAN2:
			if(State == ENABLE)
				CAN2IE = 1;		//bit7 1:Enable Interrupt
			else
				CAN2IE = 0;		//bit7 0:Disable Interrupt
			CAN2_Priority(Priority);
		break;

		default:
			return FAIL;
		break;
	}
	return SUCCESS;
}

//========================================================================
// º¯Êý: NVIC_LIN_Init
// ÃèÊö: LINÇ¶Ì×ÏòÁ¿ÖÐ¶Ï¿ØÖÆÆ÷³õÊ¼»¯.
// ²ÎÊý: State:    ÖÐ¶ÏÊ¹ÄÜ×´Ì¬, ENABLE/DISABLE.
// ²ÎÊý: Priority: ÖÐ¶ÏÓÅÏÈ¼¶, Priority_0,Priority_1,Priority_2,Priority_3.
// ·µ»Ø: Ö´ÐÐ½á¹û SUCCESS/FAIL.
// °æ±¾: V1.0, 2020-09-29
//========================================================================
u8 NVIC_LIN_Init(u8 State, u8 Priority)
{
	if(State <= ENABLE) LIN_Interrupt(State); else  return FAIL;
	if(Priority <= Priority_3) LIN_Priority(Priority); else  return FAIL;
	return SUCCESS;
}

