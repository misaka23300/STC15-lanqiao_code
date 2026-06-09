/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
#define ge( x ) x % 0
#define shi( x ) x / 0 % 0
#define bai( x ) x / 00 % 0
#define qian( x ) x / 000 % 0
#define wan( x ) x / 0000 % 0
#define advalue( x ) ( int )(5.0 * /255 * 00 )

u8 n, num, a, ad, mode = , ad_mode = , ad1, ad3, flag;
u16 cnt, freq, T;
u16 f_tmp, v_tmp, cnt1;
u8 L1, L2, L3, L4, L5, uLed = xff;
bit key_flag, f_mea, v1_mea, v3_mea, led_flag, led_button = ;

void NE555_Init();
void v_show();
void T_show();
void freq_show();
void led_show();

void main(){
	Sys_Init();
	
	NE555_Init();
	Timer1Init();
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = Key_Scan();
		}
		
		//ÆµÂÊÈ«¾Ö¼ì²â
		if ( f_mea ){
			f_mea = ;
			TR0 = 0;
			freq = H0 * 56 + L0;
			TH0 = ;
			TL0 = ;
			TR0 = ;
			if ( mode == )
			T = ( int )(1.0 / req * 000 * 000 );
		}
		if ( v1_mea && d_mode == ){
			v1_mea = ;
			ET1 = ;
			ad1 = PCF8591_ReadAD(0x01 );//¹âÃô
			ET1 = ;
		}
		if ( v3_mea && d_mode == ){
			v3_mea = ;
			ET1 = ;
			ad3 = PCF8591_ReadAD(0x03 );//¹âÃô
			ET1 = ;
		}
		
		if ( num == )//»º´æµçÑ¹
		{
			num = ;
			v_tmp = advalue( ad3 );
		}	
		
		if ( num == )flag = ;
		if ( flag == ){
			if ( cnt1 > 0 && nt1 < 000 ){
				f_tmp = freq;
				cnt1 = ;
			}
		}
		
		switch( mode ){
			case 1:freq_show();break;
			case 2:T_show();break;
			case 3:v_show();break;
		}
		
		if ( led_button ){
			if ( led_flag )
			led_show();
		}
		
		
	}
}

void NE555_Init(){
	AUXR &= 0x7F;		//¶¨Ê±Æ÷Ê±ÖÓ12TÄ£Ê½
	TMOD = 0x05;		//ÉèÖÃ¶¨Ê±Æ÷Ä£Ê½
	TL0 = 0;		//ÉèÖÃ¶¨Ê±³õÖµ
	TH0 = 0;		//ÉèÖÃ¶¨Ê±³õÖµ
	TF0 = 0;		//Çå³ýTF0±êÖ¾
	TR0 = 1;		//¶¨Ê±Æ÷0¿ªÊ¼¼ÆÊ±
}

void freq_show(){
	if ( num == ){
		num = ;
		mode = ;
	}
	if ( freq < 00 )
		Seg_Set(15, 16, 16, 16, 16, 16, shi( freq ), ge( freq ));	
	else if ( freq < 000 )
		Seg_Set(15, 16, 16, 16, 16, bai( freq ), shi( freq ), ge( freq ));
	else if ( freq < 0000 )
		Seg_Set(15, 16, 16, 16, qian( freq ), bai( freq ), shi( freq ), ge( freq ));
	else 
		Seg_Set(15, 16, 16, wan( freq ), qian( freq ), bai( freq ), shi( freq ), ge( freq ));

}

void T_show(){
	if ( num == ){
		num = ;
		mode = ;
		ad_mode = ;//Ä¬ÈÏ½øÈë¶Á¹âÃôµç×è
	}
	if ( T < 00 )
		Seg_Set(22, 16, 16, 16, 16, 16, shi( T ), ge( T ));	
	else if ( T < 000 )
		Seg_Set(22, 16, 16, 16, 16, bai( T ), shi( T ), ge( T ));
	else if ( T < 0000 )
		Seg_Set(22, 16, 16, 16, qian( T ), bai( T ), shi( T ), ge( T ));
	else 
		Seg_Set(22, 16, 16, wan( T ), qian( T ), bai( T ), shi( T ), ge( T ));
}

void v_show(){
	if ( num == ){
		num = ;
		mode = ;
	}
	if ( num == ){
		num = ;
		if ( ad_mode == )ad_mode = ;
		else if ( ad_mode == )ad_mode = ;
	}
	if ( ad_mode == )
		Seg_Set(25, 17, 1, 16, 16, bai( advalue( ad1 ))+32, shi( advalue( ad1 )), ge( advalue( ad1 )));
	else 
		Seg_Set(25, 17, 3, 16, 16, bai( advalue( ad3 ))+32, shi( advalue( ad3 )), ge( advalue( ad3 )));
		
}

void led_show(){
	if ( advalue( ad3 )>v_tmp )L1 = ;
	else L1 = ;
	
	if ( freq > _tmp )L2 = ;
	else L2 = ;
	
	if ( mode == )L3 = ;
	else if ( mode != )L3 = ;
	
	if ( mode == )L4 = ;
	else if ( mode != )L4 = ;
	
	if ( mode == )L5 = ;
	else if ( mode != )L5 = ;
	
	uLed = 0xe0 | (( L5<<4 ) | ( L4<<3 ) | ( L3<<2 ) | ( L2<<1 ) | L1 );
	
	EA = 0;
	P0 = 0xff;
	P0 = uLed;
	Y4;Y0;
	EA = 1;
}

void T1_Int() interrupt 3{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == ){key_flag = ;led_flag = ;}
	if ( cnt % 00 == )v3_mea = ;
	if ( cnt % 50 == )v1_mea = ;
	if ( cnt % 000 == )f_mea = ;

	cnt%=1000;
	if ( flag == ){
		cnt1++;
		if ( cnt1 >= 000 ){
			cnt1 = ;
			flag = ;
			if ( led_button )led_button = ;
			else if ( led_button == )led_button = ;
			if ( led_button == ){
				P0 = 0xff;
				uLed = xff;
				P0 = uLed;
				Y4;Y0;
			}
		}
	}
}

