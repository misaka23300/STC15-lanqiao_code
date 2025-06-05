#include "main.h"

#define LED_TIME 10
#define KEY_TIME 5
#define READ_TIME 750
#define ADC_TIME 1000
#define TEMP_TIME 1000

extern uchar seg[8];
extern uchar led[8];
extern uchar now_time[7];
extern uchar send_time[7];

char set_time[7] = {0, 0, 0, 0, 0, 0, 0};
uchar adc[3] = {0, 0, 0};

uchar one_tag = 99;
uchar press, state, Data;
uchar v;
bit led_flag, key_flag, read_time_flag, set_time_flag, adc_flag, temp_flag;
uint temperature;
char set_time_config;

void main()
{
	uchar i, j, k;
	
    boot_init();
    
    for (j = 0;j < 3;j++)
    {
        Data = at2402_read(j);
        if (Data > 60)
            send_time[j] = 55;
        else
            send_time[j] = Data;
    }

    init_time();
    read_temp();


    while (1)
    {
        if (led_flag)
        {
            led_display();
            led_flag = 0;
        }

        if (key_flag)
        {
            press = key_scan();
            key_flag = 0;

            if (press == 13 && state != 20)
            {
                state = 20;
            }

            else if (press == 7)
            {
                state = (state + 1) % 4;
            }

            else if(press == 19)
            {
                led[7] = 1;
                at2402_write(0x00, now_time[0]);
                Delay500ms();
                at2402_write(0x01, now_time[1]);
                Delay500ms();
                at2402_write(0x02, now_time[2]);
                Delay500ms();
                //led[7] = 0;
            }

            else if (state == 20)
            {
                switch (press)
                {
                    case 9:
                    {
                        set_time_config = (set_time_config + 1) % 3;
                    }
                    break;

                    case 17:
                    {
                        set_time_config--;
                        if (set_time_config == -1)
                        {
                            set_time_config = 2;
                        }
                    }
                    break;

                    case 14:
                    {
                        if (set_time_config == 2)
                        {
                            set_time[set_time_config] = (set_time[set_time_config] + 1) % 24;
                        }
                        else
                        {
                            set_time[set_time_config] = (set_time[set_time_config] + 1) % 60;
                        }
                        
                    }
                    break;

                    case 12:
                    {
                        set_time[set_time_config] = (set_time[set_time_config] - 1);

                        if (set_time[set_time_config] == -1)
                        {
                            if (set_time_config == 2)
                                set_time[set_time_config] = 23;
                            else
                            {
                                set_time[set_time_config] = 59;
                            }
                        }
                    }
                    break; 

                    case 13:
                    {   
                        write_time(set_time);
                        read_time();

                        state = 0;
                        set_time_config = 0;
                        
                        
                    }
                    break;

                    case 33:
                    {
                        state = 0;
                        set_time_config = 0;
                    }
                }
            }

           
        }

        if (read_time_flag)
        {
            read_time();
            read_time_flag = 0;
        }

        switch (state)
        {
            // 时间
            
            case 0:
            {
                if (one_tag != 0)
                {     
                    one_tag = 0;

                    led[0] = 1;
                    led[1] = 0;
                    led[2] = 0;
                    led[3] = 0;
                    led[4] = 0;
                    led[5] = 0;
                    led[6] = 0;
                    led[7] = 0;
                    
                    seg[2] = 17;
                    seg[5] = 17;
                }
                seg[0] = now_time[2] / 10;
                seg[1] = now_time[2] % 10;

                seg[3] = now_time[1] / 10;
                seg[4] = now_time[1] % 10;

                seg[6] = now_time[0] / 10;
                seg[7] = now_time[0] % 10;
            }
            break;

            case 20:
            {
                if (one_tag != 20)
                {
                    one_tag = 20;
                    seg[2] = 17;
                    seg[5] = 17;

                    
                    for (i = 0;i <7;i++)
                    {
                        set_time[i] = now_time[i];
                    }
                }

                if (set_time_flag)
                {
                    switch (set_time_config)
                    {
                        case 0:
                        {
                            // 秒
                            seg[6] = 16;
                            seg[7] = 16;
                        }
                        break;

                        case 1:
                        {
                            // 分
                            seg[4] = 16;
                            seg[3] = 16;
                        }
                        break;

                        case 2:
                        {
                            // 时
                            seg[1] = 16;
                            seg[0] = 16;
                        }
                    }
                }
                else
                {
                    // 时
                    seg[0] = set_time[2] / 10;
                    seg[1] = set_time[2] % 10;
                    // 分
                    seg[3] = set_time[1] / 10;
                    seg[4] = set_time[1] % 10;
                    // 秒
                    seg[6] = set_time[0] / 10;
                    seg[7] = set_time[0] % 10;
                }
            }
            break;

            case 1:
            {
                // pcf8591 ADC
                if (adc_flag)
                {
                    adc_flag = 0;
                    
                    led[0] = 0;
                    led[1] = 1;
                    led[2] = 0;
                    led[3] = 0;
                    led[4] = 0;
                    led[5] = 0;
                    led[6] = 0;
                    led[7] = 0;

                    if (one_tag != 1)
                    {
                        one_tag = 1;
                        seg[0] = 9;
                        seg[1] = 17;
                        seg[2] = 17;
                        seg[3] = 17;
                        seg[4] = 17;
                    }
                    v = pcf8591_ADC(0x01);
                                        
                    adc[0] = v / 100 % 10;
                    adc[1] = v / 10 % 10;
                    adc[2] = v % 10;

                    for (k = 0;k < 2;k++)
                    {
                        if (adc[k] == 0)
                        {
                            adc[k] = 17;
                        }
                        else
                        {
                            break;
                        }
                    }

                    seg[5] = adc[0];
                    seg[6] = adc[1];
                    seg[7] = adc[2];
                }
            }
            break;

            case 2:
            {   
                if (temp_flag)
                {
                    temp_flag = 0;
                    if (one_tag != 2)
                    {
                        one_tag = 2;

                        led[0] = 0;
                        led[1] = 0;
                        led[2] = 1;
                        led[3] = 0;
                        led[4] = 0;
                        led[5] = 0;
                        led[6] = 0;
                        led[7] = 0;

                        seg[0] = 2;
                        seg[1] = 16;
                        seg[6] = 43;
                        seg[7] = 12;

                    }
                    temperature = (uint) (read_temp() * 100);

                    //seg[3] = temperature / 10000 % 10;
                    seg[2] = temperature / 1000 % 10;
                    seg[3] = (temperature / 100 % 10) + 32;
                    seg[4] = temperature / 10 % 10;
                    seg[5] = temperature % 10;
                }
            }
            break;

            // ne555
            case 3:
            {

            }
            break;
            // 超声波
            case 4:
            {

            }
            break;
            
            // pwm
            case 5:
            {

            }
            break;
        }
    }
}

void Timer2_Isr(void) interrupt 12
{
    static uchar i;
    i = (i + 1) % 30000;
    
    seg_display();

    if (i % LED_TIME == 0)
    {
        led_flag = 1;
    }

    if (i % KEY_TIME == 0)
    {
        key_flag = 1;
    }

    if (i % READ_TIME == 0)
    {
        read_time_flag = 1;
    }

    if (i % 5000 == 0 && state == 20)
    {
        if (set_time_flag)
        {
            set_time_flag = 0;
        }
        else
        {
            set_time_flag = 1;
        }
    }

    if (i % ADC_TIME == 0)
    {
        adc_flag = 1;
    }

    if (i % TEMP_TIME == 0)
    {
        temp_flag = 1;
    }
}




