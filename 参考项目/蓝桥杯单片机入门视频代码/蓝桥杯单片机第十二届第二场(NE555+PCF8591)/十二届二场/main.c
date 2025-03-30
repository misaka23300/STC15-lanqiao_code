#include "main.h"
#define ge(x) x%10
#define shi(x) x/10%10
#define bai(x) x/100%10
#define qian(x) x/1000%10
#define wan(x) x/10000%10
#define advalue(x) (int)(5.0*x/255*100)

u8 n,num,a,ad,mode=1,ad_mode=3,ad1,ad3,flag;
u16 cnt,freq,T;
u16 f_tmp,v_tmp,cnt1;
u8 L1,L2,L3,L4,L5,uLed=0xff;
bit key_flag,f_mea,v1_mea,v3_mea,led_flag,led_button=1;

void NE555_Init();
void v_show();
void T_show();
void freq_show();
void led_show();


void main(){
	Sys_Init();
	
	NE555_Init();
	Timer1Init();
	
	while(1){
		if(key_flag){
			key_flag=0;
			num = Key_Scan();
		}
		
		//频率全局检测
		if(f_mea){
			f_mea=0;
			TR0 = 0;
			freq=TH0*256+TL0;
			TH0=0;
			TL0=0;
			TR0=1;
			if(mode==2)
			T = (int)(1.0/freq*1000*1000);
		}
		if(v1_mea&&ad_mode==1){
			v1_mea=0;
			ET1=0;
			ad1 = PCF8591_ReadAD(0x01);//光敏
			ET1=1;
		}
		if(v3_mea&&ad_mode==3){
			v3_mea=0;
			ET1=0;
			ad3 = PCF8591_ReadAD(0x03);//光敏
			ET1=1;
		}
		
		if(num==6)//缓存电压
		{
			num=0;
			v_tmp = advalue(ad3);
		}	
		
		if(num==7)flag=1;
		if(flag==0){
			if(cnt1>20&&cnt1<1000){
				f_tmp = freq;
				cnt1=0;
			}
		}
		
		switch(mode){
			case 1:freq_show();break;
			case 2:T_show();break;
			case 3:v_show();break;
		}
		
		if(led_button){
			if(led_flag)
			led_show();
		}
		
		
	}
}

void NE555_Init(){
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD = 0x05;		//设置定时器模式
	TL0 = 0;		//设置定时初值
	TH0 = 0;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}

void freq_show(){
	if(num==4){
		num=0;
		mode=2;
	}
	if(freq<100)
		Seg_Set(15,16,16,16,16,16,shi(freq),ge(freq));	
	else if(freq<1000)
		Seg_Set(15,16,16,16,16,bai(freq),shi(freq),ge(freq));
	else if(freq<10000)
		Seg_Set(15,16,16,16,qian(freq),bai(freq),shi(freq),ge(freq));
	else 
		Seg_Set(15,16,16,wan(freq),qian(freq),bai(freq),shi(freq),ge(freq));

}

void T_show(){
	if(num==4){
		num=0;
		mode=3;
		ad_mode=1;//默认进入读光敏电阻
	}
	if(T<100)
		Seg_Set(22,16,16,16,16,16,shi(T),ge(T));	
	else if(T<1000)
		Seg_Set(22,16,16,16,16,bai(T),shi(T),ge(T));
	else if(T<10000)
		Seg_Set(22,16,16,16,qian(T),bai(T),shi(T),ge(T));
	else 
		Seg_Set(22,16,16,wan(T),qian(T),bai(T),shi(T),ge(T));
}

void v_show(){
	if(num==4){
		num=0;
		mode=1;
	}
	if(num==5){
		num=0;
		if(ad_mode==1)ad_mode=3;
		else if(ad_mode==3)ad_mode=1;
	}
	if(ad_mode==1)
		Seg_Set(25,17,1,16,16,bai(advalue(ad1))+32,shi(advalue(ad1)),ge(advalue(ad1)));
	else 
		Seg_Set(25,17,3,16,16,bai(advalue(ad3))+32,shi(advalue(ad3)),ge(advalue(ad3)));
		
}

void led_show(){
	if(advalue(ad3)>v_tmp)L1=0;
	else L1=1;
	
	if(freq>f_tmp)L2=0;
	else L2=1;
	
	if(mode==1)L3=0;
	else if(mode!=1)L3=1;
	
	if(mode==2)L4=0;
	else if(mode!=2)L4=1;
	
	if(mode==3)L5=0;
	else if(mode!=3)L5=1;
	
	uLed = 0xe0 | ((L5<<4) | (L4<<3) | (L3<<2) | (L2<<1) | L1);
	
	EA = 0;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	EA = 1;
}

void T1_Int() interrupt 3{
	Seg_Show();
	cnt++;
	if(cnt%20==0){key_flag=1;led_flag=1;}
	if(cnt%200==0)v3_mea=1;
	if(cnt%250==0)v1_mea=1;
	if(cnt%1000==0)f_mea=1;

	cnt%=1000;
	if(flag==1){
		cnt1++;
		if(cnt1>=1000){
			cnt1=0;
			flag=3;
			if(led_button)led_button=0;
			else if(led_button==0)led_button=1;
			if(led_button==0){
				P0 = 0xff;
				uLed=0xff;
				P0 = uLed;
				Y4;Y0;
			}
		}
	}
}

