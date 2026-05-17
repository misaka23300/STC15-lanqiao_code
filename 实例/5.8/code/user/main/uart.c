#include "uart.h"

xdata int8_t receive_temp[100] = {0};
xdata int8_t send_temp[100] = {0};

uint8_t tx_flag = 0;
uint8_t rx_flag = 0;

int8_t putchar(int8_t Data) 
{
    
    SBUF = Data;
    while(TI == 0);
    TI = 0;

    return Data;
}

int uart_send_byte(int8_t Data)
{
    SBUF = Data;
    while(TI == 0);
    TI = 0;
    return Data;
}

void uart_send_str(int8_t *str)
{
    // 在函数内部，*str为指针指向的数据
    // str为指针
    while(*str) {
        SBUF = *str;
        while (TI == 0);
        TI = 0;
        str++;
    }
}


void Uart1_Isr(void) interrupt 4
{
	if (TI)				//检测串口1发送中断
	{
		//TI = 0;			//清除串口1发送中断请求位
	}
	if (RI)				//检测串口1接收中断
	{
		RI = 0;			//清除串口1接收中断请求位
	}
}