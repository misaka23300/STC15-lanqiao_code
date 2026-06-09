/**
 * @file STC32G_Clock.c
 * @brief 时钟配置模块
 * @date 2026 - 6 - 9
 * @version 1.0
 */

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86 )13922805190 ----------------------------------------*/
/* --- Fax: 86 - 513 - 5012956, 55012947, 55012969 ------------------------*/
/* --- Tel: 86 - 513 - 5012928, 55012929, 55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Ҫڳʹô˴,ڳעʹSTCϼ            */
/*---------------------------------------------------------------------*/

#include	"STC32G_Clock.h"
#include	"STC32G_Delay.h"

//========================================================================
// : void HIRCClkConfig( u8 div )
// : IRCʱӳʼ.
// : div: ʱӷƵϵ.
// : none.
// 汾: V1.0, 2022 - 4 - 3
//========================================================================
void HIRCClkConfig( u8 div )
{
	HIRCCR = 0x80; //ڲ IRC
	while (!( HIRCCR & 1 )); //ȴʱȶ
	CLKDIV = div;
	CLKSEL = 0x00; //ѡڲ IRC ( Ĭ )
}

//========================================================================
// : void XOSCClkConfig( u8 div )
// : ⲿʱӳʼ.
// : div: ʱӷƵϵ.
// : none.
// 汾: V1.0, 2022 - 4 - 3
//========================================================================
void XOSCClkConfig( u8 div )
{
	XOSCCR = 0xc0; //ⲿ
	while (!( XOSCCR & 1 )); //ȴʱȶ
	CLKDIV = div;  //ʱӷƵ
	CLKSEL = 0x01; //ѡⲿ
}

//========================================================================
// : void IRC32KClkConfig( u8 div )
// : 32K IRCʱӳʼ.
// : div: ʱӷƵϵ.
// : none.
// 汾: V1.0, 2022 - 4 - 3
//========================================================================
void IRC32KClkConfig( u8 div )
{
	IRC32KCR = 0x80; //ڲ 32K IRC
	while (!( IRC32KCR & 1 )); //ȴʱȶ
	CLKDIV = div;  //ʱӷƵ
	CLKSEL = 0x03; //ѡڲ 32K
}

//========================================================================
// : void HSPllClkConfig( u8 clksrc, u8 pcki, u8 pllsel, u8 div )
// : IOʱӳʼ.
// : clksrc: ϵͳʱѡ, MCLKSEL_HIRC / CLKSEL_XIRC / CLKSEL_X32K / CLKSEL_I32K / CLKSEL_PLL / CLKSEL_PLL2 / CLKSEL_I48M.
// : pllsel: PLLʱѡ, PLL_96M / LL_144M.
// : div: IOʱӷƵϵ.
// : none.
// 汾: V1.0, 2022 - 4 - 3
//========================================================================
void HSPllClkConfig( u8 clksrc, u8 pllsel, u8 div )
{
	MainClockSel( clksrc );			//ϵͳʱѡ, MCLKSEL_HIRC / CLKSEL_XIRC / CLKSEL_X32K / CLKSEL_I32K / CLKSEL_PLL / CLKSEL_PLL2 / CLKSEL_I48M

	//ϵͳʱ n ƵΪPLLʱԴ,ȷƵΪ12M
    USBCLK &= ~PCKI_MSK;
#if ( MAIN_Fosc == 12000000UL )
    USBCLK |= PCKI_D1;          //PLLʱ1Ƶ
#elif ( MAIN_Fosc == 24000000UL )
    USBCLK |= PCKI_D2;          //PLLʱ2Ƶ
#elif ( MAIN_Fosc == 48000000UL )
    USBCLK |= PCKI_D4;          //PLLʱ4Ƶ
#elif ( MAIN_Fosc == 96000000UL )
    USBCLK |= PCKI_D8;          //PLLʱ8Ƶ
#else
    USBCLK |= PCKI_D1;          //ĬPLLʱ1Ƶ
#endif

	PLLClockSel( pllsel );			//PLLʱѡ, PLL_96M / LL_144M
	PLLEnable( ENABLE );				//PLLƵʹ, ENABLE / ISABLE
	delay_ms(1 );              //ȴPLLƵ
	HSIOClockSel( HSCK_PLL );		//IOʱѡ, HSCK_MCLK / SCK_PLL
	HSClockDiv( div );					//IOʱӷƵϵ
}

