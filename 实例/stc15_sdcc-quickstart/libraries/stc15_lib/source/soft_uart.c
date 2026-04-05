/*************	功能说明	**************

本文件为模拟串口发送程序, 一般为测试监控用.

串口参数:9600,8,n,1.

可以根据主时钟自动适应.

******************************************/

#include "soft_uart.h"

#define P_TXD P31 //定义模拟串口发送端,可以是任意IO

/* 9600 波特率，每位 104 us */
void BitTime(void)
{
	unsigned char i, j;

#if (MAIN_Fosc == 11059200L)
	_nop_();
	_nop_();
	i = 2;
	j = 26;
#elif (MAIN_Fosc == 12000000L)
	i = 2;
	j = 51;
#elif (MAIN_Fosc == 16000000L)
	i = 2;
	j = 155;
#elif (MAIN_Fosc == 22118400L)
	i = 3;
	j = 57;
#elif (MAIN_Fosc == 24000000L)
	i = 3;
	j = 106;
#else
#error "soft_uart not support this clock frequency !"
#endif

	do
	{
		while (--j)
			;
	} while (--i);
}

/* 实现 printf 接口 */
int putchar(int dat)
{
	u8 i;
	EA = 0;
	P_TXD = 0;
	BitTime();
	for (i = 0; i < 8; i++)
	{
		if (dat & 1)
			P_TXD = 1;
		else
			P_TXD = 0;
		dat >>= 1;
		BitTime();
	}
	P_TXD = 1;
	EA = 1;
	BitTime();
	BitTime();
	return dat;
}

#ifndef USE_STDIO
void print(char *buffer)
{
	while (*buffer != 0)
	{
		putchar((int)*buffer);
		buffer++;
	}
}
#endif
