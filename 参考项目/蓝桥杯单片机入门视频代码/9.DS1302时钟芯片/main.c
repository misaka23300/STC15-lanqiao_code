#include "main.h"
#define s(x) x/10
#define g(x) x%10

u8 t;//计时秒
u16 cnt;//定时器0计数
u8 num;//接按键值
u8 nian,yue,ri,zhou,shi,fen,miao;
bit key_flag,led_flag,read_flag;
void main(){
	Sys_Init();
	Ds1302_Settime(0x23,0x01,0x12,0x04,0x23,0x59,0x50);
	Timer0Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(read_flag){
			read_flag=0;
			nian = Ds1302_Readtime(0x8d);
			zhou = Ds1302_Readtime(0x8b);
			yue = Ds1302_Readtime(0x89);
			ri = Ds1302_Readtime(0x87);
			shi = Ds1302_Readtime(0x85);
			fen = Ds1302_Readtime(0x83);
			miao = Ds1302_Readtime(0x81);
			if(t<2)
				Seg_Set(2,0,s(nian),g(nian)+32,g(yue)+32,s(ri),g(ri)+32,16);
			else if(t<4)
				Seg_Set(16,16,16,16,16,16,17,g(zhou));
			else 
				Seg_Set(s(shi),g(shi),17,s(fen),g(fen),17,s(miao),g(miao));
		}

		
	}
}			


void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%100==0)read_flag=1;//100ms读一次DS1302时钟数据
	if(cnt%1000==0){
		t++;
		t%=8;
	}
	cnt%=1000;
}