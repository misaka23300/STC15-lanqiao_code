#include "./Timer.h"//硬件定时器库
#include "./SMG.h"//数码管库
#include "./UART.h"//硬件串口库
#include "./LED.h"//LED库
#include "./Sys.h"//系统库
#include "./config.h"//全局配置库
#include "intrins.h"//KEIL内部库
#include "string.h"//字符串库
#include "stdio.h"//标准输入输出库

//延时500ms函数
void Delay500ms()
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);	
}

//GPIO口初始化函数
void GPIO_Init()
{
	P0M0 = 0x00; P0M1 = 0x00;//设置为准双向口模式 
	P1M0 = 0x00; P1M1 = 0x00;//设置为准双向口模式  
	P2M0 = 0x00; P2M1 = 0x00;//设置为准双向口模式 
	P3M0 = 0x00; P3M1 = 0x00;//设置为准双向口模式 
	P4M0 = 0x00; P4M1 = 0x00;//设置为准双向口模式 	
}

//全局变量初始化函数
void Tag_Init()
{
	Timer_Tag_Init();//定时器变量初始化函数
	UART_Tag_Init();//串口变量初始化函数
	LED_Tag_Init();//LED变量初始化函数
}

//外设初始化函数
void Perpherial_Init()
{
	P_SW2|=0X80;//允许访问拓展寄存器XSFR
	Timer2_Init();//定时器2初始化函数
	UART1_Init();//串口1初始化函数
	Other_Init();//其他无关外设初始化函数
}

//其他无关外设初始化函数
void Other_Init()
{
	/****初始化蜂鸣器和继电器****/
	Write_HC573(0XA0,0XAF);//关闭蜂鸣器和继电器
	
	/*******初始化数码管**********/
	Write_HC573(0XC0,0XFF);//位选全选中
	Write_HC573(0XE0,0XFF);//段选全关闭	
	
	/*******初始化LED灯***********/
	Write_HC573(0X80,0XFF);//LED灯全部熄灭

}

//系统初始化函数
void Sys_Init()
{
	GPIO_Init();//GPIO口初始化函数
	Tag_Init();//全局变量初始化函数
	Perpherial_Init();//外设初始化函数	
	Delay500ms();//延时500ms等待串口硬件稳定
	sprintf(UART_Tx_Buf,"Welcome to XMF system\r\n");//格式化数组
	UART1_Send_Str((uchar*)UART_Tx_Buf);//发送欢迎语"Welcome to XMF system"	
}