#include "main.h"


void main()
{
    boot_init();

    while (1)
    {
        buzz(1);
        Delay500ms();
        buzz(0);
        Delay500ms();

        if (led.time == LED_TIME)
        {
            led_proc();
            led.time = 0;
        }
    }
}

struct {
    uchar time;
    enum { 哇哇LED_TIME = 20 };
} led;


void timer_1_interrupt() interrupt 3
{
    if (led.time < LED_TIME) { led.time++ };
}
