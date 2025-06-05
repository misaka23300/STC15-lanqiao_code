#include "machine.h"


void batch(uchar i)
{
    switch (i)
    {
        case 4: { P2 = (P2 & 0x1F) | 0x80; break; }
        case 5: { P2 = (P2 & 0x1F) | 0xA0; break; }
        case 6: { P2 = (P2 & 0x1F) | 0xC0; break; }
        case 7: { P2 = (P2 & 0x1F) | 0xE0; break; }
    }

    P2 = P2 & 0x1F;
}


uchar receive[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uchar toward;
// 0 -> 左到右
// 1 -> 右到左
char index;
void Uart1_Isr(void) interrupt 4
{
	if (TI)				//检测串口1发送中断
	{
		TI = 0;			//清除串口1发送中断请求位
	}
	if (RI)				//检测串口1接收中断
	{

		RI = 0;			//清除串口1接收中断请求位
        receive[index] = SBUF;

        if (toward == 0) 
        {
            index++;
            if (index == 8)
            {
                index = 0;
                toward = 1;
            }
        }8
        else
        {
            index--;
            if (index == -1)
            {
                toward = 0;
            }
        }

	}
}

void Uart1_Init(void)	//9600bps@12.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器时钟1T模式
	T2L = 0xC7;			//设置定时初始值
	T2H = 0xFE;			//设置定时初始值
	AUXR |= 0x10;		//定时器2开始计时
	ES = 1;				//使能串口1中断
}


// str -> 指针地址
// *str -> 地址取值
void uartSend(uchar *str)
{
    while (*str != '\0')
    {
        SBUF = *str;

        while (TI == 0);
        TI = 0;

        str++;
    }

}



