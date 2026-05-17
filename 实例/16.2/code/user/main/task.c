#include "task.h"


uint8_t xdata key_press = 0;
uint8_t xdata display_state = 0;

uint8_t xdata distance = 0;

uint16_t idata freq = 0;
uint16_t idata freq_out = 0;

uint16_t xdata temp_10 = 0;



void start_task()
{
    ds1302_write();

}

void key_task()
{
    key_press = key_scan();

    
}


void display_task()
{
    switch (display_state) {
        case 0:
        {
            set_seg(0, 1);
            set_seg(0, 1);
            set_seg(0, 1);
            set_seg(0, 1);

            set_seg(0, 1);
            set_seg(0, 1);
            set_seg(0, 1);
            set_seg(0, 1);
        }
        break;
    }
}



void sonic_task()
{
    distance = sonic_measure();
}

void ds18b20_task()
{
    temp_10 = ds18b20_read() *10;
    if (temp_10 == 85) {
        temp_10 = 0;
    }
}

void pcf8591_task()
{
    pcf8591_adc(0x01);
    pcf8591_adc(0x03);
}


void freq_task()
{
    TR0 = 0;
    freq_out = freq;
    freq = 0;
    TR0 = 1;
}

void ds1302_task()
{
    ds1302_read();   
}



void Timer0_Isr(void) interrupt 1
{
    freq++;
}
