#include "main.h"

enum
{
    LED_TIME = 10,
    KEY_TIME = 15,
    FREQ_TIME = 1000,
    RTC_TIME = 100,
};

uint8_t led_time;
uint8_t key_time;
uint16_t freq_time;
uint8_t rtc_time;

uint8_t press;

uint8_t display_state = 1;

uint16_t freq;
uint16_t freq_out;

void key_task()
{
    //press = key_scan();
    display();

    if (press == 4)
    {
        display_state++;
        if (display_state == 3)
        {
            display_state = 0;
        }
    }
}

void display()
{
    switch (display_state)
    {
    case 0:
    {
        if (press != 99)
        {
            set_seg(0, press / 10 % 10);
            set_seg(1, press % 10);
            set_seg(2, 16);
            set_seg(3, 16);
            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, 16);
            set_seg(7, 16);
        }
    }
    break;

    case 1:
    {
        set_seg(0, freq_out / 10000 % 10);
        set_seg(1, freq_out / 1000 % 10);
        set_seg(2, freq_out / 100 % 10);
        set_seg(3, freq_out / 10 % 10);
        set_seg(4, freq_out % 10);
        set_seg(5, 16);
        set_seg(6, 16);
        set_seg(7, 16);
    }
    break;

    case 2:
    {
        set_seg(0, now_time[2] / 10 % 10);
        set_seg(1, now_time[2] % 10);
        set_seg(2, 17);
        set_seg(3, now_time[1] / 10 % 10);
        set_seg(4, now_time[1] % 10);
        set_seg(5, 17);
        set_seg(6, now_time[0] / 10 % 10);
        set_seg(7, now_time[0] % 10);
    }
    break;
    }
}

void main()
{
    boot_init();
    ds1302_write();
    while (1)
    {
        if (led_time >= LED_TIME)
        {
            // led_display();
        }

        if (key_time >= KEY_TIME)
        {
            key_task();
            key_time = 0;
        }

        if (freq_time >= FREQ_TIME)
        {
            freq_time = 0;
            freq_task();
        }

        if (rtc_time >= RTC_TIME)
        {
            ds1302_read();
            rtc_time = 0;
        }
    }
}

void freq_task()

{
    freq_out = freq;
    freq = 0;
}

void Timer0_Isr(void) interrupt 1
{
    freq++;
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();
    led_time++;
    key_time++;
    freq_time++;
    rtc_time++;
}