#include "main.h"

struct fonction_list
{
    uchar value;
    uchar flag;
    uint time;
};

struct fonction_list sonic = {0, 0, 1000};
struct fonction_list state = {0, 0, 50};

extern uchar seg[8];

void main()
{
    boot_init();

    while (1)
    {
        if (sonic.flag)
        {
            sonic.flag = 0;
            sonic.value = sonic_measure();
        }

        if (state.flag)
        {
            state.flag = 0; // Corrected from sonic.flag = 0
            state_proc();
        }
    }
}

void timer_2_1ms() interrupt 12
{
    static uint i = 0;
    i++;
    if (i > 30000)
    {
        i = 0;
    }

    seg_display();

    if (i % sonic.time == 0)
    {
        sonic.flag = 1;
    }

    if (i % state.time == 0) // Corrected from state.flag to state.time
    {
        state.flag = 1;
    }
}

void state_proc()
{
    seg[0] = sonic.value / 100 % 10;
    seg[1] = (sonic.value / 10) % 10; // Added %10 for clarity
    seg[2] = sonic.value % 10;
    seg[7] = 3;
}