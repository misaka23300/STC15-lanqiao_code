#include "main.h"

enum {
    KEY_TIME = 20,
    SEG_TIME = 200,
    DISPLAY_TIME = 103,
    SONIC_TIME = 400,
    LED_TIME = 16,
} ;


idata uint8_t key_time = 0;
idata uint16_t seg_time = 0;
idata uint16_t display_time = 0;
idata uint16_t sonic_time  = 0;
idata uint8_t led_time = 0;


void main()
{
    boot_init();

    while (1) {
        if (seg_time >= SEG_TIME) {
            seg_time = 0;
            //seg_task();

        }

        if (display_time >= DISPLAY_TIME) {
            display_time = 0;
            display_task();
        }

        if (key_time >= KEY_TIME) {
            key_time = 0;
            key_task();
        }

        if (sonic_time >= SONIC_TIME) {
            sonic_time = 0;
            sonic_task();
        }


        if (led_time >= LED_TIME) {
            led_time = 0;
            led_display(7, !TI);
        }
    }



    
}


void Timer2_Isr(void) interrupt 12
{
    seg_display();
    seg_time++;
    display_time++;
    key_time++;
    sonic_time++;
    led_time++;
}
