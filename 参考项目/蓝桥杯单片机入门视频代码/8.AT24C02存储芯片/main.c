/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"

u16 cnt;//定时器0计数
u8 num;//接按键值
u8 at_read;//AT24C02的读取数据值
bit key_flag, led_flag, read_flag;
void main(){
	at_read = AT24C02_Read(0x00 );
	Sys_Init();
	Timer0Init();
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( read_flag ){
			read_flag = ;
			at_read = T24C02_Read(0x00 );//读取0地址的数据
		}
		if ( num ){
			AT24C02_Write(0x00, num );//将按键值写入AT24C02
			num = ;
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )Seg_Set( at_read, 16, 16, 16, 16, 16, 16, 16 );
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )read_flag = ;//100ms读一次AT24C02
	cnt%=1000;
}