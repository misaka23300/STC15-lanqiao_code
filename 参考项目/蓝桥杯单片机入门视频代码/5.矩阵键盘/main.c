#include <STC15F2K60S2.H>
typedef unsigned char u8;
typedef unsigned int u16;

#define Y4 P2 = (P2&0x1f)|0x80

//P2 & 0x1f -> P2 & 0001 1111 -> 高三位清零
//(P2 & 0x1f) | 0xa0 -> 1010 0000 -> P27=1,P26=0 ,P25=1
#define Y5 P2 = (P2&0x1f)|0xa0

//P2 & 0x1f -> P2 & 0001 1111 -> 高三位清零
//(P2 & 0x1f) | 0xc0 -> 1100 0000 -> P27=P26=1 ,P25=0
#define Y6 P2 = (P2&0x1f)|0xc0

//P2 & 0x1f -> P2 & 0001 1111 -> 高三位清零
//(P2 & 0x1f) | 0xe0 -> 1110 0000 -> P27=P26=1 ,P25=1
#define Y7 P2 = (P2&0x1f)|0xe0

//Y0是关闭锁存器此时写入P0口的数据无法驱动外设
#define Y0 P2 = (P2&0x1f)

/*************  本地常量声明    **************/

//0x06->1这个字符，不过这个表是共阴极的，~0000 0110=1111 1001
u8 code duan[]={                       //标准字库
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

u8 code wei[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //位码
u8 seg[8]={16,16,16,16,16,16,16,16};

void Delay(u16 xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms--){
		i = 12;
		j = 169;
		do
		{
			while (--j);
		} while (--i);	
	}
	
}
//数码管刷新显示
void Seg_Show(){
	static u8 num=0;//8位数码管，动态显示，每一周期进来该函数一次
	
	P0=0xff;Y7;Y0;
	P0=wei[num];Y6;Y0;//完成位选
	P0=~duan[seg[num]];Y7;Y0;//完成段选

	num++;
	num%=8;
}

//设置每一个数码管显示的内容
void Seg_Set(u8 t1,t2,t3,t4,t5,t6,t7,t8){
	seg[0] = t1;
	seg[1] = t2;
	seg[2] = t3;
	seg[3] = t4;
	seg[4] = t5;
	seg[5] = t6;
	seg[6] = t7;
	seg[7] = t8;
}

#define key_state_0 0
#define key_state_1 1
#define key_state_2 2
u8 Key_Scan(){
	static u8 key_state=0;
	u8 keynum=0;
	u16 keypress;
	P44=0;P42=1;P35=1;P34=1;//第一列
	keypress = P3 & 0x0f;//获取按键值
	P44=1;P42=0;P35=1;P34=1;//第二列
	keypress = (keypress<<4) | (P3 & 0x0f);//获取按键值
	P44=1;P42=1;P35=0;P34=1;//第三列
	keypress = (keypress<<4) | (P3 & 0x0f);//获取按键值
	P44=1;P42=1;P35=1;P34=0;//第四列
	keypress = (keypress<<4) | (P3 & 0x0f);//获取按键值
	
	//状态机
	switch(key_state){
		case key_state_0:
			if(keypress!=0xffff)key_state=1;
			break;
		case key_state_1:
			if(keypress!=0x0f){
				switch(~keypress){
					case 0x8000:keynum=4;break;
					case 0x4000:keynum=5;break;
					case 0x2000:keynum=6;break;
					case 0x1000:keynum=7;break;
					
					case 0x0800:keynum=8;break;
					case 0x0400:keynum=9;break;
					case 0x0200:keynum=10;break;
					case 0x0100:keynum=11;break;
					
					case 0x0080:keynum=12;break;
					case 0x0040:keynum=13;break;
					case 0x0020:keynum=14;break;
					case 0x0010:keynum=15;break;
					
					case 0x0008:keynum=16;break;
					case 0x0004:keynum=17;break;
					case 0x0002:keynum=18;break;
					case 0x0001:keynum=19;break;
			
				}
				key_state=2;
			}
			else
				key_state=0;
			break;
		case key_state_2:
			if(keypress==0xffff)key_state=0;
			break;
	}
	
	return keynum;
}


void main(){
	u16 cnt;
	u8 num;//存储按键值
	u8 sec=5;
	u8 a;
	u8 state=1;
	P0=0xff;Y4;Y0;
	P0=0xaf;Y5;Y0;//P06,P04,初始化时这两个设备全部关闭，1010 1111 = 0xaf
	P0=0xff;Y6;Y0;//位选1111 1111,com口全选，P0=0x00
	P0=0xff;Y7;Y0;//段选1111 1111,所有数码管关
	
	

	while(1){
		if(cnt>=20){
			cnt=0;
			num = Key_Scan();
		}
		if(num){
			a=num;
			num=0;//一定要加，这个scan函数的刷新是20ms一次，所以20ms内如果返回了非0按键值，那么
			//那么就会一直是这个值在while(1)里面运行，这样会影响后面的程序
		}
		Seg_Set(a/10,a%10,16,16,16,16,16,16);
		Seg_Show();
		Delay(1);//1ms延时
		cnt++;
		
	}
}