#include "main.h"

enum {
    LED_TIME = 7,
    KEY_TIME = 20,
    DATE_TIME = 100,
    STATE_TIME = 200,
    ADC_TIME = 150
};

// key
idata uint key_time;
uchar key_press;


// state
idata uint state_time;
uchar state_mode1;
uchar state_only;

// 时间
idata uint date_time;
// uchar now_time[3];


// led
idata uint led_time;

// ADC
idata uint adc_time;
uchar adc_1;
uchar adc_3;

uint adc_3_value;
bit is_3_flag;


void adc_proc()
{
   
    if (is_3_flag)
    {
        adc_1 = ADC(0x03);
        is_3_flag = 0;
    }
    else
    {
       adc_3 = ADC(0x01); 
       is_3_flag = 1;
        
       adc_3_value = (uint) (adc_3 * 0.0196 * 100);
       // adc_3_value = adc_3_value * 100; // 取2位小数

       /* if ((adc_3_value % 10) > 5)
       {
            adc_3_value = (adc_3_value / 10) + 1;
       } */
    }
    


}


void ds1302_proc()
{
    date_read();
}

void key_proc()
{
    key_press = key_scan();
    switch (key_press)
    {
        case 4: 
        {
            switch (state_mode1)
            {
                case 0: { state_mode1 = 1; break; }
                case 1: { state_mode1 = 2; break; }
                case 2: { state_mode1 = 0; break; }
            }
        }
        break;

        case 5:
        {
           
        }
        break;
    }
}

void state_proc()
{
    switch (state_mode1)
    {
        case 0: 
        {
            seg[0] = key_press / 10 % 10;
            seg[1] = key_press % 10;

            seg[2] = 16;
            seg[3] = 16;
            seg[4] = 16;
            seg[5] = 16;
            seg[6] = 16;
            seg[7] = 16;
        }
        break;

        case 1:
        {
            if (state_only != 1)
            {
                state_only = 1;
                seg[2] = 17; seg[5] = 17;
            }

            seg[0] = time_now[2] / 10 % 10;
            seg[1] = time_now[2] % 10;

            seg[3] = time_now[1] / 10 % 10;
            seg[4] = time_now[1] % 10;

            seg[6] = time_now[0] / 10 % 10;
            seg[7] = time_now[0] % 10;
        }
        break;

        case 2:
        {
            // x x x 0     0 x x x
            // 
            if (state_only != 2)
            {
                seg[3] = 16; seg[4] = 16;
            }
            

            seg[0] = adc_1 / 100 % 10;
            seg[1] = adc_1 / 10 % 10;
            seg[2] = adc_1 % 10;

            seg[5] = (adc_3_value / 100 % 10) + 32;
            seg[6] = adc_3_value / 10 % 10;
            seg[7] = adc_3_value % 10;
        }
        break;
    }
}

void main()
{
    boot_init();
    date_write();
    ADC(0x01);
    while (1)
    {
        if (led_time == LED_TIME)
        {
            led_display();
            led_time = 0;
        }

        if (key_time == KEY_TIME)
        {
            key_proc();
            key_time = 0;
        }
        
        if (state_time == STATE_TIME)
        {
            state_proc();
            state_time = 0;
        }

        if (date_time == DATE_TIME)
        {
            ds1302_proc();
            date_time = 0;
        }

        if (adc_time == ADC_TIME)
        {
            adc_proc();
            adc_time = 0;
        }
    }
}

void Timer1_Isr(void) interrupt 3
{
    seg_display();

    if (led_time < LED_TIME) { led_time++; }

    if (key_time < KEY_TIME) { key_time++; }

    if (state_time < STATE_TIME) { state_time++; }

    if (date_time < DATE_TIME) { date_time++; }

    if (adc_time < ADC_TIME) { adc_time++; }
    
}
