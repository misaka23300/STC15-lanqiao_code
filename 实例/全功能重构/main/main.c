/**
 * @file main.c
 * @brief 程序入口与基于1ms定时器的任务调度
 * @details 使用 1ms 定时器中断作为基础时基，通过简单计时器变量实现多任务周期执行。
 *          调度思路：
 *            1. 在中断中每 1ms 对任务计时器自增；
 *            2. 在主循环中判断各任务计时器是否达到其周期，达到则执行任务并清零计时器。
 * @date 2025-12-09
 */

#include "main.h"

led_t led = {
    .time = 0,
};


key_t key = {
    .press = 0,
    .time = 0
};


 /**
 * @brief 程序入口
 * @details 初始化硬件后进入主循环，基于计时器变量周期性调用各任务。
 * @note 该函数不返回，应为 MCU 主循环。
 */
void main()
{
    boot_init();
    seg_set(2, 17);
    seg_set(3, 17);
    seg_set(4, 17);
    seg_set(5, 17);
    seg_set(6, 17);
    seg_set(7, 17);
    
    while(1) {
        if (led.time == LED_TIME) {
            led.time = 0;
            led_display();
        }

        if (key.time == KEY_TIME) {
            key.time = 0;
            key_task();
        }
    }
}

/**
 * @brief 定时器1 中断处理，1ms 基准（interrupt 3）
 * @details 在中断中执行短周期显示刷新(seg_display)并对任务计时器自增。
 *          建议仅执行必要的短耗时操作以保证中断及时返回。
 */
void timer_1_1ms() interrupt 3
{
    seg_display();
    if (led.time < LED_TIME) {
        led.time++;
    }
    if (key.time < KEY_TIME) {
        key.time++;
    }
}



void key_task()
{
    

    key.press = key_scan();
    if (key.press != 99) {
        seg_set(0, key.press / 10);
        seg_set(1, key.press % 10);
        
    }
    
    
}