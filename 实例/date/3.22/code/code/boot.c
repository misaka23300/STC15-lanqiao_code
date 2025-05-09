#include "boot.h"

void boot_init(void)
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
	batch(4);
	batch(0);

	P0 = 0xFF;
	batch(7);
	batch(0);

	P0 = 0x00;
	batch(6);
	batch(0);

	P0 = 0xAF;
	batch(5);
	batch(0);

	timer_0();
	timer_1();
	EA = 1;

}

// ne555 计数器
void timer_0(void)
{
		TMOD = 0x06; 	// 0000 0110
		AUXR &= 0x7F; 	// 0xxx xxxx
		TL0 = 0xFF;
		TH0 = 0xFF;
		TF0 = 0;
		TR0 = 1;
		ET0 = 1;
}

// 1ms
void timer_1(void)
{
	AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x18;				//设置定时初始值
	TH1 = 0xFC;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
}

void batch(uchar i)
{
	switch (i)
	{
		case 0: {P2 = (P2 & 0x1F); break;}
		case 4: {P2 = (P2 & 0x1F) | 0x80; break;}
		case 5: {P2 = (P2 & 0x1F) | 0xA0; break;}
		case 6: {P2 = (P2 & 0x1F) | 0xC0; break;}
		case 7: {P2 = (P2 & 0x1F) | 0xE0; break;}
	}
}


