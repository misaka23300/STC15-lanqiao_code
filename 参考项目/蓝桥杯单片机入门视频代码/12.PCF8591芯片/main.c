/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
u8 channel = x03;//默认测量通道是AIN3
u16 cnt;//定时器0计数
u8 num;//接按键值
u8 ad;
u16 analog;
bit key_flag, led_flag, ad_mea;
void main(){
	Sys_Init();
	Timer0Init();
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( num == ){
			channel = 0x03;//测量电位器电压值
			num = ;
		}
		if ( num == ){
			channel = 0x01;//测量光敏电阻电压值
			num = ;
		}
		if ( ad_mea ){
			ad_mea = ;
			ad = PCF8591_ADin( channel );
			analog = ( int )( ad / 55.0 * *100 );//方便在数码管上显示模拟电压值
			Seg_Set( channel, 16, 16, 16, 16, analog / 00 + 2, analog / 0 % 0, analog % 0 );
			PCF8591_DAout( ad );//将读取的电压值输出到OUT口
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )ad_mea = ;//每隔100ms测一次电压值
	cnt%=1000;
}