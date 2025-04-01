// https://www.4t.wiki/exercise/7d88509d740668ecceaf34308a093aac

#include "main.h"

extern uchar led_value[8];
extern uchar seg[8];


enum {
    KEY_TIME = 15,
    STATE_TIME = 20,
    SONIC_TIME = 900,
    ADC_TIME = 90,
    SHAN_TIME = 100
};



// pcf8591
uchar ADC_value;
uint ADC_time;

// led
uint shan_time;
bit shan_flag;

// seg
struct {
    uchar time;
    uchar mode_1;
    uchar mode_2;
    
    // 旋钮模式选择调整上限还是下限  
    // 0为下限 1 为上限
    uchar check_mode2;
    uchar one_flag;
} state;


// 参数变量
struct {
    char low_value;
    char high_value;
    uchar out_times;
} argument;


// key
struct {
    uchar time;
    uchar press;
} key;


// 继电器


// sonic
struct {
    uchar distance;
    uint time;
    uchar list[3];
} sonic;

void main()
{
  
    boot_init();
    led_state();


    state.one_flag = 99;
    argument.high_value = 60;
    argument.low_value = 10;
   

    while (1)
    {
        if (key.time == KEY_TIME)
        {
            key_proc();
            key.time = 0;
        }

        if (state.time == STATE_TIME)
        {
            state_proc();
            state.time = 0;
        }

        if (sonic.time == SONIC_TIME)
        {
            sonic_proc();
            sonic.time = 0;
        }

        if (ADC_time == ADC_TIME )
        {
            if (state.mode_2 == 1)
                ADC_proc();
            ADC_time = 0;
        }

        if (shan_time == SHAN_TIME)
        {
            if (shan_flag == 1)
            {
                shan_flag = 0;
            }
            else
            {
                shan_flag = 1;
            }
            shan_time = 0;
        }
    }
}


void Timer2_Isr(void) interrupt 12
{
    static uint i;
    i++;
    if (i > 30000) { i = 0; }

    seg_display();
    if (i % 1 == 0)
        led_display();
        adjust_out();

    if ( key.time < KEY_TIME ) { key.time++; }

    if ( state.time < STATE_TIME ) { state.time++; }

    if ( sonic.time < SONIC_TIME ) { sonic.time++; }

    if ( ADC_time < ADC_TIME ) { ADC_time++; }
    
    if ( shan_time < SHAN_TIME ) { shan_time++; }
}

void key_proc()
{   
    
    key.press = key_scan();
    
    switch (key.press)
    {
        case 4:
        {
            state.mode_1 = (state.mode_1 + 1) % 3;
            led_state();
        }
        break;

        case 5:
        {
            if (state.mode_1 == 1)
                { state.mode_2 = (state.mode_2 + 1) % 2; }
                
        }
        break;

        case 8:
        {
            if (state.mode_1 == 1 && state.mode_2 == 0)
            {
                argument.high_value = argument.high_value + 10;
                if (argument.high_value > 90)
                {
                    argument.high_value = 50;
                }
            }
            else if (state.mode_1 == 1 && state.mode_2 == 1)
            {
                led_value[7] = 0;
                state.check_mode2 = 0;
                ADC_proc();
            }
        }
        break;

        case 9:
        {
            if (state.mode_1 == 1 && state.mode_2 == 0)
            {
                argument.low_value = argument.low_value - 10;
                if (argument.low_value < 0)
                {
                    argument.low_value = 40;
                }
            }
            else if (state.mode_1 == 1 && state.mode_2 == 1)
            {
                led_value[7] = 1;
                state.check_mode2 = 1;
                ADC_proc();
            }
        }
        break;
    }
}

void state_proc()
{
    switch (state.mode_1)
    {
        // 测距
        case 0:
        {
            if (state.one_flag != 0)
            {
                state.one_flag = 0; 
                seg[0] = 43; seg[1] = 16; seg[2] = 16; seg[3] = 16; seg[4] = 16;
            }
            
            seg[5] = sonic.list[0];
            seg[6] = sonic.list[1];
            seg[7] = sonic.list[2];
        }
        break;

        // 参数
        case 1:
        {
            if (state.one_flag != 1)
            {
                state.one_flag = 1;
                seg[0] = 24; seg[2] = 16; seg[5] = 17;
            }

            seg[1] = state.mode_2 + 1;

            seg[3] = argument.low_value / 10 % 10;
            seg[4] = argument.low_value % 10;

            seg[6] = argument.high_value / 10 % 10;
            seg[7] = argument.high_value % 10;
        }
        break;

        // 记录界面
        case 2:
        {
            if (state.one_flag != 2)
            {
                state.one_flag = 2; 
                seg[0] = 14; 
                seg[1] = 16; seg[2] = 16; seg[3] = 16; 
                seg[4] = 16; seg[5] = 16; seg[6] = 16;
            }
            seg[7] = argument.out_times;
        }
        break;
    }
}


void sonic_proc()
{
    sonic.distance = sonic_measure();

    sonic.list[0] = sonic.distance / 100 % 10;
    sonic.list[1] = sonic.distance / 10 % 10;
    sonic.list[2] = sonic.distance % 10;

    delete_0(sonic.list, 3, 0);

    //adjust_out();
}

void ADC_proc()
{
	uchar value;
	
    ADC_value = ADC(0x03);
    //led_value[0] = 1;

    if (ADC_value <= 51)
    {
        value = 50; 
    }
    else if (51 < ADC_value && ADC_value <= 102)
    {
        value = 60;
    }
    else if (102 < ADC_value && ADC_value <= 153)
    {
        value = 70;
    }
    else if (154 < ADC_value && ADC_value <= 205)
    {
        value = 80;
    }
    else if (205 < ADC_value && ADC_value <= 255)
    {
        value = 90;
    }

    if (state.check_mode2 == 0)
    {
        argument.low_value = value - 50;
    }
    else if (state.check_mode2 == 1)
    {
        argument.high_value = value;
    } 

    value = 0;
}


void led_state()
{
    led_value[0] = 0;
    led_value[1] = 0;
    led_value[2] = 0;

    led_value[state.mode_1] = 1;


    // uchar i;
    // for (i = 0;i < 3;i++)
    // {
    //     if (i != state.mode_1)
    //     {
    //         led_value[i] = 0;
    //     }
    //     else
    //     {
    //         led_value[i] = 1;
    //     }
    // }
}


void adjust_out()
{
    static uchar adjust;
    if (argument.low_value <= sonic.distance && sonic.distance <= argument.high_value)
    {
        adjust = 1;
        led_value[7] = 1;
    }
    else 
    {
        led_value[7] = shan_flag;
        if (adjust == 1)
        {
            if (argument.out_times < 10)
                argument.out_times++;
            else
                argument.out_times = 17;
            
            adjust = 0;
        }
    }
}