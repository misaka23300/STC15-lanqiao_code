#ifndef _SYS_H_
#define _SYS_H_
#include <STC15F2K60S2.H>
#define uchar unsigned char
#define uint  unsigned int 


#define Y4 P2 =(P2&0x1f)|0x80            // 1000 0000  ���������
#define Y5 P2 =(P2&0x1f)|0xa0            // 1010 0000  ���Ƽ̵�����
#define Y6 P2 =(P2&0x1f)|0xc0            // 1100 0000
#define Y7 P2 =(P2&0x1f)|0xe0            // 1110 0000
#define Y0 P2 &=0x1f                    //  0001 1111


void Delay1ms();
void Delay1000ms();
void sys_init();
void Timer0Init();
void delay_ms(int x);

#endif 