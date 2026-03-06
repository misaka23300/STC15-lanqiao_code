#include "./Timer.h"//硬件定时器库
#include "./SMG.h"//数码管库
#include "./UART.h"//硬件串口库
#include "./LED.h"//LED库
#include "./Sys.h"//系统库
#include "./config.h"//全局配置库
#include "intrins.h"//KEIL内部库
#include "string.h"//字符串库
#include "stdio.h"//标准输入输出库

//串口发送缓冲区
uchar xdata UART_Tx_Buf[100];

//串口接收缓冲区
uchar xdata UART_Rx_Buf[100];

UART_FlagTypeDef uart_flag;//定义句柄

volatile uint UART1_Cnt;//定义串口1计数变量

//串口变量初始化函数
void UART_Tag_Init()
{
	uint i;//数组清空计数变量
	
	uart_flag.Tx_Flag=0;//串口发送完成标志位
	uart_flag.Rx_Flag=0;//串口接收完成标志位	
	UART1_Cnt=0;//定义串口1计数变量
	for(i=0;i<sizeof(UART_Rx_Buf)-1;i++)//清空所有数组的元素
	{
		UART_Rx_Buf[i]=0x00;//全部清空为0
	}
}

//串口1初始化函数
void UART1_Init()
{
	SCON = 0x50;//8位数据,可变波特率
	AUXR |= 0x40;//定时器时钟1T模式
	AUXR &= 0xFE;//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;//设置定时器模式
	TL1 = UART1_Buad_Reload;//设置定时初始值
	TH1 = UART1_Buad_Reload>>8;//设置定时初始值
	ET1 = 0;//禁止定时器中断
	TR1 = 1;//定时器1开始计时
	ES = 1;//使能串口1中断
	PS=1;
	EA=1;//打开总中断
}

//串口1发送字节函数
//采用中断式发送
void UART1_Send_Byte(uchar byte)
{
	SBUF=byte;//将发送数据字节载入写SBUF中,触发TI中断
	while(uart_flag.Tx_Flag);//检测发送忙标志位是否置1
	uart_flag.Tx_Flag=1;//如果此时忙标志位为0,则置位为1
}

//串口1发送字符串函数
//采用轮询式发送
void UART1_Send_Str(uchar* str)
{
	while(*str)//如果字符串对应的内容不为NULL
	{
		SBUF=*str;//将指针指向的地址内容通过写SBUF进行发送
		while(!TI);//检测TI是否为1
		TI=0;//如果TI为1,则将其归零
		str++;//指针指向下一个地址
	}
}

//putchar重定向函数uar
//通过此函数可以使用printf函数,进行串口1的发送,轮询式
char putchar(char ch)
{
	SBUF=ch;//将捕获到的字节通过写SBUF进行发送
	while(!TI);//检测TI是否为1
	TI=0;//如果TI为1,则将其归零
	return ch;//返回字节,供给printf使用
}

//串口1接收函数
uchar UART1_Rec_Byte()
{
	uchar byte;//串口接收到的字节
	byte=SBUF;//将字节从读SBUF中读取出来
	while(uart_flag.Rx_Flag);//等待串口忙标志位归零
	uart_flag.Rx_Flag=1;//如果准备好,接收下一个字节,将串口忙标志位置位为1
	return byte;//将串口接收到的字节返回
}

//串口1接收处理函数
void UART1_Rec()
{
	static uchar dat;
	dat=UART1_Rec_Byte();
	UART_Rx_Buf[UART1_Cnt]=dat;//将获取到的字节送入串口接收缓冲区
	if(UART_Rx_Buf[UART1_Cnt-1]==0x0d&&
		UART_Rx_Buf[UART1_Cnt]==0x0a)//判断是否收到了回车与换行符
	{
		UART1_Cnt=0;//如果字符接收完成,将串口计数变量归零
	}
		
	else
	{
		UART1_Cnt++;//随着接收字节的累加,串口计数变量累加
	}
}

//串口1中断服务函数
void UART1_Isr() interrupt 4
{
	if(RI)//如果串口1接收中断标志位置位为1
	{
		RI=0;//清零串口1接收中断标志位
		uart_flag.Rx_Flag=0;//串口接收完成标志位
		UART1_Rec();//串口1接收处理函数
		LED_Running();//LED运行状态指示函数
	}
	
	if(TI)//如果串口1发送中断标志位置位为1
	{
		TI=0;//清零串口1发送中断标志位
		uart_flag.Tx_Flag=0;//串口发送完成标志位
	}	
}