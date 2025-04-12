#include "main.h"

enum {
    LED_TIME = 7,
    KEY_TIME = 20,
    DATE_TIME = 100,
    STATE_TIME = 200,
    ADC_TIME = 150,
    TEMP_TIME = 800,
    SONIC_TIME = 899,
    FREQ_TIME = 1000
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

// 温度
idata uint temp_time;
uint temp;

// mode2 
uchar is_sonic;

// 超声波
idata uint sonic_time;
uchar distance;

// 测量频率
idata uint freq_time;
idata uint freq;
uint freq_number;
uchar freq_list[5] = {0, 0, 0, 0, 0};


freq_timer_0() interrupt 1
{
    freq_number++;
}


void freq_proc()
{
    freq = freq_number;
    freq_number = 0;

    freq_list[0] = freq / 10000 % 10;
    freq_list[1] = freq / 1000 % 10;
    freq_list[2] = freq / 100 % 10;
    freq_list[3] = freq / 10 % 10;
    freq_list[4] = freq % 10;

    delete_0(freq_list, 5, 0);
}

void sonic_proc()
{
    
    distance = sonic_measure();
}

void ds18b20_proc()
{
    temp = read_temperature() * 100;
}

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
        
       adc_3_value = (uint) (adc_3 * 0.0196 * 1000);
       // adc_3_value = adc_3_value * 100; // 取2位小数

       if ((adc_3_value % 10) >= 5)
       {
            adc_3_value = (adc_3_value / 10) + 1;
       }
       else
       {
        adc_3_value = adc_3_value / 10;
       }
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

                case 2: { state_mode1 = 3; break; }

                case 3: { state_mode1 = is_sonic + 10; break; }

                case 10: { state_mode1 = 0; break; }

                case 11: { state_mode1 = 0; break; }
            }
        }
        break;

        case 5:
        {
            switch (is_sonic)
            {
                case 0: 
                { 
                    timer_0_sonic();
                    is_sonic = 1; 
                    led[0] = 1;
                    led[1] = 0;
                    state_mode1 = 10; 
                    
                }
                break;

                case 1: 
                { 
                    timer_0_ne555();
                    is_sonic = 0; 
                    led[0] = 0;
                    led[1] = 1;
                    state_mode1 = 11;
                     
                }
                break; 
            }
        }
        break;
    }
}

void state_proc()
{
    switch (state_mode1)
    {
        // key界面
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

        // 时间界面
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

        // ADC界面
        case 2:
        {
            // x x x 0     0 x x x
            // 
            if (state_only != 2)
            {
                state_only = 2;
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
        // 温度界面  x x T T. T T o C
        case 3:
        {
            if (state_only != 3)
            {
                state_only = 3;
                seg[0] = 16; seg[5] = 16; seg[6] = 43;seg[7] = 12;
            }
            seg[1] = temp / 1000 % 10;
            seg[2] = (temp / 100 % 10) + 32;
            seg[3] = temp / 10 % 10;
            seg[4] = temp % 10;
        }
        break;

        // 超声波
        case 10:
        {
            if (state_only != 4)
            {
                state_only = 4;
                seg[2] = 16; seg[3] = 16; seg[4] = 16; seg[5] = 16; seg[6] = 16; seg[7] = 16;
            }
            seg[0] = distance / 100 % 10;
            seg[1] = distance / 10 % 10;
            seg[2] = distance % 10;
        }
        break;

        //freq
        case 11:
        {
            if (state_only != 5)
            {
                state_only = 5;
                seg[5] = 16; seg[6] = 16; seg[7] = 16;
            }
            seg[0] = freq_list[0];
            seg[1] = freq_list[1];
            seg[2] = freq_list[2];
            seg[3] = freq_list[3];
            seg[4] = freq_list[4];
        }
        break;
    }
    
}

void main()
{
    boot_init();
    read_temperature();
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

        if (temp_time == TEMP_TIME)
        {
            ds18b20_proc();
            temp_time = 0;
        }

        if (sonic_time == SONIC_TIME && is_sonic == 1)
        {
            sonic_proc();
            sonic_time = 0;
        }

        if (freq_time == FREQ_TIME && is_sonic == 0)
        {
            freq_proc();
            freq_time = 0;
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

    if (temp_time < TEMP_TIME) { temp_time++; }

    if (sonic_time < SONIC_TIME) { sonic_time++; }

    if (freq_time < FREQ_TIME) { freq_time++; }
    
}

// 0 0 0 1 3 

void delete_0(uchar *list, uchar len, uchar is_negative)
{
    uchar i;
    if ( len == 0 ) { return; }

    len--;
    for (i = 0;i < len;i++)
    {
        if ( list[i] == 0 )
        {
            if ( list[i-1] != 0 && is_negative == 1) 
            {
                list[i] = 17;
            }
            else
            {
                list[i] = 16;
            }
        }
        else
        {
            break;
        }
    }
}