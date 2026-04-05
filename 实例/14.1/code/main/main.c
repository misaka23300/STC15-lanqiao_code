#include "main.h"




enum {
    DISPLAY_TIME = 150,
    RTC_TIME = 100,
    ADC_TIME = 200,
    TEMP_TIME = 500,
    KEY_TIME = 20,
};

// time
uint16_t volatile idata  display_time = 0;
//uint8_t  volatile idata  display_time = 0;
uint8_t  volatile idata rtc_time = 0;
uint8_t volatile idata  adc_time = 0;
uint16_t volatile idata  temp_time = 0;
uint8_t  volatile idata  key_time = 0;

// display_task
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
            printf("send data:0 \n");
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

}



void main()
{
    boot_init();
    
    while (1) {
            
        if (display_time >= DISPLAY_TIME) {display_time = 0;display_task();}
        if (rtc_time >= RTC_TIME)   {rtc_time = 0; rtc_task(); }
        if (adc_time >= ADC_TIME)  {adc_time = 0; adc_task(); }
        if (temp_time >= TEMP_TIME) {temp_time = 0; temp_task(); }
        if (key_time >= key_time)   {key_time = 0; key_task(); }
    }
}


void Timer2_Isr(void) interrupt 12
{
    seg_display();  
    if (display_time < DISPLAY_TIME) {display_time++;}
    if (display_time < DISPLAY_TIME) {display_time++;}
    if (rtc_time < RTC_TIME)   {rtc_time++; }
    if (adc_time < ADC_TIME)  {adc_time++; }
    if (temp_time < TEMP_TIME) {temp_time++; }
    if (key_time < key_time)   {key_time++; }
}

void Timer0_Isr(void) interrupt 1
{
                        
}

