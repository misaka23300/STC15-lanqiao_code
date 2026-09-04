/*---------------------------------------------------------
MAIN.C

main º¯ÊýÑÝÊ¾ 4¸ö´®¿ÚÍ¬Ê±Ê¹ÓÃ DMA ÊÕ·¢Êý¾Ý, ÊÕµ½Êý¾ÝºóÔ­Â··µ»Ø, ²»ÏÞÊý¾Ý³¤¶È, ³ÖÐøÊÕ·¢.

Àý³ÌÖÐËùÓÐ´®¿Ú9600²¨ÌØÂÊ,Ä¬ÈÏÒý½Å,¶¨Ê±Æ÷2×÷Îª²¨ÌØÂÊ·¢ÉúÆ÷
----------------------------------------------------------*/

#include "Config.h"
#include ".\library\STC32G_GPIO.h"
#include "UART1.h"
#include "UART2.h"
#include "UART3.h"
#include "UART4.h"

/*---------------------------------------------------------
±¾µØº¯ÊýÉùÃ÷
----------------------------------------------------------*/
void Timer0_Init(void);
void XOSCClkConfig(u8 div);
void GPIO_config(void);
void Delay1000ms();


/*---------------------------------------------------------
È«¾Ö±äÁ¿
----------------------------------------------------------*/
u8 ClockSignal=0;

/*---------------------------------------------------------
main
----------------------------------------------------------*/
void main(void)
{
	WTST = 0;		//ÉèÖÃ³ÌÐòÖ¸ÁîÑÓÊ±²ÎÊý£¬¸³ÖµÎª0¿É½«CPUÖ´ÐÐÖ¸ÁîµÄËÙ¶ÈÉèÖÃÎª×î¿ì
	EAXSFR();		//À©Õ¹SFR(XFR)·ÃÎÊÊ¹ÄÜ 
	CKCON = 0;      //Ìá¸ß·ÃÎÊXRAMËÙ¶È
    
    GPIO_config();      //GPIO ³õÊ¼»¯
    
#if USE_Extern_Fosc
    XOSCClkConfig(1);   //ÇÐ»»Ê±ÖÓ
#endif
    
    UART1_Init(9600);   //´®¿Ú1 ³õÊ¼»¯
    UART2_Init(9600);   //´®¿Ú1 ³õÊ¼»¯
    UART3_Init(9600);   //´®¿Ú1 ³õÊ¼»¯
    UART4_Init(9600);   //´®¿Ú1 ³õÊ¼»¯
    Timer0_Init();      //Timer0 ³õÊ¼»¯
    EA = 1;
    
    Delay1000ms();      //µÈ´ý1Ãë, PC¶ËÏÂÔØ´úÂë,1Ãë×Ô¶¯´ò¿ªCDC´®¿Ú
    
    printf("STC32G_UART_DEMO"); //´òÓ¡ÐÅµ½CDC
    
    while(1)
    {
		if(ClockSignal>0)
        {
            u8 uart_dat[32],len;
            
            
			ClockSignal--;
            
            //´®¿Ú1½ÓÊÕ,·¢ËÍ
            do{
                len = UART1_Receive(uart_dat,32);   //¶Á´®¿Ú1ÊÕµ½µÄÊý¾Ý
                UART1_Send(uart_dat,len);           //´®¿Ú1·¢ËÍ¶Áµ½µÄÊý¾Ý
            }while(len==32);
            
            //´®¿Ú2½ÓÊÕ,·¢ËÍ
            do{
                len = UART2_Receive(uart_dat,32);   //¶Á´®¿Ú2ÊÕµ½µÄÊý¾Ý
                UART2_Send(uart_dat,len);           //´®¿Ú2·¢ËÍ¶Áµ½µÄÊý¾Ý
            }while(len==32);
            
            //´®¿Ú3½ÓÊÕ,·¢ËÍ
            do{
                len = UART3_Receive(uart_dat,32);   //¶Á´®¿Ú3ÊÕµ½µÄÊý¾Ý
                UART3_Send(uart_dat,len);           //´®¿Ú3·¢ËÍ¶Áµ½µÄÊý¾Ý
            }while(len==32);
            
            //´®¿Ú4½ÓÊÕ,·¢ËÍ
            do{
                len = UART4_Receive(uart_dat,32);   //¶Á´®¿Ú4ÊÕµ½µÄÊý¾Ý
                UART4_Send(uart_dat,len);           //´®¿Ú4·¢ËÍ¶Áµ½µÄÊý¾Ý
            }while(len==32);
            
		}
    }
}

/*---------------------------------------------------------
GPIO_config
----------------------------------------------------------*/
void GPIO_config(void)
{
	P0_MODE_IO_PU(GPIO_Pin_All);		//P0 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P1_MODE_IO_PU(GPIO_Pin_All);		//P1 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P2_MODE_IO_PU(GPIO_Pin_All);		//P2 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P3_MODE_IO_PU(GPIO_Pin_All);		//P3 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P4_MODE_IO_PU(GPIO_Pin_All);		//P4 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P5_MODE_IO_PU(GPIO_Pin_All);		//P5 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P6_MODE_IO_PU(GPIO_Pin_All);		//P6 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 ÉèÖÃÎª×¼Ë«Ïò¿Ú
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 ÉèÖÃÎª×¼Ë«Ïò¿Ú
}

/*-----------------------------------------------------------*
Timer0_Init
*-----------------------------------------------------------*/
#define OS_TICKS_PER_SEC    50u  /*Ö¸¶¨µÎ´ðÊ±ÖÓÆµÂÊ,ºê×Ô¶¯¼ÆËã×°ÔØÖµ*/
#define TM0PS_VALUE    ( MAIN_Fosc / OS_TICKS_PER_SEC / 65536UL )
#define RELOAD_VALUE   ( 65536UL - MAIN_Fosc / (TM0PS_VALUE+1U) / OS_TICKS_PER_SEC )
void Timer0_Init(void)
{
    AUXR    |=    0x80;                     //1TÄ£Ê½
    TMOD    &=    0XF0;                     //Ä£Ê½0
    TM0PS    =    TM0PS_VALUE;              //·ÖÆµÏµÊý
    TL0 = ( uint8_t )( RELOAD_VALUE );      //×°ÔØÖµ
    TH0 = ( uint8_t )( RELOAD_VALUE >> 8 ); //×°ÔØÖµ
    TF0 = 0;                                //Çå³ý±êÖ¾
    ET0 = 1;                                //Ê¹ÄÜÖÐ¶Ï
    TR0 = 1;                                //¶¨Ê±Æ÷¿ªÆô
}

/*---------------------------------------------------------
Íâ²¿¾§ÕñÊ±ÖÓ³õÊ¼»¯³ÌÐò.  div: Ê±ÖÓ·ÖÆµÏµÊý.
----------------------------------------------------------*/
#if USE_Extern_Fosc
void XOSCClkConfig(u8 div)
{
    P1_MODE_IN_HIZ(GPIO_Pin_7|GPIO_Pin_6);  //GPIOÉèÖÃ
	XOSCCR = 0xC0;                          //Æô¶¯Íâ²¿¾§Õñ
	while (!(XOSCCR & 1));                  //µÈ´ýÊ±ÖÓÎÈ¶¨
	CLKDIV = div;                           //Ê±ÖÓ·ÖÆµ
	CLKSEL = 0x01;                          //Ñ¡ÔñÍâ²¿¾§Õñ
}
#endif


/*---------------------------------------------------------
Timer0 ÖÐ¶Ï
----------------------------------------------------------*/
void Timer0_ISR_Handler (void) interrupt TMR0_VECTOR		//½øÖÐ¶ÏÊ±ÒÑ¾­Çå³ý±êÖ¾
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
	while (i) i--;
}

