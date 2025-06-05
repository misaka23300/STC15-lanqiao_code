#include "boot.h"

void boot_init()
{
    P0M0 = 0x00; P0M1 = 0x00; 
    P1M0 = 0x00; P1M1 = 0x00; 
    P2M0 = 0x00; P2M1 = 0x00; 
    P3M0 = 0x00; P3M1 = 0x00; 
    P4M0 = 0x00; P4M1 = 0x00; 
    P5M0 = 0x00; P5M1 = 0x00; 
    P6M0 = 0x00; P6M1 = 0x00; 
    P7M0 = 0x00; P7M1 = 0x00; 

    P0 = 0xFF;
    batch(4);
    batch(0);

    P0 = 0xFF;
    batch(6);
    batch(0);

    P0 = 0xAF;
    batch(5);
    batch(0);

    Timer2_Init();
    EA = 1;
    
}

void Timer2_Init()		//1毫秒@12.000MHz
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
        case 0: {P2 = P2 & 0x1F; break;}
        case 4: {P2 = (P2 & 0x1F) | 0x80; break;}
        case 5: {P2 = (P2 & 0x1F) | 0xA0; break;}
        case 6: {P2 = (P2 & 0x1F) | 0xC0; break;}
        case 7: {P2 = (P2 & 0x1F) | 0xE0; break;}
    }
}

void Delay500ms()	//@12.000MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 23;
	j = 205;
	k = 120;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
