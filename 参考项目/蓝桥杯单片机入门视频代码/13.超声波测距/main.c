#include "main.h"
u8 distance;
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag,led_flag,csb_mea;
void main(){
	Sys_Init();
	Timer0Init();
	csb_timer_init();
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(csb_mea){
			csb_mea=0;
			distance = csb_measure();
			Seg_Set(16,16,16,16,16,distance/100,distance/10%10,distance%10);
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%500==0)csb_mea=1;
	cnt%=1000;
}