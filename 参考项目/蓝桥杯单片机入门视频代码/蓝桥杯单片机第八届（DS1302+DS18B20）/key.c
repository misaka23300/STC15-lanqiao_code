#include "key.h"

#define key_state_0 0
#define key_state_1 1
#define key_state_2 2
extern u8 mode;
u8 Key_Scan(){
	static u8 key_state=0;
	u8 keynum=0;
	u8 keypress;
	keypress = P3&0x0f;
	
	switch(key_state){
		case key_state_0:
			if(keypress!=0x0f)key_state=1;
			break;
		case key_state_1:
			if(keypress!=0x0f){
				if(keypress==0x07)keynum=4;
				if(keypress==0x0b)keynum=5;
				if(keypress==0x0d)keynum=6;
				if(keypress==0x0e)keynum=7;
				key_state = 2;
			}
			else key_state=0;
			break;
		case key_state_2:
			if(keypress==0x07&&mode!=2&&mode!=3)mode=4;
			else if(keypress==0x0f&&mode==4)mode=1;
			if(keypress==0x0f)key_state=0;
			
			break;
	}
	
	return keynum;
}