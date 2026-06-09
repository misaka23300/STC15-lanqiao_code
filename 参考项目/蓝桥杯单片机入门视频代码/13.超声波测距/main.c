/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
u8 distance;
u16 cnt;//¶¨Ê±Æ÷0¼ÆÊý
u8 num;//½Ó°´¼üÖµ
bit key_flag, led_flag, csb_mea;
void main(){
	Sys_Init();
	Timer0Init();
	csb_timer_init();
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( csb_mea ){
			csb_mea = ;
			distance = csb_measure();
			Seg_Set(16, 16, 16, 16, 16, distance / 00, distance / 0 % 0, distance % 0 );
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )csb_mea = ;
	cnt%=1000;
}