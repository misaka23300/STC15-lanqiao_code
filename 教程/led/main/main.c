#include "main.h"



typedef struct {
    uint8_t period;
    uint8_t cnt;
} timer8_t;

typedef struct {
    uint16_t period;
    uint16_t cnt;
    
} timer16_t;


volatile timer8_t led_timer = {10, 0};



volatile timer16_t task_500ms  = {500, 0};
bit flag_500ms;



void main()
{
    boot_init();

    while (1) {
        if (led_timer.cnt == led_timer.period) {
            led_timer.cnt = 0;
            led_display();
        }

       if (task_500ms.cnt == task_500ms.period) {
            task_500ms.cnt = 0;
            flag_500ms = !flag_500ms;
            led_task();
       }
    }
}



void Timer1_Isr(void) interrupt 3
{
    if (led_timer.cnt < led_timer.period) {
        led_timer.cnt++;
    }

   

}


void led_task()
{
    static int8_t i;
    static int8_t toward = 1;

    led_set(i, toward);

    if (toward) {
        i++;
        if (i == 8) {
            i = 7;
            toward = 0;
        }
    }
    else {
        i--;
        if (i == -1) {
            i = 0;
            toward = 1;
        }
    }
    

}


// 0 1 2 3 4 5 6 7
//   @   @   @   @
void led_task1()
{
    static int8_t i;
    static int8_t toward = 1;

    led_set(i, toward);

    if (toward) {
        i = i + 2;
        if (i == 8) {
            toward = 0;
        }
    }
    else {
        i = i - 2;
        if (i == -2) {
            toward = 1;
        }
    }
}