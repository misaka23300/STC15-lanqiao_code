#include "main.h"

extern uchar led[8];
extern uchar seg[8];

enum {
    STATE_TIME = 90,
    KEY_TIME = 20
};

static uchar state_time; 
static uchar state_mode1;

static uchar key_press;
static uchar key_time;

void main()
{
    boot_init();

    while (1)
    {
        if (state_time == STATE_TIME)
        {
            state_proc();
            state_time = 0;
        }

        if (key_time == KEY_TIME)
        {
            key_proc();
            key_time = 0;
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    seg_display();
    led_display();

    if (state_time < STATE_TIME) { state_time++; }

    if (key_time < KEY_TIME) { key_time++; }
}

void state_proc()
{
    switch (state_mode1)
    {
        case 0:
        {
            if (key_press != 99)
            {
                seg[0] = key_press / 10 % 10;
                seg[1] = key_press % 10;
            }
            
            seg[2] = 3;
            seg[3] = 4;
            seg[4] = 5;
            seg[5] = 6;
            seg[6] = 7;
            seg[7] = 8;
        }
    }
}

void key_proc()
{
    key_press = key_scan();

}