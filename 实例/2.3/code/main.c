#include "main.h"

enum {
    KEY_TASK = 20,
    SONIC_TASK = 100,
    FREQ_TASK = 1000,
    DISPLAY_TASK = 50
};


typedef struct {
    uchar time;
    uchar press;
} KEY;

KEY key;

typedef struct {
    uint time;
    uchar distance;
} SONIC;

SONIC sonic;

/* typedef struct {
    uint time;
    uint times;
    uint out_times;
} FREQ;

FREQ freq; */

uint freq_time;
uint freq_times;
uint freq_out_times;

uchar display_mode;     // -> 显示状态
uchar display_time;

// ---------------------------------------------------- 任务调度
void main()
{
    clean_display();
    timer();

    test();
    while (1)
    {
        task_loop();
    }
}

void task_loop() 
{
    if (key.time == KEY_TASK)
    {
        key.time = 0;
        key.press = key_scan();
        key_task();

        if (sonic.time == SONIC_TASK)
        {
            sonic.time = 0;
            sonic.distance = sonic_measure();
		}
            

        if (freq_time == FREQ_TASK)
        {
            freq_time = 0;
            freq_task();
            printf("%u", freq_out_times);
        }

        if (display_time == DISPLAY_TASK)
        {
            display_time = 0;
            display_task();
        }
        
    }
}

void timer1_interrupt() interrupt 3
{
    seg_display();
    led_display();
    //display_task();

    if (key.time < KEY_TASK) { key.time++; }

    if (sonic.time < SONIC_TASK) {sonic.time++;}

    if (freq_time < FREQ_TASK) {freq_time++; }

    if (display_time < DISPLAY_TASK) { display_time++; }
}



void Timer0_Isr(void) interrupt 1
{
    freq_times++;
}

// -----------------------------------------------------------任务函数
void test()
{
    relay(1);
    led_list[0] = 1;
    putchar('c');
}



void display_task()
{
    switch (display_mode)
    {
        case 0:
        {
            if (key.press != 99)
            {
                seg_list[1] = key.press % 10;
                seg_list[0] = key.press / 10 % 10;
            }
        }
        break; 

        case 1:
        {
            seg_list[5] = sonic.distance % 10;
            seg_list[4] = sonic.distance / 10 % 10;
            seg_list[3] = sonic.distance / 100 % 10;
        }
        break; 

        case 2:
        {
            seg_list[0] = (uchar) freq_out_times / 10000;
            seg_list[1] = (uchar) freq_out_times / 1000 % 10;
            seg_list[2] = (uchar) freq_out_times / 100 % 10;
            seg_list[3] = (uchar) freq_out_times / 10 % 10;
            seg_list[4] = (uchar) freq_out_times % 10;
        }
        break; 
    }
}


void key_task()
{
    switch (key.press)
    {
        case 4: 
        {
            display_mode++;
            if (display_mode == 3) { display_mode = 0;}
        }
        break;
    }
}


void freq_task()
{

    TR0 = 0;//�ر�T0;
    freq_out_times =(uint)(TH0 << 8) | TL0;
    TR0 = 1;//�ٴδ�
    TH0 = 0;
    TL0 = 0;//��ռ�����
}