/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"

u16 cnt;//¶¨Ê±Æ÷0¼ÆÊı
u8 num;//½Ó°´¼üÖµ
bit key_flag, led_flag;
void main(){
	Sys_Init();
	Timer0Init();
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( num ){
			
			Seg_Set( num, 16, 16, 16, 16, 16, 16, 16 );
			num = ;
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	cnt%=1000;
}