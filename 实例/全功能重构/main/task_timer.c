#include "boot.h"
#include "led.h"

/*
 * 注意：本文件仅供独立测试定时器0使用。
 * 若与 main.c 共同编译请移除本文件，避免 main() 重复定义。
 */
#ifdef TASK_TIMER_STANDALONE_TEST

void main()
{
    while (1) {

    }
}

#endif


/* 定时器0中断服务函数（中断号1，非0）
 * interrupt 0 = 外部中断0，interrupt 1 = 定时器0中断
 */
void timer0_interrupt() interrupt 1
{
    static uint16_t i = 0;

    if (i % 100 == 0) {
        led_display();
    }

    i = (i + 1) % 8;
}