#include "boot.h"



void boot_init()
{
    P0M1 = 0;   P0M0 = 0;   //设置为准双向口
    P1M1 = 0;   P1M0 = 0;   //设置为准双向口
    P2M1 = 0;   P2M0 = 0;   //设置为准双向口
    P3M1 = 0;   P3M0 = 0;   //设置为准双向口
    P4M1 = 0;   P4M0 = 0;   //设置为准双向口
    P5M1 = 0;   P5M0 = 0;   //设置为准双向口
    P6M1 = 0;   P6M0 = 0;   //设置为准双向口
    P7M1 = 0;   P7M0 = 0;   //设置为准双向口

    P0 = 0xFF; latch(4);
    P0 = 0xAF; latch(5);
    P0 = 0x00; latch(6);
    P0 = 0xFF; latch(7);

    Timer0_Init();
    Timer2_Init();
    Uart1_Init();
    EA = 1;
}


void latch(uint8_t i)
{
    switch (i) {
        case 4: {P2 = (P2 & 0x1F) | 0x80; break;}
        case 5: {P2 = (P2 & 0x1F) | 0xA0; break;}
        case 6: {P2 = (P2 & 0x1F) | 0xC0; break;}
        case 7: {P2 = (P2 & 0x1F) | 0xE0; break;}
        case 0: {P2 = (P2 & 0x1F); break;}
    }
}




void Timer0_Init(void)		//100微秒@12.000MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD |= 0x04;			//设置定时器模式
	TL0 = 0xFF;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 0;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
}



void Uart1_Init(void)	//9600bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0xC7;			//设置定时初始值
	TH1 = 0xFE;			//设置定时初始值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES = 1;				//使能串口1中断
}



void Timer2_Init(void)		//1毫秒@12.000MHz
{
	AUXR |= 0x04;			//定时器时钟1T模式
	T2L = 0x20;				//设置定时初始值
	T2H = 0xD1;				//设置定时初始值
	AUXR |= 0x10;			//定时器2开始计时
	IE2 |= 0x04;			//使能定时器2中断
}
