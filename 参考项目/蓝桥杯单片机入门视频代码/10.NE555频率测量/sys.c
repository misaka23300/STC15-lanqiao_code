#include "sys.h"
void Sys_Init(){
	P0=0xff;Y4;Y0;
	P0=0xaf;Y5;Y0;
	P0=0xff;Y6;Y0;
	P0=0xff;Y7;Y0;
}
void Delay(u16 xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);	
	}
	
}

void NE555_Init(void)		//NE555初始化
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD = 0x05;		//设置定时器T0为计数器模式
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值都为0
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 0;		//不需要中断
}

//定时器1作为系统进程管理定时器
void Timer1Init(void)		//1毫秒@12.000MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x18;		//设置定时初值
	TH1 = 0xFC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;
	EA = 1;
}
