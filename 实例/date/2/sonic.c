/**
 * @file sonic.c
 * @brief 超声波传感器驱动
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "sonic.h"

sbit tx = P1 ^ 0;
sbit rx = P1 ^ 1;

void send_sonic()
{
	uchar i;
	for ( i = 0;i < 8;i++)
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
	
	// rxŒ™1 ±÷¥––
	while ( rx == 0 );
	TR0 = 1;

	// rxŒ™0 «“Œ¥“Á≥ˆ
	while ( rx == 1 && TF0 == 0 );
	TR0 = 0;

	if ( TF0 )
	{
		distance = 99;
		TF0	= 0;
	}
	else
	{
		distance = ( uint )( ( TH0 << 8 ) | TL0 ) * 0.017;
	}
	return distance;

}