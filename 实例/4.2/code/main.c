#include "main.h"

extern uchar led[8];
extern uchar seg[8];

enum {
    KEY_TASK 15,
    FLICKER_TASK 100,
    STATE_TASK 20,
    TEMP_TASK 900
}

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
    uchar value;
    uchar time;
} temp;

// 数码管显示状态
struct {
    uchar mode1;
    uchar time;
    uchar only;
} state;

// 校准界面
sturct {
    char value;
    char list[3];
} adjust;

int main()
{
    boot_init();
    state.only = 255;
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

    return 0;
}




void Timer0_Isr(void) interrupt 1
{
    /* static uint i;
    i++;
    if (i > 30000) { i = 0; } */

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
            state.mode1 = (staet.mode1 + 1) % 3;
        }
        break;
    }
}


{                       //标准字库
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
    //black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
        0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
        0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1



void state_proc()
{
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
            seg[5] = temp.value / 100 % 10;
            seg[6] = temp.value / 10 % 10;
            seg[7] = temp.value % 10;
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
            seg[5] = 
            seg[6] = 
            seg[7] = 
        }
        break;
    }
}

void ds18b20_proc()
{
    float temperature;

    temperature = read_temp();

    // 保留一位小数
    temp.value = (uint) temperature * 10;
}


void delete_0(uchar *list, uchar n, bit negative)
{
    uchar i;
    if (j == 0) { return; }

    for (i = 0;i < (j - 1);i++)
    {
        if (list[i] == 0)
        {
            list[i] = 16;
        }
        else
        {
            
        }
    }
}