#include "Led.h"

uchar led_value[8] = {0, 0, 0, 0, 0, 0, 0, 0};
void led(uchar i, bit state)
{
 	static uchar temp, last = 0xFF;

	if (state)
	{
		temp = temp | (0x01 << i);
	}
	else
	{
		temp = temp & ~(0x01 << i);
	}

	if (temp != last)
	{
		P0 = ~temp;
		Y4;
		Y0;
		last = temp;
	}
}

void led_display()
{
	static uchar i;
	led(i, led_value[i]);
	i= (i + 1) % 8;
}


void led_state(uchar j)
{
	uchar i;
	for (i = 0;i < 4;i++)
	{
		led_value[i] = 0;
		if (i == j)
		{
			led_value[j] = 1;	
		}
	}	
}


void led_shan()
{
	static uchar j;

	led_value[7] = j;
	j = ~j;

}