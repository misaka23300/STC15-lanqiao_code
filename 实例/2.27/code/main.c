#include "main.h"

enum {
    // 超声波
    SONIC_TIME = 1000,

    // 数码管
    STATE_TIME = 90,

    // 键盘
    KEY_TIME = 20,

    // DS18B20
    DS18B20_TIME = 1000,

    // DAC
    DAC_TIME = 1000

};

//bit sonic_flag, state_flag, key_flag, temp_flag, dac_flag;



// 超声波
uchar distance;
bit sonic_flag;
bit sonic_unit;

// 键盘
uchar press;
bit key_flag;
uchar state;

// DS18B20
int temperature;
bit ds18b20_flag;

// LED
extern uchar led_value[8];
bit led_flag;

// 继电器

// 数码管
extern uchar seg[8];
bit state_flag;
uchar state_1_flag;
uchar state_2;

// DAC
uchar DAC_value;
bit DAC_flag;

uchar low_dac;

// other
uchar distance_argument;
uchar temp_argument;

char calibra_value;

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

        if (state_flag)
        {
            state_flag = 0;
            state_proc();
        }

        if (ds18b20_flag)
        {
            ds18b20_flag = 0;
            ds18b20_proc();
        }

        if (key_flag)
        {
            key_flag = 0;
            key_proc();
        }
    }
    
}

void Timer2_Isr(void) interrupt 12
{
    static uint i;
    i++;
    if (i > 30000)
    {
        i = 0;
    }

    seg_display();

    if (i % SONIC_TIME == 0)
    {
        sonic_flag = 1;
    }

    if (i % STATE_TIME == 0)
    {
        state_flag = 1;
    }

    if (i % DS18B20_TIME == 0)
    {
        ds18b20_flag = 1;
    }

    if (i % KEY_TIME == 0)
    {
        key_flag = 1;
    }
}


void state_proc()
{
    switch (state)
    {
        case 0:
        {
            set_seg(
                temperature / 100 % 10,
                (temperature / 10 % 10) + 32,
                temperature % 10,
                17,
                16,
                distance / 100 % 10,
                distance / 10 % 10,
                distance % 10
            );
        }
        break;

        case 1:
        {
            switch (state_1_flag)
            {
                case 0:
                {
                    set_seg(
                        23,
                        1,
                        16, 16, 16, 16,
                        distance_argument / 10 % 10,
                        distance_argument / 10
                    );
                }
                break;

                case 1:
                {
                    set_seg(
                        23,
                        2,
                        16, 16, 16, 16,
                        temp_argument / 10 % 10,
                        temp_argument / 10
                    );
                }
                break;
            }
        }
        break;

        case 2:
        {
            switch (state_2)
            {
                case 0:
                {
                    uchar calibra_list[3] = {0, 0, 0};

                    calibra_list[1] = calibra_value / 10;
                    calibra_list[2] = calibra_value % 10;
                    
                    delete_0(calibra_list, 3, calibra_value < 0 ? 1 : 0);

                    set_seg( 15, 1, 16, 16, 16, calibra_list[0], calibra_list[1], calibra_list[2] );
                }
                break;

                case 1:
                {
                    set_seg(15, 2, 16, 16, 16, 3, 4, 0);
                }
                break;

                case 2:
                {
                    set_seg(15, 3, 16, 16, 16, 16,low_dac / 10 % 10, low_dac % 10);
                }
                break;
            }
        }
        break;
    }
 
}

void ds18b20_proc()
{
    temperature = read_temperature()* 100;
}

void delete_0(uchar *a, j, bit negative)
{
    uchar i;
    if (j == 0)
    {
        return;
    }
    j--;
    for (i = 0; i < j;i++)
    {
        if (a[i] == 0)
        {
            a[i] = 16;
            
        }
        else
        {
            if (i != 0 && negative)
            {
                a[i - 1] = 17; 
            }
            break;
        }
    }
}

void key_proc()
{
    press = key_scan();
    switch (press)
    {
        case 4:
        {
            state = (state + 1) % 3;
        }
        break; 

        case 5:
        {
            if (sonic_unit == 1)
                sonic_unit = 0;
            else
                sonic_unit = 1;
					
        }
        break;

        case 8:
        {

        }
        break;

        case 9:
        {

        }
        break;
    }
}