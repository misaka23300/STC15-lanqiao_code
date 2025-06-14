#include "main.h"

enum {
    KEY_TASK = 20,
    SONIC_TASK = 100,
    FREQ_TASK = 1000,
    DISPLAY_TASK = 50,
    UART_TASK = 10
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

typedef struct{
    uint time;
    uint times;
    uint out_times;
} FREQ;

FREQ freq;

//freq_times = 13233;

uchar display_mode;     // -> 显示状态
uchar display_time;


uint x = 2333;
uint y = 721;
// ---------------------------------------------------- 任务调度
void main()
{
    freq.times = 12345;
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
    }
    if (sonic.time == SONIC_TASK)
    {
        sonic.time = 0;
        sonic.distance = sonic_measure();
    }
        

    if (freq.time == FREQ_TASK)
    {
        freq.time = 0;
        freq_task();
        //printf("%u", freq.out_times);
    }

    if (display_time == DISPLAY_TASK)
    {
        display_time = 0;
        display_task();
    }
        
    if (uart.time == UART_TASK)
    {
        uart.time = 0;
        uart_task();
    }
}

// 1ms
void timer1_interrupt() interrupt 3
{
    seg_display();
    led_display();
    //display_task();

    if (key.time < KEY_TASK) { key.time++; }

    if (sonic.time < SONIC_TASK) {sonic.time++;}

    if (freq.time < FREQ_TASK) {freq.time++; }

    if (display_time < DISPLAY_TASK) { display_time++; }

    if (uart.out_time_flag == 1 && uart.out_time < 10) { uart.out_time++; }

    if (uart.time < UART_TASK) { uart.time++; }
}



void Timer0_Isr(void) interrupt 1
{
    /* freq_times++; */
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
            seg_list[0] =  freq.out_times / 10000;
            seg_list[1] =  freq.out_times / 1000 % 10;
            seg_list[2] =  freq.out_times / 100 % 10;
            seg_list[3] =  freq.out_times / 10 % 10;
            seg_list[4] =  freq.out_times % 10;
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

    TR0 = 0;
    freq.times = (uint)(TH0 << 8) | TL0;
    freq.out_times = freq.times;
    freq.times = 0;

    //printf("freq: %u",freq.out_times);
    TH0 = 0; TL0 = 0;
    TR0 = 1;

    //freq_out_times = freq_time;

    //freq_times = 0;    
}

void uart_task()
{
    uchar k = 1;
    //uchar position[2];
    uchar towards = 0;
    uchar i = 4;
    uchar j = 5;
    if (uart.index == 0) { return; }

    if (uart.out_time == 10)
    {
        uart.out_time = 0;
        uart.out_time_flag = 0;
        uart.index = 0;
        switch (uart.receive_data[0])
        {
            case '#':
            {
                printf("ciallo~");
            }
            break;

            case '?':
            {
                printf("%d",x);
            }
            break;

            case '^':
            {
               printf("(%d,%d)",x,y);
               
            }
            break;

            case '(':
            {
                x = 0;y = 0;
                while (uart.receive_data[k] != ')')
                {
                    if (uart.receive_data[k] >= '0' && uart.receive_data[k] <= '9')
                    {
                        if (towards == 0)
                        {
                            x = x * 10 + uart.receive_data[k] - '0';
                        }
                        else
                        {
                            y = y * 10 + uart.receive_data[k] - '0';
                        }
                    }
                    else if (uart.receive_data[k] == ',')
                    {
                        towards = 1;
                    }
                    

                    k++;
                }
                printf("(%d,%d)", x, y);
            }
            break;

            default: {printf("error");}
        }
    }
}