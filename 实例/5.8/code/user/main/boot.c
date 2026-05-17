#include "boot.h"








void boot_init()
{

    P0 = 0xFF;
    latch(4);

    P0 = 0xAF;
    latch(5);

    P0 = 0x00;
    latch(6);

    P0 = 0xFF;
    latch(7);


    Timer2_Init();

    EA = 1;
}



void latch(uint8_t i) 
{
    switch (i) {
        case 4: {P2 = (P2 & 0x1F | 0x80); break;}
        case 5: {P2 = (P2 & 0x1F | 0xA0); break;}
        case 6: {P2 = (P2 & 0x1F | 0xC0); break;}
        case 7: {P2 = (P2 & 0x1F | 0xE0); break;}
        case 0: {P2 = (P2 & 0x1F); break;}
        
    }

    P2 = (P2 & 0x1F);

}



void Timer2_Init(void)		//1毫秒@12.000MHz
{
	AUXR |= 0x04;			//定时器时钟1T模式
	T2L = 0x20;				//设置定时初始值
	T2H = 0xD1;				//设置定时初始值
	AUXR |= 0x10;			//定时器2开始计时
	IE2 |= 0x04;			//使能定时器2中断
}
