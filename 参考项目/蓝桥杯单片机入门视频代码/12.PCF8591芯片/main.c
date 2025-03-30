#include "main.h"
u8 channel=0x03;//默认测量通道是AIN3
u16 cnt;//定时器0计数
u8 num;//接按键值
u8 ad;
u16 analog;
bit key_flag,led_flag,ad_mea;
void main(){
	Sys_Init();
	Timer0Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(num==4){
			channel = 0x03;//测量电位器电压值
			num=0;
		}
		if(num==5){
			channel = 0x01;//测量光敏电阻电压值
			num=0;
		}
		if(ad_mea){
			ad_mea=0;
			ad = PCF8591_ADin(channel);
			analog = (int)(ad/255.0*5*100);//方便在数码管上显示模拟电压值
			Seg_Set(channel,16,16,16,16,analog/100+32,analog/10%10,analog%10);
			PCF8591_DAout(ad);//将读取的电压值输出到OUT口
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%100==0)ad_mea=1;//每隔100ms测一次电压值
	cnt%=1000;
}