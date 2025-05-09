#include "main.h"

enum {
    FLAG_100MS = 100
};

uchar idata times_100ms;


struct {
    uchar t_100ms;
} times;

uchar flag_100ms;
uchar only_tag;
void main()
{
    boot_init();

    while (1)
    {
        if (times.t_100ms == FLAG_100MS)
        {
            flag_100ms = !flag_100ms;
        }

        if (flag_100ms)
        {
            buzz(1);
            
        }
        else if (!flag_100ms)
        {
            buzz(0);
            
        }
    }

}

void Timer1_Isr(void) interrupt 3
{
    if (times.t_100ms < FLAG_100MS) {times.t_100ms++; }

}