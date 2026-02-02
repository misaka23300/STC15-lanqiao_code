#include "main.h"

enum {
    SONIC_TIME = 1000,
    KEY_TIME = 20,
};




sonic_t sonic;
key_t key;


void sonic_display()
{
    set_seg(0, sonic.distance / 100 % 10);
    set_seg(1, sonic.distance / 10 % 10);
    set_seg(2, sonic.distance % 10);
}

void key_task()
{
    if (key.press == 4) {
        if (sonic.mode == 0) {
            sonic.mode = 1;
        }
        else if (sonic.mode == 1) {
            sonic.mode = 0;
        }
    }
}


void sonic_task()
{
    if (sonic.mode == 1) {
        sonic.distance = sonic_measure_mode1();
    }
    else if (sonic.mode == 2) {
        sonic.distance = sonic_measure_mode2();
    }

    sonic_display();
}
void main()
{
    boot_init();

    while (1)
    {
        /* if (sonic_flag)
        {
            sonic_flag = 0;
            distance = sonic_measure();
        }

        if (state_flag)
        {
            state_flag = 0;
            state_proc();
        } */

        if (sonic.time == SONIC_TIME) {
            sonic.time = 0;
            sonic_task();
        }

        if (key.time == KEY_TIME) {
            key.time = 0;
            key.press = key_scan();
            key_task();
        }
    }
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();

    if (sonic.time < SONIC_TIME) {
        sonic.time++;
    }

    if (key.time < KEY_TIME) {
        key.time++;
    }
}


