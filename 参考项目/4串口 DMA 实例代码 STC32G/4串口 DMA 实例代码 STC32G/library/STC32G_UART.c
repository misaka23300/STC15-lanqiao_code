/**
 * @file STC32G_UART.c
 * @brief 串口驱动文件
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

//========================================================================
//                               ر
//========================================================================

#ifdef UART1
COMx_Define	COM1;
u8	UART_BUF_type TX1_Buffer[COM_TX1_Lenth];	//ͻ
u8 	UART_BUF_type RX1_Buffer[COM_RX1_Lenth];	//ջ
#endif
#ifdef UART2
COMx_Define	COM2;
u8	UART_BUF_type TX2_Buffer[COM_TX2_Lenth];	//ͻ
u8 	UART_BUF_type RX2_Buffer[COM_RX2_Lenth];	//ջ
#endif
#ifdef UART3
COMx_Define	COM3;
u8	UART_BUF_type TX3_Buffer[COM_TX3_Lenth];	//ͻ
u8 	UART_BUF_type RX3_Buffer[COM_RX3_Lenth];	//ջ
#endif
#ifdef UART4
COMx_Define	COM4;
u8	UART_BUF_type TX4_Buffer[COM_TX4_Lenth];	//ͻ
u8 	UART_BUF_type RX4_Buffer[COM_RX4_Lenth];	//ջ
#endif

//========================================================================
// : UART_Configuration
// : UARTʼ.
// : UARTx: UART, COMxṹ,οUART.hĶ.
// : none.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
u8 UART_Configuration( u8 UARTx, COMx_InitDefine *COMx )
{
#if  defined( UART1 ) || defined( UART2 ) || defined( UART3 ) || defined( UART4 )
	u16	i;
	u32	j;
#else
	UARTx = NULL;
	COMx = NULL;
#endif

#ifdef UART1
	if ( UARTx == UART1 )
	{
		COM1.TX_send    = 0;
		COM1.TX_write   = 0;
		COM1.B_TX_busy  = 0;
		COM1.RX_Cnt     = 0;
		COM1.RX_TimeOut = 0;
		
		for ( i = ; i < OM_TX1_Lenth; i++)	TX1_Buffer[i] = 0;
		for ( i = ; i < OM_RX1_Lenth; i++)	RX1_Buffer[i] = 0;

		SCON = ( SCON & 0x3f ) | COMx->UART_Mode;	//ģʽ
		if (( COMx->UART_Mode == UART_9bit_BRTx ) || ( COMx->UART_Mode == UART_8bit_BRTx ))	//ɱ䲨
		{
			j = ( MAIN_Fosc / 4 ) / COMx->UART_BaudRate;	//1T
			if ( j >= 65536UL )	return FAIL;	//
			j = 65536UL - j;
			if ( COMx->UART_BRT_Use == BRT_Timer2 )
			{
				T2R = 0;		//Timer stop
				S1BRT = 1;	//S1 BRT Use Timer2;
				T2_CT = 0;	//Timer2 set As Timer
				T2x12 = 1;	//Timer2 set as 1T mode
				T2H = ( u8 )( j>>8 );
				T2L = ( u8 )j;
				T2R = 1;		//Timer run enable
			}
			else
			{
				TR1 = 0;
				S1BRT = 0;		//S1 BRT Use Timer1;
				T1_CT = 0;		//Timer1 set As Timer
				TMOD &= ~0x30;//Timer1_16bitAutoReload;
				T1x12 = 1;		//Timer1 set as 1T mode
				TH1 = ( u8 )( j>>8 );
				TL1 = ( u8 )j;
				TR1  = 1;
			}
		}
		else if ( COMx->UART_Mode == UART_ShiftRight )
		{
			if ( COMx->BaudRateDouble == ENABLE )	S1M0x6 = 1;	//̶SysClk / 
			else								S1M0x6 = 0;	//̶SysClk / 2
		}
		else if ( COMx->UART_Mode == UART_9bit )	//̶SysClk * ^SMOD / 4
		{
			if ( COMx->BaudRateDouble == ENABLE )	SMOD = 1;	//̶SysClk / 2
			else								SMOD = 0;	//̶SysClk / 4
		}
		UART1_RxEnable( COMx->UART_RxEnable );	//UARTʹ

		return SUCCESS;
	}
#endif
#ifdef UART2
	if ( UARTx == UART2 )
	{
		COM2.TX_send    = 0;
		COM2.TX_write   = 0;
		COM2.B_TX_busy  = 0;
		COM2.RX_Cnt     = 0;
		COM2.RX_TimeOut = 0;

		for ( i = ; i < OM_TX2_Lenth; i++)	TX2_Buffer[i] = 0;
		for ( i = ; i < OM_RX2_Lenth; i++)	RX2_Buffer[i] = 0;

		S2CON = ( S2CON & 0x3f ) | COMx->UART_Mode;	//ģʽ
		if (( COMx->UART_Mode == UART_9bit_BRTx ) ||( COMx->UART_Mode == UART_8bit_BRTx ))	//ɱ䲨
		{
			j = ( MAIN_Fosc / 4 ) / COMx->UART_BaudRate;	//1T
			if ( j >= 65536UL )	return FAIL;	//
			j = 65536UL - j;
			T2R = 0;		//Timer stop
			T2_CT = 0;	//Timer2 set As Timer
			T2x12 = 1;	//Timer2 set as 1T mode
			T2H = ( u8 )( j>>8 );
			T2L = ( u8 )j;
			T2R = 1;		//Timer run enable
		}
		else	return FAIL;	//ģʽ
		UART2_RxEnable( COMx->UART_RxEnable );	//UARTʹ

		return SUCCESS;
	}
#endif
#ifdef UART3
	if ( UARTx == UART3 )
	{
		COM3.TX_send    = 0;
		COM3.TX_write   = 0;
		COM3.B_TX_busy  = 0;
		COM3.RX_Cnt     = 0;
		COM3.RX_TimeOut = 0;
		for ( i = ; i < OM_TX3_Lenth; i++)	TX3_Buffer[i] = 0;
		for ( i = ; i < OM_RX3_Lenth; i++)	RX3_Buffer[i] = 0;

		if (( COMx->UART_Mode == UART_9bit_BRTx ) || ( COMx->UART_Mode == UART_8bit_BRTx ))	//ɱ䲨
		{
			if ( COMx->UART_Mode == UART_9bit_BRTx )	S3_9bit();	//9bit
			else									S3_8bit();	//8bit
			j = ( MAIN_Fosc / 4 ) / COMx->UART_BaudRate;	//1T
			if ( j >= 65536UL )	return FAIL;	//
			j = 65536UL - j;
			if ( COMx->UART_BRT_Use == BRT_Timer2 )
			{
				T2R = 0;		//Timer stop
				S3_BRT_UseTimer2();	//S3 BRT Use Timer2;
				T2_CT = 0;	//Timer2 set As Timer
				T2x12 = 1;	//Timer2 set as 1T mode
				T2H = ( u8 )( j>>8 );
				T2L = ( u8 )j;
				T2R = 1;		//Timer run enable
			}
			else
			{
				T3R = 0;		//Timer stop
				S3_BRT_UseTimer3();		//S3 BRT Use Timer3;
				T3H = ( u8 )( j>>8 );
				T3L = ( u8 )j;
				T3_CT = 0;	//Timer3 set As Timer
				T3x12 = 1;	//Timer3 set as 1T mode
				T3R = 1;		//Timer run enable
			}
		}
		else	return FAIL;	//ģʽ
		UART3_RxEnable( COMx->UART_RxEnable );	//UARTʹ

		return SUCCESS;
	}
#endif
#ifdef UART4
	if ( UARTx == UART4 )
	{
		COM4.TX_send    = 0;
		COM4.TX_write   = 0;
		COM4.B_TX_busy  = 0;
		COM4.RX_Cnt     = 0;
		COM4.RX_TimeOut = 0;
		for ( i = ; i < OM_TX4_Lenth; i++)	TX4_Buffer[i] = 0;
		for ( i = ; i < OM_RX4_Lenth; i++)	RX4_Buffer[i] = 0;

		if (( COMx->UART_Mode == UART_9bit_BRTx ) || ( COMx->UART_Mode == UART_8bit_BRTx ))	//ɱ䲨
		{
			if ( COMx->UART_Mode == UART_9bit_BRTx )	S4_9bit();	//9bit
			else									S4_8bit();	//8bit
			j = ( MAIN_Fosc / 4 ) / COMx->UART_BaudRate;	//1T
			if ( j >= 65536UL )	return FAIL;	//
			j = 65536UL - j;
			if ( COMx->UART_BRT_Use == BRT_Timer2 )
			{
				T2R = 0;		//Timer stop
				S4_BRT_UseTimer2();	//S4 BRT Use Timer2;
				T2_CT = 0;	//Timer2 set As Timer
				T2x12 = 1;	//Timer2 set as 1T mode
				T2H = ( u8 )( j>>8 );
				T2L = ( u8 )j;
				T2R = 1;		//Timer run enable
			}
			else
			{
				T4R = 0;		//Timer stop
				S4_BRT_UseTimer4();		//S4 BRT Use Timer4;
				T4H = ( u8 )( j>>8 );
				T4L = ( u8 )j;
				T4_CT = 0;	//Timer4 set As Timer
				T4x12 = 1;	//Timer4 set as 1T mode
				T4R = 1;		//Timer run enable
			}
		}
		else	return FAIL;	//ģʽ
		UART4_RxEnable( COMx->UART_RxEnable );	//UARTʹ
		
		return SUCCESS;
	}
#endif
	return FAIL;	//
}

/*********************************************************/

/********************* UART1  ************************/
#ifdef UART1
void TX1_write2buff( u8 dat )	//1ͺ
{
    #if ( UART_QUEUE_MODE == 1 )
	TX1_Buffer[COM1.TX_write] = dat;	//װͻ壬ʹöʽݷͣһԷݳȲҪСCOM_TXn_Lenth
	if (++COM1.TX_write >= COM_TX1_Lenth )	COM1.TX_write = 0;

	if ( COM1.B_TX_busy == 0 )		//
	{  
		COM1.B_TX_busy = 1;		//־æ
		TI = 1;					//ж
	}
    #else
    //ʽͷ
	SBUF = dat;
	COM1.B_TX_busy = 1;		//־æ
	while ( COM1.B_TX_busy );
    #endif
}

void PrintString1( u8 *puts )
{
    for (; *puts != 0;	puts++)  TX1_write2buff(*puts ); 	//ֹͣ0
}

#endif

/********************* UART2  ************************/
#ifdef UART2
void TX2_write2buff( u8 dat )	//2ͺ
{
    #if ( UART_QUEUE_MODE == 1 )
	TX2_Buffer[COM2.TX_write] = dat;	//װͻ壬ʹöʽݷͣһԷݳȲҪСCOM_TXn_Lenth
	if (++COM2.TX_write >= COM_TX2_Lenth )	COM2.TX_write = 0;

	if ( COM2.B_TX_busy == 0 )		//
	{  
		COM2.B_TX_busy = 1;		//־æ
		S2TI = 1;				//ж
	}
    #else
    //ʽͷ
	S2BUF = dat;
	COM2.B_TX_busy = 1;		//־æ
	while ( COM2.B_TX_busy );
    #endif
}

void PrintString2( u8 *puts )
{
    for (; *puts != 0;	puts++)  TX2_write2buff(*puts ); 	//ֹͣ0
}

#endif

/********************* UART3  ************************/
#ifdef UART3
void TX3_write2buff( u8 dat )	//3ͺ
{
    #if ( UART_QUEUE_MODE == 1 )
	TX3_Buffer[COM3.TX_write] = dat;	//װͻ壬ʹöʽݷͣһԷݳȲҪСCOM_TXn_Lenth
	if (++COM3.TX_write >= COM_TX3_Lenth )	COM3.TX_write = 0;

	if ( COM3.B_TX_busy == 0 )		//
	{  
		COM3.B_TX_busy = 1;		//־æ
		S3TI = 1;				//ж
	}
    #else
    //ʽͷ
	S3BUF = dat;
	COM3.B_TX_busy = 1;		//־æ
	while ( COM3.B_TX_busy );
    #endif
}

void PrintString3( u8 *puts )
{
    for (; *puts != 0;	puts++)  TX3_write2buff(*puts ); 	//ֹͣ0
}

#endif

/********************* UART4  ************************/
#ifdef UART4
void TX4_write2buff( u8 dat )	//4ͺ
{
    #if ( UART_QUEUE_MODE == 1 )
	TX4_Buffer[COM4.TX_write] = dat;	//װͻ壬ʹöʽݷͣһԷݳȲҪСCOM_TXn_Lenth
	if (++COM4.TX_write >= COM_TX4_Lenth )	COM4.TX_write = 0;

	if ( COM4.B_TX_busy == 0 )		//
	{  
		COM4.B_TX_busy = 1;		//־æ
		S4TI = 1;				//ж
	}
    #else
    //ʽͷ
	S4BUF = dat;
	COM4.B_TX_busy = 1;		//־æ
	while ( COM4.B_TX_busy );
    #endif
}

void PrintString4( u8 *puts )
{
    for (; *puts != 0;	puts++)  TX4_write2buff(*puts ); 	//ֹͣ0
}

#endif

/*********************************************************/
/*
void COMx_write2buff( u8 UARTx, u8 dat )  //UART1 / ART2 / ART3 / ART4
{
	if ( UARTx == UART1 )	TX1_write2buff( dat );
	if ( UARTx == UART2 )	TX2_write2buff( dat );
	if ( UARTx == UART3 )	TX3_write2buff( dat );
	if ( UARTx == UART4 )	TX4_write2buff( dat );
}

void PrintString( u8 UARTx, u8 *puts )
{
    for (; *puts != 0;	puts++)  COMx_write2buff( UARTx,*puts ); 	//ֹͣ0
}
*/

/********************* Printf  ************************/
#if ( PRINTF_SELECT == 1 )

char putchar( char c )
{
	TX1_write2buff( c );
	return c;
}

#elif( PRINTF_SELECT == 2 )

char putchar( char c )
{
	TX2_write2buff( c );
	return c;
}

#elif( PRINTF_SELECT == 3 )

char putchar( char c )
{
	TX3_write2buff( c );
	return c;
}

#elif( PRINTF_SELECT == 4 )

char putchar( char c )
{
	TX4_write2buff( c );
	return c;
}

#endif
