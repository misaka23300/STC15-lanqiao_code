#include "main.h"
#define ge(x)  x%10
#define shi(x) x/10%10
#define bai(x) x/100%10
#define f_ad   (int)(sum/5/255.0*500)
#define t_pam  (int)((param/10.0)*51)

u8 n,num,a,ad,cnt,err_key,mode=1;
u8 uLed=0xff,L1=1,L2,L3;
u8 n_mea;
u16 sum;
u16 cnt1;
char param=0,tmp_param;
bit key_flag,v_mea,flag,l1_flag,led_flag;

void Volt_Show();
void Param_Set();
void Cnt_Show();
void led_show();

void main(){
	Sys_Init();
//	AT24C02_Read(0x01);
//	AT24C02_Read(0x02);
	param = AT24C02_Read(0x00);
	if(param>50){
		param=20;
		AT24C02_Write(0x00,20);
	}
	Timer0Init();
	while(1){
		if(key_flag){
			key_flag=0;
			num = Key_Scan();
		}
		
		if(v_mea){
			ET0=0;
			ad = PCF8591_Read(0x03);
			ET0=1;
			n_mea++;
			sum+=ad;
			if(n_mea==5){
				n_mea=0;
				if(mode==1)
				Seg_Set(25,16,16,16,16,bai(f_ad)+32,shi(f_ad),ge(f_ad));
				sum=0;
			}
			v_mea = 0;
		}
		
		switch(mode){
			case 1:Volt_Show();break;
			case 2:Param_Set();break;
			case 3:Cnt_Show();break;
		}
		
		//ÏÂ½µÑØ´¥·¢
		
		if(ad>t_pam&&flag==0){
			flag=1;
		}
		if(flag==1){
			if(ad<t_pam){
				flag=0;
				cnt++;
			}
		}	
		
		
		
		if(led_flag){
			led_flag=0;
			led_show();
		}
		

	}
}

void Volt_Show(){
	if(num==12){
		err_key=0;
		mode =2;
		tmp_param=param;
		num=0;
	}
	if(num!=12&&num!=0){
		err_key++;
		num=0;
	}
	
}

void Param_Set(){
	if(num==12){
		num=0;
		flag=0;
		err_key=0;
		param=tmp_param;
		mode=3;
		//´æ´¢Æ÷´æ´¢Êı¾İ
		AT24C02_Write(0x00,param);
	}
	if(num==16){
		err_key=0;
		tmp_param+=5;
		if(tmp_param>50)tmp_param=0;
		num=0;
	}
	if(num==17){
		err_key=0;
		num=0;
		tmp_param-=5;
		if(tmp_param<0)tmp_param=50;
	}
	if(num!=12&&num!=16&&num!=17&&num!=0){
		err_key++;
		num=0;
	}
	Seg_Set(24,16,16,16,16,shi(tmp_param)+32,ge(tmp_param),0);
}

void Cnt_Show(){
	if(num==12){
		err_key=0;
		num=0;
		mode =1;
	}
	if(num==13){
		err_key=0;
		num=0;
		cnt=0;
	}
	if(num!=12&&num!=13&&num!=0){
		err_key++;
		num=0;
	}
	Seg_Set(22,16,16,16,16,16,shi(cnt),ge(cnt));
}

void led_show(){
	if(ad<t_pam){
		l1_flag=1;
	}
	else if(ad>=t_pam){
		l1_flag=0;
		cnt1=0;
		L1 = 1;
	}
	
	if(cnt%2==1)L2=0;
	else if(cnt%2!=1)L2=1;
	
	if(err_key>=3)L3=0;
	else if(err_key<3)L3=1;
	
	uLed = 0xf8 | ((L3<<2) | (L2<<1) | L1);
	
	ET0 = 0;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	ET0 = 1;
}	

u8 n1,n2;
void T0_Int() interrupt 1{
	Seg_Show();
	n++;
	n2++;
	n1++;
	
	if(n>=10){
		n=0;
		key_flag=1;
		
	}
	if(n1>=20){
		v_mea = 1;
		
		n1=0;
	}
	if(n2>=20){
		led_flag=1;
		n2 = 0;
	}
	
	if(l1_flag){
		cnt1++;
		if(cnt1>=5000){
			cnt1=0;
			L1 = 0;
		}	
	}
	
}