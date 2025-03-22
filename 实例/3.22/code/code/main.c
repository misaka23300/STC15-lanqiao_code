#include "main.h"

const uchar code SEG_TIME = 1;
const uchar code KEY_TIME = 40;
const uchar code DATE_TIME = 100;
const uchar code LED_TIME = 50;

bit seg_flag, freq_flag, key_flag, ds1302_flag, freq_fushu, led_flag, shan_flag;


uint freq_high, freq_low;
long uint freq;

// 1 - 9 *1000
char freq_out = 2;

// -9 - 9 *100
char freq_xiaozhun = 0;


uchar state;
char state_1 = 1;
char state_3 = 0;

uchar time[3] = {0, 0, 0};

long uint freq_max;
uchar max_time[3] = {0, 0, 0};

extern uchar led_value[8];

void main()
{
	// 秒 分 时
	uchar times[3] = {0, 0, 23};
	write_datetime(times);

	boot_init();

	while (1)
	{
		if (seg_flag)
		{
			seg_flag = 0;
			state_proc();
		}
		
		if (freq_flag)
		{
			freq_flag = 0;
			freq_proc();
		}
		
		if (key_flag)
		{
			key_flag = 0;
			key_proc();
		}
		
		if (ds1302_flag)
		{
			ds1302_flag = 0;
			ds1302_proc();
		}

		if (led_flag)
		{
			led_flag = 0;
			led_proc();
			led_display();
		}
		
			
	}
}


void timer_1_1ms(void) interrupt 3
{
	static uint i;
	i = (i + 1);

	if (i >= 30000)
	{
		i = 0;
	}

	//led_display();

	if (i % LED_TIME == 0)
	{
		led_flag = 1;
	}

	if (i % SEG_TIME == 0)
	{
		seg_display();
		seg_flag = 1;
	}

	if (i % 1000 == 0)
	{
		freq_flag = 1;
	}

	if (i % KEY_TIME == 0)
	{
		key_flag = 1;
	}

	if (i % DATE_TIME == 0)
	{
		ds1302_flag = 1;
	}

	if (i % 200 == 0)
	{
		if (shan_flag == 1)
			shan_flag = 0;
		else
			shan_flag = 1;
	}
}

void timer_0_ne555(void) interrupt 1
{
	freq_low++;
	if (freq_low == 30000)
	{
		freq_low = 0;
		freq_high++;
	}

}

void freq_proc(void)
{
	freq = 0;
	freq = (freq_high * 30000 + freq_low);

	// 如果校准值为负数
	if (freq_xiaozhun < 0)
	{
		// 如果校准值比频率高
		if (freq < (-freq_xiaozhun* 100))
		{
			freq_fushu = 1;
		}
		else 
		{
			freq_fushu = 0;
		}
	}
	// 正数
	else
	{
		freq_fushu = 0;
	}

	if (freq_fushu == 0)
	{
		freq = freq + (freq_xiaozhun* 100);
	}

	freq_high = 0;
	freq_low = 0;

	if (freq > freq_max)
	{
		freq_max = freq;
		max_time[0] = time[0];
		max_time[1] = time[1];
		max_time[2] = time[2];
	}

	DAC_proc();
}

void ds1302_proc(void)
{
	read_datetime(time);	
}

void key_proc(void)
{
	uchar press;
	press = key_scan();

	switch (press)
	{
		case 4:
		{
			state = (state + 1) % 4;
		}
		break;

		case 5:
		{
			if (state == 1)
			{
				state_1++;
				if (state_1 == 3)
				{
					state_1 = 1;
				}	
			}
			else if (state == 3)
			{
				state_3++;
				if (state_3 == 2)
				{
					state_3 = 0;
				}
			}
		}
		break;

		case 8:
		{
			if (state == 1)
			{
				if (state_1 == 1)
				{
					freq_out++;
					if (freq_out == 10)
					{
						freq_out = 9;
					}
				}
				else if (state_1 == 2)
				{
					freq_xiaozhun++;
					if (freq_xiaozhun == 10)
					{
						freq_xiaozhun = 9;
					}
				}
			}
		}
		break;

		case 9:
		{
			if (state == 1)
			{
				if (state_1 == 1)
				{
					freq_out--;
					if (freq_out == 0)
					{
						freq_out = 1;
					}
				}
				else if (state_1 == 2)
				{
					freq_xiaozhun--;
					if (freq_xiaozhun == -10)
					{
						freq_xiaozhun = -9;
					}
				}
			}
		}
		break;
	}
}


void state_proc(void)
{
	uchar freq_array[5] = {0, 0, 0, 0, 0};
	uchar xiaozhun_array[3] = {0, 0, 0};
	uchar max_array[5] = {0, 0, 0, 0, 0};
	switch (state)
	{
	 	case 0:
		{
			
			if (freq_fushu == 1)
			{
				freq_array[0] = 16;
				freq_array[1] = 16;
				freq_array[2] = 16;
				freq_array[3] = 21;
				freq_array[4] = 21;
			}
			else if (freq_fushu == 0)
			{
			    freq_array[0] = freq / 10000 % 10;
				freq_array[1] = freq / 1000 % 10;
				freq_array[2] = freq / 100 % 10;
				freq_array[3] = freq / 10 % 10;
				freq_array[4] = freq % 10;
	
				delete_0(freq_array, 4);
			}
			

			set_seg(15, 16, 16, freq_array[0], freq_array[1], freq_array[2], freq_array[3], freq_array[4]);	
		}
		break;

		case 1:
		{
			// 参数界面 超限参数 
			if (state_1 == 1)
			{
				xiaozhun_array[0] = freq_out;
				xiaozhun_array[1] = 0;
				xiaozhun_array[2] = 0;
			}

			else if (state_1 == 2)
			{
				if (freq_xiaozhun < 0)
				{
					
					xiaozhun_array[0] = 17;
					xiaozhun_array[1] = -freq_xiaozhun;
					xiaozhun_array[2] = 0;
				}
				else if (freq_xiaozhun > 0)
				{
					xiaozhun_array[0] = 16;
					xiaozhun_array[1] = freq_xiaozhun;
					xiaozhun_array[2] = 0;	
				}
				else
				{
					xiaozhun_array[0] = 16;
					xiaozhun_array[1] = 16;
					xiaozhun_array[2] = 16;
				}
			}

			set_seg(24, state_1, 16, 16, xiaozhun_array[0], xiaozhun_array[1], xiaozhun_array[2], 0);
			
		}
		break;

		case 2:
		{
			set_seg(time[2] / 10, time[2] % 10, 17, 
					time[1] / 10, time[1] % 10, 17,
					time[0] / 10, time[0] % 10
					);
		}
		break;

		case 3:
		{
			if (state_3 == 0)
			{
				max_array[0] = freq_max / 10000 % 10;
				max_array[1] = freq_max / 1000 % 10;
				max_array[2] = freq_max / 100 % 10;
				max_array[3] = freq_max / 10 % 10;
				max_array[4] = freq_max % 10;

				delete_0(max_array, 4);
				set_seg(18, 15, 16, max_array[0], max_array[1],  max_array[2], max_array[3], max_array[4]);
			}
			else if(state_3 == 1)
			{
				set_seg(18, 43, 
				max_time[2] / 10, max_time[2] % 10, 
				max_time[1] / 10, max_time[1] % 10, 
				max_time[0] / 10, max_time[0] % 10
				);			
			}
		}
		break;
	}
}


void delete_0(uchar *arr, uchar j)
{
	// j 为数组个数 
	uchar i;
	for (i = 0;i < j;i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = 16;
		}
		else
		{
			break;
		}
	}
}

void DAC_proc(void)
{
	uchar value;
	if (freq_fushu)
	{
		value = 1;
	}
	else if (freq < 500)
	{
		value = 1;
	}
	else if (500 <= freq && freq < (freq_out*1000))
	{
		value = ( (freq_out - 500) / 4) * freq;
	}
	else if (freq > (freq_out* 1000))
	{
		value = 5;	
	}

	DAC(value);
}

void led_proc(void)
{	
	//led_display();
	if (state == 0)
	{
		led_value[0] = shan_flag;
	}
	else
	{
		led_value[0] = 0;
	}

	if (freq_fushu)
	{
		led_value[1] = 1;
	}
	else if (freq > freq_out*1000)
	{
		led_value[1] = shan_flag;
	}
	else
	{
		led_value[1] = 0;
	}
	// 此处会影响显示
	//led_display();
}
