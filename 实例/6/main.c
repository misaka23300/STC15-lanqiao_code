#include "main.h"

const uchar code SONIC_TIME = 500; 
const uchar code KEY_TIME = 150;
const uchar code SEG_TIME = 1;
const uchar code LED_TIME = 5;
const uchar code TEMPERATURE_TIME = 500;
bit seg_flag, led_flag, sonic_flag, key_flag, temp_flag;
bit sonic_units;
uchar state;
 
uint distance;
uchar temperature;

void main()
{
    boot_init();
    while (1)
    {
        if (sonic_flag)
        {
            sonic_flag = 0;
            distance = sonic_measure();
        }

        if (key_flag)
        {
            uchar press;

            key_flag = 0;
            press = key_scan();
            key_proc(press);
        }

        if (led_flag)
        {
            led_flag = 0;
            led_display();
        }

        if (seg_flag)
        {
            seg_flag = 0;
            seg_display();
            state_proc();
        }

        if (temp_flag)
        {
            temp_flag = 0;
            temp_proc();
        }
    }
}

void timer_1_1ms() interrupt 3
{
    static uint i;
    i = (i + 1) % 30000;

   
    if (i % SEG_TIME == 0)
    {
        seg_flag = 1;
    }
    
    if (i % LED_TIME == 0)
    {
        led_flag = 1;
    }

    if (i % SONIC_TIME == 0)
    {
        sonic_flag = 1;
    }

    if (i % KEY_TIME == 0)
    {
        key_flag = 1;
    }

    if (i % TEMPERATURE_TIME == 0)
    {
        temp_flag = 1;
    }
}

void key_proc(uchar press)
{
    switch (press)
    {
        case 0:
        {
            state = (state + 1) % 3;
        }
    }
}

void state_proc()
{
    switch (state)
    {
        case 0:
        {
            if (sonic_units)
            {
                
                // cm
                set_seg(temperature / 1000 % 10,
                        temperature / 100 % 10,
                        temperature / 10 % 10,
                        17,
                        16,
                        16,
                        distance / 10 % 10,
                        distance % 10
                        );  
            }
            else
            {
                set_seg(temperature / 1000 % 10,
                        temperature / 100 % 10,
                        temperature / 10 % 10,
                        17,
                        16,
                        34, // 0.
                        distance / 10 % 10,
                        distance % 10
                        );
            }

           
        }
        break;

        case 1:
        {
            //set_seg();
        }
				break;
        
    }
}

void temp_proc()
{
    float temp;
    temp = read_temperature();

    temperature = temp * 100;
}
