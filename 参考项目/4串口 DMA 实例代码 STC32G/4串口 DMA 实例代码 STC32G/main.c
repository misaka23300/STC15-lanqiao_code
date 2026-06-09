/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*---------------------------------------------------------
MAIN.C

main ʾ 4ͬʱʹ DMA շ, յݺԭ·, ݳ, շ.

д9600,Ĭ,ʱ2Ϊʷ
----------------------------------------------------------*/

#include "Config.h"
#include ".\library\STC32G_GPIO.h"
#include "UART1.h"
#include "UART2.h"
#include "UART3.h"
#include "UART4.h"

/*---------------------------------------------------------
غ
----------------------------------------------------------*/
void Timer0_Init( void );
void XOSCClkConfig( u8 div );
void GPIO_config( void );
void Delay1000ms();

/*---------------------------------------------------------
ȫֱ
----------------------------------------------------------*/
u8 ClockSignal = ;

/*---------------------------------------------------------
main
----------------------------------------------------------*/
void main( void )
{
	WTST = 0;		//óָʱֵΪ0ɽCPUִָٶΪ
	EAXSFR();		//չSFR( XFR )ʹ 
	CKCON = 0;      //߷XRAMٶ
    
    GPIO_config();      //GPIO ʼ
    
#if USE_Extern_Fosc
    XOSCClkConfig(1 );   //лʱ
#endif
    
    UART1_Init(9600 );   //1 ʼ
    UART2_Init(9600 );   //1 ʼ
    UART3_Init(9600 );   //1 ʼ
    UART4_Init(9600 );   //1 ʼ
    Timer0_Init();      //Timer0 ʼ
    EA = 1;
    
    Delay1000ms();      //ȴ1, PCش, 1ԶCDC
    
    printf("STC32G_UART_DEMO"); //ӡŵCDC
    
    while (1 )
    {
		if ( ClockSignal > )
        {
            u8 uart_dat[32], len;
            
            
			ClockSignal--;
            
            //1,
            do{
                len = UART1_Receive( uart_dat, 32 );   //1յ
                UART1_Send( uart_dat, len );           //1Ͷ
            }while ( len == 2 );
            
            //2,
            do{
                len = UART2_Receive( uart_dat, 32 );   //2յ
                UART2_Send( uart_dat, len );           //2Ͷ
            }while ( len == 2 );
            
            //3,
            do{
                len = UART3_Receive( uart_dat, 32 );   //3յ
                UART3_Send( uart_dat, len );           //3Ͷ
            }while ( len == 2 );
            
            //4,
            do{
                len = UART4_Receive( uart_dat, 32 );   //4յ
                UART4_Send( uart_dat, len );           //4Ͷ
            }while ( len == 2 );
            
		}
    }
}

/*---------------------------------------------------------
GPIO_config
----------------------------------------------------------*/
void GPIO_config( void )
{
	P0_MODE_IO_PU( GPIO_Pin_All );		//P0 Ϊ׼˫
	P1_MODE_IO_PU( GPIO_Pin_All );		//P1 Ϊ׼˫
	P2_MODE_IO_PU( GPIO_Pin_All );		//P2 Ϊ׼˫
	P3_MODE_IO_PU( GPIO_Pin_All );		//P3 Ϊ׼˫
	P4_MODE_IO_PU( GPIO_Pin_All );		//P4 Ϊ׼˫
	P5_MODE_IO_PU( GPIO_Pin_All );		//P5 Ϊ׼˫
	P6_MODE_IO_PU( GPIO_Pin_All );		//P6 Ϊ׼˫
	P7_MODE_IO_PU( GPIO_Pin_All );		//P7 Ϊ׼˫
	P7_MODE_IO_PU( GPIO_Pin_All );		//P7 Ϊ׼˫
}

/*-----------------------------------------------------------*
Timer0_Init
*-----------------------------------------------------------*/
#define OS_TICKS_PER_SEC    50u  /*ָδʱƵ,Զװֵ*/
#define TM0PS_VALUE    ( MAIN_Fosc / OS_TICKS_PER_SEC / 65536UL )
#define RELOAD_VALUE   ( 65536UL - MAIN_Fosc / ( TM0PS_VALUE + U ) / OS_TICKS_PER_SEC )
void Timer0_Init( void )
{
    AUXR    |=    0x80;                     //1Tģʽ
    TMOD    &=    0XF0;                     //ģʽ0
    TM0PS    =    TM0PS_VALUE;              //Ƶϵ
    TL0 = ( uint8_t )( RELOAD_VALUE );      //װֵ
    TH0 = ( uint8_t )( RELOAD_VALUE >> 8 ); //װֵ
    TF0 = 0;                                //־
    ET0 = 1;                                //ʹж
    TR0 = 1;                                //ʱ
}

/*---------------------------------------------------------
ⲿʱӳʼ.  div: ʱӷƵϵ.
----------------------------------------------------------*/
#if USE_Extern_Fosc
void XOSCClkConfig( u8 div )
{
    P1_MODE_IN_HIZ( GPIO_Pin_7|GPIO_Pin_6 );  //GPIO
	XOSCCR = 0xC0;                          //ⲿ
	while (!( XOSCCR & 1 ));                  //ȴʱȶ
	CLKDIV = div;                           //ʱӷƵ
	CLKSEL = 0x01;                          //ѡⲿ
}
#endif

/*---------------------------------------------------------
Timer0 ж
----------------------------------------------------------*/
void Timer0_ISR_Handler ( void ) interrupt TMR0_VECTOR		//жʱѾ־
{
    ClockSignal++;
}

/*---------------------------------------------------------
Delay1000ms
----------------------------------------------------------*/
void Delay1000ms()		//@11.0592MHz
{
	unsigned long edata i;

	_nop_();
	_nop_();
	i = 2764798UL;
	while ( i ) i--;
}

