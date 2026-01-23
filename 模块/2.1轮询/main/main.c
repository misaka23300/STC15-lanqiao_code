#include "stdio.h"
#include "main.h"

#define LED_TIME 10;

int led_time;


int main()
{
    while (true) {

        if (led_time == LED_TIME) {
            led_time = 0;
            led_display(0xFF);
        }
    }
    return 0;
}
void timer_0_interrupt() interrupt 1
{
    if (led_time < LED_TIME) {
        led_time++;
    }
    
}

uint8_t latch(uint8_t i)
{
    switch(i) {
        case 4: {P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: {P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: {P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: {P2 = (P2 & 0x1F) | 0xE0; break; }
        default: {return 1;}
    }
    P2 = P2 & 0x1F;
    return 0;

}


uint8_t led_display(uint8_t i)
{
    P0 = i;
    latch(4);
    return 0;
}




