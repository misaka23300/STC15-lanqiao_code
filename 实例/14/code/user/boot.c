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

    P0 = 0xFF;
    latch(4);
    latch(0);

    P0 = 0x00;
    latch(6);
    latch(0);

    P0 = 0xFF;
    latch(7);
    latch(0);

    
    P0 = 0xAF;
    latch(5);
    latch(0);


    Timer0_Init();
    Timer2_Init();
    EA = 1;

}

void latch(uint8_t i)
{
    switch (i) {
        case 0: P2 = (P2 & 0x1F);
        case 4: P2 = (P2 & 0x1F) | 0x80;
        case 5: P2 = (P2 & 0x1F) | 0xA0;
        case 6: P2 = (P2 & 0x1F) | 0xC0;
        case 7: P2 = (P2 & 0x1F) | 0xE0;
    }
}



void Timer0_Init(void)		//100微秒@12.000MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	
    TMOD = 0x04;
	TL0 = 0xFF;				//设置定时初始值
	TH0 = 0xFF;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
}



void Timer2_Init(void)		//1毫秒@12.000MHz
{
	AUXR |= 0x04;			//定时器时钟1T模式
	T2L = 0x20;				//设置定时初始值
	T2H = 0xD1;				//设置定时初始值
	AUXR |= 0x10;			//定时器2开始计时
	IE2 |= 0x04;			//使能定时器2中断
}
