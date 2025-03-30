#include "main.h"

enum {
    // 超声波
    SONIC_TIME = 1000,

    // 数码管
    STATE_TIME = 90,

    // 键盘
    KEY_TIME = 15,

    // DS18B20
    DS18B20_TIME = 1000,

    // DAC
    DAC_TIME = 1000,

    // LED
    LED_TIME = 20
};

//bit sonic_flag, state_flag, key_flag, temp_flag, dac_flag;

// 超声波
struct 
{
    uchar distance;
    bit sonic_flag;
    bit sonic_unit;
} sonic;

// 键盘
struct 
{
    bit key_flag;
    uchar state;
};


struct
{
    int value;
    bit ds18b20_flag;
} temp;



// LED
extern uchar led_value[8];
bit led_flag;

// 继电器

// 数码管
extern uchar seg[8];
bit state_flag;
uchar state_1;
uchar state_2;

// DAC
uchar DAC_value;
bit DAC_flag;

//0.1 - 2.0 * 10
// 1 - 20
uchar  low_dac;

// other
uchar distance_argument;
uchar temp_argument;

char calibra_value;

uchar speed;

void main()
{
    read_temperature();
    boot_init();
    led_proc();
    

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

        if (led_flag)
        {
            led_flag = 0;
            led_proc();
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

    if (i % LED_TIME == 0)
    {
        led_flag = 1;
    }
}


void state_proc()
{
    switch (state)
    {
        case 0:
        {

            // 2 3. 5 - x x 2 5
            set_seg(
                temperature / 1000 % 10,
                (temperature / 100 % 10) + 32,
                temperature / 10 % 10,
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
            switch (state_1)
            {
                case 0:
                {
                    // P 1 x x x x 4 0
                    set_seg(
                        24,
                        1,
                        16, 16, 16, 16,
                        distance_argument / 10 % 10,
                        distance_argument / 10
                    );
                }
                break;

                case 1:
                {
                    // P 2 x x x x 3 0
                    set_seg(
                        24,
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
                    
                    // F 1 x x x 0 x x 5
                    set_seg( 15, 1, 16, 16, 16, calibra_list[0], calibra_list[1], calibra_list[2] );
                }
                break;

                case 1:
                {
                    // F 2 x x x 3 4 0
                    set_seg(15, 2, 16, 16, 16, speed / 100 % 10, speed / 10 % 10, speed % 10);
                }
                break;

                case 2:
                {
                    // F 3 x x x x 0. 2
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
    uchar press;
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
            switch (state)
            {
                case 0:
                {
                    if (sonic_unit == 1)
                    sonic_unit = 0;
                    else
                        sonic_unit = 1;
                }
                break;

                case 1:
                {
                    state_2 = (state_2 + 1) % 2;
                }
                break; 
            }
                       
					
        }
        break;

        case 8:
        {
            if (state == 2)
            {
                if (state_2 == 0 && distance_argument != 90)
                {
                    distance_argument = distance_argument + 10;
                }
                else if (state_2 == 1 && speed != 90)
                {
                    speed = speed + 10;
                }
                else if (state_2 == 2 && low_dac != 20)
                {
                    low_dac = low_dac + 1;
                }
            }
            else if (state == 1)
            {
                //dac_proc();
            }
        }
        break;

        case 9:
        {
            if (state == 2)
            {
                switch (state_2)
                {
                    case 0:
                    {
                        if (distance_argument != 10)
                            distance_argument = distance_argument - 10;
                    }
                    break;

                    case 1:
                    {
                        //if ()
                    }
                    break;
                }
            }
        }
        break;
    }
}

void led_proc()
{
    uchar i;
    for (i = 0;i < 8;i++)
    {
        if (i != state)
            led_value[i] = 0;
        else
            led_value[i] = 1;
    }
    led_display();
}


