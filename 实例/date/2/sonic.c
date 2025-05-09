#include "sonic.h"

sbit tx = P1 ^ 0;
sbit rx = P1 ^ 1;

void send_sonic()
{
	uchar i;
	for (i = 0;i < 8;i++)
	{
	 	tx = 1;
		Delay14us();
		tx = 0;
		Delay14us();
	}
}

uint sonic_measure()
{
	uint distance;
	
	TR0 = 0;
	TL0 = 0;TH0 = 0;
	TF0 = 0;

	send_sonic();
	
	// rx为1时执行
	while (rx == 0);
	TR0 = 1;

	// rx为0 且未溢出
	while (rx == 1 && TF0 == 0);
	TR0 = 0;

	if (TF0)
	{
		distance = 99;
		TF0	= 0;
	}
	else
	{
		distance = (uint)( (TH0 << 8) | TL0) * 0.017;
	}
	return distance;

}