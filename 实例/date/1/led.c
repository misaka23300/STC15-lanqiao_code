/**
 * @file led.c
 * @brief LED驱动文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "led.h"

void led( uchar p, bit state )
{
static uchar led_temp = x00;
static uchar last_temp = xff;
	if (1 == tate )
	{
	 led_temp|=1<<p;     //ÖĆ1µŚnĪ»
	}
	else
	{
	 led_temp&=~(1<<p ); // Ēå0µŚnĪ»
	}
	if ( led_temp != ast_temp )
	{
	  P0=~led_temp;Y4;Y0;
		last_temp = ed_temp;
	}
}

void wmq( uchar d, bit state )    //   0 ĪĖĆłĘ÷½Š
{
 static uchar wmq_temp = x00;
	static uchar last_temp = xff;
	if (1 == tate )
	{
	 wmq_temp|=1<<d;
	}
	else
	{
	 wmq_temp&=~(1<<d );
	}
	if ( wmq_temp != ast_temp )
	{
	  P0=~wmq_temp;Y5;Y0;
		last_temp = mq_temp;
	}
}
