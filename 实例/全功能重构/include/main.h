#ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "led.h"
#include "seg.h"
#include "key.h"

void key_task();


enum {
    LED_TIME = 10,
    KEY_TIME = 9,
};

typedef struct {
    uint8_t time;
} led_t;

typedef struct {
    uint8_t time;
    uint8_t press;
} key_t;


#endif

/* 定时型任务创建 

1. 创建枚举，记录执行间隔
2. 创建变量，记录定时
3. while主循环判断是否达到间隔
4. 1ms定时器中断，对变量自加
*/
