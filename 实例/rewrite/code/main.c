#include "main.h"

enum {
    LED_TIME = 20,
    KEY_TIME = 15,
    TRC_TIME = 100
};

struct {
    uchar time;
   
} led;

struct {
    uchar time;
    uchar press;
} key;

typedef struct {
    uchar rtc_time;
    uchar code init_time[7]; // 秒 分 时 天 月 星期 年 
    uchar now_time[3];
} RTC;

RTC rtc = {
    0,
    {0x50, 0x59, 0x23, 0x01, 0x01, 0x01, 0x25},
    {0, 0, 0}
};



void main()
{
    
    boot_init();

    while (1)
    {
        check_time();
    }
}

void boot_init()
{
    clean_display();
    Timer1_Init();
    EA = 1;
    write_datetime(rtc.init_time);
}

void check_time()
{
    if (led.time == LED_TIME)
    {
        led_proc();
        led.time = 0;
    }

    if (key.time == KEY_TIME)
    {
        key_proc();
        key.time = 0;
    }

    if (rtc.time == TRC_TIME)
    {
        read_datetime(rtc.now_time);
        rtc.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    if (led.time < LED_TIME) { led.time++; }

    if (key.time < KET_TIME) { key.time++; }

    if (rtc.time < RTC_TIME) { rtc.time++; }

}


void led_proc()
{
    led_display();
}


void key_proc()
{
    key.press = key_scan();

    switch (key.press)
    {
        case 4:
        {

        }
        break;
    }

}