#include "main.h"

enum {
    SONIC_TIME = 1000,
    STATE_TIME = 90
};

bit sonic_flag, state_flag;

extern uchar seg[8];
uchar distance;

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
    seg[0] = distance / 100 % 10;
    seg[1] = distance / 10 % 10;
    seg[2] = distance % 10;
}


