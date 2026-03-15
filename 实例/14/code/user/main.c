#include "main.h"

enum {
    LED_TIME = 10,
    KEY_TIME = 15,
};

uint8_t led_time;
uint8_t key_time;

uint8_t press;
void key_task()
{
    press = key_scan();
    display();
}

uint8_t display_state;
void display()
{
    switch (display_state) {
    case 0: {
        if (press != 99) {
            set_seg(0, press / 10 % 10);
            set_seg(1, press % 10);
        }
    }
    }
}

void main()
{
    boot_init();

    while (1) {
        if (led_time >= LED_TIME) {
            // led_display();
        }

        if (key_time >= KEY_TIME) {
            key_task();
        }
    }
}

void Timer0_Isr(void) interrupt 1
{
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();
    led_time++;
}