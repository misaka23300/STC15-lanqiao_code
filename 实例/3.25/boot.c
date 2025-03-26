#include "boot.h"

void boot_init(void)
{
    P0M0 = 0x00;

    P0 = 0xFF;
    batch(4);
    batch(0);

    P0 = 0xAF;
    batch(5);
    batch(0);

    P0 = 0x00;
    batch(6);
    batch(0);

    P0 = 0xFF;
    batch(7);
    batch(0);

    timer_0();
    timer_1();
    timer_2();
    EA = 1;
}

//ne555
void timer_0(void)
{
    // 计数器 8位自动重装载 

    // xxxx 0110


    // 定时器0 -> 计数器 
    //AUXR |= 0x80;
    //TMOD = (TMOD & 0xF0) | 0x06;
    TL0 = 0x00; 
    TH0 = 0x00;

    TF0 = 0;
    TR0 = 1;
    ET0 = 0;
}

// sonic
void timer_1(void)
{
    AUXR |= 0x40;			//定时器时钟1T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x50;				//设置定时初始值
	TH1 = 0xFB;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 0;				//定时器1开始计时
	ET1 = 0;				//使能定时器1中断

}

void timer_2(void)
{
    AUXR &= 0xFB;			//定时器时钟12T模式
	T2L = 0x18;				//设置定时初始值
	T2H = 0xFC;				//设置定时初始值
	AUXR |= 0x10;			//定时器2开始计时
	IE2 |= 0x04;			//使能定时器2中断

}

void batch(uchar i)
{
    switch (i)
    {
        case 4: {P2 = (P2 & 0x1F) | 0x80; break;}
        case 5: {P2 = (P2 & 0x1F) | 0xA0; break;}
        case 6: {P2 = (P2 & 0x1F) | 0xC0; break;}
        case 7: {P2 = (P2 & 0x1F) | 0xE0; break;}
        case 0: {P2 = (P2 & 0x1F); break;}
    }
}

void Delay14us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}

