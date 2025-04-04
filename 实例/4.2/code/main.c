#include "main.h"

extern uchar led[8];
extern uchar seg[8];

enum {
    KEY_TASK = 10,
    FLICKER_TASK = 100,
    STATE_TASK = 20,
    TEMP_TASK = 1000
};

// key
struct {
    uchar time;
    uchar press;
} key;

// 闪烁
struct {
    uchar time;
    uchar state;
} flicker;

// 测温
struct {
    int value;
    uint time;
} temp;

// 数码管显示状态
struct {
    uchar mode1;
    uchar mode2;    // 触发  | 0 -> 上触发 | 1 -> 下触发
    uchar time;
    uchar only;
} state;

// 校准界面
struct {
    char value;
    char list[3];
    char negative;
} adjust;

// 参数界面
struct {
    char value;
    char list[3];
    char negative;
} argument;

void main()
{
    boot_init();
    state.only = 255;
    temp.value = 0;

    argument.value = 26;

    read_temp();

    led_proc(0);
    led_proc(1);
    led_proc(2);

    while (1)
    {
        if (key.time == KEY_TASK) 
        {
            key.time = 0;
            key_proc();
        }

        if (flicker.time == FLICKER_TASK)
        {
            flicker.time = 0;
            flicker.state = !flicker.state;
        }

        if (state.time == STATE_TASK)
        {
            state.time = 0;
            state_proc();
        }

        if (temp.time == TEMP_TASK)
        {
            temp.time = 0;
            ds18b20_proc();
        }
    }
}


void Timer0_Isr(void) interrupt 1
{
    seg_display();
    led_display();

    if ( key.time < KEY_TASK ) { key.time++; }

    if ( flicker.time < FLICKER_TASK ) { flicker.time++; }

    if ( state.time < STATE_TASK ) { state.time++; }

    if ( temp.time < TEMP_TASK ) { temp.time++; }
    
}


void key_proc()
{
    key.press = key_scan();

    switch (key.press)
    {
        case 4:
        {
            state.mode1 = (state.mode1 + 1) % 3;
            led_proc(0);
        }
        break;

        case 5:
        {
            state.mode2 = (state.mode2 + 1) % 2;
            led_proc(1);
            led_proc(2);
        }
        break;

        // 减按键
        case 8:
        {
            if (state.mode1 == 1 && adjust.value != -99)
            {
                adjust.value--;
            }
            else if (state.mode1 == 2 && argument.value != -99)
            {
                argument.value--;
            }
        }
        break;

        // 加按键
        case 9:
        {
            if (state.mode1 == 1 && adjust.value != 99)
            {
                adjust.value++;
            }
            else if (state.mode1 == 2 && argument.value != 99)
            {
                argument.value++;
            }
        }
        break;
    }
}

void state_proc()
{
    uchar i;
    switch (state.mode1)
    {
        
        // 温度界面
        case 0:
        {
            // C 16 16 16 16 T T. T     T -> 温度值
            if (state.only != 0)
            {
                state.only = 0;
                seg[0] = 12; seg[1] = 16; seg[2] = 16; seg[3] = 16; seg[4] = 16;
            }
            seg[5] = (uchar) (temp.value / 100 % 10);
            seg[6] = (uchar) ( (temp.value / 10 % 10) + 32);
            seg[7] = (uchar) (temp.value % 10);
        }
        break;
        
        // 校准值
        case 1:
        {
            // E 16 16 16 16 A A A      A -> 校准值 进行负数处理 范围 -99 ~ 99
            if (state.only != 1)
            {
                state.only = 1;
                seg[0] = 14; seg[1] = 16; seg[2] = 16; seg[3] = 16; seg[4] = 16;
            }

            if (adjust.value < 0)
            {
                i = -adjust.value;
                adjust.negative = 1;
            }
            else
            {
                i = adjust.value;
                adjust.negative = 0;
            }

            adjust.list[0] = i / 100 % 10;
            adjust.list[1] = i / 10 % 10;
            adjust.list[2] = i % 10;

            delete_0(adjust.list, 3, adjust.value < 0 ? 1 : 0);

            seg[5] = adjust.list[0];
            seg[6] = adjust.list[1];
            seg[7] = adjust.list[2];
        }
        break;

        // 参数界面
        case 2:
        {
            // H 16 16 16 16 A A A   A -> 参数 -99 ~ 99
            if (state.only != 2)
            {
                state.only = 2;
                seg[0] = 18; seg[1] = 16; seg[2] = 16; seg[3] = 16; seg[4] = 16;
            }

            if (argument.value < 0)
            {
                i = -argument.value;
                argument.negative = 1;
            }
            else
            {
                i = argument.value;
                argument.negative = 0;
            }

            argument.list[0] = i / 100 % 10;
            argument.list[1] = i / 10 % 10;
            argument.list[2] = i % 10;

            delete_0(argument.list, 3, argument.value < 0 ? 1 : 0);

            seg[5] = argument.list[0];
            seg[6] = argument.list[1];
            seg[7] = argument.list[2];
        }
        break;
    }
}

void ds18b20_proc()
{
    float temperature;
    
    temperature = read_temp();

    temperature = temperature + adjust.value;

    // 保留一位小数
    temp.value = (int) (temperature * 10);

    
    led_proc(2);
}


void delete_0(uchar *list, uchar n, bit negative)
{
    uchar i;
    if (n == 0) { return; }

    for (i = 0;i < (n - 1);i++)
    {
        if (list[i] == 0)
        {
            
            if (list[i + 1] != 0 && negative == 1)
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

void led_proc(uchar i)
{
    switch (i)
    {
        case 0:
        {
            // 状态灯
            led[0] = 0; led[1] = 0; led[2] = 0;
            led[state.mode1] = 1;  
        }
        break;

        case 1:
        {
            // 上下限灯
            if (state.mode2 == 0)
            {
                led[3] = 1;
                led[4] = 0;
            }
            else
            {
                led[3] = 0;
                led[4] = 1;
            }
        }
        break;

        case 2:
        {
            // check

            if (state.mode2 == 0)
            {
                if (temp.value > argument.value* 10)
                {
                    led[7] = 1;
                }
                else
                {
                    led[7] = 0;
                }
            }
            else if (state.mode2 == 1)
            {
                if (temp.value< argument.value* 10)
                {
                    led[7] = 1;
                }
                else
                {
                    led[7] = 0;
                }
            }
        }
        break;
    }
}

