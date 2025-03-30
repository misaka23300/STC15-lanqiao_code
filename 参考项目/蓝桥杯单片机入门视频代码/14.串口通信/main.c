#include "main.h"
u8 LED_BUFF=0xff;//LED缓存区，一开始全灭
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag,led_flag,uart_send;
void main(){
	Sys_Init();
	Timer0Init();
	UartInit();
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(uart_send){
			uart_send=0;
			Uart_SendString("hello world\r\n");
		}
		if(led_flag){
			led_flag=0;
			ET0=0;//关闭中断，防止数码管刷新影响点灯
			P0=LED_BUFF;
			Y4;Y0;
			ET0=1;//打开中断
		}
		

	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%200==0)uart_send=1;
	cnt%=1000;
}

void UART_INT() interrupt 4{
	if(RI){
		RI=0;
		LED_BUFF = SBUF;//获取串口数据点灯
	}
}