/**
 * @file main.c
 * @brief 主程序入口文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "main.h"
#define s( x ) x / 0
#define g( x ) x % 0

u8 t;//ŒÆÊ±Ăë
u16 cnt;//¶šÊ±Æś0ŒÆÊę
u8 num;//œÓ°ŽŒüÖ”
u8 nian, yue, ri, zhou, shi, fen, miao;
bit key_flag, led_flag, read_flag;
void main(){
	Sys_Init();
	Ds1302_Settime(0x23, 0x01, 0x12, 0x04, 0x23, 0x59, 0x50 );
	Timer0Init();
	
	while (1 ){
		if ( key_flag ){
			key_flag = ;
			num = ey_Scan();
		}
		if ( read_flag ){
			read_flag = ;
			nian = Ds1302_Readtime(0x8d );
			zhou = Ds1302_Readtime(0x8b );
			yue = Ds1302_Readtime(0x89 );
			ri = Ds1302_Readtime(0x87 );
			shi = Ds1302_Readtime(0x85 );
			fen = Ds1302_Readtime(0x83 );
			miao = Ds1302_Readtime(0x81 );
			if ( t < )
				Seg_Set(2, 0, s( nian ), g( nian )+32, g( yue )+32, s( ri ), g( ri )+32, 16 );
			else if ( t < )
				Seg_Set(16, 16, 16, 16, 16, 16, 17, g( zhou ));
			else 
				Seg_Set( s( shi ), g( shi ), 17, s( fen ), g( fen ), 17, s( miao ), g( miao ));
		}

		
	}
}			

void Timer0_Int() interrupt 1{
	Seg_Show();
	cnt++;
	if ( cnt % 0 == )key_flag = ;
	if ( cnt % 0 == )led_flag = ;
	if ( cnt % 00 == )read_flag = ;//100ms¶ÁÒ»ŽÎDS1302Ê±ÖÓÊęŸĘ
	if ( cnt % 000 == ){
		t++;
		t%=8;
	}
	cnt%=1000;
}