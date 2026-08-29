#ifndef __DISPLAY_H__
#define __DISPLAY_H__   /* 修复: 补齐 include guard 末尾下划线, 避免头文件重复包含失效 */

#include "machine.h"

// 数码管刷新
void seg_display(void);

// LED灯刷新
void led_display(void);

// 继电器 输入1为开启 0为关闭
void relay(bit state);

// 蜂鸣器 1为开启 0为关闭
void buzz(bit state);

// 配置数码管的显示数据  修复: 所有参数显式声明 uint8_t, 不再依赖旧式隐式 int
void set_seg_value(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                   uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
void set_seg_list(uint8_t *list);

// 配置led灯的显示数据
void set_led_value(uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                   uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
#endif