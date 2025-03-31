#include "main.h"

enum {
    SONIC_TIME = 1000,
    STATE_TIME = 90
};

bit sonic_flag, state_flag;

extern uchar seg[8];
uchar distance;

// 0.5 ~ 5.0,c
uchar valtage_high, voltage_low;
uchar state;

void main()
{
    boot_init();

    while (1)
    {
        if (sonic_flag)
        {
            sonic_flag = 0;
            distance = sonic_measure();
        }

        if (state_flag)
        {
            state_flag = 0;
            state_proc();
        }
    }
    
}

void Timer2_Isr(void) interrupt 12
{
    static uint i;
    i++;
    if (i > 30000)
    {
        i = 0;
    }

    seg_display();

    if (i % SONIC_TIME == 0)
    {
        sonic_flag = 1;
    }

    if (i % STATE_TIME == 0)
    {
        state_flag = 1;
    }
}


void state_proc()
{
    switch (state)
    {
        case 0:
        {
            if (one_flag != 0)
            {
                one_flag = 0;
                seg[0] = 25;
                seg[1] = 16;
                seg[2] = 16;
                seg[3] = 16;
                seg[4] = 16;
            }
            seg[5] = (v / 100 % 10) + 32;
            seg[6] = v / 10;
            seg[7] = v % 10;
        }
        break;

        case 1:
        {
            if (one_flag != 1)
            {
                one_flag = 1;

                seg[0] = 24;
                seg[1] = 16;
                seg[2] = 16;

                seg[5] = 16;
            }

            seg[3] = voltage_high / 10;
            seg[4] = voltage_high % 10;

            seg[6] = voltage_low / 10;
            seg[7] = voltage_low % 10;
        }
        break;

        case 2:
        {
            if (one_flag != 2)
            {
                one_flag = 2;
                seg[0] = 42;
                seg[1] = 16;
                seg[2] = 16;
                seg[3] = 16;
                seg[4] = 16;
            }
            if (distance == 255)
            {
                seg[5] = 16;
                seg[6] = distance / 10 % 10;
                seg[7] = distance % 10;
            }
            else
            {
                seg[5] = 16;
                seg[6] = distance / 10 % 10;
                seg[7] = distance % 10;
            } 
        }
        break;
    }
}
    

void key_proc()
{
    uchar press;
    press = key_sca();

    switch (press)
    {
        case 4:
        {
            state = (state + 1) % 3;
        }
        break;

        case 5:
        {
            low_high_state = ~low_high_state;
        }
        break;

        case 7:
        {

        }
        break;
    }
}


uchar voltage(uchar value)
{
    if (value != 5)
        vlaue++;
    
}