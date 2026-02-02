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

    P0 = 0xAF;
    latch(5);
    latch(0);

    P0 = 0x00;
    latch(6);
    latch(0);

    P0 = 0xFF;
    latch(7);
    latch(0);

    Timer2_Init();
    EA = 1;
}

void latch(uchar i)
{
    switch (i)
    {
        case 0: { P2 = P2 & 0x1F; break; }
        case 4: { P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: { P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: { P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: { P2 = (P2 & 0x1F) | 0xE0; break; }
    }
}

void Timer2_Init(void)		//1毫秒@12.000MHz
{
	AUXR &= 0xFB;			//定时器时钟12T模式
	T2L = 0x18;				//设置定时初始值
	T2H = 0xFC;				//设置定时初始值
	AUXR |= 0x10;			//定时器2开始计时
	IE2 |= 0x04;			//使能定时器2中断
}

// 
void Delay14us(void)	//@12.000MHz
{
	unsigned char data i;

	_nop_();
	_nop_();
	i = 39;
	while (--i);
}

void delete_0(uchar *a, uchar j, uchar negative)
{
	uchar i;
    if (j == 0)
    {
        return;
    }
    j--;
    for (i = 0;i < j;i++)
    {
        if (a[i] == 0) 
            { a[i] = 16; }
        else
        {
            if (negative  == 1 && i != 0) { a[i-1] = 17; }
            break;
        }
    }
}
