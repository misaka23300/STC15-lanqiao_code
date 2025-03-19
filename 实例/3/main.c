#include "main.h"

#define LED_TIME 3
#define KEY_TIME 5
#define CLOCK_TIME 150
#define TEMP_TIME 1000
#define ADC_TIME 1000
bit key_flag, ds1302_flag, temp_flag, adc_flag, boling_flag;
bit naozhong_work;

uchar set;
uchar state, press;
uchar one_tag = 233;
uchar adc;
char boling_time = 2;
uchar times;

float temp;
uint temperature;
extern uchar led[8];
extern uchar seg[8];

extern uchar now_time[7];

char clock_time[3] = {0, 0, 0};
char naozhong_time[3] = {0, 0, 0};

void main()
{
    uchar i;
    boot_init();
    init_time();
    // hex
    naozhong_time[0] = read_2k(0x00);
    naozhong_time[1] = read_2k(0x01);
    naozhong_time[2] = read_2k(0x02);

    while (1)
    {   
        for (i = 0;i < 3;i++)
        {
            if (naozhong_time[i] == now_time[i])
            {
                naozhong_work = 1;
            }
            else
            {
                naozhong_work = 0;
                break;
            }
        }

        if (naozhong_work)
        {   
            sandy(0x04,1);
            if (boling_flag)
            {
                times++;
                led[0] = 1;
                led[1] = 1;
            }
            else
            {
                led[0] = 0;
                led[1] = 0;
                for (i = 0;i < 8;i++)
                {
                    seg[i] = 0;
                    one_tag = 255;
                }
            }

            if (times == 10)
            {
                naozhong_work = 0;
                led[0] = 0;
                led[1] = 0;
                for (i = 0;i < 8;i++)
                {
                    seg[i] = 0;
                    one_tag = 255;
                }
            }
        }


        if (ds1302_flag)
        {
            read_time();
        }

        if (key_flag)
        {
            press = key_scan();
            key_flag = 0;
            
            if (press == 4)
            {
                if (set == 0)
                    state = (state + 1) % 3;
                else
                    if (state == 20)
                    {
                        state = 21;
                    }
                    else if (state == 21)
                    {
                        state = 20;
                    }
            }

            if (press == 24)
            {
                if (set != 1)
                {
                    set = 1;
                    state = 20;
                }
                else
                {
                    if (state == 20)
                    {
                        write_time(clock_time);
                    }
                    else if (state == 21)
                    {
                        write_2k(0x00, naozhong_time[0]);
                        write_2k(0x01, naozhong_time[1]);
                        write_2k(0x02, naozhong_time[2]);
                    }
                }
                
            }

            if (press == 27)
            {
                if (set == 1)
                {
                    set = 0;
                    state = 0;
                }
            }

            if (press == 7 && set == 1)
            {
                boling_time--;
                if (boling_time == -1)
                {
                    boling_time = 2;
                }
            }

            if (press == 5 && set == 1)
            {
                if (state == 20)
                {
                    if (boling_time != 2)
                    clock_time[boling_time] = (clock_time[boling_time] + 1) % 60;
                    else
                        clock_time[boling_time] = (clock_time[boling_time] + 1) % 24;
                }

                else if (state == 21)
                {
                    if (boling_time != 2)
                    naozhong_time[boling_time] = (naozhong_time[boling_time] + 1) % 60;
                    else
                        naozhong_time[boling_time] = (naozhong_time[boling_time] + 1) % 24;
                }
                
            }

            if (press == 6 && set == 1)
            {
               if (state == 20)
               {
                clock_time[boling_time]--;
                if (clock_time[boling_time] == -1)
                {
                    if (boling_time != 2)
                        clock_time[boling_time] = 59;
                    else
                        clock_time[boling_time] = 23;
                }
               }
                else
                {
                    naozhong_time[boling_time]--;
                    if (naozhong_time[boling_time] == -1)
                    {
                        if (boling_time != 2)
                            naozhong_time[boling_time] = 59;
                        else
                            naozhong_time[boling_time] = 23;
                    }
                }
              
            }
           

           if (press == 5 || press == 6 || press == 7 || press == 8)
           {
                if (set == 0)
                {
                    state = 0;
                }
           }
        
        }

        switch (state)
        {
            case 0:
            {
                if (one_tag != 0)
                {
                    one_tag = 0;
                    seg[2] = 17;
                    seg[5] = 17;
                }

                seg[7] = now_time[0] % 10;
                seg[6] = now_time[0] / 10;

                seg[4] = now_time[1] % 10;
                seg[3] = now_time[1] / 10;

                seg[1] = now_time[2] % 10;
                seg[0] = now_time[2] / 10;
            }
            break;

            case 1:
            {
                if (temp_flag)
                {
                    temp_flag = 0;
                    temp = read_temperatrue();
                    temperature = (int) (temp * 100);
                    if (one_tag != 1)
                    {
                        one_tag = 1;
                        seg[0] = 43;
                        seg[1] = 43;
                        seg[2] = 16;
                        seg[3] = 16;
                    }    
                    seg[4] = temperature / 1000 % 10;
                    seg[5] = (temperature / 100 % 10) + 32;
                    seg[6] = temperature / 10 % 10;
                    seg[7] = temperature % 10;
                }
            }

            break;

            case 2:
            {
                if (adc_flag)
                {
                    adc_flag = 0;
                    adc = ADC(0x01);

                    if (one_tag != 2)
                    {
                        one_tag = 2;
                        seg[0] = 21;
                        seg[1] = 16;
                        seg[2] = 16;
                        seg[3] = 16;
                        seg[4] = 16;
                      
                    }

                    seg[5] = adc / 100 % 10;
                    seg[6] = adc / 10 % 10;
                    seg[7] = adc % 10;
                }
            }
            break;

            case 20:
            {
                if (one_tag != 20)
                {
                    one_tag = 20;
                    seg[0] = 15;
                    seg[1] = 16;

                    for (i = 0;i < 3;i++)
                    {
                        clock_time[i] = now_time[i];
                    }
                    
                }

                if (boling_flag == 0)
                {
                    seg[2] = clock_time[2] / 10;
                    seg[3] = clock_time[2] % 10;

                    seg[4] = clock_time[1] / 10;
                    seg[5] = clock_time[1] % 10;

                    seg[6] = clock_time[0] / 10;
                    seg[7] = clock_time[0] % 10;
                }

                if (boling_flag)
                {
                    switch (boling_time)
                    {
                        case 2:
                        {
                            seg[2] = 16;
                            seg[3] = 16;
                        }
                        break;

                        case 1:
                        {
                            seg[4] = 16;
                            seg[5] = 16;
                        }
                        break;

                        case 0:
                        {
                            seg[6] = 16;
                            seg[7] = 16;
                        }
                        break;
                    }
                }
            }
            break;

            case 21:
            {
                if (one_tag != 21)
                {
                    one_tag = 21;
                    seg[0] = 24;
                    seg[1] = 16;
                    
                }

                if (boling_flag == 0)
                {
                    seg[2] = naozhong_time[2] / 10;
                    seg[3] = naozhong_time[2] % 10;

                    seg[4] = naozhong_time[1] / 10;
                    seg[5] = naozhong_time[1] % 10;

                    seg[6] = naozhong_time[0] / 10;
                    seg[7] = naozhong_time[0] % 10;
                }

                if (boling_flag)
                {
                    switch (boling_time)
                    {
                        case 2:
                        {
                            seg[2] = 16;
                            seg[3] = 16;
                        }
                        break;

                        case 1:
                        {
                            seg[4] = 16;
                            seg[5] = 16;
                        }
                        break;

                        case 0:
                        {
                            seg[6] = 16;
                            seg[7] = 16;
                        }
                        break;
                    }
                }
            }
            break;
        }
    }
}


timer_11() interrupt 1
{
    static uchar i;
    i = (i + 1) % 30000;

    seg_display();

    if (i % LED_TIME == 0)
    {
        led_display();
    }

    if (i % KEY_TIME == 0)
    {
        key_flag = 1;
    }

    if (i % CLOCK_TIME == 0)
    {
        ds1302_flag = 1;
    }

    if (i % TEMP_TIME == 0 && state == 1)
    {
        temp_flag = 1;
    }

    if (i % ADC_TIME == 0 && state == 2)
    {
        adc_flag = 1;
    }

    if (i % 500 == 0)
    {
        if (boling_flag == 1)
        {
            boling_flag = 0;
        }
        else
        {
            boling_flag = 1;
        }
    }
}