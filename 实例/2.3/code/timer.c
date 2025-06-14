#include "timer.h"


// timer0 -> freq
// timer1 -> 1ms
// timer2 -> uart


UART uart;



/* void Timer0Init(void)		//100微秒@12.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD = 0x05;		//���ö�ʱ��T0Ϊ������ģʽ
	TL0 = 0;		//���ö�ʱ��ֵ
	TH0 = 0;		//���ö�ʱ��ֵ��Ϊ0
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ

} */


void Timer0Init(void)		//100微秒@12.000MHz
{
	AUXR &= 0x7F;			//定时器时钟12T模式
	//TMOD &= 0xF0;			//设置定时器模式
    TMOD = 0x05;			//设置定时器0为模式2
	TL0 = 0x00;				//设置定时初始值
	TH0 = 0x00;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	//ET0 = 1;				//使能定时器0中断
}


void Timer1Init(void)		//1毫秒@12.000MHz
{
	AUXR |= 0x40;		//定时器时钟1T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x20;		//设置定时初值
	TH1 = 0xD1;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
    ET1 = 1;
}




void UartInit(void)		//9600bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	//AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x05;		//定时器2时钟为Fosc,即1T
	T2L = 0xC7;		//设定定时初值
	T2H = 0xFE;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
    ES = 1;
}



void uart_interrupt() interrupt 4
{
    uchar Data;
    if (RI)
    {
        RI = 0;
        Data = SBUF;
        uart.out_time = 0;
        uart.out_time_flag = 1;

        uart.receive_data[uart.index] = Data;
        uart.index++;

        if (uart.index == (UART_LEN - 1) )
        {
            uart.index = 0;
        }
    }
}

char putchar(char c)
{
    SBUF = c;
    while (TI == 0);
    TI = 0;
    return c;
}

void timer()
{
    Timer0Init();
    Timer1Init();
    UartInit();

    EA = 1;
}