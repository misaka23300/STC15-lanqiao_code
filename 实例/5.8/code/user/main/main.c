#include "main.h"

enum {
    KEY_TIME = 20,
    SEG_TIME = 200,
    DISPLAY_TIME = 50,
    SONIC_TIME = 400,
    LED_TIME = 16,
    DELAY_100ms = 100,
} ;


idata uint8_t key_time = 0;
idata uint16_t seg_time = 0;
idata uint16_t display_time = 0;
idata uint16_t sonic_time  = 0;
idata uint8_t led_time = 0;

xdata uint8_t work_3s_flag = 0;
xdata uint16_t work_3s_time = 0;

void main()
{
    boot_init();
    uart_send();
    while (1) {
        if (seg_time >= SEG_TIME) {
            seg_time = 0;
            //seg_task();

        }

        if (display_time >= DISPLAY_TIME) {
            display_time = 0;
            display_task();
        }

        if (key_time >= KEY_TIME) {
            key_time = 0;
            key_task();
        }

        if (sonic_time >= SONIC_TIME) {
            sonic_time = 0;
            sonic_task();
        }


        if (led_time >= LED_TIME) {
            led_time = 0;
            led_display(7, !TI);
        }

        if (work_3s_flag && work_3s_time >= 3000) {
            work_3s();
            work_3s_flag = 0;
            work_3s_time = 0;
        }
    }



    
}

// 定时器延时方案
//变量: 标志位、计数变量

//中断: 在标志位为1时,累加计数变量
//调用函数:调用第一次函数,把标志置为1
//主循环:标志为1时,判断是否到时间
void work_3s()
{
    if (work_3s_flag == 0) {
        work_3s_flag = 1;
        relay(1);
    }
    else {
        relay(0);
    }
}


void Timer2_Isr(void) interrupt 12
{
    seg_display();
    seg_time++;
    display_time++;
    key_time++;
    sonic_time++;
    led_time++;

    if (work_3s_flag) {
        work_3s_time++;
    }
}
