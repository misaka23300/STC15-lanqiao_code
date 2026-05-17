#include "main.h"




enum {
    DISPLAY_TIME = 200,
    DS1302_TIME = 100,
    ADC_TIME = 200,
    TEMP_TIME = 500,
    KEY_TIME = 30,
};

// time
uint16_t volatile idata  display_time = 0;
uint8_t  volatile idata ds1302_time = 0;
uint8_t volatile idata  adc_time = 0;
uint16_t volatile idata  temp_time = 0;
uint8_t  volatile idata  key_time = 0;

// display_task



void main()
{
    boot_init();
    start_task();
    while (1) {
            
        if (display_time >= DISPLAY_TIME) {display_time = 0;display_task();}
        if (ds1302_time >= DS1302_TIME)   {ds1302_time = 0; rtc_task(); }
        if (adc_time >= ADC_TIME)  {adc_time = 0; adc_task(); }
        if (temp_time >= TEMP_TIME) {temp_time = 0; temp_task(); }
        if (key_time >= KEY_TIME)   {key_time = 0; key_task(); }
    }
}


void Timer2_Isr(void) interrupt 12
{
    seg_display();  
    if (display_time < DISPLAY_TIME) {display_time++;}
    if (ds1302_time < DS1302_TIME)   {ds1302_time++; }
    if (adc_time < ADC_TIME)  {adc_time++; }
    if (temp_time < TEMP_TIME) {temp_time++; }
    if (key_time < KEY_TIME)   {key_time++; }
}

void Timer0_Isr(void) interrupt 1
{
                        
}

