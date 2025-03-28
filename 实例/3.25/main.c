#include "main.h"

uchar state;
bit sonic_flag;
uchar distance;
/* enum 
{
    SONIC_TIME = 500
}; */
#define SONIC_TIME 1000

void main()
{
    boot_init();
    while (1)
    {
        if (sonic_flag)
        {
            sonic_flag = 0;
            sonic_proc();
        }
    }
}

void timer_0_ne555(void) interrupt 1
{
    //freq++;
}

void timer_2_1ms(void) interrupt 12
{
    static uint i;
    i++;
    if (i > 30000)
    {
        i = 0;
    }

    seg_display();
    state_proc();
    
    if (i % SONIC_TIME == 0)
    {
        sonic_flag = 1;
    }
}


void state_proc()
{
    switch (state)
    {
        case 0:
        { 
            set_seg(distance / 100 % 10, distance / 10 % 10, distance % 10, 0, 0, 0 ,0, 0);
        }
        break;
    }
}

void sonic_proc()
{
    distance = sonic_measure();
}