/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺫﻝﺗﻳﺻ۹ﺿﻌﺏﮊﺷﮨﻅﺷﮌﺗﺽﺣﺑﺯﺑﻲﺡﻣ,ﮄﻣﺿﻌﺏﮊﺷﮨﻅﺷﻉ۱ﺣﺊﮌﺗﺽﺣﭼﺯSTCﭖﺥﻉﮌﭼﺵﺙﺍﺏﮊﺷﮨ            */
/*---------------------------------------------------------------------*/


/*************  ﺗ۵ﺥﻎﺯﭖﺣﺊ    **************

ﺎﺝﭺﮮﺏﮊﭨﻱﺽﻌSTC32Gﺳ۹ﻅﺊﺟﻊﺷﺝﺩ؛ﭖﺥﮌﭖﺹﻠﺵﻛ9ﺛﺋﺷﺷﺎﻓﺷﺑﺎﻗﮌﺿ.

ﭘﮊﺛﺽﮌﭖﺹﻠﺵﻛﺭﺵﭖﺥJ7۰۱J8ﮊﺋﺵﻑﺛﺋﺷﺷﺎﻗﮌﺿ.

ﺑ؟ﺟﻌ3ﭘ۷ﮌﺎﺓ۱ﺯﺱﺻﭨﺑ؟ﮌﮮﺝﻏﺕﺋﺑ؟ﺟﻌ2.

ﺑ؟ﺟﻌ2ﮌﻛﺏﺉﺑﺽﺑ؟ﺟﻌ3ﺛﺽﮌﻁﭖﺛﭖﺥﮌﮮﺝﻏ.

ﺱﻱﺑ؟ﺟﻌ2ﺓ۱ﺯﺱﮌﮮﺝﻏ۲؛MCUﮌﻁﭖﺛﭦﮩﺑﺽﺑ؟ﺟﻌ2ﺿ­ﺹﻱﮌﻛﺏﺉ.

******************************************/

#include "FreeRTOS.h"
#include "task.h"

#include "uart2_3.h"

/****************************** ﺽﺣﭨ۶ﭘ۷ﺻﮒﭦﻡ ***********************************/

#define Baudrate2   (65536 - MAIN_Fosc / 115200 / 4)
#define Baudrate3   (65536 - MAIN_Fosc / 115200 / 4)

#define UART2_BUF_LENGTH    64
#define UART3_BUF_LENGTH    64

bit B_TX2_Busy; //ﺓ۱ﺯﺱﺣ۵ﺎﻡﻅﺝ
bit B_TX3_Busy; //ﺓ۱ﺯﺱﺣ۵ﺎﻡﻅﺝ
uint8_t  TX2_Send;   //ﺻﺹﺓ۱ﺙﺩﮌﮮ
uint8_t  TX2_Cnt;    //ﺓ۱ﺯﺱﺙﺩﮌﮮ
uint8_t  RX2_Cnt;    //ﺛﺽﮌﻁﺙﺩﮌﮮ
uint8_t  TX3_Send;   //ﺻﺹﺓ۱ﺙﺩﮌﮮ
uint8_t  TX3_Cnt;    //ﺓ۱ﺯﺱﺙﺩﮌﮮ
uint8_t  RX3_Cnt;    //ﺛﺽﮌﻁﺙﺩﮌﮮ
uint8_t  RX2_TimeOut;
uint8_t  RX3_TimeOut;

uint8_t  TX2_Buffer[UART2_BUF_LENGTH]; //ﺛﺽﮌﻁﭨﭦﺏﮒ
uint8_t  RX2_Buffer[UART2_BUF_LENGTH]; //ﺛﺽﮌﻁﭨﭦﺏﮒ
uint8_t  TX3_Buffer[UART3_BUF_LENGTH]; //ﺛﺽﮌﻁﭨﭦﺏﮒ
uint8_t  RX3_Buffer[UART3_BUF_LENGTH]; //ﺛﺽﮌﻁﭨﭦﺏﮒ

uint16_t Sec_Cnt;    //1ﺣﻣﺙﺩﮌﮮ

void UART2_config(uint8_t brt);   // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﺳﻐﺷ۶.
void UART3_config(uint8_t brt);   // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﮌﺗﺽﺣTimer3ﻉﺉﺎ۷ﮊﻊﺡﮌ.
void UART2_TxByte(uint8_t dat);
void UART3_TxByte(uint8_t dat);
void PrintString2(uint8_t *puts);
void PrintString3(uint8_t *puts);

/* RTCﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION_PROTO( vUart2_3Task, pvParameters )
{
    uint8_t i;
    
    Sec_Cnt = 0;
    UART2_config(2);    // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﺳﻐﺷ۶.
    UART3_config(3);    // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﮌﺗﺽﺣTimer3ﻉﺉﺎ۷ﮊﻊﺡﮌ.

    PrintString2("STC32G UART2-UART3 Test Programme!\r\n");  //UART2ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
    PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
    while(1)
    {
        Sec_Cnt++;
        if(Sec_Cnt >= (uint16_t)pvParameters)
        {
            Sec_Cnt = 0;
            PrintString3("STC32G UART3-UART2 Test Programme!\r\n");  //UART3ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺓﻳﺑ؟
        }

        if(RX2_TimeOut > 0)     //ﺏ؛ﮌﺎﺙﺩﮌﮮ
        {
            if(--RX2_TimeOut == 0)
            {
                for(i=0; i<RX2_Cnt; i++)    UART2_TxByte(RX2_Buffer[i]);    //ﺍﺹﮌﻁﭖﺛﭖﺥﮌﮮﺝﻏﺱ۷ﺗﮮﺑ؟ﺟﻌ2ﮌﻛﺏﺉ
                RX2_Cnt  = 0;   //ﮄﮒﺏﮮﻉﻅﺛﻌﮌﮮ
            }
        }
        
        vTaskDelay(1);
    }
    
    vTaskDelete(NULL);
}   

//========================================================================
// ﭦﺁﮌﮮ: void UART2_TxByte(uint8_t dat)
// ﺣﻟﮌﺉ: ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺛﻌ.
// ﺎﺳﮌﮮ: ﺳﻐ.
// ﺓﭖﭨﻊ: ﺳﻐ.
// ﺍﮔﺎﺝ: V1.0, 2014-6-30
//========================================================================
void UART2_TxByte(uint8_t dat)
{
	TX2_Buffer[TX2_Cnt] = dat;	//ﻉﺍﺓ۱ﺯﺱﭨﭦﺏﮒ
	if(++TX2_Cnt >= UART2_BUF_LENGTH)	TX2_Cnt = 0;

	if(B_TX2_Busy == 0)		//ﺟﻁﺵﺷ
	{  
		B_TX2_Busy = 1;		//ﺎﻡﻅﺝﺣ۵
		S2TI = 1;			//ﺑ۴ﺓ۱ﺓ۱ﺯﺱﻅﺷﭘﺵ
	}
}

//========================================================================
// ﭦﺁﮌﮮ: void UART3_TxByte(uint8_t dat)
// ﺣﻟﮌﺉ: ﺓ۱ﺯﺱﺻﭨﺕﺉﻉﻅﺛﻌ.
// ﺎﺳﮌﮮ: ﺳﻐ.
// ﺓﭖﭨﻊ: ﺳﻐ.
// ﺍﮔﺎﺝ: V1.0, 2014-6-30
//========================================================================
void UART3_TxByte(uint8_t dat)
{
	TX3_Buffer[TX3_Cnt] = dat;	//ﻉﺍﺓ۱ﺯﺱﭨﭦﺏﮒ
	if(++TX3_Cnt >= UART3_BUF_LENGTH)	TX3_Cnt = 0;

	if(B_TX3_Busy == 0)		//ﺟﻁﺵﺷ
	{  
		B_TX3_Busy = 1;		//ﺎﻡﻅﺝﺣ۵
		S3TI = 1;			//ﺑ۴ﺓ۱ﺓ۱ﺯﺱﻅﺷﭘﺵ
	}
}

//========================================================================
// ﭦﺁﮌﮮ: void PrintString2(uint8_t *puts)
// ﺣﻟﮌﺉ: ﺑ؟ﺟﻌ2ﺓ۱ﺯﺱﻉﻅﺓﻳﺑ؟ﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: puts:  ﻉﻅﺓﻳﺑ؟ﻅﺕﻁﻣ.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
//========================================================================
void PrintString2(uint8_t *puts)
{
    for (; *puts != 0;  puts++)     //ﺽﺉﭖﺛﺱ۲ﻅﺗﺓﻳ0ﺛﻕﮌﺋ
    {
        UART2_TxByte(*puts);
    }
}

//========================================================================
// ﭦﺁﮌﮮ: void PrintString3(uint8_t *puts)
// ﺣﻟﮌﺉ: ﺑ؟ﺟﻌ3ﺓ۱ﺯﺱﻉﻅﺓﻳﺑ؟ﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: puts:  ﻉﻅﺓﻳﺑ؟ﻅﺕﻁﻣ.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
//========================================================================
void PrintString3(uint8_t *puts)
{
    for (; *puts != 0;  puts++)     //ﺽﺉﭖﺛﺱ۲ﻅﺗﺓﻳ0ﺛﻕﮌﺋ
    {
        UART3_TxByte(*puts);
    }
}

//========================================================================
// ﭦﺁﮌﮮ: SetTimer2Baudraye(uint16_t dat)
// ﺣﻟﮌﺉ: ﺭﻟﻅﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌﺓ۱ﺭﻲﺩﺊ۰۲
// ﺎﺳﮌﮮ: dat: Timer2ﭖﺥﻅﻊﻉﺍﻅﭖ.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
//========================================================================
void SetTimer2Baudraye(uint16_t dat)
{
    T2R = 0;		//Timer stop
    T2_CT = 0;	//Timer2 set As Timer
    T2x12 = 1;	//Timer2 set as 1T mode
    T2H = (uint8_t)(dat / 256);
    T2L = (uint8_t)(dat % 256);
    ET2 = 0;    //ﺛﻳﻅﺗﻅﺷﭘﺵ
    T2R = 1;		//Timer run enable
}

//========================================================================
// ﭦﺁﮌﮮ: void UART3_config(uint8_t brt)
// ﺣﻟﮌﺉ: UART3ﺏﺀﮌﺙﭨﺁﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: brt: ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﮌﺗﺽﺣTimer3ﻉﺉﺎ۷ﮊﻊﺡﮌ.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
//========================================================================
void UART3_config(uint8_t brt)    // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﮌﺗﺽﺣTimer3ﻉﺉﺎ۷ﮊﻊﺡﮌ.
{
    if(brt == 2)
    {
        SetTimer2Baudraye((uint16_t)Baudrate3);
        S3CON = 0x10;       //8ﺳﭨﮌﮮﺝﻏ, ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌﺓ۱ﺭﻲﺩﺊ, ﺿﮌﺷﻥﺛﺽﮌﻁ
    }
    else
    {
        T3R = 0;		//Timer stop
        S3CON = 0x50;       //8ﺳﭨﮌﮮﺝﻏ, ﮌﺗﺽﺣTimer3ﻉﺉﺎ۷ﮊﻊﺡﮌﺓ۱ﺭﻲﺩﺊ, ﺿﮌﺷﻥﺛﺽﮌﻁ
        T3H = (uint8_t)(Baudrate3 / 256);
        T3L = (uint8_t)(Baudrate3 % 256);
        T3_CT = 0;	//Timer3 set As Timer
        T3x12 = 1;	//Timer3 set as 1T mode
        T3R = 1;		//Timer run enable
    }
    ES3  = 1;       //ﺿﮌﺷﻥUART3ﻅﺷﭘﺵ
    S3_S = 1;       //UART3 switch bit1 to: 0: P0.0 P0.1,  1: P5.0 P5.1

    B_TX3_Busy = 0;
    TX3_Send = 0;
    TX3_Cnt = 0;
    RX3_Cnt = 0;
}

//========================================================================
// ﭦﺁﮌﮮ: void UART2_config(uint8_t brt)
// ﺣﻟﮌﺉ: UART2ﺏﺀﮌﺙﭨﺁﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: brt: ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﺳﻐﺷ۶.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
//========================================================================
void UART2_config(uint8_t brt)    // ﺹ۰ﺿﮦﺎ۷ﮊﻊﺡﮌ, 2: ﮌﺗﺽﺣTimer2ﻉﺉﺎ۷ﮊﻊﺡﮌ, ﺩﻛﺯﮰﻅﭖ: ﺳﻐﺷ۶.
{
    if(brt == 2)
    {
        SetTimer2Baudraye((uint16_t)Baudrate2);

        S2CON = (S2CON & 0x3f) | 0x40;    //UART2ﺥ۲ﮌﺛ, 0x00: ﺱ؛ﺎﺛﺻﺩﺳﭨﮌﻛﺏﺉ, 0x40: 8ﺳﭨﮌﮮﺝﻏ,ﺟﺭﺎﻛﺎ۷ﮊﻊﺡﮌ, 0x80: 9ﺳﭨﮌﮮﺝﻏ,ﺗﮊﭘ۷ﺎ۷ﮊﻊﺡﮌ, 0xc0: 9ﺳﭨﮌﮮﺝﻏ,ﺟﺭﺎﻛﺎ۷ﮊﻊﺡﮌ
        ES2   = 1;         //ﺿﮌﺷﻥﻅﺷﭘﺵ
        S2REN = 1;         //ﺿﮌﺷﻥﺛﺽﮌﻁ
        S2_S  = 1;         //UART2 switch to: 0: P1.0 P1.1,  1: P4.6 P4.7

        B_TX2_Busy = 0;
        TX2_Send = 0;
        TX2_Cnt = 0;
        RX2_Cnt = 0;
    }
}

//========================================================================
// ﭦﺁﮌﮮ: void UART2_int (void) interrupt UART2_VECTOR
// ﺣﻟﮌﺉ: UART2ﻅﺷﭘﺵﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: nine.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
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
// ﭦﺁﮌﮮ: void UART3_int (void) interrupt UART3_VECTOR
// ﺣﻟﮌﺉ: UART3ﻅﺷﭘﺵﭦﺁﮌﮮ۰۲
// ﺎﺳﮌﮮ: nine.
// ﺓﭖﭨﻊ: none.
// ﺍﮔﺎﺝ: VER1.0
// ﺫﻁﺩﻌ: 2014-11-28
// ﺎﺕﻉ۱: 
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
