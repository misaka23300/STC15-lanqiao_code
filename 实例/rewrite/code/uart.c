#include "uart.h"

typedef struct {
	uchar idata buffData[16];
	uchar buffIndex;
} UART;

UART uart;


void Uart1_Init(void)	//4800bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0xC0;			//设置定时初始值
	TH1 = 0xFD;			//设置定时初始值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES = 1;				//使能串口1中断
}


void uart_receive() interrupt 4
{
	uchar temp;

	if(RI)
	{
		RI = 0;
		temp = SBUF;
		if (temp != '\0')
		{
			if (uart.buffIdnex < 16)
			{
				uart.buffData[uart.buffIndex] = temp;
				uart.buffIndex++;
			}
		}
		else
		{
			uart.buffIndex = 0;
		}
	}
}


