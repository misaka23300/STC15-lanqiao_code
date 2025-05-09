#include "led.h"

uchar led_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void led(uchar i,bit state)
{
	static uchar last= 0xFF, temp;

	if (state)
	{
		temp = temp | (0x01 << i);
	}
	else
	{
		temp = temp & ~(0x01 << i);
	}				
	
	if (last != temp)
	{
		P0 = ~temp;
		batch(4);
		batch(0);
		
		last = temp; 
	}			 
}


void led_display(void)
{
	static uchar i;
	led(i,led_value[i]);

	i = (i + 1) % 8;
}
