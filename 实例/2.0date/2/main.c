#include "main.h"

#define KEY_TIME 15
#define SONIC_TIME 1000
#define ADC_TIME 500
#define LED_TIME 20
#define SHAN_TIME 100


extern uchar seg[8];
extern uchar led_value[8];
bit key_flag, sonic_flag, adc_flag, adc_state, shan_flag;

uchar press;
// 模式
uchar state, mode = 1;
uchar distance[2];
uchar adc;

uchar one_tag;

uchar low = 0;
uchar high = 50;

uchar times;

void main()
{
	boot_init();
	led_state(state);
	while (1)
	{
		if (key_flag)
		{
			key_flag = 0;
			key_proc();
			state_machine();
		}

		if (sonic_flag && state == 0)
		{
			sonic_proc();
			sonic_flag = 0;
		}

		// 
		if (adc_flag && mode == 2 && state == 1)
		{
			adc_flag = 0;
			adc_proc();
		}
		
		

		state_machine();
	}
}

void timer1() interrupt 3
{
	static uint i;
	i = (i + 1) % 30000;
	
	seg_display();

	if ( i % KEY_TIME == 0)
	{
		key_flag = 1;
	}

	if (i % SONIC_TIME == 0)
	{
		sonic_flag = 1;
	}

	if (i % ADC_TIME == 0)
	{
		adc_flag = 1;
	}
	
	if (i % LED_TIME == 0)
	{
		led_display();
	}

	if (i % SHAN_TIME == 0 && shan_flag == 1)
	{
		led_shan();
	}
}

void key_proc()
{
	
	press = key_scan();
	switch (press)
	{
		case 4:
		{
			state = (state + 1) % 3;
			led_state(state);
		}
		break;

		case 5:
		{
			if (mode == 1)
			{
				mode = 2;
			}
			else
			{
				mode = 1;
			}
		}
		break;

		// low
		case 8:
		{
			if (mode == 1)
			{
				low = (low + 10) % 50;
				adc_state = 3;
			}	
			else
			{
				adc_state = 0;	
			}
		}
		break;

		case 9:
		{
			if (mode == 1)
			{
				high = (high + 10);
				if (high == 100)
					high = 50;
				adc_state = 3;
			}	
			else
			{
				adc_state = 1;	
			}
		}
		break;
	}
}

void sonic_proc()
{
	uint dis;
	// 99.23 -> 9923
	dis = sonic_measure() * 100;
	// 个位数
	distance[1] = dis / 100 % 10;
	// 十位数
    distance[0] = dis / 1000 % 10;
	if (distance[0] == 0)
		distance[0] = 16;

	check_distance();
}

void check_distance()
{
	uchar dis = distance[1] + distance[0] * 10;
	//uchar dis = 20;
	if (low <= dis && dis <= high)
	{
	 	led_value[7] = 1;
		shan_flag = 0;
	}
	else
	{
		if (times < 10) 
			times++;
		else
		{
			times = 17;
		}
		shan_flag = 1;
	}
}

void adc_proc()
{
	uchar v;
	uchar j;
	adc = ADC(0x03);
	v = adc;
	
	if (adc_state)
	{
		if (0 <= v && v < 51)
		 {
		 	j = 50;	
		 }
		 else if (51 <= v && v < 102)
		 {
		 	j = 60;
		 }
		 else if (102 <= v && v < 153)
		 {
		 	j = 70;
		 }
		 else if (153 <= v && v < 204)
		 {
		 	j = 80;
		 }
		 else if (204 <= v && v <= 255)
		 {
		 	j = 90;
		 }
	  high = j;
	}
	else
	{
		 if (0 <= v && v < 51)
		 {
		 	j = 0;	
		 }
		 else if (51 <= v && v < 102)
		 {
		 	j = 10;
		 }
		 else if (102 <= v && v < 153)
		 {
		 	j = 20;
		 }
		 else if (153 <= v && v < 204)
		 {
		 	j = 30;
		 }
		 else if (204 <= v && v <= 255)
		 {
		 	j = 40;
		 }
		low = j;			
	}
	 
	 
	
}



void state_machine()
{
	switch (state)
	{
		case 0:
		{
			set_seg(43, 16, 16, 16, 16, 16, distance[0], distance[1]); 
		} 
		break;

		case 1:
		{
		   set_seg(24, mode, 16, low / 10, low % 10, 17, high / 10, high % 10);
		}
		break;

		case 2:
		{
			set_seg(14, 16, 16, 16, 16, 16, 16, times);
		}
		break;
	}
}