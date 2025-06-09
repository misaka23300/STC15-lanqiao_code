#include "machine.h"

void clean_display()
{
    P0M0 = 0x00; P0M1 = 0x00;
    P1M0 = 0x00; P1M1 = 0x00;
    P2M0 = 0x00; P2M1 = 0x00;
    P3M0 = 0x00; P3M1 = 0x00;
    P4M0 = 0x00; P4M1 = 0x00;
    P5M0 = 0x00; P5M1 = 0x00;
    P6M0 = 0x00; P6M1 = 0x00;
    P7M0 = 0x00; P7M1 = 0x00;

    P0 = 0xFF;
    batch(4);

    P0 = 0xAF;
    batch(5);

    P0 = 0x00;
    batch(6);

    P0 = 0xFF;
    batch(7);
}

void batch(uchar i)
{
    switch (i)
    {
        case 4: { P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: { P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: { P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: { P2 = (P2 & 0x1F) | 0xE0; break; }
    }
    P2 = (P2 & 0x1F);
}

void Timer0_Init(void) // 1微秒@12.000MHz
{
    AUXR |= 0x80;      // 定时器时钟1T模式
    TMOD &= 0xF0;      // 设置定时器模式
    TMOD |= 0x02;      // 设置定时器模式
    TMOD |= 0x04;
    TL0 = 0xFF;        // 设置定时初始值
    TH0 = 0xFF;        // 设置定时重载值
    TF0 = 0;           // 清除TF0标志
    TR0 = 1;           // 定时器0开始计时
    ET0 = 1;           // 使能定时器0中断
}

void Timer1_Init(void) // 1毫秒@12.000MHz
{
    AUXR |= 0x40;      // 定时器时钟1T模式
    TMOD &= 0x0F;      // 设置定时器模式
    TL1 = 0x20;        // 设置定时初始值
    TH1 = 0xD1;        // 设置定时初始值
    TF1 = 0;           // 清除TF1标志
    TR1 = 1;           // 定时器1开始计时
    ET1 = 1;           // 使能定时器1中断
}

void Uart1_Init(void) // 9600bps@12.000MHz
{
    SCON = 0x50;       // 8位数据,可变波特率
    AUXR |= 0x01;      // 串口1选择定时器2为波特率发生器
    AUXR |= 0x04;      // 定时器时钟1T模式
    T2L = 0xC7;        // 设置定时初始值
    T2H = 0xFE;        // 设置定时初始值
    AUXR |= 0x10;      // 定时器2开始计时
    ES = 1;            // 使能串口1中断
    // PS = 1;
}

void pcaInit()
{
    uint CCAP0_TIME = 1000;

    CMOD = 0x00;
    CCON = 0x00;

    CH = 0x00; CL = 0x00;

    CCAPM0 = 0x49;  // 0100 1001
    CCAP0L = CCAP0_TIME; CCAP0H = CCAP0_TIME >> 8;

    EA = 1;
    CCON = 0x41;     // 0100 0001
    PPCA = 1;
}

void timer()
{
    // timer2 -> 串口
    // timer1 -> 超声波
    // timer0 -> 频率

    Timer0_Init();
    Timer1_Init();
    //pcaInit();
    Uart1_Init();
    EA = 1;
}





