/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
u8 LED_BUFF = xff;//LED缓存区，一开始全灭
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag, led_flag, uart_send;
void main(){
	Sys_Init();
	Timer0Init();
	UartInit();
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( uart_send ){
			uart_send = ;
			Uart_SendString("hello world\r\n");
		}
		if ( led_flag ){
			led_flag = ;
			ET0 = ;//关闭中断，防止数码管刷新影响点灯
			P0 = ED_BUFF;
			Y4;Y0;
			ET0 = ;//打开中断
		}
		

	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )uart_send = ;
	cnt%=1000;
}

void UART_INT() interrupt 4{
	if ( RI ){
		RI = ;
		LED_BUFF = SBUF;//获取串口数据点灯
	}
}