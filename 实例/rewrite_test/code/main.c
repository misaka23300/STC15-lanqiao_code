#include "main.h"


// 显示状态
typedef struct {
    uchar time;
    uchar mode_0;
} STATE;

STATE state;

// 串口
typedef struct {
    uint time;
    
} UART;

code uchar str[] = "ciallo~";
code float number = 0.0721;

UART uart;

// 键盘
typedef struct {
    uchar time;
    uchar press;
} KEY;

KEY key;

// 日期
typedef struct {
    uchar number[8];
    uchar i;
    uchar input;

} CAL;

CAL calculator;

// 超声波
typedef struct {
    uint distance;
    uint time;
} SONIC;
    
SONIC sonic;

enum {
    STATE_TIME = 50,
    UART_TIME = 1000,
    KEY_TIME = 20,
    SONIC_TIME = 100
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

    if (sonic.time == SONIC_TIME)
    {
        sonic_task();
        sonic.time = 0;
    }
}

void timer_1_interrupt() interrupt 3
{
    

    if ( state.time < STATE_TIME ) { state.time++; }

    if ( uart.time < UART_TIME ) { uart.time++; }

    if ( key.time < KEY_TIME ) { key.time++; }

    if (sonic.time < SONIC_TIME) {sonic.time++; }
    
    seg_display();
}




void display_task()
{
    switch (state.mode_0)
    {
        case 0:
        {
            set_seg_value(sonic.distance % 10 / 10 , sonic.distance / 10, 0, 0, 0, 0, 0, 0);
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
}

void sonic_task()
{
    sonic.distance = measurePCA();
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
    pcaInit();
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