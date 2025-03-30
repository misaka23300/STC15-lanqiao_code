#include "main.h"

u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag,led_flag;
void main(){
	Sys_Init();
	Timer0Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(num){
			
			Seg_Set(num,16,16,16,16,16,16,16);
			num=0;
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	cnt%=1000;
}