#include "timer.h"


// timer0 -> freq
// timer1 -> 1ms
// timer2 -> uart






void Timer0Init(void)		//100微秒@12.000MHz
{
	//AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD = 0x05;		//���ö�ʱ��T0Ϊ������ģʽ
	TL0 = 0xFF;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ��Ϊ0
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;		//����Ҫ�ж�
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



void timer()
{
    Timer0Init();
    
	Timer1Init();
    EA = 1;
}