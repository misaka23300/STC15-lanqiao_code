#include "uart.h"



int8_t putchar(int8_t ch)
{
    SBUF = ch;

    while(!TI);
    TI = 0;

    return ch;
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
	}
}