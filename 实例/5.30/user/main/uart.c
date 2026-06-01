#include "uart.h"


uint8_t rx_index = 0;
uint8_t xdata rx_receive_done = 0;

int8_t rx_flag = 0;
int8_t tx_flag = 0;

int8_t xdata rx_temp[100] = {0};
int8_t xdata tx_temp[100] = {0};



int8_t putchar(int8_t Data)
{
    SBUF = Data;
    while (!TI);
    TI = 0;
    return Data;
}


int8_t uart_receive_char()
{
    int8_t byte;
    byte = SBUF;
    while (rx_flag);
    rx_flag = 1;

    return byte;
}

int8_t uart_receive_str()
{
    int8_t byte;
    byte = uart_receive_char();
    rx_temp[rx_index] = byte;

    if (rx_temp[rx_index] == '\n') {
        //rx_is_write = 0;
        rx_index = 0;
        rx_receive_done = 1;
    }
    else {
        rx_index++;
    }
		
	return 0;
}

int8_t clear_rx_temp()
{
    memset(rx_temp, 0, sizeof(rx_temp));

    return 0;
}

void Uart1_Isr(void) interrupt 4
{
	if (TI)				//检测串口1发送中断
	{
		TI = 0;			//清除串口1发送中断请求位
	}
	if (RI)				//检测串口1接收中断
	{
		RI = 0;			//清除串口1接收中断请求位
        rx_flag = 0;
       uart_receive_str();
	}
}


