#include "main.h"

enum {
    LED_TIME = 10,
    KEY_TIME = 15,
    FREQ_TIME = 1000,
    RTC_TIME = 100,
    ADC_TIME = 200,
    TEMP_TIME = 200,
};

uint8_t idata led_time;
uint8_t idata key_time;
uint16_t idata freq_time;
uint8_t idata rtc_time;
uint16_t idata adc_time;
uint16_t idata temp_time;

uint8_t press;

uint8_t display_state = 1;

uint16_t freq;
uint16_t freq_out;

uint8_t channel_1;
uint8_t channel_3;

uint16_t temp_10;

void temp_task()
{
    float temp;
    temp = read_temperature();
    temp_10 = temp * 10;
}

void adc_task()
{
    static uint8_t i;
    if (i) {
        channel_3 = adc_read(0x01);
    } else {
        channel_1 = adc_read(0x03);
    }

    i = i + 1;
    if (i == 2) {
        i = 0;
    }
}

void key_task()
{
    press = key_read();
    display();

    if (press == 4) {
        display_state++;
        if (display_state == 5) {
            display_state = 0;
        }
    }
}

void display()
{
    switch (display_state) {
    case 0: {
        if (press != 99) {
            set_seg(0, press / 10 % 10);
            set_seg(1, press % 10);
            set_seg(2, 16);
            set_seg(3, 16);
            set_seg(4, 16);
            set_seg(5, 16);
            set_seg(6, 16);
            set_seg(7, 16);
        }
    } break;

    case 1: {
        set_seg(0, freq_out / 10000 % 10);
        set_seg(1, freq_out / 1000 % 10);
        set_seg(2, freq_out / 100 % 10);
        set_seg(3, freq_out / 10 % 10);
        set_seg(4, freq_out % 10);
        set_seg(5, 16);
        set_seg(6, 16);
        set_seg(7, 16);
    } break;

    case 2: {
        set_seg(0, now_time[2] / 10 % 10);
        set_seg(1, now_time[2] % 10);
        set_seg(2, 17);
        set_seg(3, now_time[1] / 10 % 10);
        set_seg(4, now_time[1] % 10);
        set_seg(5, 17);
        set_seg(6, now_time[0] / 10 % 10);
        set_seg(7, now_time[0] % 10);
    } break;

    case 3: {
        set_seg(0, channel_1 / 100 % 10);
        set_seg(1, channel_1 / 10 % 10);
        set_seg(2, channel_1 % 10);
        set_seg(3, 16);
        set_seg(4, 16);
        set_seg(5, channel_3 / 100 % 10);
        set_seg(6, channel_3 / 10 % 10);
        set_seg(7, channel_3 % 10);
    } break;

    case 4: {
        set_seg(0, temp_10 / 100 % 10);
        set_seg(1, temp_10 / 10 % 10 + 32);
        set_seg(2, temp_10 % 10);
        set_seg(3, 17);
        set_seg(4, 0);
        set_seg(5, 7);
        set_seg(6, 2);
        set_seg(7, 1);
    } break;
    }
}

void main()
{
    boot_init();
    ds1302_write();
    adc_read(0x03);
    read_temperature();
    led(0, 1);
    while (1) {
        if (led_time >= LED_TIME) {
            // led_display();
        }

        if (key_time >= KEY_TIME) {
            key_task();
            key_time = 0;
        }

        if (freq_time >= FREQ_TIME) {
            freq_time = 0;
            freq_task();
        }

        if (rtc_time >= RTC_TIME) {
            ds1302_read();
            rtc_time = 0;
        }

        if (adc_time >= ADC_TIME) {
            adc_time = 0;
            adc_task();
        }

        if (temp_time >= TEMP_TIME) {
            temp_time = 0;
            temp_task();
        }
    }
}

void freq_task()

{
    freq_out = freq;
    freq = 0;
}

void Timer0_Isr(void) interrupt 1
{
    freq++;
}

void Timer2_Isr(void) interrupt 12
{
    seg_display();
    led_time++;
    key_time++;
    freq_time++;
    rtc_time++;
    adc_time++;
    temp_time++;
}