#include "main.h"


enum {
    STATE_TIME = 50
};




typedef struct {
    uchar time;
    uchar mode_0;
} STATE;




STATE state;




void main()
{
    
    boot_init();
    
    while (1)
    {
        task_loop();
    }
}

void boot_init()
{
    clean_display();

    Timer1_Init();
    EA = 1;

    //write_datetime(rtc.init_time);
}

void task_loop()
{
    
    if (state.time == STATE_TIME)
    {
        display_task();
        state.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    if (state.time < STATE_TIME) {state.time++; }
    seg_display();
}




void display_task()
{
    switch (state.mode_0)
    {
        case 0:
        {
            set_seg_value(2, 3, 0, 0 ,0 ,0, 0, 0);
        }
        break;

       /*  case 1:
        {
            set_seg()
        } */
    }
}



