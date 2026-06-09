/**
 * @file STC32G_NVIC.c
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

#include "STC32G_NVIC.h"

//========================================================================
// : NVIC_Timer0_Init
// : Timer0ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_Timer0_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) Timer0_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) Timer0_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_Timer1_Init
// : Timer1ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_Timer1_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) Timer1_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) Timer1_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_Timer2_Init
// : Timer2ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_Timer2_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) Timer2_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_Timer3_Init
// : Timer3ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_Timer3_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) Timer3_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_Timer4_Init
// : Timer4ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_Timer4_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) Timer4_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_INT0_Init
// : INT0ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_INT0_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) INT0_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) INT0_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_INT1_Init
// : INT1ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_INT1_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) INT1_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) INT1_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_INT2_Init
// : INT2ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_INT2_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) INT2_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_INT3_Init
// : INT3ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_INT3_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) INT3_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_INT4_Init
// : INT4ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, NULL.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_INT4_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) INT4_Interrupt( State ); else  return FAIL;
	Priority = NULL;
	return SUCCESS;
}

//========================================================================
// : NVIC_ADC_Init
// : ADCǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_ADC_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) ADC_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) ADC_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_CMP_Init
// : ȽǶжϿʼ.
// : State:    жʹ״̬, RISING_EDGE / ALLING_EDGE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_CMP_Init( u8 State, u8 Priority )
{
	if ( State & RISING_EDGE )	PIE = 1;			//ж
	else	PIE = 0;			//ֹж
	if ( State & FALLING_EDGE )	NIE = 1;		//½ж
	else	NIE = 0;			//ֹж
	if ( Priority <= Priority_3 ) CMP_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_I2C_Init
// : I2CǶжϿʼ.
// : Mode:     ģʽ, I2C_Mode_Master / 2C_Mode_Slave.
// : State:    жʹ״̬, I2C_Mode_Master: ENABLE / ISABLE.
//                              I2C_Mode_Slave: I2C_ESTAI / 2C_ERXI / 2C_ETXI / 2C_ESTOI / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_I2C_Init( u8 Mode, u8 State, u8 Priority )
{
	if ( Mode > 1 ) return FAIL;
	if ( Mode == 1 )	//I2C_Mode_Master
	{
		I2C_Master_Inturrupt( State );
	}
	else if ( Mode == 0 )	//I2C_Mode_Slave
	{
		I2CSLCR = ( I2CSLCR & ~0x78 ) | State;
	}
	if ( Priority <= Priority_3 ) CMP_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_UART1_Init
// : UART1ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_UART1_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) UART1_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) UART1_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_UART2_Init
// : UART2ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_UART2_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) UART2_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) UART2_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_UART3_Init
// : UART3ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_UART3_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) UART3_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) UART3_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_UART4_Init
// : UART4ǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_UART4_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) UART4_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) UART4_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_SPI_Init
// : SPIǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_SPI_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) SPI_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) SPI_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

//========================================================================
// : NVIC_RTC_Init
// : SPIǶжϿʼ.
// : State:    жʹ״̬, жʹ, 0x80:ж, 0x40:ж, 0x20:Сʱж, 0x10:ж, 0x08:ж, 0x04:1 / ж, 0x02:1 / ж, 0x01:1 / 2ж /DISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_RTC_Init( u8 State, u8 Priority )
{
	if ( Priority <= Priority_3 ) RTC_Priority( Priority ); else  return FAIL;
	RTC_Interrupt( State ); 
	return SUCCESS;
}

//========================================================================
// : NVIC_PWM_Init
// : PWMǶжϿʼ.
// : Channel:  ͨ, PWMA / WMB.
// : State:    жʹ״̬, PWM_BIE / WM_TIE / WM_COMIE / WM_CC8IE~PWM_CC1IE / WM_UIE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
#ifndef PWMA
#define	PWMA	9
#endif
#ifndef PWMB
#define	PWMB	10
#endif
u8 NVIC_PWM_Init( u8 Channel, u8 State, u8 Priority )
{
	if ( Channel > PWMB ) return FAIL;
	if ( Priority > Priority_3 ) return FAIL;
	switch( Channel )
	{
		case PWMA:
			PWMA_IER = State;
			PWMA_Priority( Priority );
		break;

		case PWMB:
			PWMB_IER = State;
			PWMB_Priority( Priority );
		break;

		default:
			PWMB_IER = State;
			Priority = NULL;
		break;
	}
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_ADC_Init
// : DMA ADCǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_ADC_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_ADC_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_ADC_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_ADC_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_ADC_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_ADC_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_M2M_Init
// : DMA M2MǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_M2M_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_M2M_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_M2M_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_M2M_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_M2M_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_M2M_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_SPI_Init
// : DMA SPIǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 7
//========================================================================
u8 NVIC_DMA_SPI_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_SPI_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_SPI_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_SPI_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_SPI_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_SPI_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART1_Tx_Init
// : DMA UART1 TxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART1_Tx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR1T_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR1T_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR1T_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR1T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR1T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART1_Rx_Init
// : DMA UART1 RxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART1_Rx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR1R_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR1R_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR1R_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR1R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR1R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART2_Tx_Init
// : DMA UART2 TxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART2_Tx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR2T_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR2T_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR2T_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR2T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR2T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART2_Rx_Init
// : DMA UART2 RxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART2_Rx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR2R_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR2R_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR2R_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR2R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR2R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART3_Tx_Init
// : DMA UART3 TxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART3_Tx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR3T_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR3T_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR3T_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR3T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR3T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART3_Rx_Init
// : DMA UART3 RxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART3_Rx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR3R_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR3R_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR3R_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR3R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR3R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART4_Tx_Init
// : DMA UART4 TxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART4_Tx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR4T_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR4T_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR4T_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR4T_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR4T_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_UART4_Rx_Init
// : DMA UART4 RxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_UART4_Rx_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_UR4R_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_UR4R_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_UR4R_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_UR4R_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_UR4R_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_LCM_Init
// : DMA LCMǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_DMA_LCM_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_LCM_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_LCM_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_LCM_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_LCM_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_LCM_CFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_LCM_Init
// : LCMǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2021 - 5 - 1
//========================================================================
u8 NVIC_LCM_Init( u8 State, u8 Priority )
{
	LCMIFCFG &= ~0x30;
	if ( Priority <= Priority_3 ) LCMIFCFG |= Priority << 4;
	if ( State == ENABLE )
		LCMIFCFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		LCMIFCFG &= ~0x80;		//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_I2CT_Init
// : DMA I2C TxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2022 - 3 - 5
//========================================================================
u8 NVIC_DMA_I2CT_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_I2CT_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_I2CT_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_I2CT_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_I2CT_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_I2CT_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_DMA_I2CR_Init
// : DMA I2C RxǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : Bus_Priority: ߷ȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2022 - 3 - 5
//========================================================================
u8 NVIC_DMA_I2CR_Init( u8 State, u8 Priority, u8 Bus_Priority )
{
	DMA_I2CR_CFG &= ~0x0f;
	if ( Priority <= Priority_3 ) DMA_I2CR_CFG |= Priority << 2;
	if ( Bus_Priority <= Priority_3 ) DMA_I2CR_CFG |= Bus_Priority;	//߷ȼ
	if ( State == ENABLE )
		DMA_I2CR_CFG |= 0x80;		//bit7 1:Enable Interrupt
	else
		DMA_I2CR_CFG &= ~0x80;	//bit7 0:Disable Interrupt
	return SUCCESS;
}

//========================================================================
// : NVIC_CAN_Init
// : CANǶжϿʼ.
// : Channel:  ͨ, CAN1 / AN2.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2023 - 3 - 7
//========================================================================
#ifndef CAN1
#define	CAN1	0
#endif
#ifndef CAN2
#define	CAN2	1
#endif
u8 NVIC_CAN_Init( u8 Channel, u8 State, u8 Priority )
{
	if ( Channel > CAN2 ) return FAIL;
	if ( Priority > Priority_3 ) return FAIL;
	switch( Channel )
	{
		case CAN1:
			if ( State == ENABLE )
				CANIE = 1;		//bit7 1:Enable Interrupt
			else
				CANIE = 0;		//bit7 0:Disable Interrupt
			CAN1_Priority( Priority );
		break;

		case CAN2:
			if ( State == ENABLE )
				CAN2IE = 1;		//bit7 1:Enable Interrupt
			else
				CAN2IE = 0;		//bit7 0:Disable Interrupt
			CAN2_Priority( Priority );
		break;

		default:
			return FAIL;
		break;
	}
	return SUCCESS;
}

//========================================================================
// : NVIC_LIN_Init
// : LINǶжϿʼ.
// : State:    жʹ״̬, ENABLE / ISABLE.
// : Priority: жȼ, Priority_0, Priority_1, Priority_2, Priority_3.
// : ִн SUCCESS / AIL.
// 汾: V1.0, 2020 - 9 - 9
//========================================================================
u8 NVIC_LIN_Init( u8 State, u8 Priority )
{
	if ( State <= ENABLE ) LIN_Interrupt( State ); else  return FAIL;
	if ( Priority <= Priority_3 ) LIN_Priority( Priority ); else  return FAIL;
	return SUCCESS;
}

