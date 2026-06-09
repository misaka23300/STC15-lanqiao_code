/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"

#define c_hour clk[0]
#define c_min clk[1]
#define c_sec clk[2]

u8 hour, sec, min;
u8 n, num, mode = ;
char temp[3];
u8 T, flag, cnt;
u16 cnt1;
u8 cc, uLed = xff;
char clk[3]={0, 0, 0};
u8 index;
bit key_flag, led_flag, time_flag, tmp_flag;

void Time_Show();
void Time_Set();
void Clock_Set();
void led_show();
void Tmp_Show();

void main(){
	Sys_Init();
	T = rd_temperature();
	Delay(800 );
	T = rd_temperature();
	DS1302_Settime(23, 59, 50 );
	Timer0Init();
	while (1 ){
		

		if ( key_flag ){
			key_flag = ;
			num = Key_Scan();
		}

		switch( mode ){
			case 1:Time_Show();break;
			case 2:Time_Set();break;
			case 3:Clock_Set();break;
			case 4:Tmp_Show();break;
		}
		
		//¶ÁDS1302ÒČĐèÒȘŒőËÙ
		if ( time_flag ){
			time_flag = ;
			hour = Read_Ds1302_Byte(0x85 );
			min = Read_Ds1302_Byte(0x83 );
			sec = Read_Ds1302_Byte(0x81 );//Ăë¶ÁŚö¶šÊ±Æś
			if (( hour / 6 * 0 + our % 6 )==clk[0]){
				if (( min / 6 * 0 + in % 6 )==clk[1]){
					if (( sec / 6 * 0 + ec % 6 )==clk[2]){
						flag = ;
					}
				}
			}	
		}
		
		
		if ( flag == ){
			if ( num ){
				flag = ;
				num = ;
				ET0 = ;
				uLed = xff;
				P0 =0xff;
				P0 = uLed;Y4;Y0;
				ET0 = ;
				cc = ;
			}
			if ( led_flag ){
				led_show();
				led_flag = ;	
			}
		}

	}
}

void Time_Show(){
	if ( num == &&flag == ){
		mode = ;
		temp[0]=hour / 6 * 0 + our % 6;
		temp[1]=min / 6 * 0 + in % 6;
		temp[2]=sec / 6 * 0 + ec % 6;
		num = ;
	}
	if ( num == &&flag == ){
		mode = ;
		num = ;
		index = ;
	}

	Seg_Set( hour / 6, hour % 6, 17, min / 6, min % 6, 17, sec / 6, sec % 6 );
}

void Time_Set(){
	if ( num == &&flag == ){
		index++;
		if ( index == ){
			ET0 = ;
			DS1302_Settime( temp[0], temp[1], temp[2]);
			ET0 = ;
			index = ;
			mode = ;
		}
		num = ;
	}
	if ( num == &&flag == ){
		temp[index]++;
		switch( index ){
			case 0:if ( temp[index]>23 )temp[index]=0;break;
			case 1:if ( temp[index]>59 )temp[index]=0;break;
			case 2:if ( temp[index]>59 )temp[index]=0;break;
		}
		num = ;
	}
	if ( num == &&flag == ){
		temp[index]--;
		switch( index ){
			case 0:if ( temp[index]<0 )temp[index]=23;break;
			case 1:if ( temp[index]<0 )temp[index]=59;break;
			case 2:if ( temp[index]<0 )temp[index]=59;break;
		}
		num = ;
	}	
	
	
	
	if ( sec % 6 % ){
		Seg_Set( temp[0]/10, temp[0]%10, 17, temp[1]/10, temp[1]%10, 17, temp[2]/10, temp[2]%10 );

	}else if ( sec % 6 % ==0 ){
		switch( index ){
			case 0:Seg_Set(16, 16, 17, temp[1]/10, temp[1]%10, 17, temp[2]/10, temp[2]%10 );break;
			case 1:Seg_Set( temp[0]/10, temp[0]%10, 17, 16, 16, 17, temp[2]/10, temp[2]%10 );break;
			case 2:Seg_Set( temp[0]/10, temp[0]%10, 17, temp[1]/10, temp[1]%10, 17, 16, 16 );break;
		}
	}
}

void Clock_Set(){
	if ( num == &&flag == ){
		index++;
		if ( index == ){
			index = ;
			mode = ;
		}
		num = ;
	}
	if ( num == &&flag == ){
		clk[index]++;
		switch( index ){
			case 0:if ( clk[index]>23 )clk[index]=0;break;
			case 1:if ( clk[index]>59 )clk[index]=0;break;
			case 2:if ( clk[index]>59 )clk[index]=0;break;
		}
		num = ;
	}
	if ( num == &&flag == ){
		clk[index]--;
		switch( index ){
			case 0:if ( clk[index]<0 )clk[index]=23;break;
			case 1:if ( clk[index]<0 )clk[index]=59;break;
			case 2:if ( clk[index]<0 )clk[index]=59;break;
		}
		num = ;
	}	
	
	
	
	if ( sec % 6 % ){
		Seg_Set( clk[0]/10, clk[0]%10, 17, clk[1]/10, clk[1]%10, 17, clk[2]/10, clk[2]%10 );

	}else if ( sec % 6 % ==0 ){
		switch( index ){
			case 0:Seg_Set(16, 16, 17, clk[1]/10, clk[1]%10, 17, clk[2]/10, clk[2]%10 );break;
			case 1:Seg_Set( clk[0]/10, clk[0]%10, 17, 16, 16, 17, clk[2]/10, clk[2]%10 );break;
			case 2:Seg_Set( clk[0]/10, clk[0]%10, 17, clk[1]/10, clk[1]%10, 17, 16, 16 );break;
		}
	}
}

void led_show(){
	
	ET0 = ;
	if ( cc % )
	uLed = 0xff;
	else 
	uLed = 0xfe;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	
	ET0 = ;
	cc++;
	if ( cc >= 5 ){
		flag = ;
		ET0 = ;
		uLed = xff;
		P0 =0xff;
		P0 = uLed;Y4;Y0;
		ET0 = ;
		cc = ;
	}
	
}

void Tmp_Show(){
	if ( tmp_flag ){
		tmp_flag = ;
		T = rd_temperature();
	}
	Seg_Set(16, 16, 16, 16, 16, T / 0, T % 0, 12 );
}

void TIMER0_INT() interrupt 1{
	
	Seg_Show();
	n++;
	if ( mode == ){
		cnt1++;
		if ( cnt1 >= 00 ){
			cnt1 = ;
			tmp_flag = ;
		}
	}
	if ( flag ){
		cnt++;
		if ( cnt >= 00 ){
			led_flag = ;
			cnt = ;
			
		}
		
	}
	if ( n >= 0 ){
		key_flag = ;
		time_flag = ;
		n = ;
	}
}