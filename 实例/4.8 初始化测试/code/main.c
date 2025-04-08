#include "main.h"

extern uchar idata led[8];
extern uchar idata seg[8];

enum {
    STATE_TIME = 20,
    KEY_TIME = 30,
    DATE_TIME = 100
};

idata uint state_time; 
uchar state_mode1;

uchar idata key_press;
uint key_time;

uchar key_list[2];

uchar idata date_now_time[3];
idata uchar date_init_time[3] = {0x22, 0x22, 0x22};
uint date_time;


void main()
{
    boot_init();
    datetime_write(date_init_time);
    date_now_time[0] = 0;
    date_now_time[1] = 0;
    date_now_time[2] = 0;
    while (1)
    {
        if (state_time == 1)
        {
            state_time = 0;
            state_proc();
            
        }

        if (key_time == 1)
        {
            key_time = 0;
            key_proc();
            
        }

        if (date_time == 1)
        {
            date_time = 0;
            ds1302_proc();
            
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    static uint i;
    i++;
    
    if (i >= 3000)
    {
        i = 0;
    }

    seg_display();
    led_display();

    if (i % STATE_TIME == 0)
    {
        state_time = 1;
    }

    if (i % KEY_TIME == 0)
    {
        key_time = 1;
    }

    if (i % DATE_TIME == 0)
    {
        date_time = 1;
    }
     
    /* if (state_time < STATE_TIME) { state_time++; }

    if (key_time < KEY_TIME) { key_time++; }

    if (date_time < DATE_TIME) { date_time++; } */
   
} 

void state_proc()
{
    switch (state_mode1)
    {
        case 0:
        {
            if (key_press != 99)
            {
                seg[0] = key_list[0];
                seg[1] = key_list[1];
            }
            
            seg[2] = 3;
            seg[3] = 4;
            seg[4] = 5;
            seg[5] = 6;
            seg[6] = 7;
            seg[7] = 8;
        }
        break;


       case 1:
        {
            seg[0] = date_now_time[2] / 10 % 10;
            seg[1] = date_now_time[2] % 10;

            seg[2] = 17;

            seg[3] = date_now_time[1] / 10 % 10;
            seg[4] = date_now_time[1] % 10;

            seg[5] = 17;

            seg[6] = date_now_time[0] / 10 % 10;
            seg[7] = date_now_time[0] % 10;
        }
        break; 
    }
}

void key_proc()
{
    key_press = key_scan();
    

    switch (key_press)
    {
        case 4:
        {
            state_mode1 = (state_mode1 + 1) % 2;
        }
        break;
    }
}

void ds1302_proc()
{
    datetime_read(date_now_time);
}