#include "task.h"

task_t tasks[MAX_TASK];
uint8_t task_count = 0;

/* 添加一个定时任务 */
void task_add(void (*func)(void), uint16_t period)
{
    if (task_count < MAX_TASK) {
        tasks[task_count].callback = func;
        tasks[task_count].period   = period;
        tasks[task_count].counter  = 0;
        task_count++;
    }
}

/* 在主循环中执行任务 */
void task_run(void)
{
    uint8_t i;
    for (i = 0; i < task_count; i++) {
        if (tasks[i].counter >= tasks[i].period) {
            tasks[i].counter = 0;
            tasks[i].callback();    // 执行任务
        }
    }
}

/* 1ms 调用一次（在定时器中断里用） */
void task_timer_tick(void)
{
    uint8_t i;
    for (i = 0; i < task_count; i++) {
        if (tasks[i].counter < tasks[i].period) {
            tasks[i].counter++;
        }
    }
}
