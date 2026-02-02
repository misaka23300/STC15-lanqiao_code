#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>

#define MAX_TASK 8     // 最多 8 个定时任务

typedef struct {
    void (*callback)(void);  // 任务函数
    uint16_t period;         // 周期（ms）
    uint16_t counter;        // 累计计时
} task_t;

void task_add(void (*func)(void), uint16_t period);
void task_run(void);
void task_timer_tick(void);  // 1ms 调用

#endif
