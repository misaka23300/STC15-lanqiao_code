#include "main.h"

enum {
    LED_TIME = 10,
    KEY_TIME = 20,
    SHAN_TIME = 500,
    FREQ_TIME = 500,

};

uint8_t volatile led_time;
uint8_t volatile key_time;
uint16_t volatile shan_time;
uint16_t volatile freq_time;

uint16_t freq_data;
uint16_t freq_out;

uint16_t volatile task_count;
bit freq_flag;
void main()
{
    boot_init();

    while (1) {
        if (led_time >= LED_TIME) {
            led_time = 0;
            led_display();
        }

        if (key_time >= KEY_TIME) {
            key_time = 0;
            key_task();
        }

        if (shan_time >= SHAN_TIME) {
            shan_time = 0;
            shan_task();
        }

        if (freq_time >= FREQ_TIME) {
            // freq_task();
            freq_time = 0;
        }
        freq_task();
    }
}

void Timer2_Isr(void) interrupt 12
{
    task_count++;
    if (task_count % 1000 == 0) {
        freq_flag = 1;
    }

    seg_display();

    led_time++;

    //key_time++;

    shan_time++;

    /*
        if (freq_time < FREQ_TIME) {
            freq_time++;
        } */

    if (task_count == 30000) {
        task_count = 0;
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
    display_task();
}

uint8_t display_state = 0;

void display_task()
{
    switch (display_state) {
    case 0: {
        seg_set(0, freq_out / 10000 % 10);
        seg_set(1, freq_out / 1000 % 10);
        seg_set(2, freq_out / 100 % 10);
        seg_set(3, freq_out / 100 % 10);
        seg_set(4, freq_out / 10 % 10);
        seg_set(5, freq_out % 10);
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
    if (freq_flag) {
        freq_flag = 0;
        TR0 = 0;
        freq_data = TH0 * 256 + TL0;
        TH0 = 0x00;
        TL0 = 0x00;
        TR0 = 1;

        freq_out = freq_data;
    }

    // freq_data = 0;
}

void freq_interrupt() interrupt 1
{
    // freq_data++;
}