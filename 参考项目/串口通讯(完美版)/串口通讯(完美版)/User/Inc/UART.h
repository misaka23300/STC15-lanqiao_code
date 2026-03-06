#ifndef _UART_H
#define _UART_H

#include "./config.h"//包含配置库

//定义串口1波特率
#define UART1_Buad_Rate 9600L

//定义串口1波特率发生器重装值
#define UART1_Buad_Reload (65536-(MAIN_FOSC/UART1_Buad_Rate/4))

//串口发送缓冲区
extern uchar xdata UART_Tx_Buf[100];

//串口接收缓冲区
extern uchar xdata UART_Rx_Buf[100];

//串口忙标志位数据结构体定义
typedef struct{
	uchar Tx_Flag:1;//串口发送完成标志位
	uchar Rx_Flag:1;//串口接收完成标志位
}UART_FlagTypeDef;

extern UART_FlagTypeDef uart_flag;//定义句柄

//定义串口1计数变量
extern volatile uint UART1_Cnt;

//串口变量初始化函数
void UART_Tag_Init();

//串口1初始化函数
void UART1_Init();

//串口1发送字节函数
void UART1_Send_Byte(uchar byte);

//串口1发送字符串函数
void UART1_Send_Str(uchar* str);

//串口1接收函数
uchar UART1_Rec_Byte();

//串口1接收处理函数
void UART1_Rec();

#endif