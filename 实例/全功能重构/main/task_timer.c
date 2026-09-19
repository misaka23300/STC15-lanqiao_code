#include "boot.h"


void main()
{
    while (1) {

    }
}



void timer0_interrupt() interrupt 1
{
    static uint16_t i;

    if (i % 100 == 0) {
        led_display();
    }

    i++;
}