#include "main.h"

enum {
   
    FREQ_TASK = 1000,
    DISPLAY_TASK = 50
};




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

    if (freq_time == FREQ_TASK)
    {
        freq_time = 0;
        freq_task();
        printf("timer: %u", freq_out_times);
    }

    if (display_time == DISPLAY_TASK)
    {
        display_time = 0;
        display_task();
    }
        
    
}

void timer1_interrupt() interrupt 3
{
    seg_display();
    led_display();
    //display_task();

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

        
    seg_list[0] = (uchar) freq_out_times / 10000;
    seg_list[1] = (uchar) freq_out_times / 1000 % 10;
    seg_list[2] = (uchar) freq_out_times / 100 % 10;
    seg_list[3] = (uchar) freq_out_times / 10 % 10;
    seg_list[4] = (uchar) freq_out_times % 10;
        
        
}



void freq_task()
{

    TR0 = 0;//�ر�T0;
    freq_out_times =(uint)(TH0 << 8) | TL0;
    TR0 = 1;//�ٴδ�
    TH0 = 0;
    TL0 = 0;//��ռ�����
}