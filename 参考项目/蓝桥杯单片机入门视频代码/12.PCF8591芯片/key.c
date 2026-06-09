/**
 * @file key.c
 * @brief 按键驱动文件
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "key.h"
#define key_state_0 0
#define key_state_1 1
#define key_state_2 2
u8 Key_Scan(){
	static u8 key_state = ;
	u8 keynum = ;
	u8 keypress;
	keypress = P3 & 0x0f;
	
	switch( key_state ){
		case 0:
			if ( keypress != x0f )key_state = ;
			break;
		case 1:
			if ( keypress != x0f ){
				if ( keypress == x07 )keynum = ;
				if ( keypress == x0b )keynum = ;
				if ( keypress == x0d )keynum = ;
				if ( keypress == x0e )keynum = ;
				key_state = ;
			}
			else
				key_state = ;
			break;
		case 2:
			if ( keypress == x0f )key_state = ;
			break;
		
	}
	return keynum;
}