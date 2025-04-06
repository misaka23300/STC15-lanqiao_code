#include "main.h"


enum {
    DS1302_TASK = 100;
};

struct {
    uchar now_time[3];
    uchar time;
    uchar init_time[3];
} date;



void main()
{
    boot_init(); 
    
    write_datetime();
    while (1)
    {
        if (date.time == DS1302_TASK)
        {
            date.time = 0;
            ds1302_proc();
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    seg_display();
    led_display();

    if (date.time < DS1302_TASK) { date.time++; }
}



void ds1302_proc()
{
    read_datatime(date.now_time);
}