#include "main.h"

enum {
    LED_TIME = 7,
    KEY_TIME = 20,
    DATE_TIME = 100,
    STATE_TIME = 200
};

// key
idata uint key_time;
uchar key_press;


// state
idata uint state_time;
uchar state_mode1;
uchar state_only;

// 时间
idata uint date_time;
// uchar now_time[3];


// led
idata uint led_time;

void ds1302_proc()
{
    date_read();
}

void key_proc()
{
    key_press = key_scan();
    switch (key_press)
    {
        case 4: 
        {
            switch (state_mode1)
            {
                case 0: { state_mode1 = 1; break; }
                case 1: { state_mode1 = 2; break; }
                case 2: { state_mode1 = 0; break; }
            }
        }
        break;

        case 5:
        {
           
        }
        break;
    }
}

void state_proc()
{
    switch (state_mode1)
    {
        case 0: 
        {
            seg[0] = key_press / 10 % 10;
            seg[1] = key_press % 10;
        }
        break;

        case 1:
        {
            if (state_only != 1)
            {
                state_only = 1;
                seg[2] = 17; seg[5] = 17;
            }

            seg[0] = time_now[2] / 10 % 10;
            seg[1] = time_now[2] % 10;

            seg[3] = time_now[1] / 10 % 10;
            seg[4] = time_now[1] % 10;

            seg[6] = time_now[0] / 10 % 10;
            seg[7] = time_now[0] % 10;
        }
        break;

        case 2:
        {
            // x x x x     x x x x
            // 
            if (state_only != 2)
            {
                seg[3] = 16; seg[4] = 16;
            }
            break;

            
        }
        break;
    }
}

void main()
{
    boot_init();
    date_write();
    while (1)
    {
        if (led_time == LED_TIME)
        {
            led_display();
            led_time = 0;
        }

        if (key_time == KEY_TIME)
        {
            key_proc();
            key_time = 0;
        }
        
        if (state_time == STATE_TIME)
        {
            state_proc();
            state_time = 0;
        }

        if (date_time == DATE_TIME)
        {
            ds1302_proc();
            date_time = 0;
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    seg_display();

    if (led_time < LED_TIME) { led_time++; }

    if (key_time < KEY_TIME) { key_time++; }

    if (state_time < STATE_TIME) { state_time++; }

    if (date_time < DATE_TIME) { date_time++; }


    
}
