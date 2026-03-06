#include "main.h"

enum { LED_TIME = 10,
    KEY_TIME = 20,
    SHAN_TIME = 500 };

uint8_t led_time;
uint8_t key_time;
uint16_t shan_time;

void main()
{
    boot_init();
    seg_value[0] = 17;
    seg_value[1] = 18;
    seg_value[2] = 19;
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
}

void key_task()
{
    static uint8_t key_press;
    key_press = key_scan();

    if (key_press != 99) {
        seg_value[0] = key_press / 10 % 10;
        seg_value[1] = key_press % 10;
    }
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