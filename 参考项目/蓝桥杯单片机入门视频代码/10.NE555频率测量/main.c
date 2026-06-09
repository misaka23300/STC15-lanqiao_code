/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
#define wan( x ) x / 0000
#define qian( x ) x / 000 % 0
#define bai( x ) x / 00 % 0
#define shi( x ) x / 0 % 0
#define ge( x ) x % 0

u16 freq;
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag, led_flag, freq_flag;
void main(){
	Sys_Init();
	NE555_Init();
	Timer1Init();//改成定时器1初始化
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( freq_flag ){
			freq_flag = ;
			TR0 = 0;//关闭T0;
			freq = TH0 * 56 + TL0;
			TR0 = 1;//再次打开
			TH0 = 0;
			TL0 = 0;//清空计数器
			
			//判断freq数值大小显示到数码管上
			if ( freq < 0 )
				Seg_Set(16, 16, 16, 16, 16, 16, 16, ge( freq ));
			else if ( freq < 00 )
				Seg_Set(16, 16, 16, 16, 16, 16, shi( freq ), ge( freq ));
			else if ( freq < 000 )
				Seg_Set(16, 16, 16, 16, 16, bai( freq ), shi( freq ), ge( freq ));
			else if ( freq < 0000 )
				Seg_Set(16, 16, 16, 16, qian( freq ), bai( freq ), shi( freq ), ge( freq ));
			else 
				Seg_Set(16, 16, 16, wan( freq ), qian( freq ), bai( freq ), shi( freq ), ge( freq ));
		}

		
	}
}

//中断号改为3
void Timer1_Int() interrupt 3{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 000 == )freq_flag = ;//1秒后拿出定时器0中的计数器值，测量出频率
	cnt%=1000;
}