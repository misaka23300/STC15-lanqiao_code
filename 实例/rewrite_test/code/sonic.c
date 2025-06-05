#include "sonic.h"

sbit tx = P3 ^ 0;
sbit rx = P3 ^ 1;




void sendSonic()
{
    tx = 0;
    Delay14us();
    tx = 1;
    Delay14us();
}



// 使用定时器1

/* void Timer1_Init()		//100微秒@11.0592MHz
{
	AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1 = 0x00;				//设置定时初始值
	TH1 = 0x00;				//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 0;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
}
 */

uchar measureTimer1()
{
    uchar distance;

    TR1 = 0; TF1 = 0;
    TH1 = 0x00; TL1 = 0x00;

    sendSonic();

    while (rx == 0);
    TR1 = 1;
    while (rx == 1 && TF1 != 0);
    TR1 = 0;

    if (TF1)
    {
        distance = 255;
    }
    else
    {
        distance = (uchar)(TH1 << 8 | TL1)* 0.017;

    }

    return distance;
}

//  使用PCA

void pcaInit()
{
    CMOD |= 0x08;
    CCON = 0x00;
    CH = 0x00; CL = 0x00;
    CR = 0;
    CF = 0;
}



uint measurePCA()
 {
    uint distance;

    CH = 0; CL = 0;
    CR = 0; CF = 0;

    sendSonic();

    while (rx == 0);

    CR = 1;

    while (rx == 1 && CF == 0);

    CR = 0;

    if (CF)
    {
        distance = 999;
    }
    else
    {
        distance = (uint) (CH << 8 | CL)* 17 / 1000;
    }

    return distance;
 }