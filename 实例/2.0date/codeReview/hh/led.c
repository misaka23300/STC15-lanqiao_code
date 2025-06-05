#include "led.h"
void led(uchar p,bit state)
{
	static uchar led_tmp=0x00;
	static uchar led_last=0xff;
	if(state)
	{
		led_tmp|=(0x01<<p);	
	}
	else
	{
		led_tmp&=~(0x01<<p);
	}
	if(led_tmp!=led_last)
	{
		P0=led_tmp;Y4;Y0;
		led_last=led_tmp;
	}
}
//void ctrl(uchar d,bit state)
//{
//	static uchar ctrl_tmp=0x00;
//	static uchar ctrl_last=0xff;
//	if(state)
//	{
//		ctrl_tmp|=(0x01<<d);	
//	}
//	else
//	{
//		ctrl_tmp&=~(0x01<<d);
//	}
//	if(ctrl_tmp!=ctrl_last)
//	{
//		P0=ctrl_tmp;Y5;Y0;
//		ctrl_last=ctrl_tmp;
//	}
//}