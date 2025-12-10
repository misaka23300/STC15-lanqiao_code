#include "main.h"


enum {
    LED_TIME = 20,
    KEY_TIME = 15,
    TRC_TIME = 100,
    STATE_TIME = 50,
    RTC_TIME = 1000
};


typedef struct {
    uint8_t time;
} LED;


typedef struct {
    uint8_t time;
    uint8_t press;
} KEY;


typedef struct {
    uint8_t rtc_time;
    uint8_t init_time[7]; // 秒 分 时 天 月 星期 年 
    uint8_t now_time[3];
    uint16_t time;
} RTC;


typedef struct {
    uint8_t time;
    uint8_t mode_0;
} STATE;


LED led;
KEY key;
RTC rtc = {
    0,
    {0x50, 0x59, 0x23, 0x01, 0x01, 0x01, 0x25},
    {0, 0, 0}
};
STATE state;




void main()
{
    
    boot_init();
    
    while (1)
    {
        task_loop();
    }
}

void boot_init()
{
    clean_display();

    Timer1_Init();
    EA = 1;

    write_datetime(rtc.init_time);
}

void task_loop()
{
    if (led.time == LED_TIME)
    {
        led_task();
        led.time = 0;
    }

    if (key.time == KEY_TIME)
    {
        key_task();
        key.time = 0;
    }

    if (rtc.time == TRC_TIME)
    {
        read_datetime(rtc.now_time);
        rtc.time = 0;
    }

    if (state.time == STATE_TIME)
    {
        display_task();
        state.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    if (led.time < LED_TIME) { led.time++; }

    if (key.time < KEY_TIME) { key.time++; }

    if (rtc.time < RTC_TIME) { rtc.time++; }

    if (state.time < STATE_TIME) {state.time++; }

}


void led_task()
{
    led_display();
}


void key_task()
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

void display_task()
{
    switch (state.mode_0)
    {
        case 0:
        {
            set_seg_value(2, 3, 0, 0 ,0 ,0, 0, 0);
        }
        break;

       /*  case 1:
        {
            set_seg()
        } */
    }
}



void write_start_times()
{
    uchar times;
    times = AT24C02_read(0x00);
    times = times + 1;
    AT24C02_write(0x00, times);
}



