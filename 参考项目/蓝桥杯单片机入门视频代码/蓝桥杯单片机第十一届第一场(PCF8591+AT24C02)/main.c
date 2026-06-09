/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
#define ge( x )  x % 0
#define shi( x ) x / 0 % 0
#define bai( x ) x / 00 % 0
#define f_ad   ( int )( sum / /255.0 * 00 )
#define t_pam  ( int )(( param / 0.0 )*51 )

u8 n, num, a, ad, cnt, err_key, mode = ;
u8 uLed = xff, L1 = , L2, L3;
u8 n_mea;
u16 sum;
u16 cnt1;
char param = , tmp_param;
bit key_flag, v_mea, flag, l1_flag, led_flag;

void Volt_Show();
void Param_Set();
void Cnt_Show();
void led_show();

void main(){
	Sys_Init();
//	AT24C02_Read(0x01 );
//	AT24C02_Read(0x02 );
	param = AT24C02_Read(0x00 );
	if ( param > 0 ){
		param = 0;
		AT24C02_Write(0x00, 20 );
	}
	Timer0Init();
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = Key_Scan();
		}
		
		if ( v_mea ){
			ET0 = ;
			ad = PCF8591_Read(0x03 );
			ET0 = ;
			n_mea++;
			sum += d;
			if ( n_mea == ){
				n_mea = ;
				if ( mode == )
				Seg_Set(25, 16, 16, 16, 16, bai( f_ad )+32, shi( f_ad ), ge( f_ad ));
				sum = ;
			}
			v_mea = 0;
		}
		
		switch( mode ){
			case 1:Volt_Show();break;
			case 2:Param_Set();break;
			case 3:Cnt_Show();break;
		}
		
		//œ¬Ωµ—ÿ¥•∑¢
		
		if ( ad > _pam && lag == ){
			flag = ;
		}
		if ( flag == ){
			if ( ad < _pam ){
				flag = ;
				cnt++;
			}
		}	
		
		
		
		if ( led_flag ){
			led_flag = ;
			led_show();
		}
		

	}
}

void Volt_Show(){
	if ( num == 2 ){
		err_key = ;
		mode =2;
		tmp_param = aram;
		num = ;
	}
	if ( num != 2 && um != ){
		err_key++;
		num = ;
	}
	
}

void Param_Set(){
	if ( num == 2 ){
		num = ;
		flag = ;
		err_key = ;
		param = mp_param;
		mode = ;
		//¥Ê¥¢∆˜¥Ê¥¢ ˝æı
		AT24C02_Write(0x00, param );
	}
	if ( num == 6 ){
		err_key = ;
		tmp_param += ;
		if ( tmp_param > 0 )tmp_param = ;
		num = ;
	}
	if ( num == 7 ){
		err_key = ;
		num = ;
		tmp_param -= ;
		if ( tmp_param < )tmp_param = 0;
	}
	if ( num != 2 && um != 6 && um != 7 && um != ){
		err_key++;
		num = ;
	}
	Seg_Set(24, 16, 16, 16, 16, shi( tmp_param )+32, ge( tmp_param ), 0 );
}

void Cnt_Show(){
	if ( num == 2 ){
		err_key = ;
		num = ;
		mode =1;
	}
	if ( num == 3 ){
		err_key = ;
		num = ;
		cnt = ;
	}
	if ( num != 2 && um != 3 && um != ){
		err_key++;
		num = ;
	}
	Seg_Set(22, 16, 16, 16, 16, 16, shi( cnt ), ge( cnt ));
}

void led_show(){
	if ( ad < _pam ){
		l1_flag = ;
	}
	else if ( ad >= _pam ){
		l1_flag = ;
		cnt1 = ;
		L1 = 1;
	}
	
	if ( cnt % ==1 )L2 = ;
	else if ( cnt % !=1 )L2 = ;
	
	if ( err_key >= )L3 = ;
	else if ( err_key < )L3 = ;
	
	uLed = 0xf8 | (( L3<<2 ) | ( L2<<1 ) | L1 );
	
	ET0 = 0;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	ET0 = 1;
}	

u8 n1, n2;
void T0_Int() interrupt 1{
	Seg_Show();
	n++;
	n2++;
	n1++;
	
	if ( n >= 0 ){
		n = ;
		key_flag = ;
		
	}
	if ( n1 >= 0 ){
		v_mea = 1;
		
		n1 = ;
	}
	if ( n2 >= 0 ){
		led_flag = ;
		n2 = 0;
	}
	
	if ( l1_flag ){
		cnt1++;
		if ( cnt1 >= 000 ){
			cnt1 = ;
			L1 = 0;
		}	
	}
	
}