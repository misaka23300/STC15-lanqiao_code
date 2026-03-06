#include "./Timer.h"//硬件定时器库
#include "./SMG.h"//数码管库
#include "./UART.h"//硬件串口库
#include "./LED.h"//LED库
#include "./Sys.h"//系统库
#include "./config.h"//全局配置库
#include "intrins.h"//KEIL内部库
#include "string.h"//字符串库
#include "stdio.h"//标准输入输出库

/***************************************************************
											LED控制函数库
1、MCU接收到0XAx(x=0 1 2 4 8)时,x负责控制LED1~LED4的开关
2、MCU接收到0XBx(x=0 1 2 4 8)时,x负责控制LED5~LED8的开关
3、MCU接收到0XC0时,MCU向PC端发送"The System is Running..."
***************************************************************/

LED_ConfigTypeDef led_config;//定义句柄

//LED变量初始化函数
void LED_Tag_Init()
{
	//LED暂存变量,存储LED状态,不能对端口直接进行逻辑操作,
	//否则将会造成不可预估的后果
	led_config.LED_Temp=0x00;
	
	//LED暂存变量高低位变量,分别存储高4位和低4位的LED状态
	led_config.LED_TempH=0X00;
	led_config.LED_TempL=0X00;	
	
	//位状态变量,取值串口接收字节高4位判断对应LED的低4位还是高4位
	led_config.Bit_Sta=0x00;

	//LED状态控制变量,取值串口接收字节低4位判断LED状态
	led_config.LED_Sta=0x00;	
}

//LED位状态判断函数
bit LED_Bit_Handler()
{
	bit Flag_Temp;//位变量中间变量
	
	//将串口接收到的数据高4位赋值给变量
	led_config.Bit_Sta=(UART_Rx_Buf[0]&0xf0)>>4;
	if(led_config.Bit_Sta==0X0A)//如果高4位为A
	{
		Flag_Temp=LED_Low;//返回0:对应的是LED1~LED4
	}
	
	else if(led_config.Bit_Sta==0X0B)//如果高4位为B
	{
		Flag_Temp=LED_High;//返回1:对应的是LED5~LED8
	}
	return Flag_Temp;//将位变量中间变量返回
}

//LED状态判断函数
void LED_Sta_Handler()
{
	bit Sta_Temp;//LED状态中间变量
	
	Sta_Temp=LED_Bit_Handler();//将串口1接收到的高4位存储进LED状态中间变量中
	//将串口接收到的数据低4位赋值给变量
	led_config.Bit_Sta=UART_Rx_Buf[0]&0x0f;	
	if(Sta_Temp==LED_Low)//如果控制的是LED1~LED4
	{
		//直接将低4位的值赋值给LED暂存变量,赋值给P0端口控制LED
		led_config.LED_TempL=led_config.Bit_Sta;
	}
	else if(Sta_Temp==LED_High)//如果控制的是LED5~LED8
	{
		//将低4位的值左移4位再赋值给LED暂存变量,赋值给P0端口控制LED
		led_config.LED_TempH=led_config.Bit_Sta<<4;
	}
	//将LED暂存变量的低位和高位相加,赋值给LED暂存变量,进行LED显示
	led_config.LED_Temp=led_config.LED_TempH+led_config.LED_TempL;
	Write_HC573(0X80,~led_config.LED_Temp);//赋值LED,使得LED显示
}

//LED运行状态指示函数
void LED_Running()
{
	if (UART_Rx_Buf[0]==0xc0&&UART1_Cnt==0)// 确保接收到完整消息
	{
		sprintf(UART_Tx_Buf,"%s","The System is Running...\r\n");
		UART1_Send_Str((uchar*)UART_Tx_Buf); // 发送提示信息
	}
}