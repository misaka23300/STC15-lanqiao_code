/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/


/*************  功能说明    **************

本例程基于STC32G为主控芯片的实验箱9进行编写测试.

短接实验箱上的J7、J8跳线进行测试.

串口3定时发送一串数据给串口2.

串口2输出从串口3接收到的数据.

往串口2发送数据，MCU收到后从串口2原样输出.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "uart2_3.h"

/****************************** 用户定义宏 ***********************************/

#define Baudrate2   (65536 - MAIN_Fosc / 115200 / 4)
#define Baudrate3   (65536 - MAIN_Fosc / 115200 / 4)

#define UART2_BUF_LENGTH    64
#define UART3_BUF_LENGTH    64

bit B_TX2_Busy; //发送忙标志
bit B_TX3_Busy; //发送忙标志
uint8_t  TX2_Send;   //已发计数
uint8_t  TX2_Cnt;    //发送计数
uint8_t  RX2_Cnt;    //接收计数
uint8_t  TX3_Send;   //已发计数
uint8_t  TX3_Cnt;    //发送计数
uint8_t  RX3_Cnt;    //接收计数
uint8_t  RX2_TimeOut;
uint8_t  RX3_TimeOut;

uint8_t  TX2_Buffer[UART2_BUF_LENGTH]; //接收缓冲
uint8_t  RX2_Buffer[UART2_BUF_LENGTH]; //接收缓冲
uint8_t  TX3_Buffer[UART3_BUF_LENGTH]; //接收缓冲
uint8_t  RX3_Buffer[UART3_BUF_LENGTH]; //接收缓冲

uint16_t Sec_Cnt;    //1秒计数

void UART2_config(uint8_t brt);   // 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.
void UART3_config(uint8_t brt);   // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
void UART2_TxByte(uint8_t dat);
void UART3_TxByte(uint8_t dat);
void PrintString2(uint8_t *puts);
void PrintString3(uint8_t *puts);

/* RTC任务函数 */
portTASK_FUNCTION_PROTO( vUart2_3Task, pvParameters )
{
    uint8_t i;
    
    Sec_Cnt = 0;
    UART2_config(2);    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.
    UART3_config(3);    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.

    PrintString2("STC32G UART2-UART3 Test Programme!\r\n");  //UART2发送一个字符串
    PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3发送一个字符串
    while(1)
    {
        Sec_Cnt++;
        if(Sec_Cnt >= (uint16_t)pvParameters)
        {
            Sec_Cnt = 0;
            PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3发送一个字符串
        }

        if(RX2_TimeOut > 0)     //超时计数
        {
            if(--RX2_TimeOut == 0)
            {
                for(i=0; i<RX2_Cnt; i++)    UART2_TxByte(RX2_Buffer[i]);    //把收到的数据通过串口2输出
                RX2_Cnt  = 0;   //清除字节数
            }
        }
        
        vTaskDelay(1);
    }
    
    vTaskDelete(NULL);
}   

//========================================================================
// 函数: void UART2_TxByte(uint8_t dat)
// 描述: 发送一个字节.
// 参数: 无.
// 返回: 无.
// 版本: V1.0, 2014-6-30
//========================================================================
void UART2_TxByte(uint8_t dat)
{
	TX2_Buffer[TX2_Cnt] = dat;	//装发送缓冲
	if(++TX2_Cnt >= UART2_BUF_LENGTH)	TX2_Cnt = 0;

	if(B_TX2_Busy == 0)		//空闲
	{  
		B_TX2_Busy = 1;		//标志忙
		S2TI = 1;			//触发发送中断
	}
}

//========================================================================
// 函数: void UART3_TxByte(uint8_t dat)
// 描述: 发送一个字节.
// 参数: 无.
// 返回: 无.
// 版本: V1.0, 2014-6-30
//========================================================================
void UART3_TxByte(uint8_t dat)
{
	TX3_Buffer[TX3_Cnt] = dat;	//装发送缓冲
	if(++TX3_Cnt >= UART3_BUF_LENGTH)	TX3_Cnt = 0;

	if(B_TX3_Busy == 0)		//空闲
	{  
		B_TX3_Busy = 1;		//标志忙
		S3TI = 1;			//触发发送中断
	}
}

//========================================================================
// 函数: void PrintString2(uint8_t *puts)
// 描述: 串口2发送字符串函数。
// 参数: puts:  字符串指针.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void PrintString2(uint8_t *puts)
{
    for (; *puts != 0;  puts++)     //遇到停止符0结束
    {
        UART2_TxByte(*puts);
    }
}

//========================================================================
// 函数: void PrintString3(uint8_t *puts)
// 描述: 串口3发送字符串函数。
// 参数: puts:  字符串指针.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void PrintString3(uint8_t *puts)
{
    for (; *puts != 0;  puts++)     //遇到停止符0结束
    {
        UART3_TxByte(*puts);
    }
}

//========================================================================
// 函数: SetTimer2Baudraye(uint16_t dat)
// 描述: 设置Timer2做波特率发生器。
// 参数: dat: Timer2的重装值.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void SetTimer2Baudraye(uint16_t dat)
{
    T2R = 0;		//Timer stop
    T2_CT = 0;	//Timer2 set As Timer
    T2x12 = 1;	//Timer2 set as 1T mode
    T2H = (uint8_t)(dat / 256);
    T2L = (uint8_t)(dat % 256);
    ET2 = 0;    //禁止中断
    T2R = 1;		//Timer run enable
}

//========================================================================
// 函数: void UART3_config(uint8_t brt)
// 描述: UART3初始化函数。
// 参数: brt: 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART3_config(uint8_t brt)    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 使用Timer3做波特率.
{
    if(brt == 2)
    {
        SetTimer2Baudraye((uint16_t)Baudrate3);
        S3CON = 0x10;       //8位数据, 使用Timer2做波特率发生器, 允许接收
    }
    else
    {
        T3R = 0;		//Timer stop
        S3CON = 0x50;       //8位数据, 使用Timer3做波特率发生器, 允许接收
        T3H = (uint8_t)(Baudrate3 / 256);
        T3L = (uint8_t)(Baudrate3 % 256);
        T3_CT = 0;	//Timer3 set As Timer
        T3x12 = 1;	//Timer3 set as 1T mode
        T3R = 1;		//Timer run enable
    }
    ES3  = 1;       //允许UART3中断
    S3_S = 1;       //UART3 switch bit1 to: 0: P0.0 P0.1,  1: P5.0 P5.1

    B_TX3_Busy = 0;
    TX3_Send = 0;
    TX3_Cnt = 0;
    RX3_Cnt = 0;
}

//========================================================================
// 函数: void UART2_config(uint8_t brt)
// 描述: UART2初始化函数。
// 参数: brt: 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART2_config(uint8_t brt)    // 选择波特率, 2: 使用Timer2做波特率, 其它值: 无效.
{
    if(brt == 2)
    {
        SetTimer2Baudraye((uint16_t)Baudrate2);

        S2CON = (S2CON & 0x3f) | 0x40;    //UART2模式, 0x00: 同步移位输出, 0x40: 8位数据,可变波特率, 0x80: 9位数据,固定波特率, 0xc0: 9位数据,可变波特率
        ES2   = 1;         //允许中断
        S2REN = 1;         //允许接收
        S2_S  = 1;         //UART2 switch to: 0: P1.0 P1.1,  1: P4.6 P4.7

        B_TX2_Busy = 0;
        TX2_Send = 0;
        TX2_Cnt = 0;
        RX2_Cnt = 0;
    }
}

//========================================================================
// 函数: void UART2_int (void) interrupt UART2_VECTOR
// 描述: UART2中断函数。
// 参数: nine.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART2_int (void) interrupt UART2_VECTOR
{
    if(S2RI)
    {
        S2RI = 0;    //Clear Rx flag
        if(RX2_Cnt >= UART2_BUF_LENGTH)  RX2_Cnt = 0;
        RX2_Buffer[RX2_Cnt] = S2BUF;
        RX2_Cnt++;
        RX2_TimeOut = 5;
    }

    if(S2TI)
    {
        S2TI = 0;    //Clear Tx flag
        if(TX2_Send != TX2_Cnt)
        {
            S2BUF = TX2_Buffer[TX2_Send];
            if(++TX2_Send >= UART2_BUF_LENGTH)  TX2_Send = 0;
        }
        else
        {
            B_TX2_Busy = 0;
        }
    }
}

//========================================================================
// 函数: void UART3_int (void) interrupt UART3_VECTOR
// 描述: UART3中断函数。
// 参数: nine.
// 返回: none.
// 版本: VER1.0
// 日期: 2014-11-28
// 备注: 
//========================================================================
void UART3_int (void) interrupt UART3_VECTOR
{
    if(S3RI)
    {
        S3RI = 0;    //Clear Rx flag
        RX3_Buffer[RX3_Cnt] = S3BUF;
        if(++RX3_Cnt >= UART3_BUF_LENGTH)   RX3_Cnt = 0;
        RX3_TimeOut = 5;
    }

    if(S3TI)
    {
        S3TI = 0;   //Clear Tx flag
        if(TX3_Send != TX3_Cnt)
        {
            S3BUF = TX3_Buffer[TX3_Send];
            if(++TX3_Send >= UART3_BUF_LENGTH)  TX3_Send = 0;
        }
        else
        {
            B_TX3_Busy = 0;
        }
    }
}
