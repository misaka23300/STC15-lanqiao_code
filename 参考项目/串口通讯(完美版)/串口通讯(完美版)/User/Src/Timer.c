#include "./Timer.h"//硬件定时器库
#include "./SMG.h"//数码管库
#include "./UART.h"//硬件串口库
#include "./LED.h"//LED库
#include "./Sys.h"//系统库
#include "./config.h"//全局配置库
#include "intrins.h"//KEIL内部库
#include "string.h"//字符串库
#include "stdio.h"//标准输入输出库

Timer_Delay_TypeDef timer_delay;//定义句柄 

//定时器变量初始化函数
void Timer_Tag_Init()
{
	timer_delay.Msecflag1=0x00;
	timer_delay.Msecflag2=0x00;
	timer_delay.Msecflag3=0x00;
	timer_delay.Msecflag4=0x00;
	timer_delay.Msecflag5=0x00;
	timer_delay.Msecflag6=0x00;
	timer_delay.Msecflag7=0x00;
	timer_delay.Msecflag8=0x00;
}

//定时器2初始化函数
void Timer2_Init()
{
	AUXR |= 0x04;//定时器时钟1T模式
	T2L = Timer2_Reload;//设置定时初始值
	T2H = Timer2_Reload>>8;//设置定时初始值
	AUXR |= 0x10;//定时器2开始计时
	IE2 |= 0x04;//使能定时器2中断
	EA=1;//打开总中断
}

//定时器2中断服务函数
void Timer2_Isr() interrupt 12
{
	timer_delay.Msecflag1++;
	timer_delay.Msecflag2++;
	timer_delay.Msecflag3++;
	timer_delay.Msecflag4++;
	timer_delay.Msecflag5++;
	timer_delay.Msecflag6++;
	timer_delay.Msecflag7++;
	timer_delay.Msecflag8++;	
	
	if(timer_delay.Msecflag1==5)//LED刷新时间5ms
	{
		LED_Sta_Handler();//LED状态判断函数
		timer_delay.Msecflag1=0;
	}	
	
	if(timer_delay.Msecflag2==1)//数码管刷新时间1ms
	{	
		SMG_Display(UART_Rx_Buf[0]);
		timer_delay.Msecflag2=0;
	}
	
}