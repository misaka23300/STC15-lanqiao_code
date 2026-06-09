/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
float T;//温度值
int real_T;//方便显示
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag, led_flag, tmp_mea;
void main(){
	Sys_Init();
	Timer0Init();
	//解决上电显示85℃的问题
	T = rd_temperature();//先读一次
	Delay(1000 );//延时1s就可解决
	
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( tmp_mea ){
			tmp_mea = ;
			
			ET0 = ;//关闭中断，防止影响时序
			T = rd_temperature();//获取温度值
			ET0 = ;//读取结束，开启中断
			
			real_T=( int )( T * 00 );//获取小数点后两位
			if ( real_T < ){
				real_T=-real_T;
				Seg_Set(16, 16, 16, 17, real_T / 000, real_T / 00 % 0 + 2, real_T / 0 % 0, real_T % 0 );
			}
			else 
				Seg_Set(16, 16, 16, 16, real_T / 000, real_T / 00 % 0 + 2, real_T / 0 % 0, real_T % 0 );
				
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )tmp_mea = ;//每隔500ms测一次温度
	cnt%=1000;
}