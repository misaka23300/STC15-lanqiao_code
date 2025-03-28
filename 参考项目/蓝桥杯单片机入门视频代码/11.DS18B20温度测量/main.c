#include "main.h"
float T;//温度值
int real_T;//方便显示
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag,led_flag,tmp_mea;
void main(){
	Sys_Init();
	Timer0Init();
	//解决上电显示85℃的问题
	T = rd_temperature();//先读一次
	Delay(1000);//延时1s就可解决
	
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(tmp_mea){
			tmp_mea=0;
			
			ET0=0;//关闭中断，防止影响时序
			T = rd_temperature();//获取温度值
			ET0=1;//读取结束，开启中断
			
			real_T=(int)(T*100);//获取小数点后两位
			if(real_T<0){
				real_T=-real_T;
				Seg_Set(16,16,16,17,real_T/1000,real_T/100%10+32,real_T/10%10,real_T%10);
			}
			else 
				Seg_Set(16,16,16,16,real_T/1000,real_T/100%10+32,real_T/10%10,real_T%10);
				
		}
		
	}
}

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%500==0)tmp_mea=1;//每隔500ms测一次温度
	cnt%=1000;
}