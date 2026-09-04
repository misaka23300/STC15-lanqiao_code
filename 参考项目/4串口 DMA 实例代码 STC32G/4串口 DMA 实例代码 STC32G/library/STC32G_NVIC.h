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

#ifndef	__STC32G_NVIC_H
#define	__STC32G_NVIC_H

#include	"config.h"

//========================================================================
//                              ¶¨ÒåÉùÃ÷
//========================================================================

#define	FALLING_EDGE		1		//²úÉúÏÂ½µÑØÖÐ¶Ï
#define	RISING_EDGE			2		//²úÉúÉÏÉýÑØÖÐ¶Ï

//========================================================================
//                              ¶¨Ê±Æ÷ÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	Timer0_Interrupt(n)		(n==0?(ET0 = 0):(ET0 = 1))				/* Timer0ÖÐ¶ÏÊ¹ÄÜ */
#define 	Timer1_Interrupt(n)		(n==0?(ET1 = 0):(ET1 = 1))				/* Timer1ÖÐ¶ÏÊ¹ÄÜ */
#define 	Timer2_Interrupt(n)		(n==0?(ET2 = 0):(ET2 = 1))				/* Timer2ÖÐ¶ÏÊ¹ÄÜ */
#define 	Timer3_Interrupt(n)		(n==0?(ET3 = 0):(ET3 = 1))				/* Timer3ÖÐ¶ÏÊ¹ÄÜ */
#define 	Timer4_Interrupt(n)		(n==0?(ET4 = 0):(ET4 = 1))				/* Timer4ÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                             Íâ²¿ÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	INT0_Interrupt(n)		(n==0?(EX0 = 0):(EX0 = 1))			/* INT0ÖÐ¶ÏÊ¹ÄÜ */
#define 	INT1_Interrupt(n)		(n==0?(EX1 = 0):(EX1 = 1))			/* INT1ÖÐ¶ÏÊ¹ÄÜ */
#define 	INT2_Interrupt(n)		(n==0?(EX2 = 0):(EX2 = 1))			/* INT2ÖÐ¶ÏÊ¹ÄÜ */
#define 	INT3_Interrupt(n)		(n==0?(EX3 = 0):(EX3 = 1))			/* INT3ÖÐ¶ÏÊ¹ÄÜ */
#define 	INT4_Interrupt(n)		(n==0?(EX4 = 0):(EX4 = 1))			/* INT4ÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                              ADCÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	ADC_Interrupt(n)		(n==0?(EADC = 0):(EADC = 1))	/* ADCÖÐ¶Ï¿ØÖÆ */

//========================================================================
//                              SPIÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	SPI_Interrupt(n)		(n==0?(ESPI = 0):(ESPI = 1))	/* SPIÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                              RTCÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	RTC_Interrupt(n)				RTCIEN = (n)		/* RTCÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                              UARTÖÐ¶ÏÉèÖÃ
//========================================================================

#define		UART1_Interrupt(n)	(n==0?(ES = 0):(ES = 1))					/* UART1ÖÐ¶ÏÊ¹ÄÜ */
#define		UART2_Interrupt(n)	(n==0?(ES2 = 0):(ES2 = 1))				/* UART2ÖÐ¶ÏÊ¹ÄÜ */
#define		UART3_Interrupt(n)	(n==0?(ES3 = 0):(ES3 = 1))				/* UART3ÖÐ¶ÏÊ¹ÄÜ */
#define		UART4_Interrupt(n)	(n==0?(ES4 = 0):(ES4 = 1))				/* UART4ÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                              I2CÖÐ¶ÏÉèÖÃ
//========================================================================

#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0£º½ûÖ¹ I2C ¹¦ÄÜ£»1£ºÊ¹ÄÜ I2C ¹¦ÄÜ

//========================================================================
//                              LINÖÐ¶ÏÉèÖÃ
//========================================================================

#define 	LIN_Interrupt(n)				(n==0?(LINIE = 0):(LINIE = 1))					/* LINÖÐ¶ÏÊ¹ÄÜ */

//========================================================================
//                            ÖÐ¶ÏÓÅÏÈ¼¶¶¨Òå
//========================================================================

//´®¿Ú2ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	UART2_Priority(n)			do{if(n == 0) PS2H = 0, PS2 = 0; \
																if(n == 1) PS2H = 0, PS2 = 1; \
																if(n == 2) PS2H = 1, PS2 = 0; \
																if(n == 3) PS2H = 1, PS2 = 1; \
															}while(0)
//SPIÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	SPI_Priority(n)				do{if(n == 0) PSPIH = 0, PSPI = 0; \
																if(n == 1) PSPIH = 0, PSPI = 1; \
																if(n == 2) PSPIH = 1, PSPI = 0; \
																if(n == 3) PSPIH = 1, PSPI = 1; \
															}while(0)
//Íâ²¿ÖÐ¶Ï4ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	INT4_Priority(n)				do{if(n == 0) PX4H = 0, PX4 = 0; \
																if(n == 1) PX4H = 0, PX4 = 1; \
																if(n == 2) PX4H = 1, PX4 = 0; \
																if(n == 3) PX4H = 1, PX4 = 1; \
															}while(0)
//±È½ÏÆ÷ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	CMP_Priority(n)				do{if(n == 0) PCMPH = 0, PCMP = 0; \
																if(n == 1) PCMPH = 0, PCMP = 1; \
																if(n == 2) PCMPH = 1, PCMP = 0; \
																if(n == 3) PCMPH = 1, PCMP = 1; \
															}while(0)
//I2CÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	I2C_Priority(n)				do{if(n == 0) PI2CH = 0, PI2C = 0; \
																if(n == 1) PI2CH = 0, PI2C = 1; \
																if(n == 2) PI2CH = 1, PI2C = 0; \
																if(n == 3) PI2CH = 1, PI2C = 1; \
															}while(0)
//´®¿Ú3ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	UART3_Priority(n)			do{if(n == 0) PS3H = 0, PS3 = 0; \
																if(n == 1) PS3H = 0, PS3 = 1; \
																if(n == 2) PS3H = 1, PS3 = 0; \
																if(n == 3) PS3H = 1, PS3 = 1; \
															}while(0)
//´®¿Ú4ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	UART4_Priority(n)			do{if(n == 0) PS4H = 0, PS4 = 0; \
																if(n == 1) PS4H = 0, PS4 = 1; \
																if(n == 2) PS4H = 1, PS4 = 0; \
																if(n == 3) PS4H = 1, PS4 = 1; \
															}while(0)

//Íâ²¿ÖÐ¶Ï0ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	INT0_Priority(n)			do{if(n == 0) PX0H = 0, PX0 = 0; \
																if(n == 1) PX0H = 0, PX0 = 1; \
																if(n == 2) PX0H = 1, PX0 = 0; \
																if(n == 3) PX0H = 1, PX0 = 1; \
															}while(0)
//Íâ²¿ÖÐ¶Ï1ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	INT1_Priority(n)			do{if(n == 0) PX1H = 0, PX1 = 0; \
																if(n == 1) PX1H = 0, PX1 = 1; \
																if(n == 2) PX1H = 1, PX1 = 0; \
																if(n == 3) PX1H = 1, PX1 = 1; \
															}while(0)
//¶¨Ê±Æ÷0ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	Timer0_Priority(n)		do{if(n == 0) PT0H = 0, PT0 = 0; \
																if(n == 1) PT0H = 0, PT0 = 1; \
																if(n == 2) PT0H = 1, PT0 = 0; \
																if(n == 3) PT0H = 1, PT0 = 1; \
															}while(0)
//¶¨Ê±Æ÷1ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	Timer1_Priority(n)		do{if(n == 0) PT1H = 0, PT1 = 0; \
																if(n == 1) PT1H = 0, PT1 = 1; \
																if(n == 2) PT1H = 1, PT1 = 0; \
																if(n == 3) PT1H = 1, PT1 = 1; \
															}while(0)
//´®¿Ú1ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	UART1_Priority(n)			do{if(n == 0) PSH = 0, PS = 0; \
																if(n == 1) PSH = 0, PS = 1; \
																if(n == 2) PSH = 1, PS = 0; \
																if(n == 3) PSH = 1, PS = 1; \
															}while(0)
//ADCÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	ADC_Priority(n)				do{if(n == 0) PADCH = 0, PADC = 0; \
																if(n == 1) PADCH = 0, PADC = 1; \
																if(n == 2) PADCH = 1, PADC = 0; \
																if(n == 3) PADCH = 1, PADC = 1; \
															}while(0)
//µÍÑ¹¼ì²âÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	LVD_Priority(n)				do{if(n == 0) PLVDH = 0, PADC = 0; \
																if(n == 1) PLVDH = 0, PADC = 1; \
																if(n == 2) PLVDH = 1, PADC = 0; \
																if(n == 3) PLVDH = 1, PADC = 1; \
															}while(0)
//¸ß¼¶PWMAÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	PWMA_Priority(n)			do{if(n == 0) PPWMAH = 0, PPWMA = 0; \
																if(n == 1) PPWMAH = 0, PPWMA = 1; \
																if(n == 2) PPWMAH = 1, PPWMA = 0; \
																if(n == 3) PPWMAH = 1, PPWMA = 1; \
															}while(0)

//¸ß¼¶PWMBÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	PWMB_Priority(n)			do{if(n == 0) PPWMBH = 0, PPWMB = 0; \
																if(n == 1) PPWMBH = 0, PPWMB = 1; \
																if(n == 2) PPWMBH = 1, PPWMB = 0; \
																if(n == 3) PPWMBH = 1, PPWMB = 1; \
															}while(0)

//RTCÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	RTC_Priority(n)			do{if(n == 0) PRTCH = 0, PRTC = 0; \
																if(n == 1) PRTCH = 0, PRTC = 1; \
																if(n == 2) PRTCH = 1, PRTC = 0; \
																if(n == 3) PRTCH = 1, PRTC = 1; \
															}while(0)

//CAN1ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	CAN1_Priority(n)		do{if(n == 0) PCANH = 0, PCANL = 0; \
																if(n == 1) PCANH = 0, PCANL = 1; \
																if(n == 2) PCANH = 1, PCANL = 0; \
																if(n == 3) PCANH = 1, PCANL = 1; \
															}while(0)

//CAN2ÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	CAN2_Priority(n)		do{if(n == 0) PCAN2H = 0, PCAN2L = 0; \
																if(n == 1) PCAN2H = 0, PCAN2L = 1; \
																if(n == 2) PCAN2H = 1, PCAN2L = 0; \
																if(n == 3) PCAN2H = 1, PCAN2L = 1; \
															}while(0)

//LINÖÐ¶ÏÓÅÏÈ¼¶¿ØÖÆ
#define 	LIN_Priority(n)		do{if(n == 0) PLINH = 0, PLINL = 0; \
																if(n == 1) PLINH = 0, PLINL = 1; \
																if(n == 2) PLINH = 1, PLINL = 0; \
																if(n == 3) PLINH = 1, PLINL = 1; \
															}while(0)


//========================================================================
//                           Íâ²¿º¯ÊýºÍ±äÁ¿ÉùÃ÷
//========================================================================

u8 NVIC_Timer0_Init(u8 State, u8 Priority);
u8 NVIC_Timer1_Init(u8 State, u8 Priority);
u8 NVIC_Timer2_Init(u8 State, u8 Priority);
u8 NVIC_Timer3_Init(u8 State, u8 Priority);
u8 NVIC_Timer4_Init(u8 State, u8 Priority);
u8 NVIC_INT0_Init(u8 State, u8 Priority);
u8 NVIC_INT1_Init(u8 State, u8 Priority);
u8 NVIC_INT2_Init(u8 State, u8 Priority);
u8 NVIC_INT3_Init(u8 State, u8 Priority);
u8 NVIC_INT4_Init(u8 State, u8 Priority);
u8 NVIC_ADC_Init(u8 State, u8 Priority);
u8 NVIC_SPI_Init(u8 State, u8 Priority);
u8 NVIC_RTC_Init(u8 State, u8 Priority);
u8 NVIC_CMP_Init(u8 State, u8 Priority);
u8 NVIC_I2C_Init(u8 Mode, u8 State, u8 Priority);
u8 NVIC_UART1_Init(u8 State, u8 Priority);
u8 NVIC_UART2_Init(u8 State, u8 Priority);
u8 NVIC_UART3_Init(u8 State, u8 Priority);
u8 NVIC_UART4_Init(u8 State, u8 Priority);
u8 NVIC_PWM_Init(u8 Channel, u8 State, u8 Priority);
u8 NVIC_DMA_ADC_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_M2M_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_SPI_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_LCM_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_I2CT_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_I2CR_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART1_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART1_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART2_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART2_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART3_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART3_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART4_Tx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_DMA_UART4_Rx_Init(u8 State, u8 Priority, u8 Bus_Priority);
u8 NVIC_LCM_Init(u8 State, u8 Priority);
u8 NVIC_CAN_Init(u8 Channel, u8 State, u8 Priority);
u8 NVIC_LIN_Init(u8 State, u8 Priority);

#endif

