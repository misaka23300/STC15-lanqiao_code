#include "main.h"

#define c_hour clk[0]
#define c_min clk[1]
#define c_sec clk[2]


u8 hour,sec,min;
u8 n,num,mode=1;
char temp[3];
u8 T,flag,cnt;
u16 cnt1;
u8 cc,uLed=0xff;
char clk[3]={0,0,0};
u8 index;
bit key_flag,led_flag,time_flag,tmp_flag;


void Time_Show();
void Time_Set();
void Clock_Set();
void led_show();
void Tmp_Show();

void main(){
	Sys_Init();
	T = rd_temperature();
	Delay(800);
	T = rd_temperature();
	DS1302_Settime(23,59,50);
	Timer0Init();
	while(1){
		

		if(key_flag){
			key_flag=0;
			num = Key_Scan();
		}

		switch(mode){
			case 1:Time_Show();break;
			case 2:Time_Set();break;
			case 3:Clock_Set();break;
			case 4:Tmp_Show();break;
		}
		
		//读DS1302也需要减速
		if(time_flag){
			time_flag=0;
			hour = Read_Ds1302_Byte(0x85);
			min = Read_Ds1302_Byte(0x83);
			sec = Read_Ds1302_Byte(0x81);//秒读做定时器
			if((hour/16*10+hour%16)==clk[0]){
				if((min/16*10+min%16)==clk[1]){
					if((sec/16*10+sec%16)==clk[2]){
						flag=1;
					}
				}
			}	
		}
		
		
		if(flag==1){
			if(num){
				flag=0;
				num=0;
				ET0=0;
				uLed=0xff;
				P0 =0xff;
				P0 = uLed;Y4;Y0;
				ET0=1;
				cc=0;
			}
			if(led_flag){
				led_show();
				led_flag=0;	
			}
		}

	}
}

void Time_Show(){
	if(num==7&&flag==0){
		mode=2;
		temp[0]=hour/16*10+hour%16;
		temp[1]=min/16*10+min%16;
		temp[2]=sec/16*10+sec%16;
		num=0;
	}
	if(num==6&&flag==0){
		mode=3;
		num=0;
		index=0;
	}

	Seg_Set(hour/16,hour%16,17,min/16,min%16,17,sec/16,sec%16);
}

void Time_Set(){
	if(num==7&&flag==0){
		index++;
		if(index==3){
			ET0=0;
			DS1302_Settime(temp[0],temp[1],temp[2]);
			ET0=1;
			index=0;
			mode=1;
		}
		num=0;
	}
	if(num==5&&flag==0){
		temp[index]++;
		switch(index){
			case 0:if(temp[index]>23)temp[index]=0;break;
			case 1:if(temp[index]>59)temp[index]=0;break;
			case 2:if(temp[index]>59)temp[index]=0;break;
		}
		num=0;
	}
	if(num==4&&flag==0){
		temp[index]--;
		switch(index){
			case 0:if(temp[index]<0)temp[index]=23;break;
			case 1:if(temp[index]<0)temp[index]=59;break;
			case 2:if(temp[index]<0)temp[index]=59;break;
		}
		num=0;
	}	
	
	
	
	if(sec%16%2){
		Seg_Set(temp[0]/10,temp[0]%10,17,temp[1]/10,temp[1]%10,17,temp[2]/10,temp[2]%10);

	}else if(sec%16%2==0){
		switch(index){
			case 0:Seg_Set(16,16,17,temp[1]/10,temp[1]%10,17,temp[2]/10,temp[2]%10);break;
			case 1:Seg_Set(temp[0]/10,temp[0]%10,17,16,16,17,temp[2]/10,temp[2]%10);break;
			case 2:Seg_Set(temp[0]/10,temp[0]%10,17,temp[1]/10,temp[1]%10,17,16,16);break;
		}
	}
}


void Clock_Set(){
	if(num==6&&flag==0){
		index++;
		if(index==3){
			index=0;
			mode=1;
		}
		num=0;
	}
	if(num==5&&flag==0){
		clk[index]++;
		switch(index){
			case 0:if(clk[index]>23)clk[index]=0;break;
			case 1:if(clk[index]>59)clk[index]=0;break;
			case 2:if(clk[index]>59)clk[index]=0;break;
		}
		num=0;
	}
	if(num==4&&flag==0){
		clk[index]--;
		switch(index){
			case 0:if(clk[index]<0)clk[index]=23;break;
			case 1:if(clk[index]<0)clk[index]=59;break;
			case 2:if(clk[index]<0)clk[index]=59;break;
		}
		num=0;
	}	
	
	
	
	if(sec%16%2){
		Seg_Set(clk[0]/10,clk[0]%10,17,clk[1]/10,clk[1]%10,17,clk[2]/10,clk[2]%10);

	}else if(sec%16%2==0){
		switch(index){
			case 0:Seg_Set(16,16,17,clk[1]/10,clk[1]%10,17,clk[2]/10,clk[2]%10);break;
			case 1:Seg_Set(clk[0]/10,clk[0]%10,17,16,16,17,clk[2]/10,clk[2]%10);break;
			case 2:Seg_Set(clk[0]/10,clk[0]%10,17,clk[1]/10,clk[1]%10,17,16,16);break;
		}
	}
}

void led_show(){
	
	ET0=0;
	if(cc%2)
	uLed = 0xff;
	else 
	uLed = 0xfe;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	
	ET0=1;
	cc++;
	if(cc>=25){
		flag=0;
		ET0=0;
		uLed=0xff;
		P0 =0xff;
		P0 = uLed;Y4;Y0;
		ET0=1;
		cc=0;
	}
	
}

void Tmp_Show(){
	if(tmp_flag){
		tmp_flag=0;
		T = rd_temperature();
	}
	Seg_Set(16,16,16,16,16,T/10,T%10,12);
}

void TIMER0_INT() interrupt 1{
	
	Seg_Show();
	n++;
	if(mode==4){
		cnt1++;
		if(cnt1>=500){
			cnt1=0;
			tmp_flag=1;
		}
	}
	if(flag){
		cnt++;
		if(cnt>=200){
			led_flag=1;
			cnt=0;
			
		}
		
	}
	if(n>=10){
		key_flag=1;
		time_flag=1;
		n=0;
	}
}