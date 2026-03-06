/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺫﻝﺗﻳﺻ۹ﺿﻌﺏﮊﺷﮨﻅﺷﮌﺗﺽﺣﺑﺯﺑﻲﺡﻣ,ﮄﻣﺿﻌﺏﮊﺷﮨﻅﺷﻉ۱ﺣﺊﮌﺗﺽﺣﭼﺯSTCﭖﺥﻉﮌﭼﺵﺙﺍﺏﮊﺷﮨ            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_NVIC_H
#define	__STC32G_NVIC_H

#include	"FreeRTOS.h"

//========================================================================
//                              ﭘ۷ﺻﮒﺭﻱﺣﺊ
//========================================================================

#define	FALLING_EDGE		1		//ﺎﻲﺭﻲﺵﺡﺛﭖﺹﻊﻅﺷﭘﺵ
#define	RISING_EDGE			2		//ﺎﻲﺭﻲﺭﺵﺭﮮﺹﻊﻅﺷﭘﺵ

//========================================================================
//                              ﭘ۷ﮌﺎﺩﺊﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	Timer0_Interrupt(n)		(n==0?(ET0 = 0):(ET0 = 1))				/* Timer0ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	Timer1_Interrupt(n)		(n==0?(ET1 = 0):(ET1 = 1))				/* Timer1ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	Timer2_Interrupt(n)		(n==0?(ET2 = 0):(ET2 = 1))				/* Timer2ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	Timer3_Interrupt(n)		(n==0?(ET3 = 0):(ET3 = 1))				/* Timer3ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	Timer4_Interrupt(n)		(n==0?(ET4 = 0):(ET4 = 1))				/* Timer4ﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                             ﺱﻗﺎﺟﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	INT0_Interrupt(n)		(n==0?(EX0 = 0):(EX0 = 1))			/* INT0ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	INT1_Interrupt(n)		(n==0?(EX1 = 0):(EX1 = 1))			/* INT1ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	INT2_Interrupt(n)		(n==0?(EX2 = 0):(EX2 = 1))			/* INT2ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	INT3_Interrupt(n)		(n==0?(EX3 = 0):(EX3 = 1))			/* INT3ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define 	INT4_Interrupt(n)		(n==0?(EX4 = 0):(EX4 = 1))			/* INT4ﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                              ADCﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	ADC_Interrupt(n)		(n==0?(EADC = 0):(EADC = 1))	/* ADCﻅﺷﭘﺵﺟﻊﻅﺩ */

//========================================================================
//                              SPIﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	SPI_Interrupt(n)		(n==0?(ESPI = 0):(ESPI = 1))	/* SPIﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                              RTCﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	RTC_Interrupt(n)				RTCIEN = (n)		/* RTCﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                              UARTﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define		UART1_Interrupt(n)	(n==0?(ES = 0):(ES = 1))					/* UART1ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define		UART2_Interrupt(n)	(n==0?(ES2 = 0):(ES2 = 1))				/* UART2ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define		UART3_Interrupt(n)	(n==0?(ES3 = 0):(ES3 = 1))				/* UART3ﻅﺷﭘﺵﮌﺗﺥﻎ */
#define		UART4_Interrupt(n)	(n==0?(ES4 = 0):(ES4 = 1))				/* UART4ﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                              I2Cﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0۲ﭦﺛﻳﻅﺗ I2C ﺗ۵ﺥﻎ۲ﭨ1۲ﭦﮌﺗﺥﻎ I2C ﺗ۵ﺥﻎ

//========================================================================
//                              LINﻅﺷﭘﺵﺭﻟﻅﺣ
//========================================================================

#define 	LIN_Interrupt(n)				(n==0?(LINIE = 0):(LINIE = 1))					/* LINﻅﺷﭘﺵﮌﺗﺥﻎ */

//========================================================================
//                            ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﭘ۷ﺻﮒ
//========================================================================

//ﺑ؟ﺟﻌ2ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	UART2_Priority(n)			do{if(n == 0) PS2H = 0, PS2 = 0; \
																if(n == 1) PS2H = 0, PS2 = 1; \
																if(n == 2) PS2H = 1, PS2 = 0; \
																if(n == 3) PS2H = 1, PS2 = 1; \
															}while(0)
//SPIﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	SPI_Priority(n)				do{if(n == 0) PSPIH = 0, PSPI = 0; \
																if(n == 1) PSPIH = 0, PSPI = 1; \
																if(n == 2) PSPIH = 1, PSPI = 0; \
																if(n == 3) PSPIH = 1, PSPI = 1; \
															}while(0)
//ﺱﻗﺎﺟﻅﺷﭘﺵ4ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	INT4_Priority(n)				do{if(n == 0) PX4H = 0, PX4 = 0; \
																if(n == 1) PX4H = 0, PX4 = 1; \
																if(n == 2) PX4H = 1, PX4 = 0; \
																if(n == 3) PX4H = 1, PX4 = 1; \
															}while(0)
//ﺎﺫﺛﺵﺩﺊﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	CMP_Priority(n)				do{if(n == 0) PCMPH = 0, PCMP = 0; \
																if(n == 1) PCMPH = 0, PCMP = 1; \
																if(n == 2) PCMPH = 1, PCMP = 0; \
																if(n == 3) PCMPH = 1, PCMP = 1; \
															}while(0)
//I2Cﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	I2C_Priority(n)				do{if(n == 0) PI2CH = 0, PI2C = 0; \
																if(n == 1) PI2CH = 0, PI2C = 1; \
																if(n == 2) PI2CH = 1, PI2C = 0; \
																if(n == 3) PI2CH = 1, PI2C = 1; \
															}while(0)
//ﺑ؟ﺟﻌ3ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	UART3_Priority(n)			do{if(n == 0) PS3H = 0, PS3 = 0; \
																if(n == 1) PS3H = 0, PS3 = 1; \
																if(n == 2) PS3H = 1, PS3 = 0; \
																if(n == 3) PS3H = 1, PS3 = 1; \
															}while(0)
//ﺑ؟ﺟﻌ4ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	UART4_Priority(n)			do{if(n == 0) PS4H = 0, PS4 = 0; \
																if(n == 1) PS4H = 0, PS4 = 1; \
																if(n == 2) PS4H = 1, PS4 = 0; \
																if(n == 3) PS4H = 1, PS4 = 1; \
															}while(0)

//ﺱﻗﺎﺟﻅﺷﭘﺵ0ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	INT0_Priority(n)			do{if(n == 0) PX0H = 0, PX0 = 0; \
																if(n == 1) PX0H = 0, PX0 = 1; \
																if(n == 2) PX0H = 1, PX0 = 0; \
																if(n == 3) PX0H = 1, PX0 = 1; \
															}while(0)
//ﺱﻗﺎﺟﻅﺷﭘﺵ1ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	INT1_Priority(n)			do{if(n == 0) PX1H = 0, PX1 = 0; \
																if(n == 1) PX1H = 0, PX1 = 1; \
																if(n == 2) PX1H = 1, PX1 = 0; \
																if(n == 3) PX1H = 1, PX1 = 1; \
															}while(0)
//ﭘ۷ﮌﺎﺩﺊ0ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	Timer0_Priority(n)		do{if(n == 0) PT0H = 0, PT0 = 0; \
																if(n == 1) PT0H = 0, PT0 = 1; \
																if(n == 2) PT0H = 1, PT0 = 0; \
																if(n == 3) PT0H = 1, PT0 = 1; \
															}while(0)
//ﭘ۷ﮌﺎﺩﺊ1ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	Timer1_Priority(n)		do{if(n == 0) PT1H = 0, PT1 = 0; \
																if(n == 1) PT1H = 0, PT1 = 1; \
																if(n == 2) PT1H = 1, PT1 = 0; \
																if(n == 3) PT1H = 1, PT1 = 1; \
															}while(0)
//ﺑ؟ﺟﻌ1ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	UART1_Priority(n)			do{if(n == 0) PSH = 0, PS = 0; \
																if(n == 1) PSH = 0, PS = 1; \
																if(n == 2) PSH = 1, PS = 0; \
																if(n == 3) PSH = 1, PS = 1; \
															}while(0)
//ADCﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	ADC_Priority(n)				do{if(n == 0) PADCH = 0, PADC = 0; \
																if(n == 1) PADCH = 0, PADC = 1; \
																if(n == 2) PADCH = 1, PADC = 0; \
																if(n == 3) PADCH = 1, PADC = 1; \
															}while(0)
//ﭖﺱﺹﺗﺙﮞﺎﻗﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	LVD_Priority(n)				do{if(n == 0) PLVDH = 0, PADC = 0; \
																if(n == 1) PLVDH = 0, PADC = 1; \
																if(n == 2) PLVDH = 1, PADC = 0; \
																if(n == 3) PLVDH = 1, PADC = 1; \
															}while(0)
//ﺕﻑﺙﭘPWMAﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	PWMA_Priority(n)			do{if(n == 0) PPWMAH = 0, PPWMA = 0; \
																if(n == 1) PPWMAH = 0, PPWMA = 1; \
																if(n == 2) PPWMAH = 1, PPWMA = 0; \
																if(n == 3) PPWMAH = 1, PPWMA = 1; \
															}while(0)

//ﺕﻑﺙﭘPWMBﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	PWMB_Priority(n)			do{if(n == 0) PPWMBH = 0, PPWMB = 0; \
																if(n == 1) PPWMBH = 0, PPWMB = 1; \
																if(n == 2) PPWMBH = 1, PPWMB = 0; \
																if(n == 3) PPWMBH = 1, PPWMB = 1; \
															}while(0)

//RTCﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	RTC_Priority(n)			do{if(n == 0) PRTCH = 0, PRTC = 0; \
																if(n == 1) PRTCH = 0, PRTC = 1; \
																if(n == 2) PRTCH = 1, PRTC = 0; \
																if(n == 3) PRTCH = 1, PRTC = 1; \
															}while(0)

//CAN1ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	CAN1_Priority(n)		do{if(n == 0) PCANH = 0, PCANL = 0; \
																if(n == 1) PCANH = 0, PCANL = 1; \
																if(n == 2) PCANH = 1, PCANL = 0; \
																if(n == 3) PCANH = 1, PCANL = 1; \
															}while(0)

//CAN2ﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	CAN2_Priority(n)		do{if(n == 0) PCAN2H = 0, PCAN2L = 0; \
																if(n == 1) PCAN2H = 0, PCAN2L = 1; \
																if(n == 2) PCAN2H = 1, PCAN2L = 0; \
																if(n == 3) PCAN2H = 1, PCAN2L = 1; \
															}while(0)

//LINﻅﺷﭘﺵﺽﺧﺵﺫﺙﭘﺟﻊﻅﺩ
#define 	LIN_Priority(n)		do{if(n == 0) PLINH = 0, PLINL = 0; \
																if(n == 1) PLINH = 0, PLINL = 1; \
																if(n == 2) PLINH = 1, PLINL = 0; \
																if(n == 3) PLINH = 1, PLINL = 1; \
															}while(0)


//========================================================================
//                           ﺱﻗﺎﺟﭦﺁﮌﮮﭦﺱﺎﻛﭼﺟﺭﻱﺣﺊ
//========================================================================

uint8_t NVIC_Timer0_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_Timer1_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_Timer2_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_Timer3_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_Timer4_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_INT0_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_INT1_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_INT2_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_INT3_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_INT4_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_ADC_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_SPI_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_RTC_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_CMP_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_I2C_Init(uint8_t Mode, uint8_t State, uint8_t Priority);
uint8_t NVIC_UART1_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_UART2_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_UART3_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_UART4_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_PWM_Init(uint8_t Channel, uint8_t State, uint8_t Priority);
uint8_t NVIC_DMA_ADC_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_M2M_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_SPI_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_LCM_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_I2CT_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_I2CR_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART1_Tx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART1_Rx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART2_Tx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART2_Rx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART3_Tx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART3_Rx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART4_Tx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_DMA_UART4_Rx_Init(uint8_t State, uint8_t Priority, uint8_t Bus_Priority);
uint8_t NVIC_LCM_Init(uint8_t State, uint8_t Priority);
uint8_t NVIC_CAN_Init(uint8_t Channel, uint8_t State, uint8_t Priority);
uint8_t NVIC_LIN_Init(uint8_t State, uint8_t Priority);

#endif

