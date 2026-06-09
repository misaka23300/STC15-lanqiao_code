/**
 * @file task_timer.c
 * @brief 定时器驱动文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "boot.h"

void main() {
	while (1) {
	}
}

void timer0_interrupt() interrupt 0 {
	static uint16_t i;

	if (i % 100 == 0) {
		led_display();
	}

	i = (i + 1) % 8;
}