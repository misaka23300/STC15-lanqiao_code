#include "uart.h"


enum {
    UART_MAX_LEN = 8
};


typedef struct {
    uint8_t receiveData[UART_MAX_LEN];
    uint8_t index;
    
} UART;

UART uart;

void Uart1_Isr(void) interrupt 4
{
    uint8_t Data;

	if (RI)				//检测串口1接收中断
	{
        RI = 0;			//清除串口1接收中断请求位

        Data = SBUF;

        if (uart.Data != '\0' && uart.index < (UART_MAX_LEN - 1) )
        {
            uart.receiveData[index] = uart.Data;
            uart.index++;
        }
        else
        {
            uart.receiveData[index] = '/0';
            uart.index = 0;
        }
	}
}

void Uart1_Init(void)	//9600bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器时钟1T模式
	T2L = 0xC7;			//设置定时初始值
	T2H = 0xFE;			//设置定时初始值
	AUXR |= 0x10;		//定时器2开始计时
	ES = 1;				//使能串口1中断
}


void uartSend(uchar *str)
{
    while (*str != '\0')
    {
        SBUF = *str;
        while (TI == 0);
        TI = 0;
        str++;
    }
}