#include "main.h"




idata KEY key;
idata FREQ freq;
idata CAR car;
idata SONIC sonic;


xdata PCF8591 adc;
xdata DISPLAY display;
idata POSITION position;
xdata SPEED speed;

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
        sonic_task();
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

void key_task()     // -> key.press
{
    key.press = key_scan();

    switch (key.press)
    {
        case  4:
        {
            if (state.mode == 0)
            {
                if (uart.receive_dat_flag == 1)
                {
                    uart.receive_data_flag = 0;
                    state.mode = 1;
                }
                
            }
            else if (state.mode == 2)
            {
                if (sonic.distance >= 30)
                {
                    sonic.lock = 0;
                    state.mode = 1;
                }
            }

        }
        break;
        
        case 5:
        {
            if (state.mode == 2)
            {
                position.now[0] = 0;
                position.now[1] = 0;
            }
        }
        break;

        case 8:
        {
            if (display.state == 1) {speed.argument_state = 0;}

            display.state++;
            
            if (display.state == 3) {display.mode = 0;}
        }
        break;

        case 9:
        {
            if (display.state == 2)
            {
                speed.argument_state++;
                if (speed.argument_state == 2) {speed.argumen_state = 0; }
            }
        }
        break;

        case 12:
        {
            if (display.state == 2)
            {
                if (speed.argument_state == 0) { speed.r += 0.1; }
            }
        }
        break;
    }
}


void freq_task()    // -> freq.times_out  -> speed.value
{
    freq.times_out = freq.times;
    freq.times = 0;
    speed.value = 3.14 * speed.r * freq.times / 100 + speed.b;
}


void number_display(uint i)
{
    seg_list[3] = i / 10000 % 10;
    seg_list[4] = i / 1000 % 10;
    seg_list[5] = i / 100 % 10;
    seg_list[6] = i / 10 % 10;
    seg_list[7] = i % 10;

}


void uart_task()    // <- uart.receive 
{
    if (uart.index == 0) {return ;}

    if (uart.out_time > 10)
    {
        uart.out_time = 0;
        uart.out_time_flag = 0;

        if (uart.receive_data[0] == '(')
        {
            if (state.mode = 0)
            {
                printf("Got it");
                get_position();
                position.going[0] = input.x;
                position.going[1] = input.y;
            }
            else
            {
                printf("Busy");
            }
        }
        else if (uart.receive_data[0] = '?')
        {
            if (state.mode == 0) { printf("Idle"); }
            else if (state.mode == 1) { printf("Wait"); }
            else if (state.mode == 2) { printf("Busy"); }
        }
        else if (uart.receive_data[0] = '#')
        {
            printf("(");
            printf(position.now[0]);
            printf(",");
            printf(position.now[1]);
            printf(")");
        }
        else 
        {
            printf("Error");
        }
    }
}

void adc_task()     // -> adc.is_dat_no_night
{
    adc.value = ADC(0x03);

    if (adc.value > 61)
    {
        adc.is_day_no_night = 1;
    }
    else
    {
        adc.is_day_no_night = 0;
    }
}

void display_task()
{
    switch (display.state)
    {
        // L XXX - YYY
        case 0:
        {
            if (state.mode == 0)
            {
                seg_list[0] = 18;
                seg_list[1] = position.now[0] / 100 % 10;
                seg_list[2] = position.now[0] / 10 % 10;
                seg_list[3] = position.now[0] % 10;
                seg_list[4] = 16;
                seg_list[5] = position.now[1] / 100 % 10;
                seg_list[6] = position.now[1] / 10 % 10;
                seg_list[7] = position.now[1] % 10;
            }
            else if (state.mode == 1 || state.mode == 2)
            {
                seg_list[0] = 18;
                seg_list[1] = position.going[0] / 100 % 10;
                seg_list[2] = position.going[0] / 10 % 10;
                seg_list[3] = position.going[0] % 10;
                seg_list[4] = 16;
                seg_list[5] = position.going[1] / 100 % 10;
                seg_list[6] = position.going[1] / 10 % 10;
                seg_list[7] = position.going[1] % 10;
            }
        }
        break;
    }
}


void speed_task()
{
    
}


void sonic_task()   // -> sonic.distance
{
    sonic.distance = sonic_measure();
    if (sonic.distance < 30 && sonic.lock == 0)
    {
        state.mode = 2;
        sonic.lock = 1;
    }
    
}