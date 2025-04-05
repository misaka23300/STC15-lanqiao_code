#include "main.h"

enum {
    UART_TASK = 2000
};

struct {
    uint time; 
    
} uart;

void main()
{
    uchar send_data[] = "ciallo~ \r \n";
    boot_init();
    
    while (1)
    {
        if (uart.time == UART_TASK)
        {
            uart.time = 0;
            uart_send(send_data);
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    if (uart.time < UART_TASK) { uart.time++; }
}

void uart_send(uchar *str)
{
    while (*str != '\0')
    {
        SBUF = *str;
        while (TI == 0);
        TI = 0;
        str++;
    }
}

void uart_receive() interrupt 4
{
	if(RI)
	{
		RI=0;
		//LED_BUFF = SBUF;//获取串口数据点灯
	}
}

