#include "boot.h"


void main()
{
    while (1) {

    }
}



void timer0_interrupt() interrupt 0
{
    static uint16_t i;

    if (i % 100 == 0) {
        led_display();
    } 

    i = (i + 1) % 8;
}