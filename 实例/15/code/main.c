#include "main.h"




idata KEY key;
idata FREQ freq;
idata CAR car;
idata SONIC sonic;



// PCA_______________________________________

/* void pcaInterrupt() interrupt 7
{
    if (CCF0)
    {
        CCF0 = 0;
        setPcaTime += CCAP0_TIME;

        CCAP0L = setPcaTime;
        CCAP0H = setPcaTime >> 8;
        
        time_1ms();
    }
}
 */

void Timer1_Isr(void) interrupt 3
{
    time_1ms();
}
// 频率
void Timer0_Isr(void) interrupt 1
{
    freq.times++;
}


// 任务调度_______________________________________


void time_1ms()
{
    seg_display();
    led_display();


    if (key.time < KEY_TIME) { key.time++; }

    if (freq.time < FREQ_TIME) { freq.time++; }

    if (uart.time < UART_TIME) {uart.time++; }

    if (uart.out_time_flag && uart.out_time < 11) { uart.out_time++; }

    if (sonic.time < SONIC_TIME) {sonic.time++; }

 }


void task_loop()
{
    uchar *p = &sonic.distance;
    if (key.time == KEY_TIME)
    {
        key_task();        
        key.time = 0;
    }

    if (freq.time == FREQ_TIME)
    {
        freq.time = 0;
        freq_task();
    }

    if (uart.time == UART_TIME)
    {
        uart.time = 0;
        uart_task();
    }

    if (sonic.time == SONIC_TIME)
    {
        sonic.time = 0;
        sonic.distance = sonic_measure();
        printf(p);
        seg_list[5] = sonic.distance / 100 % 10;
        seg_list[6] = sonic.distance / 10 % 10;
        seg_list[7] = sonic.distance % 10;
    }
}

void main()
{
    
    clean_display();
    timer();
    printf("start");
    
    while (1)
    {
        task_loop();
    }
}


// _________________________________________任务函数

void key_task()
{
    key.press = key_scan();
}



/* void free_state(uchar xx, yy)
{
    uchar distance_x;
    uchar distance_y;
		uchar distance;
    distance_x = car.x - xx;
    distance_y = car.y - yy;

    distance = distance_x * distance_x + distance_y *distance_y;
    distance = sqrt(distance);

} */


void freq_task()
{
    freq.times_out = freq.times;
    freq.times = 0;
    
}


void number_display(uint i)
{
    seg_list[3] = i / 10000 % 10;
    seg_list[4] = i / 1000 % 10;
    seg_list[5] = i / 100 % 10;
    seg_list[6] = i / 10 % 10;
    seg_list[7] = i % 10;

}


void uart_task()
{
    if (uart.index == 0) {return ;}

    if (uart.out_time > 10)
    {
        uart.out_time = 0;
        uart.out_time_flag = 0;

        printf("ciallo~");
    }
}

