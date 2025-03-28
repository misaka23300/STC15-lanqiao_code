#include <STC15F2K60S2.H>
typedef unsigned char u8;
typedef unsigned int u16;

#define Y4 P2 = (P2&0x1f)|0x80

//P2 & 0x1f -> P2 & 0001 1111 -> ����λ����
//(P2 & 0x1f) | 0xa0 -> 1010 0000 -> P27=1,P26=0 ,P25=1
#define Y5 P2 = (P2&0x1f)|0xa0

//P2 & 0x1f -> P2 & 0001 1111 -> ����λ����
//(P2 & 0x1f) | 0xc0 -> 1100 0000 -> P27=P26=1 ,P25=0
#define Y6 P2 = (P2&0x1f)|0xc0

//P2 & 0x1f -> P2 & 0001 1111 -> ����λ����
//(P2 & 0x1f) | 0xe0 -> 1110 0000 -> P27=P26=1 ,P25=1
#define Y7 P2 = (P2&0x1f)|0xe0

//Y0�ǹر���������ʱд��P0�ڵ������޷���������
#define Y0 P2 = (P2&0x1f)

/*************  ���س�������    **************/

//0x06->1����ַ�������������ǹ������ģ�~0000 0110=1111 1001
u8 code duan[]={                       //��׼�ֿ�
//   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,
//black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00,0x40,0x76,0x1E,0x70,0x38,0x37,0x5C,0x73,0x3E,0x78,0x3d,0x67,0x50,0x37,0x6e,
    0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF,0x46};    //0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

u8 code wei[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};      //λ��
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
//�����ˢ����ʾ
void Seg_Show(){
	static u8 num=0;//8λ����ܣ���̬��ʾ��ÿһ���ڽ����ú���һ��
	
	P0=0xff;Y7;Y0;
	P0=wei[num];Y6;Y0;//���λѡ
	P0=~duan[seg[num]];Y7;Y0;//��ɶ�ѡ

	num++;
	num%=8;
}

//����ÿһ���������ʾ������
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
	u8 keypress;
	keypress = P3 & 0x0f;//��ȡ����ֵ
	
	//״̬��
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
				key_state=2;
			}
			else
				key_state=0;
			break;
		case key_state_2:
			if(keypress==0x0f)key_state=0;
			break;
	}
	
	return keynum;
}
void Timer0Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;//������ʱ��0���ж�
	EA = 1;//�������ж�
}

void Timer1Init(void)		//100΢��@12.000MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0x9C;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1 = 1;//������ʱ��1���ж�
}

u8 sec;//�뵥Ԫ
u16 cnt;//��ʱ��0����
u8 n;//��ʱ��1����
u8 num;
u8 compare;//�Ƚ���
bit key_flag,flag=0;
void main(){
	
	P0=0xff;Y4;Y0;
	P0=0xaf;Y5;Y0;//P06,P04,��ʼ��ʱ�������豸ȫ���رգ�1010 1111 = 0xaf
	P0=0xff;Y6;Y0;//λѡ1111 1111,com��ȫѡ��P0=0x00
	P0=0xff;Y7;Y0;//��ѡ1111 1111,��������ܹ�
	
	Timer0Init();
	Timer1Init();

	while(1){
		
		if(key_flag){
			key_flag=0;
			Seg_Set(sec/10,sec%10,16,16,16,16,16,16);
			num=Key_Scan();
		}
		if(num==4){
			num=0;
			flag=!flag;//����flag=1��ɽ������������֮��ֹͣ������
		}
		if(num==5){
			num=0;
			sec=0;//����
		}
		if(num==6){
			num=0;
			compare+=2;//���ȵȼ�+1��6���ȼ���0��2,4,6,8,10
			if(compare==12){
				compare=0;
			}
			
		}
		
		
		
		
	}
}

//ϵͳ���̹���
void Timer0_INT() interrupt 1{
	Seg_Show();//1ms����һ��
	cnt++;
	if(cnt%20==0)key_flag=1;
	if(cnt==1000){
		if(flag==1)
			sec++;
	}
	cnt%=1000;
}

//1khz,�ɱ�ռ�ձ�
void Timer1_INT() interrupt 3{
	n++;
	if(n<=compare){P0=0x00;Y4;Y0;}//����
	else {P0=0xff;Y4;Y0;}//����
	n%=10;
}