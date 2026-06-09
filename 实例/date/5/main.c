#include "main.h"

uchar state;

void main()
{
    boot_init();
    while (1)
    {
        seg_display();
    }
}

void timer_1_1ms(void) interrupt 3
{
    static uint i;
    i++;
    if (i >= 1000)
    {
        i = 0;
    }
}