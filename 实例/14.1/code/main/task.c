#include "task.h"



uint8_t xdata key_press = 0;

uint8_t xdata display_state = 0;


void start_task()
{
    set_led(0, 1);
    set_seg(7, 2);
    seg_display();
    printf("ciallo~ \n");
    display_state = 0;

    ds1302_write();
    ds1302_read();

    pcf8591_adc(0x01);
    pcf8591_dac(0xFF);


}

void display_task()
{
    switch (display_state) {
        case 0:
        {
           /*  //printf("send data:0 \n");
            if (key_press != 99) {
                set_seg(0, key_press / 10 % 10);
                set_seg(1, key_press % 10);
               
            }
             set_seg(2, 1);
                set_seg(3, 1);

                set_seg(4, 1);
                set_seg(5, 1);
                set_seg(6, 1);
                set_seg(7, 1); */
        }
        break;

        case 1:
        {
            set_seg(0, 1);
            set_seg(1, 1);
            set_seg(2, 1);
            set_seg(3, 1);

            set_seg(4, 1);
            set_seg(5, 1);
            set_seg(6, 1);
            set_seg(7, 1);
        }
        break;
    }
}

void rtc_task()
{

}

void adc_task()
{


}

void temp_task()
{

}



void key_task()
{
    key_press = key_scan();

     if (key_press != 99) {
                set_seg(0, key_press / 10 % 10);
                set_seg(1, key_press % 10);
               
            }
}

