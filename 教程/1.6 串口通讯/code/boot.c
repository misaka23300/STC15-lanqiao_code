#include "boot.h"

void boot_init()
{
    Timer1_Init();
    timer_2();
    EA = 1;
}

// timer2 -> 串口
// timer1 -> 1ms

void timer_2()
{
    SCON = 0x50;    // 8位Uart, 允许接受数据
    AUXR |= 0x01;    // 定时器2作为波特率发生器
    AUXR |= 0x04;    // 定时器工作在1T模式

    // 设置波特率4800bps
    T2L = 0x8F;
    T2H = 0xFD;

    AUXR |= 0x10;   // 定时器开始计数
    ES = 1;         // 允许串口中断 
}

void Timer1_Init(void)		//1毫秒@12.000MHz
{
	AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x18;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
}

