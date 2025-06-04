#include "main.h"



typedef struct {
    uchar time;
    uchar mode_0;
} STATE;

STATE state;

typedef struct {
    uint time;
    
} UART;

code uchar str[] = "ciallo~";
code float number = 0.0721;
UART uart;


typedef struct {
    uchar time;
    uchar press;
} KEY;

KEY key;


enum {
    STATE_TIME = 50,
    UART_TIME = 1000,
    KEY_TIME = 20
};



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

    if (key.time == KEY_TIME)
    {
        key_task();
        key.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    

    if ( state.time < STATE_TIME ) { state.time++; }

    if ( uart.time < UART_TIME ) { uart.time++; }

    if ( key.time < KEY_TIME ) { key.time++; }
    
    seg_display();
}




void display_task()
{
    switch (state.mode_0)
    {
        case 0:
        {
            //set_seg_value(2, 3, 0, 0, 0, 0, 0, 0);
        }
        break;

     
    }
}

void uart_task()
{
    //uart_send(str);
}


void key_task()
{
    key.press = key_scan();

    switch (key.press)
    {
        case 4:
        {
            set_seg_value(4, 0, 0, 0, 0, 0, 0, 0);
        }
        break;

        case 5:
        {
            set_seg_value(5, 0, 0, 0, 0, 0, 0, 0);
        }
        break;
    }
}




void main()
{
    
    char buf[20];  

    boot_init();
    uart_send("设备完成了初始化");

    sprintf(buf, "%.2f\r\n", number);
    uart_send(buf);

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


void pcaInit()
{
    CMOD = 0x00;    // 配置时钟源 12分频
    CCON = 0x00;    // 清除标志位，停止PCA
    CCAPM0 = 0x49;  // 
    CL = 0x00;
    CH = 0x00;

    CCAP0L = 1000 & 0xFF;
    CCAP0H = (1000 >> 8) & 0xFF;

    EA = 1;     // 开启使能总中断
    ECF = 1;    // 开启PCA中断
    CCON |=  0x40;  // 启动PCA
}

void PCAInterrupt() interrupt 7
{
    
}