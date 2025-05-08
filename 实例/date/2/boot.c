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
	Y4;
	Y0;

	P0 = 0x00;
	Y6;
	Y0;

	P0 = 0xFF;
	Y7;
	Y0;

	P0 = 0xAF;
	Y5;
	Y0;

	timer_1();
	EA = 1;
}

// 1ms
void timer_1()
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x18;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;	
}




void Delay14us()
{
   unsigned char i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}





