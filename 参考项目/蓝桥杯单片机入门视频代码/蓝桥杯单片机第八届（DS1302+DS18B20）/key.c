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
extern u8 mode;
u8 Key_Scan(){
	static u8 key_state = ;
	u8 keynum = ;
	u8 keypress;
	keypress = P3&0x0f;
	
	switch( key_state ){
		case key_state_0:
			if ( keypress != x0f )key_state = ;
			break;
		case key_state_1:
			if ( keypress != x0f ){
				if ( keypress == x07 )keynum = ;
				if ( keypress == x0b )keynum = ;
				if ( keypress == x0d )keynum = ;
				if ( keypress == x0e )keynum = ;
				key_state = 2;
			}
			else key_state = ;
			break;
		case key_state_2:
			if ( keypress == x07 && ode != &&mode != )mode = ;
			else if ( keypress == x0f && ode == )mode = ;
			if ( keypress == x0f )key_state = ;
			
			break;
	}
	
	return keynum;
}