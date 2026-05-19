#include "task.h"


uint8_t xdata press = 0;
uint8_t xdata distance = 0;
uint8_t xdata display_state = 1;

void seg_task()
{
    //每隔0.2s变化一次
    static uint8_t left_temp = 0;
    uint8_t xdata roll_ciallo[5] = {0, 1, 2, 3, 4};
    static uint8_t xdata roll_ciallo_temp[18] = {16, 16, 16, 16, 16,
                                         16, 16, 16, 16, 16, 0, 13, 0, 
                                         0, 0, 7, 2, 1,};
    uint8_t idata i = 0;


    left_temp = roll_ciallo_temp[17];

    for (i = 17; i > 0; i--) {
        roll_ciallo_temp[i] = roll_ciallo_temp[i-1];
    }

    roll_ciallo_temp[0] = left_temp;

    set_seg(0, roll_ciallo_temp[5]);
    set_seg(1, roll_ciallo_temp[6]);
    set_seg(2, roll_ciallo_temp[7]);
    set_seg(3, roll_ciallo_temp[8]);
    set_seg(4, roll_ciallo_temp[9]);
    set_seg(5, roll_ciallo_temp[10]);
    set_seg(6, roll_ciallo_temp[11]);
    set_seg(7, roll_ciallo_temp[12]);
}


void key_task()
{
    press = key_scan();
    
    if (press != 0x99) {
        
        buzz(1);
    }
    else {
        buzz(0);
    }

    if (press == 4) {
        display_state++;
        if (display_state == 2) {
            display_state = 0;
        }
    }

    else if (press == 5) {
        work_3s();
    }

    else if (press == 8) {
        uart_send();
    }
}



void sonic_task()
{
    distance = sonic_measure();
}


void display_task()
{
    switch (display_state) {
        case 0:
            seg_task();
            
        break;

        case 1:
            set_seg(0, distance / 100 % 10);
            set_seg(1, distance / 10 % 10);
            set_seg(2, distance % 10);
            set_seg(3, 16);
            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, 16);
            set_seg(7, 16);

        break;
    }
}


void uart_send()
{
    
    sprintf(send_temp, "ciallo \r\n");
    uart_send_str(send_temp);
}