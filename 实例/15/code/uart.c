#include "uart.h"



idata UART uart;
INPUT input;


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
    if (RI)
    {
        RI = 0;
        
        ET1 = 0;
        seg_list[0] = 1;
        // 串口超时判断
        uart.out_time = 0;
        uart.out_time_flag = 1;

        uart.receive_data[uart.index] = SBUF;
        uart.index++;

        if (uart.index > RECEIVE_LEN) {uart.index = 0; }
        ET1 = 1;
        PT1 = 1;
    }
}

void get_position() // uart.receive_data -> input.x input.y
{
    uchar i = 0;
    uchar towards = 0;

    input.x = 0;
    input.y = 0;

    while (uart.receive_data[i] != ')')
    {
        if (uart.receive_data[i] >= '0' && uart.receive_data[i] <= '9')
        {
            if (towards == 0)
            {
                input.x = input.x * 10 + (uart.receive_data[i] - '0'); 
            }
            else
            {
                input.y = input.y * 10 + (uart.receive_data[i] - '0');
            }  
        }
        else if (uart.receive_data[i] == ',' )
        {
            towards = 1;
        }
        
        i++;
    }
}



char putchar(char c) 
{
    SBUF = c;         // 发送字符到串口
    while (!TI);      // 等待发送完成
    TI = 0;           // 清除发送中断标志
    return c;
}
