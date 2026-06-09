/**
 * @file STC32G_UART_Isr.c
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

#include "STC32G_UART.h"

bit B_ULinRX1_Flag;
bit B_ULinRX2_Flag;

//========================================================================
// : UART1_ISR_Handler
// : UART1жϺ.
// : none.
// : none.
// 汾: V1.0, 2020 - 9 - 3
//========================================================================
#ifdef UART1
void UART1_ISR_Handler ( void ) interrupt UART1_VECTOR
{
	u8 Status;

	if ( RI )
	{
		RI = 0;

		//--------USART LIN---------------
		Status = USARTCR5;
		if ( Status & 0x02 )     //if LIN header is detected
		{
			B_ULinRX1_Flag = 1;
		}

		if ( Status & 0xc0 )     //if LIN break is detected / LIN header error is detected
		{
			COM1.RX_Cnt = 0;
		}
		USARTCR5 &= ~0xcb;    //Clear flag
		//--------------------------------
		
        if ( COM1.RX_Cnt >= COM_RX1_Lenth )	COM1.RX_Cnt = 0;
        RX1_Buffer[COM1.RX_Cnt++] = SBUF;
        COM1.RX_TimeOut = TimeOutSet1;
	}

	if ( TI )
	{
		TI = 0;
		
        #if ( UART_QUEUE_MODE == 1 )   //жǷʹöģʽ
		if ( COM1.TX_send != COM1.TX_write )
		{
		 	SBUF = TX1_Buffer[COM1.TX_send];
			if (++COM1.TX_send >= COM_TX1_Lenth )		COM1.TX_send = 0;
		}
		else	COM1.B_TX_busy = 0;
        #else
        COM1.B_TX_busy = 0;     //ʹʽֱæ־
        #endif
	}
}
#endif

//========================================================================
// : UART2_ISR_Handler
// : UART2жϺ.
// : none.
// : none.
// 汾: V1.0, 2020 - 9 - 3
//========================================================================
#ifdef UART2
void UART2_ISR_Handler ( void ) interrupt UART2_VECTOR
{
	u8 Status;

	if ( S2RI )
	{
		CLR_RI2();

		//--------USART LIN---------------
		Status = USART2CR5;
		if ( Status & 0x02 )     //if LIN header is detected
		{
			B_ULinRX2_Flag = 1;
		}

		if ( Status & 0xc0 )     //if LIN break is detected / LIN header error is detected
		{
			COM2.RX_Cnt = 0;
		}
		USART2CR5 &= ~0xcb;   //Clear flag
		//--------------------------------
		
        if ( COM2.RX_Cnt >= COM_RX2_Lenth )	COM2.RX_Cnt = 0;
        RX2_Buffer[COM2.RX_Cnt++] = S2BUF;
        COM2.RX_TimeOut = TimeOutSet2;
	}

	if ( S2TI )
	{
		CLR_TI2();
		
        #if ( UART_QUEUE_MODE == 1 )   //жǷʹöģʽ
		if ( COM2.TX_send != COM2.TX_write )
		{
		 	S2BUF = TX2_Buffer[COM2.TX_send];
			if (++COM2.TX_send >= COM_TX2_Lenth )		COM2.TX_send = 0;
		}
		else	COM2.B_TX_busy = 0;
        #else
        COM2.B_TX_busy = 0;     //ʹʽֱæ־
        #endif
	}
}
#endif

//========================================================================
// : UART3_ISR_Handler
// : UART3жϺ.
// : none.
// : none.
// 汾: V1.0, 2020 - 9 - 3
//========================================================================
#ifdef UART3
void UART3_ISR_Handler ( void ) interrupt UART3_VECTOR
{
	if ( S3RI )
	{
		CLR_RI3();

        if ( COM3.RX_Cnt >= COM_RX3_Lenth )	COM3.RX_Cnt = 0;
        RX3_Buffer[COM3.RX_Cnt++] = S3BUF;
        COM3.RX_TimeOut = TimeOutSet3;
	}

	if ( S3TI )
	{
		CLR_TI3();
		
        #if ( UART_QUEUE_MODE == 1 )   //жǷʹöģʽ
		if ( COM3.TX_send != COM3.TX_write )
		{
		 	S3BUF = TX3_Buffer[COM3.TX_send];
			if (++COM3.TX_send >= COM_TX3_Lenth )		COM3.TX_send = 0;
		}
		else	COM3.B_TX_busy = 0;
        #else
        COM3.B_TX_busy = 0;     //ʹʽֱæ־
        #endif
	}
}
#endif

//========================================================================
// : UART4_ISR_Handler
// : UART4жϺ.
// : none.
// : none.
// 汾: V1.0, 2020 - 9 - 3
//========================================================================
#ifdef UART4
void UART4_ISR_Handler ( void ) interrupt UART4_VECTOR
{
	if ( S4RI )
	{
		CLR_RI4();

        if ( COM4.RX_Cnt >= COM_RX4_Lenth )	COM4.RX_Cnt = 0;
        RX4_Buffer[COM4.RX_Cnt++] = S4BUF;
        COM4.RX_TimeOut = TimeOutSet4;
	}

	if ( S4TI )
	{
		CLR_TI4();
		
        #if ( UART_QUEUE_MODE == 1 )   //жǷʹöģʽ
		if ( COM4.TX_send != COM4.TX_write )
		{
		 	S4BUF = TX4_Buffer[COM4.TX_send];
			if (++COM4.TX_send >= COM_TX4_Lenth )		COM4.TX_send = 0;
		}
		else	COM4.B_TX_busy = 0;
        #else
        COM4.B_TX_busy = 0;     //ʹʽֱæ־
        #endif
	}
}
#endif
