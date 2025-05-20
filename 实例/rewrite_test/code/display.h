#ifndef __DISPLAY_H__
#define __DISPLAY_H_

#include "machine.h"

// 数码管刷新
void seg_display();

/* // LED灯刷新
void led_display();

// 继电器 输入1为开启 0为关闭
void relay(bit state);

// 蜂鸣器 1为开启 0为关闭
void buzz(bit state);
 */
// 配置数码管的显示数据
void set_seg_value(uchar d0, d1, d2, d3, d4, d5, d6, d7);
/* void set_seg_list(uchar *list); */

/* // 配置led灯的显示数据
void set_led_value(uchar d0, d1, d2, d3, d4, d5, d6, d7); */
#endif