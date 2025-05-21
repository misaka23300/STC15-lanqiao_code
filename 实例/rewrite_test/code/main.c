#include "main.h"

enum {
    STATE_TIME = 50,
    UART_TIME = 1000
};

typedef struct {
    uchar time;
    uchar mode_0;
} STATE;

STATE state;

typedef struct {
    uint time;
    
} UART;

code uchar str[] = "ciallo~";
UART uart;



void task_loop()
{
    
    if (state.time == STATE_TIME)
    {
        display_task();
        state.time = 0;
    }

    if (uart.time == UART_TIME)
    {
        uart_task();
        uart.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    

    if ( state.time < STATE_TIME ) { state.time++; }

    if ( uart.time < UART_TIME ) { uart.time++; }
    
    seg_display();
}




void display_task()
{
    switch (state.mode_0)
    {
        case 0:
        {
            set_seg_value(2, 3, 0, 0, 0, 0, 0, 0);
        }
        break;

     
    }
}

void uart_task()
{
    //uart_send(str);
}

void main()
{
    
    boot_init();
    uart_send("设备完成了初始化");
    while (1)
    {
        task_loop();
    }
}

void boot_init()
{
    clean_display();

    
    Timer1_Init();
    Uart1_Init();
    EA = 1;

    
}