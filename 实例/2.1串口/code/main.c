#include "main.h"

extern uchar led_array[8];

enum {
    TIME_CCAP_0 = 1000,
    LED_TIME = 2,
    WATERLED_TIME = 500
};

uint timer_0;

typedef struct{
    uchar time;
    uint waterTime;
} LED;

LED led;

void pcaInit()
{
    CMOD = 0x00;              // 配置时钟
    CCON = 0x00;              // 清除标志位，停止PCA
    
    CL = 0x00; CH = 0x00;     // 设置计数器初值

    CCAPM0 = 0x49;            // 比较模式
    CCAP0L = TIME_CCAP_0;
    CCAP0H = TIME_CCAP_0 >> 8;

    EA = 1;
    CCON = 0x41;    // 0100 0001

    //CCON |= 0x40;               // CR = 1;
    PPCA = 1;


    timer_0 = TIME_CCAP_0;
}


void pcaInit()
{
    CMOD = 0x00;
    CCON = 0x00;

    CL = 0x00; CH = 0x00;

    CCAPM0  0x49;
    CCAP0L = TIME_CCAP_0; 
    CCAP0H = TIME_CCAP_0 >> 8;

    EA = 1;
    CCON = 0x41;
}

void pcaInterrupt() interrupt 7
{
    
    if (CCF0)
    {
        CCF0 = 0;
        
        CCAP0L = timer_0; CCAP0H = timer_0 >> 8;

        timer_0 += TIME_CCAP_0;

        if ( led.time < LED_TIME ) { led.time++; } 
        if ( led.waterTime < WATERLED_TIME) { led.waterTime++; }
    }
}


void waterLed()
{
    static uchar toward;
    led_array[0] = toward;
    led_array[1] = toward;
    led_array[2] = toward;
    led_array[3] = toward;
    led_array[4] = toward;
    led_array[5] = toward;
    led_array[6] = toward;
    led_array[7] = toward;

    if (toward == 1)
    {
        toward = 0;
    }
    else
    {
        toward = 1;
    }
}


void taskLoop()
{
    if (led.time == LED_TIME)
    {
        led.time = 0;
        led_display();
    }

    if (led.waterTime == WATERLED_TIME)
    {
        led.waterTime = 0;
        waterLed();
    }
}

void main()
{
    pcaInit();
    while (1)
    {
        taskLoop();
    }
}



