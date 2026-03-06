#include "main.h"

enum {
    LED_TIME = 10,
    KEY_TIME = 20,
    SHAN_TIME = 500,
    FREQ_TIME = 1000,

};

uint8_t led_time;
uint8_t key_time;
uint16_t shan_time;
uint16_t freq_time;

uint16_t freq_data;

void main()
{
    boot_init();

    while (1) {
        if (led_time == LED_TIME) {
            led_time = 0;
            led_display();
        }

        if (key_time == KEY_TIME) {
            key_time = 0;
            key_task();
        }

        if (shan_time == SHAN_TIME) {
            shan_time = 0;
            shan_task();
        }

        if (freq_time == FREQ_TIME) {
            freq_time = 0;
            freq_task();
        }
    }
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();
    if (led_time < LED_TIME) {
        led_time++;
    }
    if (key_time < KEY_TIME) {
        key_time++;
    }
    if (shan_time < SHAN_TIME) {
        shan_time++;
    }

    if (freq_time < FREQ_TIME) {
        freq_time++;
    }
}

uint8_t key_press;
void key_task()
{

    key_press = key_scan();
}

void shan_task()
{
    static uint8_t i;

    led_set(7, i);
    i++;
    if (i == 2) {
        i = 0;
    }
}

uint8_t display_state = 0;

void display_task()
{
    switch (display_state) {
    case 0: {
        seg_set(0, freq_data / 10000 % 10);
        seg_set(1, freq_data / 1000 % 10);
        seg_set(2, freq_data / 100 % 10);
        seg_set(3, freq_data / 100 % 10);
        seg_set(4, freq_data / 10 % 10);
        seg_set(5, freq_data % 10);
        seg_set(5, 17);
    } break;

    case 1: {
        if (key_press != 99) {
            seg_value[0] = key_press / 10 % 10;
            seg_value[1] = key_press % 10;
        }
    } break;
    }
}

void freq_task()
{
    /* uint8_t high, low;
    high = TH0;
    low = TL0;
    TH0 = 0x00;
    TL0 = 0x00; */

    /* freq_data = high << 8 | low; */

    display_task();
    freq_data = 0;
}

void freq_interrupt() interrupt 1
{
    freq_data++;
}