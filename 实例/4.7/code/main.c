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



// 数码管显示状态
struct {
    uchar mode1;
    uchar mode2;    // 触发  | 0 -> 上触发 | 1 -> 下触发
    uchar time;
    uchar only;
} state;


// ds1302   -> date
struct {
    uchar now_time[3];
    uint time;
    uchar init_time[3];
} date;


// 查询界面 -> 数组
struct {
    uchar value[3];
    uchar index;
} search;


// 数据界面 -> ADC数据
struct {
    uint light_value;
    uint RB2_value;
} adc;




void main()
{
    boot_init();
    state.only = 255;
    

    

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

        
    }
}


void Timer0_Isr(void) interrupt 1
{
    seg_display();
    led_display();
    
    state_proc();
    if ( key.time < KEY_TASK ) { key.time++; }

    if ( flicker.time < FLICKER_TASK ) { flicker.time++; }

    if ( state.time < STATE_TASK ) { state.time++; }

    
}


void key_proc()
{
    key.press = key_scan();

    switch (key.press)
    {
        case 4:
        {
            state.mode1 = (state.mode1 + 1) % 3;
        }
        break;
    }
}

void state_proc()
{
   
    switch (state.mode1)
    {
        case 0: 
        {
            // 时间界面
           
            {
               
                seg[2] = 17; seg[5] = 17; 
            }
            // 小时
            seg[0] = date.now_time[2] / 10 % 10;
            seg[1] = date.now_time[2] % 10;
            // 分钟
            seg[3] = date.now_time[1] / 10 % 10;
            seg[4] = date.now_time[1] % 10;
            // 秒
            seg[6] = date.now_time[0] / 10 % 10;
            seg[7] = date.now_time[0] % 10;
        }
        break;

        // 数据界面 P g. g g  U v. v v     g -> 光敏电阻   v -> 旋钮电压 
        case 1:
        {
            if (state.only != 2)
            {
                state.only = 2;
                seg[0] = 24; seg[4] = 25;
            }

            seg[1] = adc.light_value / 100 % 10;
            seg[2] = (adc.light_value / 10 % 10) + 32;
            seg[3] = adc.light_value % 10;
            
            seg[5] = adc.RB2_value / 100 % 10;
            seg[6] = (adc.RB2_value / 10 % 10) + 32;
            seg[7] = adc.RB2_value % 10;
        }
        break;

        case 2:
        {
            if (state.only != 2)
            {
                state.only = 2;
                seg[0] = 42;
            }
            seg[1] = search.index;
            //seg[2] = 
        }
        break;
    }
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


