#include "main.h"

extern uchar led[8];
extern uchar seg[8];


// ds1302   -> date
struct {
    uchar now_time[3];
    uint time;
    uchar init_time[3];
} date = {
    { 0, 0, 0 },
    0,
    { 23,59,50 }
};


// 数码管显示数据 -> state
struct {
    uint time;
    uchar mode1;
    uchar only;
} state;


// 数据界面 -> ADC数据
struct {
    uint light_value;
    uint RB2_value;
} adc;


// 查询界面 -> 数组
struct {
    uchar value[3][3];
    uchar index;
} search;


// 键盘 -> press time
struct {
    uchar press;
    uint time;
} key;


uint date_time;
uint state_time;
uint key_time;


void main()
{
    boot_init(); 

    state.only = 2;
    state.mode1 = 0;

    write_datetime(date.init_time);

    //state_proc();

    while (1)
    {
       
        if (date_time == 100)
        {
            led[2]= 0;
            ds1302_proc();
            date_time = 0;
        }

        if (state_time == 90)
        {
            state_proc();
            state_time = 0;
        }

        if (key_time == 20)
        {
            key_proc();
            key_time = 0;
        }
    }
}

void Timer1_Isr() interrupt 12
{
    seg_display();
    led_display();

    if (date_time < 100) { date_time++; }

    if (state_time < 90) { state_time++; }

    if (key_time < 20) { key_time++; }


}



void ds1302_proc()
{
    read_datatime(date.now_time);
}

void state_proc()
{
    switch (state.mode1)
    {
        case 0: 
        {
            // 时间界面
            if (state.only != 0)
            {
                state.only = 0;
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

void ADC_proc()
{
    adc.light_value = ( ADC(0x01) / 255)* 500;
    adc.RB2_value = ( ADC(0x03) / 255)* 500;
}


void search_proc()
{

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