/**
 * @file led.c
 * @brief LED 位图缓冲与显示刷新模块
 * @details 提供 8 位 LED 显示缓冲（led[]）和逐位刷新函数 led_display()。
 * @date 2025-12-09
 */

#include "led.h"

/**
 * @brief LED 显示缓冲
 * @details 每个元素表示对应位是否点亮（0=灭，非0=亮），
 *          led_display() 会根据该缓冲更新物理 IO。
 */
uint8_t led_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/**
 * @brief LED 逐位刷新显示函数
 * @details 本函数使用静态局部变量维护当前扫描位和临时状态：
 *          - i: 当前扫描位索引（0..7）
 *          - temp: 当前输出位掩码缓存
 *          - last: 上一次输出值，用于避免不必要的 IO 更新
 *
 *          每次调用会处理一位的显示，建议由周期性中断或主循环频繁调用以维持稳定显示。
 *
 * @note 输出到 P0 之前对 temp 取反（~temp）以匹配硬件驱动极性；随后通过 latch(4)/latch(0) 完成锁存。
 * @return void
 */
void led_display()
{
    static uint8_t i;
    static uint8_t temp;
    static uint8_t last = 0xFF;

    if (led_value[i]) {
        temp = temp | (0x01 << i);
    } else {
        temp = temp & ~(0x01 << i);
    }

    if (last != temp) {
        P0 = ~temp;
        latch(4);
        latch(0);
        last = temp;
    }

    i++;
    if (i == 8) {
        i = 0;
    }
}


void led_set(uint8_t position, bit value)
{
    led_value[position] = value;
}