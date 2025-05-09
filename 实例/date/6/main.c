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

extern uchar seg[8];

uchar argument_state;
uchar argument_temp;
uchar factory_state;

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
    uchar argument[8] = {0, 0, 0, 0 ,0 ,0 ,0, 0};
    uchar i;
    switch (state)
    {
        // 测距
        case 0:
        {
            if (sonic_units == 0)
            {
                // cm
                argument[5] = 0;
                argument[6] = distance / 10 % 10;
                argument[7] = distance % 10;

                // 清零
                if (argument[6] == 0)
                {
                    argument[6] = 16;
                }
            }
            else
            {
                // m
                argument[5] = 32;
                argument[6] = distance / 10 % 10;
                argument[7] = distance % 10;
            }
            
            set_seg(temperature / 1000 % 10,
                    temperature / 100 % 10,
                    temperature / 10 % 10,
                    17,
                    16,
                    argument[5],
                    argument[6],
                    argument[7]
                    );  
        }
        break;
        
        // 参数界面
        case 1:
        {
            
            if (argument_state == 1)
            {
                argument[6] = argument_distance / 10 % 10;
                argument[7] = argument_distance % 10;
            }
            else if (argument_state = 2)
            {
                argument[6] = argument_temp / 10 % 10;
                argument[7] = argument_temp % 10;
            }

            set_seg(24, argument_state, 
                    16, 16, 16, 16, 
                    argument[6], argument[7]
                    );
        }
		break;

        // uchar factory_state;
        // char f1_value;
        case 2:
        {
            // factory
            argument[0] = 15;
            argument[1] = factory_state;
            argument[2] = 16;
            argument[3] = 16;
            argument[4] = 16;

            switch (factory_state)
            {
                case 1: 
                {
                    if (f1_value < 0)
                    {
                        argument[5] = 17;
                    }
                    else
                    {
                        argument[5] = 16;
                    }
                    
                    argument[6] = f1_value / 10;
                    argument[7] = f1_value % 10;
                }
                break;
            }
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
