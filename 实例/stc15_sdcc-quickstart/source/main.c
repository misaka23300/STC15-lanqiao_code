/**
 * 本例使用芯片：STC15F104W
 * 
 * 主时钟频率：16MHz, 在 config.h 中更改 MAIN_Fosc 调节主时钟频率
 * 
 * 软件 UART：
 *      TX 引脚：P31
 *      波特率：9600
 * 
 * 烧录工具：STC-ISP 
*/

#include "config.h"
#include "delay.h"
#include "soft_uart.h"

#define LED_Toggle() P34 = !P34

void main()
{
    while (1)
    {
        LOG("Hello, STC15F104W !");
        LED_Toggle();
        delay_ms(200);
    }
}
