/*---------------------------------------------------------
MAIN.C

main 函数演示 4个串口同时使用 DMA 收发数据, 收到数据后原路返回, 不限数据长度, 持续收发.

例程中所有串口9600波特率,默认引脚,定时器2作为波特率发生器
----------------------------------------------------------*/

#include "Config.h"
#include ".\library\STC32G_GPIO.h"
#include "UART1.h"
#include "UART2.h"
#include "UART3.h"
#include "UART4.h"

/*---------------------------------------------------------
本地函数声明
----------------------------------------------------------*/
void Timer0_Init(void);
void XOSCClkConfig(u8 div);
void GPIO_config(void);
void Delay1000ms();


/*---------------------------------------------------------
全局变量
----------------------------------------------------------*/
u8 ClockSignal=0;

/*---------------------------------------------------------
main
----------------------------------------------------------*/
void main(void)
{
	WTST = 0;		//设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
	EAXSFR();		//扩展SFR(XFR)访问使能 
	CKCON = 0;      //提高访问XRAM速度
    
    GPIO_config();      //GPIO 初始化
    
#if USE_Extern_Fosc
    XOSCClkConfig(1);   //切换时钟
#endif
    
    UART1_Init(9600);   //串口1 初始化
    UART2_Init(9600);   //串口1 初始化
    UART3_Init(9600);   //串口1 初始化
    UART4_Init(9600);   //串口1 初始化
    Timer0_Init();      //Timer0 初始化
    EA = 1;
    
    Delay1000ms();      //等待1秒, PC端下载代码,1秒自动打开CDC串口
    
    printf("STC32G_UART_DEMO"); //打印信到CDC
    
    while(1)
    {
		if(ClockSignal>0)
        {
            u8 uart_dat[32],len;
            
            
			ClockSignal--;
            
            //串口1接收,发送
            do{
                len = UART1_Receive(uart_dat,32);   //读串口1收到的数据
                UART1_Send(uart_dat,len);           //串口1发送读到的数据
            }while(len==32);
            
            //串口2接收,发送
            do{
                len = UART2_Receive(uart_dat,32);   //读串口2收到的数据
                UART2_Send(uart_dat,len);           //串口2发送读到的数据
            }while(len==32);
            
            //串口3接收,发送
            do{
                len = UART3_Receive(uart_dat,32);   //读串口3收到的数据
                UART3_Send(uart_dat,len);           //串口3发送读到的数据
            }while(len==32);
            
            //串口4接收,发送
            do{
                len = UART4_Receive(uart_dat,32);   //读串口4收到的数据
                UART4_Send(uart_dat,len);           //串口4发送读到的数据
            }while(len==32);
            
		}
    }
}

/*---------------------------------------------------------
GPIO_config
----------------------------------------------------------*/
void GPIO_config(void)
{
	P0_MODE_IO_PU(GPIO_Pin_All);		//P0 设置为准双向口
	P1_MODE_IO_PU(GPIO_Pin_All);		//P1 设置为准双向口
	P2_MODE_IO_PU(GPIO_Pin_All);		//P2 设置为准双向口
	P3_MODE_IO_PU(GPIO_Pin_All);		//P3 设置为准双向口
	P4_MODE_IO_PU(GPIO_Pin_All);		//P4 设置为准双向口
	P5_MODE_IO_PU(GPIO_Pin_All);		//P5 设置为准双向口
	P6_MODE_IO_PU(GPIO_Pin_All);		//P6 设置为准双向口
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 设置为准双向口
	P7_MODE_IO_PU(GPIO_Pin_All);		//P7 设置为准双向口
}

/*-----------------------------------------------------------*
Timer0_Init
*-----------------------------------------------------------*/
#define OS_TICKS_PER_SEC    50u  /*指定滴答时钟频率,宏自动计算装载值*/
#define TM0PS_VALUE    ( MAIN_Fosc / OS_TICKS_PER_SEC / 65536UL )
#define RELOAD_VALUE   ( 65536UL - MAIN_Fosc / (TM0PS_VALUE+1U) / OS_TICKS_PER_SEC )
void Timer0_Init(void)
{
    AUXR    |=    0x80;                     //1T模式
    TMOD    &=    0XF0;                     //模式0
    TM0PS    =    TM0PS_VALUE;              //分频系数
    TL0 = ( uint8_t )( RELOAD_VALUE );      //装载值
    TH0 = ( uint8_t )( RELOAD_VALUE >> 8 ); //装载值
    TF0 = 0;                                //清除标志
    ET0 = 1;                                //使能中断
    TR0 = 1;                                //定时器开启
}

/*---------------------------------------------------------
外部晶振时钟初始化程序.  div: 时钟分频系数.
----------------------------------------------------------*/
#if USE_Extern_Fosc
void XOSCClkConfig(u8 div)
{
    P1_MODE_IN_HIZ(GPIO_Pin_7|GPIO_Pin_6);  //GPIO设置
	XOSCCR = 0xC0;                          //启动外部晶振
	while (!(XOSCCR & 1));                  //等待时钟稳定
	CLKDIV = div;                           //时钟分频
	CLKSEL = 0x01;                          //选择外部晶振
}
#endif


/*---------------------------------------------------------
Timer0 中断
----------------------------------------------------------*/
void Timer0_ISR_Handler (void) interrupt TMR0_VECTOR		//进中断时已经清除标志
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

