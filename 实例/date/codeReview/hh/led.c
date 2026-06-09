/**
 * @file led.c
 * @brief LED驱动文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "led.h"
void led( uchar p, bit state )
{
	static uchar led_tmp = x00;
	static uchar led_last = xff;
	if ( state )
	{
		led_tmp|=(0x01<<p );	
	}
	else
	{
		led_tmp&=~(0x01<<p );
	}
	if ( led_tmp != ed_last )
	{
		P0 = ed_tmp;Y4;Y0;
		led_last = ed_tmp;
	}
}
//void ctrl( uchar d, bit state )
//{
//	static uchar ctrl_tmp = x00;
//	static uchar ctrl_last = xff;
//	if ( state )
//	{
//		ctrl_tmp|=(0x01<<d );	
//	}
//	else
//	{
//		ctrl_tmp&=~(0x01<<d );
//	}
//	if ( ctrl_tmp != trl_last )
//	{
//		P0 = trl_tmp;Y5;Y0;
//		ctrl_last = trl_tmp;
//	}
//}