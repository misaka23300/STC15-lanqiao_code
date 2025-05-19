 #ifndef __MAIN_H__
#define __MAIN_H__

#include "boot.h"
#include "display.h"
#include "key.h"
#include "iic.h"

enum {
    LED_TIME = 20,
    KEY_TIME = 15,
    TRC_TIME = 100,
    STATE_TIME = 50
};


typedef struct {
    uchar time;
} LED;


typedef struct {
    uchar time;
    uchar press;
} KEY;


typedef struct {
    uchar rtc_time;
    uchar code init_time[7]; // 秒 分 时 天 月 星期 年 
    uchar now_time[3];
} RTC;



#endif