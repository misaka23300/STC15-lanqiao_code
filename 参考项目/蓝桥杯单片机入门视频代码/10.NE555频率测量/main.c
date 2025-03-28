#include "main.h"
#define wan(x) x/10000
#define qian(x) x/1000%10
#define bai(x) x/100%10
#define shi(x) x/10%10
#define ge(x) x%10

u16 freq;
u16 cnt;//定时器0计数
u8 num;//接按键值
bit key_flag,led_flag,freq_flag;
void main(){
	Sys_Init();
	NE555_Init();
	Timer1Init();//改成定时器1初始化
	
	while(1){
		if(key_flag){
			key_flag=0;
			num=Key_Scan();
		}
		if(freq_flag){
			freq_flag=0;
			TR0 = 0;//关闭T0;
			freq = TH0*256 + TL0;
			TR0 = 1;//再次打开
			TH0 = 0;
			TL0 = 0;//清空计数器
			
			//判断freq数值大小显示到数码管上
			if(freq<10)
				Seg_Set(16,16,16,16,16,16,16,ge(freq));
			else if(freq<100)
				Seg_Set(16,16,16,16,16,16,shi(freq),ge(freq));
			else if(freq<1000)
				Seg_Set(16,16,16,16,16,bai(freq),shi(freq),ge(freq));
			else if(freq<10000)
				Seg_Set(16,16,16,16,qian(freq),bai(freq),shi(freq),ge(freq));
			else 
				Seg_Set(16,16,16,wan(freq),qian(freq),bai(freq),shi(freq),ge(freq));
		}

		
	}
}


//中断号改为3
void Timer1_Int() interrupt 3{
	Seg_Show();
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt%50==0)led_flag=1;
	if(cnt%1000==0)freq_flag=1;//1秒后拿出定时器0中的计数器值，测量出频率
	cnt%=1000;
}