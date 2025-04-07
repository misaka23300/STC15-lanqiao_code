#include "main.h"

extern uchar led[8];
extern uchar seg[8];

enum {
    STATE_TIME = 1000
};

struct {
    uint time;
} state;


void main()
{
    boot_init();
    
    while (1)
    {
        if (state.time == STATE_TIME)
        {
            state.time = 0;
            state_proc();
        }
    }                                                                                                                                                                                                                                                                  

}

void Timer0_Isr(void) interrupt 1
{
    seg_display();
    led_display();
    
    if (state.time < STATE_TIME) { state.time++; }

    
}


void state_proc()
{
    static uchar i;
    seg[0] = i;
    i = (i + 1) % 8;
}