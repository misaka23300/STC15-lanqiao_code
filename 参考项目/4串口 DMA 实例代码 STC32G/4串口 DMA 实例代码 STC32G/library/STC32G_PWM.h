#ifndef _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_PWM_H_
#define _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_PWM_H_

/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCAI.com ---------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- BBS: www.STCAIMCU.com  -----------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Ҫڳʹô˴,ڳעʹSTCϼ            */
/*---------------------------------------------------------------------*/

#ifndef __STC32G_PWM_H
#define __STC32G_PWM_H   

#include  "config.h"

//========================================================================
//                               PWM
//========================================================================

//                           7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_ENO = 0xFEB1H;  ENO4N ENO4P ENO3N ENO3P ENO2N ENO2P ENO1N ENO1P  0000,0000  /* ʹܼĴ */ 
//sfr PWMB_ENO = 0xFEB5H;    -   ENO8P   -   ENO7P   -   ENO6P   -   ENO5P  0000,0000  /* ʹܼĴ */ 
#define    PWM1P_OUT_EN()  PWMA_ENO |= 0x01  /* ʹ PWM1P  */
#define    PWM1P_OUT_DIS()  PWMA_ENO &= ~0x01  /* ֹ PWM1P  */
#define    PWM1N_OUT_EN()  PWMA_ENO |= 0x02  /* ʹ PWM1N  */
#define    PWM1N_OUT_DIS()  PWMA_ENO &= ~0x02  /* ֹ PWM1N  */
#define    PWM2P_OUT_EN()  PWMA_ENO |= 0x04  /* ʹ PWM2P  */
#define    PWM2P_OUT_DIS()  PWMA_ENO &= ~0x04  /* ֹ PWM2P  */
#define    PWM2N_OUT_EN()  PWMA_ENO |= 0x08  /* ʹ PWM2N  */
#define    PWM2N_OUT_DIS()  PWMA_ENO &= ~0x08  /* ֹ PWM2N  */
#define    PWM3P_OUT_EN()  PWMA_ENO |= 0x10  /* ʹ PWM3P  */
#define    PWM3P_OUT_DIS()  PWMA_ENO &= ~0x10  /* ֹ PWM3P  */
#define    PWM3N_OUT_EN()  PWMA_ENO |= 0x20  /* ʹ PWM3N  */
#define    PWM3N_OUT_DIS()  PWMA_ENO &= ~0x20  /* ֹ PWM3N  */
#define    PWM4P_OUT_EN()  PWMA_ENO |= 0x40  /* ʹ PWM3P  */
#define    PWM4P_OUT_DIS()  PWMA_ENO &= ~0x40  /* ֹ PWM3P  */
#define    PWM4N_OUT_EN()  PWMA_ENO |= 0x80  /* ʹ PWM3N  */
#define    PWM4N_OUT_DIS()  PWMA_ENO &= ~0x80  /* ֹ PWM3N  */

#define    PWM5P_OUT_EN()  PWMB_ENO |= 0x01  /* ʹ PWM5P  */
#define    PWM5P_OUT_DIS()  PWMB_ENO &= ~0x01  /* ֹ PWM5P  */
#define    PWM6P_OUT_EN()  PWMB_ENO |= 0x04  /* ʹ PWM6P  */
#define    PWM6P_OUT_DIS()  PWMB_ENO &= ~0x04  /* ֹ PWM6P  */
#define    PWM7P_OUT_EN()  PWMB_ENO |= 0x10  /* ʹ PWM7P  */
#define    PWM7P_OUT_DIS()  PWMB_ENO &= ~0x10  /* ֹ PWM7P  */
#define    PWM8P_OUT_EN()  PWMB_ENO |= 0x40  /* ʹ PWM8P  */
#define    PWM8P_OUT_DIS()  PWMB_ENO &= ~0x40  /* ֹ PWM8P  */

#define    PWMA_OutChannelSel(n)    PWMA_ENO = n  //ѡͨ
#define    PWMB_OutChannelSel(n)    PWMB_ENO = n  //ѡͨ

//                          7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_PS = 0xFEB2H;  C4PS1 C4PS0 C3PS1 C3PS0 C2PS1 C2PS0 C1PS1 C1PS0  0000,0000  /* ʹܼĴ */ 
//sfr PWMB_PS = 0xFEB6H;  C8PS1 C8PS0 C7PS1 C7PS0 C6PS1 C6PS0 C5PS1 C5PS0  0000,0000  /* ʹܼĴ */ 

#define    PWM1_USE_P10P11()    PWMA_PS = (PWMA_PS & ~0x03)        /* PWM ͨ 1 лP10(PWM1P) P11(PWM1N) */ 
#define    PWM1_USE_P20P21()    PWMA_PS = (PWMA_PS & ~0x03) | 0x01  /* PWM ͨ 1 лP20(PWM1P) P21(PWM1N) */ 
#define    PWM1_USE_P60P61()    PWMA_PS = (PWMA_PS & ~0x03) | 0x02  /* PWM ͨ 1 лP60(PWM1P) P61(PWM1N) */ 

#define    PWM2_USE_P12P13()    PWMA_PS = (PWMA_PS & ~0x0C)          /* PWM ͨ 2 лP12/P54(PWM2P) P13(PWM2N) */ 
#define    PWM2_USE_P22P23()    PWMA_PS = (PWMA_PS & ~0x0C) | 0x04  /* PWM ͨ 2 лP22(PWM2P) P23(PWM2N) */ 
#define    PWM2_USE_P62P63()    PWMA_PS = (PWMA_PS & ~0x0C) | 0x08  /* PWM ͨ 2 лP62(PWM2P) P63(PWM2N) */ 

#define    PWM3_USE_P14P15()    PWMA_PS = (PWMA_PS & ~0x30)          /* PWM ͨ 3 лP14(PWM3P) P15(PWM3N) */ 
#define    PWM3_USE_P24P25()    PWMA_PS = (PWMA_PS & ~0x30) | 0x10  /* PWM ͨ 3 лP24(PWM3P) P25(PWM3N) */ 
#define    PWM3_USE_P64P65()    PWMA_PS = (PWMA_PS & ~0x30) | 0x20  /* PWM ͨ 3 лP64(PWM3P) P65(PWM3N) */ 

#define    PWM4_USE_P16P17()    PWMA_PS = (PWMA_PS & ~0xC0)          /* PWM ͨ 4 лP16(PWM4P) P17(PWM4N) */ 
#define    PWM4_USE_P26P27()    PWMA_PS = (PWMA_PS & ~0xC0) | 0x40  /* PWM ͨ 4 лP26(PWM4P) P27(PWM4N) */ 
#define    PWM4_USE_P66P67()    PWMA_PS = (PWMA_PS & ~0xC0) | 0x80  /* PWM ͨ 4 лP66(PWM4P) P67(PWM4N) */ 
#define    PWM4_USE_P34P33()    PWMA_PS = (PWMA_PS | 0xC0)          /* PWM ͨ 4 лP34(PWM4P) P33(PWM4N) */ 

#define    PWM5_USE_P20()      PWMB_PS = (PWMB_PS & ~0x03)          /* PWM ͨ 5 лP20(PWM5) */ 
#define    PWM5_USE_P17()      PWMB_PS = (PWMB_PS & ~0x03) | 0x01  /* PWM ͨ 5 лP17(PWM5) */ 
#define    PWM5_USE_P00()      PWMB_PS = (PWMB_PS & ~0x03) | 0x02  /* PWM ͨ 5 лP00(PWM5) */ 
#define    PWM5_USE_P74()      PWMB_PS = (PWMB_PS | 0x03)          /* PWM ͨ 5 лP74(PWM5) */ 

#define    PWM6_USE_P21()      PWMB_PS = (PWMB_PS & ~0x0C)          /* PWM ͨ 6 лP21(PWM6) */ 
#define    PWM6_USE_P54()      PWMB_PS = (PWMB_PS & ~0x0C) | 0x04  /* PWM ͨ 6 лP54(PWM6) */ 
#define    PWM6_USE_P01()      PWMB_PS = (PWMB_PS & ~0x0C) | 0x08  /* PWM ͨ 6 лP01(PWM6) */ 
#define    PWM6_USE_P75()      PWMB_PS = (PWMB_PS | 0x0C)          /* PWM ͨ 6 лP75(PWM6) */ 

#define    PWM7_USE_P22()      PWMB_PS = (PWMB_PS & ~0x30)          /* PWM ͨ 7 лP22(PWM7) */ 
#define    PWM7_USE_P33()      PWMB_PS = (PWMB_PS & ~0x30) | 0x10  /* PWM ͨ 7 лP33(PWM7) */ 
#define    PWM7_USE_P02()      PWMB_PS = (PWMB_PS & ~0x30) | 0x20  /* PWM ͨ 7 лP02(PWM7) */ 
#define    PWM7_USE_P76()      PWMB_PS = (PWMB_PS | 0x30)          /* PWM ͨ 7 лP76(PWM7) */ 

#define    PWM8_USE_P23()      PWMB_PS = (PWMB_PS & ~0xC0)          /* PWM ͨ 8 лP23(PWM8) */ 
#define    PWM8_USE_P34()      PWMB_PS = (PWMB_PS & ~0xC0) | 0x40  /* PWM ͨ 8 лP34(PWM8) */ 
#define    PWM8_USE_P03()      PWMB_PS = (PWMB_PS & ~0xC0) | 0x80  /* PWM ͨ 8 лP03(PWM8) */ 
#define    PWM8_USE_P77()      PWMB_PS = (PWMB_PS | 0xC0)          /* PWM ͨ 8 лP77(PWM8) */ 

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_IOAUX = 0xFEB3H;  AUX4N AUX4P AUX3N AUX3P AUX2N AUX2P AUX1N AUX1P  0000,0000  /* ʹܼĴ */ 
//sfr PWMB_IOAUX = 0xFEB7H;    -   AUX8P   -   AUX7P   -   AUX6P   -   AUX5P  0000,0000  /* ʹܼĴ */ 
#define AUX4N      (1<<7)
#define AUX4P      (1<<6)
#define AUX3N      (1<<5)
#define AUX3P      (1<<4)
#define AUX2N      (1<<3)
#define AUX2P      (1<<2)
#define AUX1N      (1<<1)
#define AUX1P      (1)

#define AUX8P      (1<<6)
#define AUX7P      (1<<4)
#define AUX6P      (1<<2)
#define AUX5P      (1)


//                           7     6     5    4    3    2    1     0    Reset Value
//sfr PWMA_CR1 = 0xFEC0H;  ARPEA CMSA1 CMSA0 DIRA OPMA URSA UDISA CENA  0000,0000  /* ƼĴ 1 */ 
//sfr PWMB_CR1 = 0xFEE0H;  ARPEB CMSB1 CMSB0 DIRB OPMB URSB UDISB CENB  0000,0000  /* ƼĴ 1 */ 
#define ARPE1      (1<<7)
#define ARPE2      (1<<7)
#define PWMA_AlignMode_Edge()      PWMA_CR1 = (PWMA_CR1 & ~0x60)
#define PWMA_AlignMode_Mid1()      PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x20
#define PWMA_AlignMode_Mid2()      PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x40
#define PWMA_AlignMode_Mid3()      PWMA_CR1 = (PWMA_CR1 | 0x60)
#define PWMA_DIR_UP()              PWMA_CR1 &= ~0x10
#define PWMA_DIR_DN()              PWMA_CR1 |= 0x10
#define PWMA_OPMA(n)              (n==1?(PWMA_CR1 |= 0x08):(PWMA_CR1 &= ~0x08))  //ģʽ 0ڷ¼ʱֹͣ1ڷһθ¼ʱ CEN λֹͣ
#define PWMA_URSA(n)              (n==1?(PWMA_CR1 |= 0x04):(PWMA_CR1 &= ~0x04))  //Դ
#define PWMA_UDISA(n)              (n==1?(PWMA_CR1 |= 0x02):(PWMA_CR1 &= ~0x02))  //ֹ 0£UEV¼1¼
//#define PWMA_CEN_Enable()          PWMA_CR1 |= 0x01    //1ʹܼ
#define PWMA_CEN_Disable()        PWMA_CR1 &= ~0x01    //0ֹ
#define PWMA_CEN_Enable(n)        (n==1?(PWMA_CR1 |= 0x01):(PWMA_CR1 &= ~0x01))    //1ʹܼ

#define PWMB_AlignMode_Edge()      PWMB_CR1 = (PWMB_CR1 & ~0x60)
#define PWMB_AlignMode_Mid1()      PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x20
#define PWMB_AlignMode_Mid2()      PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x40
#define PWMB_AlignMode_Mid3()      PWMB_CR1 = (PWMB_CR1 | 0x60)
#define PWMB_DIR_UP()              PWMB_CR1 &= ~0x10
#define PWMB_DIR_DN()              PWMB_CR1 |= 0x10
#define PWMB_OPMB(n)              (n==1?(PWMB_CR1 |= 0x08):(PWMB_CR1 &= ~0x08))  //ģʽ 0ڷ¼ʱֹͣ1ڷһθ¼ʱ CEN λֹͣ
#define PWMB_URSB(n)              (n==1?(PWMB_CR1 |= 0x04):(PWMB_CR1 &= ~0x04))  //Դ
#define PWMB_UDISB(n)              (n==1?(PWMB_CR1 |= 0x02):(PWMB_CR1 &= ~0x02))  //ֹ 0£UEV¼1¼
//#define PWMB_CEN_Enable()          PWMB_CR1 |= 0x01    //1ʹܼ
#define PWMB_CEN_Disable()        PWMB_CR1 &= ~0x01    //0ֹ
#define PWMB_CEN_Enable(n)        (n==1?(PWMB_CR1 |= 0x01):(PWMB_CR1 &= ~0x01))    //1ʹܼ


//                           7     6     5    4    3    2    1    0    Reset Value
//sfr PWMA_CR2 = 0xFEC1H;  TI1S MMSA2 MMSA1 MMSA0  -  COMSA  -  CCPCA  0000,x0x0  /* ƼĴ 2 */ 
//sfr PWMB_CR2 = 0xFEE1H;  TI5S MMSB2 MMSB1 MMSB0  -  COMSB  -  CCPCB  0000,x0xx  /* ƼĴ 2 */ 
#define PWM1P_TI1()              PWMA_CR2 &= ~0x80
#define PWM1P2P3P_XOR_TI1()      PWMA_CR2 |= 0x80
#define PWM5P_TI2()              PWMB_CR2 &= ~0x80
#define PWM5P6P7P_XOR_TI2()      PWMB_CR2 |= 0x80

#define MMSn_RESET          0    //λ
#define MMSn_ENABLE          1    //ʹ
#define MMSn_UPDATE          2    //
#define MMSn_COMP_TRGO      3    //Ƚ
#define MMSn_OC1REF_TRGO    4    //Ƚ
#define MMSn_OC2REF_TRGO    5    //Ƚ
#define MMSn_OC3REF_TRGO    6    //Ƚ
#define MMSn_OC4REF_TRGO    7    //Ƚ

#define PWMA_MainModeSel(n)    PWMA_CR2 = (PWMA_CR2 & ~0x70) | (n<<4)  //ģʽѡ
#define PWMB_MainModeSel(n)    PWMB_CR2 = (PWMB_CR2 & ~0x70) | (n<<4)  //ģʽѡ

//0 CCPC=1 ʱֻ COMG λ 1 ʱЩλű
//1 CCPC=1 ʱֻ COMG λ 1  TRGI صʱЩλű
#define PWMA_COMSUpdateCtrl(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x04):(PWMA_CR2 &= ~0x04))  ///ȽϿλĸ¿ѡ
#define PWMB_COMSUpdateCtrl(n)    PWMB_CR2 = (n==1?(PWMB_CR2 |= 0x04):(PWMB_CR2 &= ~0x04))  ///ȽϿλĸ¿ѡ
//0 CCIE CCINE CCiP CCiNP  OCIM λԤװص
//1 CCIE CCINE CCiP CCiNP  OCIM λԤװصģøλֻ COMGλ󱻸¡
#define PWMA_CCPCAPreloaded(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x01):(PWMA_CR2 &= ~0x01))  ///ȽԤװؿλ(λֻԾлͨ)
#define PWMB_CCPCBPreloaded(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x01):(PWMA_CR2 &= ~0x01))  ///ȽԤװؿλ(λֻԾлͨ)


//                           7    6    5    4    3    2     1     0    Reset Value
//sfr PWMA_SMCR = 0xFEC2H;  MSMA TSA2 TSA1 TSA0  -  SMSA2 SMSA1 SMSA0  0000,x000  /* ģʽƼĴ */ 
//sfr PWMB_SMCR = 0xFEE2H;  MSMB TSB2 TSB1 TSB0  -  SMSB2 SMSB1 SMSB0  0000,x000  /* ģʽƼĴ */ 
#define SMCR_TSn_ITR2        2
#define SMCR_TSn_EDGE        4
#define SMCR_TSn_TIMER1      5
#define SMCR_TSn_TIMER2      6
#define SMCR_TSn_ETRF        7

#define PWMA_SMCR_Source(n)    PWMA_SMCR = (PWMA_SMCR & ~0x70) | (n<<4)  //Դѡ
#define PWMB_SMCR_Source(n)    PWMB_SMCR = (PWMB_SMCR & ~0x70) | (n<<4)  //Դѡ

#define SMCR_SMSA_INSIDE_CLK      0
#define SMCR_SMSA_ENCODER_M1      1
#define SMCR_SMSA_ENCODER_M2      2
#define SMCR_SMSA_ENCODER_M3      3
#define SMCR_SMSA_RESET            4
#define SMCR_SMSA_GATE            5
#define SMCR_SMSA_TRIG            6
#define SMCR_SMSA_EXT_CLK          7

#define PWMA_SMCR_SMS(n)    PWMA_SMCR = (PWMA_SMCR & ~0x07) | (n & 7)  //ʱ//ģʽѡ
#define PWMB_SMCR_SMS(n)    PWMB_SMCR = (PWMB_SMCR & ~0x07) | (n & 7)  //ʱ//ģʽѡ

//                           7    6    5      4     3     2     1     0     Reset Value
//sfr PWMA_ETR = 0xFEC3H;  ETP1 ECE1 ETPS11 ETPS10 ETF13 ETF12 ETF11 ETF10  0000,0000  /* ⲿĴ */ 
//sfr PWMB_ETR = 0xFEE3H;  ETP2 ECE2 ETPS21 ETPS20 ETF23 ETF22 ETF21 ETF20  0000,0000  /* ⲿĴ */ 

//                           7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_IER = 0xFEC4H;  BIEA TIEA COMIEA CC4IE CC3IE CC2IE CC1IE UIEA  0000,0000  /* жʹܼĴ */ 
//sfr PWMB_IER = 0xFEE4H;  BIEB TIEB COMIEB CC8IE CC7IE CC6IE CC5IE UIEB  0000,0000  /* жʹܼĴ */ 
#define PWMA_UIEA_Enable()    PWMA_IER |= 0x01    //1ж
#define PWMA_UIEA_Disable()    PWMA_IER &= ~0x01    //0ֹж
#define PWMA_CC1IE_Enable()    PWMA_IER |= 0x02    //1/Ƚж
#define PWMA_CC1IE_Disable()  PWMA_IER &= ~0x02    //0ֹ/Ƚж
#define PWMA_CC2IE_Enable()    PWMA_IER |= 0x04    //1/Ƚж
#define PWMA_CC2IE_Disable()  PWMA_IER &= ~0x04    //0ֹ/Ƚж
#define PWMA_CC3IE_Enable()    PWMA_IER |= 0x08    //1/Ƚж
#define PWMA_CC3IE_Disable()  PWMA_IER &= ~0x08    //0ֹ/Ƚж
#define PWMA_CC4IE_Enable()    PWMA_IER |= 0x10    //1/Ƚж
#define PWMA_CC4IE_Disable()  PWMA_IER &= ~0x10    //0ֹ/Ƚж
#define PWMA_COMIEA_Enable()  PWMA_IER |= 0x20    //1COMж
#define PWMA_COMIEA_Disable()  PWMA_IER &= ~0x20    //0ֹCOMж
#define PWMA_TIEA_Enable()    PWMA_IER |= 0x40    //1ж
#define PWMA_TIEA_Disable()    PWMA_IER &= ~0x40    //0ֹж
#define PWMA_BIEA_Enable()    PWMA_IER |= 0x80    //1ɲж
#define PWMA_BIEA_Disable()    PWMA_IER &= ~0x80    //0ֹɲж

//                           7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_SR1 = 0xFEC5H;  BIF1 TIF1 COMIF1 CC4IF CC3IF CC2IF CC1IF UIF1  0000,0000  /* ״̬Ĵ 1 */ 
//sfr PWMB_SR1 = 0xFEE5H;  BIF2 TIF2 COMIF2 CC8IF CC7IF CC6IF CC5IF UIF2  0000,0000  /* ״̬Ĵ 1 */ 
#define UIF1      1
#define CC1IF      (1<<1)
#define CC2IF      (1<<2)
#define CC3IF      (1<<3)
#define CC4IF      (1<<4)
#define COMIF1    (1<<5)
#define TIF1      (1<<6)
#define BIF1      (1<<7)

#define UIF2      1
#define CC5IF      (1<<1)
#define CC6IF      (1<<2)
#define CC7IF      (1<<3)
#define CC8IF      (1<<4)
#define COMIF2    (1<<5)
#define TIF2      (1<<6)
#define BIF2      (1<<7)

//                          7   6   5    4     3     2     1    0   Reset Value
//sfr PWMA_SR2 = 0xFEC6H;   -   -   -  CC4OF CC3OF CC2OF CC1OF  -   xxx0,000x  /* ״̬Ĵ 2 */ 
//sfr PWMB_SR2 = 0xFEE6H;   -   -   -  CC8OF CC7OF CC6OF CC5OF  -   xxx0,000x  /* ״̬Ĵ 2 */ 

//                          7   6    5    4    3    2    1    0   Reset Value
//sfr PWMA_EGR = 0xFEC7H;  BG1 TG1 COMG1 CC4G CC3G CC2G CC1G UG1  0000,0000  /* ¼Ĵ */ 
//sfr PWMB_EGR = 0xFEE7H;  BG2 TG2 COMG2 CC8G CC7G CC6G CC5G UG2  0000,0000  /* ¼Ĵ */ 

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  OC1CE OC1M2 OC1M1 OC1M0 OC1PE OC1FE CC1S1 CC1S0  0000,0000  /* /ȽģʽĴ 1 - ͨΪȽģʽ */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  OC5CE OC5M2 OC5M1 OC5M0 OC5PE OC5FE CC5S1 CC5S0  0000,0000  /* /ȽģʽĴ 1 - ͨΪȽģʽ */ 
#define OCnCE      (1<<7)

#define CCMRn_FREEZE              0x00    //
#define CCMRn_MATCH_VALID          0x10    //ƥʱͨ n ΪЧƽ
#define CCMRn_MATCH_INVALID        0x20    //ƥʱͨ n ΪЧƽ
#define CCMRn_ROLLOVER            0x30    //ת
#define CCMRn_FORCE_INVALID        0x40    //ǿΪЧƽ
#define CCMRn_FORCE_VALID          0x50    //ǿΪЧƽ
#define CCMRn_PWM_MODE1            0x60    //PWM ģʽ 1
#define CCMRn_PWM_MODE2            0x70    //PWM ģʽ 2

#define PWMA_OC1ModeSet(n)        PWMA_CCMR1 = (PWMA_CCMR1 & ~0x70) | (n)    //Ƚģʽ
#define PWMB_OC5ModeSet(n)        PWMB_CCMR1 = (PWMB_CCMR1 & ~0x70) | (n)    //Ƚģʽ

#define PWMA_OC1_ReloadEnable(n)  (n==1?(PWMA_CCMR1 |= 0x08):(PWMA_CCMR1 &= ~0x08))    // OC1PE ȽϵԤװع
#define PWMB_OC5_ReloadEnable(n)  (n==1?(PWMB_CCMR1 |= 0x08):(PWMB_CCMR1 &= ~0x08))    // OC5PE ȽϵԤװع
//#define PWMA_OC1_ReloadEnable()    PWMA_CCMR1 |= 0x08    //1 OC1PE ȽϵԤװع
//#define PWMA_OC1_RelosdDisable()  PWMA_CCMR1 &= ~0x08    //0ֹ OC1PE ȽϵԤװع
//#define PWMB_OC5_ReloadEnable()    PWMB_CCMR1 |= 0x08    //1 OC5PE ȽϵԤװع
//#define PWMB_OC5_RelosdDisable()  PWMB_CCMR1 &= ~0x08    //0ֹ OC5PE ȽϵԤװع

#define PWMA_OC1_FastEnable(n)    (n==1?(PWMA_CCMR1 |= 0x04):(PWMA_CCMR1 &= ~0x04))    //1 OC1FE ȽϿٹ
#define PWMB_OC5_FastEnable(n)    (n==1?(PWMB_CCMR1 |= 0x04):(PWMB_CCMR1 &= ~0x04))    //1 OC5FE ȽϿٹ
//#define PWMA_OC1_FastEnable()      PWMA_CCMR1 |= 0x04    //1 OC1FE ȽϿٹ
//#define PWMA_OC1_FastDisable()    PWMA_CCMR1 &= ~0x04    //0ֹ OC1FE ȽϿٹ
//#define PWMB_OC5_FastEnable()      PWMB_CCMR1 |= 0x04    //1 OC5FE ȽϿٹ
//#define PWMB_OC5_FastDisable()    PWMB_CCMR1 &= ~0x04    //0ֹ OC5FE ȽϿٹ

#define CCAS_OUTPUT            0x00    //
#define CCAS_IUTPUT_TI1FP1    0x01    //룬IC1/IC2/IC3/IC4 ӳ TI1FP1 
#define CCAS_IUTPUT_TI2FP1    0x02    //룬IC1/IC2/IC3/IC4 ӳ TI2FP1 
#define CCAS_IUTPUT_TRC        0x03    //룬IC1/IC2/IC3/IC4 ӳ TRC 
#define CCBS_OUTPUT            0x00    //
#define CCBS_IUTPUT_TI5FP5    0x01    //룬IC5/IC6/IC7/IC8 ӳ TI5FP5 
#define CCBS_IUTPUT_TI6FP5    0x02    //룬IC5/IC6/IC7/IC8 ӳ TI6FP5 
#define CCBS_IUTPUT_TRC        0x03    //룬IC5/IC6/IC7/IC8 ӳ TRC 

#define PWMA_CC1S_Direction(n)    PWMA_CCMR1 = (PWMA_CCMR1 & ~0x03) | (n)    ///Ƚ 1 ѡλͨķ/ŵѡ
#define PWMB_CC5S_Direction(n)    PWMB_CCMR1 = (PWMB_CCMR1 & ~0x03) | (n)    ///Ƚ 5 ѡλͨķ/ŵѡ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  IC1F3 IC1F2 IC1F1 IC1F0 IC1PSC1 IC1PSC0 CC1S1 CC1S0  0000,0000  /* /ȽģʽĴ 1 - ͨΪģʽ */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  IC5F3 IC5F2 IC5F1 IC5F0 IC5PSC1 IC5PSC0 CC5S1 CC5S0  0000,0000  /* /ȽģʽĴ 1 - ͨΪģʽ */ 

#define ICnF_01_Clock      0
#define ICnF_02_Clock      1
#define ICnF_04_Clock      2
#define ICnF_08_Clock      3
#define ICnF_12_Clock      4
#define ICnF_16_Clock      5
#define ICnF_24_Clock      6
#define ICnF_32_Clock      7
#define ICnF_48_Clock      8
#define ICnF_64_Clock      9
#define ICnF_80_Clock      10
#define ICnF_96_Clock      11
#define ICnF_128_Clock    12
#define ICnF_160_Clock    13
#define ICnF_192_Clock    14
#define ICnF_256_Clock    15

#define PWMA_IC1F_FilterClock(n)  PWMA_CCMR1 = (PWMA_CCMR1 & 0x0F) | (n<<4)    //벶 1 ˲ѡ񣬸λ TIn ĲƵʼ˲
#define PWMB_IC5F_FilterClock(n)  PWMB_CCMR1 = (PWMB_CCMR1 & 0x0F) | (n<<4)    //벶 5 ˲ѡ񣬸λ TIn ĲƵʼ˲

#define PWMA_IC1PSC_PrescalerSet(n)    PWMA_CCMR1 = (PWMA_CCMR1 & 0xF3) | ((n&3)<<2)    /// 1 ԤƵ0~3
#define PWMB_IC5PSC_PrescalerSet(n)    PWMB_CCMR1 = (PWMB_CCMR1 & 0xF3) | ((n&3)<<2)    /// 5 ԤƵ0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  OC2CE OC2M2 OC2M1 OC2M0 OC2PE OC2FE CC2S1 CC2S0  0000,0000  /* /ȽģʽĴ 2 - ͨΪȽģʽ */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  OC6CE OC6M2 OC6M1 OC6M0 OC6PE OC6FE CC6S1 CC6S0  0000,0000  /* /ȽģʽĴ 2 - ͨΪȽģʽ */ 

#define PWMA_OC2ModeSet(n)        PWMA_CCMR2 = (PWMA_CCMR2 & ~0x70) | (n)    //Ƚģʽ
#define PWMB_OC6ModeSet(n)        PWMB_CCMR2 = (PWMB_CCMR2 & ~0x70) | (n)    //Ƚģʽ

#define PWMA_OC2_ReloadEnable()    PWMA_CCMR2 |= 0x08    //1 OC2PE ȽϵԤװع
#define PWMA_OC2_RelosdDisable()  PWMA_CCMR2 &= ~0x08    //0ֹ OC2PE ȽϵԤװع
#define PWMB_OC6_ReloadEnable()    PWMB_CCMR2 |= 0x08    //1 OC6PE ȽϵԤװع
#define PWMB_OC6_RelosdDisable()  PWMB_CCMR2 &= ~0x08    //0ֹ OC6PE ȽϵԤװع

#define PWMA_OC2_FastEnable()      PWMA_CCMR2 |= 0x04    //1 OC2FE ȽϿٹ
#define PWMA_OC2_FastDisable()    PWMA_CCMR2 &= ~0x04    //0ֹ OC2FE ȽϿٹ
#define PWMB_OC6_FastEnable()      PWMB_CCMR2 |= 0x04    //1 OC6FE ȽϿٹ
#define PWMB_OC6_FastDisable()    PWMB_CCMR2 &= ~0x04    //0ֹ OC6FE ȽϿٹ

#define PWMA_CC2S_Direction(n)    PWMA_CCMR2 = (PWMA_CCMR2 & ~0x03) | (n)    ///Ƚ 2 ѡλͨķ/ŵѡ
#define PWMB_CC6S_Direction(n)    PWMB_CCMR2 = (PWMB_CCMR2 & ~0x03) | (n)    ///Ƚ 6 ѡλͨķ/ŵѡ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  IC2F3 IC2F2 IC2F1 IC2F0 IC2PSC1 IC2PSC0 CC2S1 CC2S0  0000,0000  /* /ȽģʽĴ 2 - ͨΪģʽ */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  IC6F3 IC6F2 IC6F1 IC6F0 IC6PSC1 IC6PSC0 CC6S1 CC6S0  0000,0000  /* /ȽģʽĴ 2 - ͨΪģʽ */ 

#define PWMA_IC2F_FilterClock(n)  PWMA_CCMR2 = (PWMA_CCMR2 & 0x0F) | (n<<4)    //벶 2 ˲ѡ񣬸λ TIn ĲƵʼ˲
#define PWMB_IC6F_FilterClock(n)  PWMB_CCMR2 = (PWMB_CCMR2 & 0x0F) | (n<<4)    //벶 6 ˲ѡ񣬸λ TIn ĲƵʼ˲

#define PWMA_IC2PSC_PrescalerSet(n)    PWMA_CCMR2 = (PWMA_CCMR2 & 0xF3) | ((n&3)<<2)    /// 2 ԤƵ0~3
#define PWMB_IC6PSC_PrescalerSet(n)    PWMB_CCMR2 = (PWMB_CCMR2 & 0xF3) | ((n&3)<<2)    /// 6 ԤƵ0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  OC3CE OC3M2 OC3M1 OC3M0 OC3PE OC3FE CC3S1 CC3S0  0000,0000  /* /ȽģʽĴ 3 - ͨΪȽģʽ */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  OC7CE OC7M2 OC7M1 OC7M0 OC7PE OC7FE CC7S1 CC7S0  0000,0000  /* /ȽģʽĴ 3 - ͨΪȽģʽ */ 

#define PWMA_OC3ModeSet(n)        PWMA_CCMR3 = (PWMA_CCMR3 & ~0x70) | (n)    //Ƚģʽ
#define PWMB_OC7ModeSet(n)        PWMB_CCMR3 = (PWMB_CCMR3 & ~0x70) | (n)    //Ƚģʽ

#define PWMA_OC3_ReloadEnable()    PWMA_CCMR3 |= 0x08    //1 OC3PE ȽϵԤװع
#define PWMA_OC3_RelosdDisable()  PWMA_CCMR3 &= ~0x08    //0ֹ OC3PE ȽϵԤװع
#define PWMB_OC7_ReloadEnable()    PWMB_CCMR3 |= 0x08    //1 OC7PE ȽϵԤװع
#define PWMB_OC7_RelosdDisable()  PWMB_CCMR3 &= ~0x08    //0ֹ OC7PE ȽϵԤװع

#define PWMA_OC3_FastEnable()      PWMA_CCMR3 |= 0x04    //1 OC3FE ȽϿٹ
#define PWMA_OC3_FastDisable()    PWMA_CCMR3 &= ~0x04    //0ֹ OC3FE ȽϿٹ
#define PWMB_OC7_FastEnable()      PWMB_CCMR3 |= 0x04    //1 OC7FE ȽϿٹ
#define PWMB_OC7_FastDisable()    PWMB_CCMR3 &= ~0x04    //0ֹ OC7FE ȽϿٹ

#define PWMA_CC3S_Direction(n)    PWMA_CCMR3 = (PWMA_CCMR3 & ~0x03) | (n)    ///Ƚ 3 ѡλͨķ/ŵѡ
#define PWMB_CC7S_Direction(n)    PWMB_CCMR3 = (PWMB_CCMR3 & ~0x03) | (n)    ///Ƚ 7 ѡλͨķ/ŵѡ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  IC3F3 IC3F2 IC3F1 IC3F0 IC3PSC1 IC3PSC0 CC3S1 CC3S0  0000,0000  /* /ȽģʽĴ 3 - ͨΪģʽ */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  IC7F3 IC7F2 IC7F1 IC7F0 IC7PSC1 IC7PSC0 CC7S1 CC7S0  0000,0000  /* /ȽģʽĴ 3 - ͨΪģʽ */ 

#define PWMA_IC3F_FilterClock(n)  PWMA_CCMR3 = (PWMA_CCMR3 & 0x0F) | (n<<4)    //벶 3 ˲ѡ񣬸λ TIn ĲƵʼ˲
#define PWMB_IC7F_FilterClock(n)  PWMB_CCMR3 = (PWMB_CCMR3 & 0x0F) | (n<<4)    //벶 7 ˲ѡ񣬸λ TIn ĲƵʼ˲

#define PWMA_IC3PSC_PrescalerSet(n)    PWMA_CCMR3 = (PWMA_CCMR3 & 0xF3) | ((n&3)<<2)    /// 3 ԤƵ0~3
#define PWMB_IC7PSC_PrescalerSet(n)    PWMB_CCMR3 = (PWMB_CCMR3 & 0xF3) | ((n&3)<<2)    /// 7 ԤƵ0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  OC4CE OC4M2 OC4M1 OC4M0 OC4PE OC4FE CC4S1 CC4S0  0000,0000  /* /ȽģʽĴ 4 - ͨΪȽģʽ */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  OC8CE OC8M2 OC8M1 OC8M0 OC8PE OC8FE CC8S1 CC8S0  0000,0000  /* /ȽģʽĴ 4 - ͨΪȽģʽ */ 

#define PWMA_OC4ModeSet(n)        PWMA_CCMR4 = (PWMA_CCMR4 & ~0x70) | (n)    //Ƚģʽ
#define PWMB_OC8ModeSet(n)        PWMB_CCMR4 = (PWMB_CCMR4 & ~0x70) | (n)    //Ƚģʽ

#define PWMA_OC4_ReloadEnable()    PWMA_CCMR4 |= 0x08    //1 OC4PE ȽϵԤװع
#define PWMA_OC4_RelosdDisable()  PWMA_CCMR4 &= ~0x08    //0ֹ OC4PE ȽϵԤװع
#define PWMB_OC8_ReloadEnable()    PWMB_CCMR4 |= 0x08    //1 OC8PE ȽϵԤװع
#define PWMB_OC8_RelosdDisable()  PWMB_CCMR4 &= ~0x08    //0ֹ OC8PE ȽϵԤװع

#define PWMA_OC4_FastEnable()      PWMA_CCMR4 |= 0x04    //1 OC4FE ȽϿٹ
#define PWMA_OC4_FastDisable()    PWMA_CCMR4 &= ~0x04    //0ֹ OC4FE ȽϿٹ
#define PWMB_OC8_FastEnable()      PWMB_CCMR4 |= 0x04    //1 OC8FE ȽϿٹ
#define PWMB_OC8_FastDisable()    PWMB_CCMR4 &= ~0x04    //0ֹ OC8FE ȽϿٹ

#define PWMA_CC4S_Direction(n)    PWMA_CCMR4 = (PWMA_CCMR4 & ~0x03) | (n)    ///Ƚ 4 ѡλͨķ/ŵѡ
#define PWMB_CC8S_Direction(n)    PWMB_CCMR4 = (PWMB_CCMR4 & ~0x03) | (n)    ///Ƚ 8 ѡλͨķ/ŵѡ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  IC4F3 IC4F2 IC4F1 IC4F0 IC4PSC1 IC4PSC0 CC4S1 CC4S0  0000,0000  /* /ȽģʽĴ 4 - ͨΪģʽ */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  IC8F3 IC8F2 IC8F1 IC8F0 IC8PSC1 IC8PSC0 CC8S1 CC8S0  0000,0000  /* /ȽģʽĴ 4 - ͨΪģʽ */ 

#define PWMA_IC4F_FilterClock(n)  PWMA_CCMR4 = (PWMA_CCMR4 & 0x0F) | (n<<4)    //벶 4 ˲ѡ񣬸λ TIn ĲƵʼ˲
#define PWMB_IC8F_FilterClock(n)  PWMB_CCMR4 = (PWMB_CCMR4 & 0x0F) | (n<<4)    //벶 8 ˲ѡ񣬸λ TIn ĲƵʼ˲

#define PWMA_IC4PSC_PrescalerSet(n)    PWMA_CCMR4 = (PWMA_CCMR4 & 0xF3) | ((n&3)<<2)    /// 4 ԤƵ0~3
#define PWMB_IC8PSC_PrescalerSet(n)    PWMB_CCMR4 = (PWMB_CCMR4 & 0xF3) | ((n&3)<<2)    /// 8 ԤƵ0~3

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER1 = 0xFECCH;  CC2NP CC2NE CC2P CC2E CC1NP CC1NE CC1P CC1E  0000,0000  /* /ȽʹܼĴ 1 */ 
//sfr PWMB_CCER1 = 0xFEECH;    -     -   CC6P CC6E   -     -   CC5P CC5E  0000,0000  /* /ȽʹܼĴ 1 */ 

//#define PWMA_CC1E_Enable(n)        PWMA_CCER1 = (PWMA_CCER1 & ~0x01) | (n)        //벶/Ƚ
//#define PWMA_CC1NE_Enable(n)      PWMA_CCER1 = (PWMA_CCER1 & ~0x04) | (n << 2)  //Ƚ

#define PWMA_CCER1_Disable()      PWMA_CCER1 = 0x00      //ر벶/Ƚ
#define PWMA_CC1E_Enable()        PWMA_CCER1 |= 0x01    //1벶/Ƚ
#define PWMA_CC1E_Disable()        PWMA_CCER1 &= ~0x01    //0ر벶/Ƚ
#define PWMA_CC1P_LowValid()      PWMA_CCER1 |= 0x02    //1͵ƽЧ
#define PWMA_CC1P_HighValid()      PWMA_CCER1 &= ~0x02    //0ߵƽЧ
#define PWMA_CC1P_CaptureRise()    PWMA_CCER1 |= 0x02    //1 TI1F  TI2F ½
#define PWMA_CC1P_CaptureFall()    PWMA_CCER1 &= ~0x02    //0 TI1F  TI2F 
#define PWMA_CC1NE_Enable()        PWMA_CCER1 |= 0x04    //1Ƚ
#define PWMA_CC1NE_Disable()      PWMA_CCER1 &= ~0x04    //0رձȽ
#define PWMA_CC1NP_LowValid()      PWMA_CCER1 |= 0x08    //1͵ƽЧ
#define PWMA_CC1NP_HighValid()    PWMA_CCER1 &= ~0x08    //0ߵƽЧ

#define PWMA_CC2E_Enable()        PWMA_CCER1 |= 0x10    //1벶/Ƚ
#define PWMA_CC2E_Disable()        PWMA_CCER1 &= ~0x10    //0ر벶/Ƚ
#define PWMA_CC2P_LowValid()      PWMA_CCER1 |= 0x20    //1͵ƽЧ
#define PWMA_CC2P_HighValid()      PWMA_CCER1 &= ~0x20    //0ߵƽЧ
#define PWMA_CC2P_CaptureRise()    PWMA_CCER1 |= 0x20    //1 TI1F  TI2F ½
#define PWMA_CC2P_CaptureFall()    PWMA_CCER1 &= ~0x20    //0 TI1F  TI2F 
#define PWMA_CC2NE_Enable()        PWMA_CCER1 |= 0x40    //1Ƚ
#define PWMA_CC2NE_Disable()      PWMA_CCER1 &= ~0x40    //0رձȽ
#define PWMA_CC2NP_LowValid()      PWMA_CCER1 |= 0x80    //1͵ƽЧ
#define PWMA_CC2NP_HighValid()    PWMA_CCER1 &= ~0x80    //0ߵƽЧ

#define PWMB_CCER1_Disable()      PWMB_CCER1 = 0x00      //ر벶/Ƚ
#define PWMB_CC5E_Enable()        PWMB_CCER1 |= 0x01    //1벶/Ƚ
#define PWMB_CC5E_Disable()        PWMB_CCER1 &= ~0x01    //0ر벶/Ƚ
#define PWMB_CC5P_LowValid()      PWMB_CCER1 |= 0x02    //1͵ƽЧ
#define PWMB_CC5P_HighValid()      PWMB_CCER1 &= ~0x02    //0ߵƽЧ
#define PWMB_CC5P_CaptureRise()    PWMB_CCER1 |= 0x02    //1 TI1F  TI2F ½
#define PWMB_CC5P_CaptureFall()    PWMB_CCER1 &= ~0x02    //0 TI1F  TI2F 

#define PWMB_CC6E_Enable()        PWMB_CCER1 |= 0x10    //1벶/Ƚ
#define PWMB_CC6E_Disable()        PWMB_CCER1 &= ~0x10    //0ر벶/Ƚ
#define PWMB_CC6P_LowValid()      PWMB_CCER1 |= 0x20    //1͵ƽЧ
#define PWMB_CC6P_HighValid()      PWMB_CCER1 &= ~0x20    //0ߵƽЧ
#define PWMB_CC6P_CaptureRise()    PWMB_CCER1 |= 0x20    //1 TI1F  TI2F ½
#define PWMB_CC6P_CaptureFall()    PWMB_CCER1 &= ~0x20    //0 TI1F  TI2F 

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER2 = 0xFECDH;  CC4NP CC4NE CC4P CC4E CC3NP CC3NE CC3P CC3E  0000,0000  /* /ȽʹܼĴ 2 */ 
//sfr PWMB_CCER2 = 0xFEEDH;    -     -   CC8P CC8E   -     -   CC7P CC7E  0000,0000  /* /ȽʹܼĴ 2 */ 

#define PWMA_CCER2_Disable()      PWMA_CCER2 = 0x00      //ر벶/Ƚ
#define PWMA_CC3E_Enable()        PWMA_CCER2 |= 0x01    //1벶/Ƚ
#define PWMA_CC3E_Disable()        PWMA_CCER2 &= ~0x01    //0ر벶/Ƚ
#define PWMA_CC3P_LowValid()      PWMA_CCER2 |= 0x02    //1͵ƽЧ
#define PWMA_CC3P_HighValid()      PWMA_CCER2 &= ~0x02    //0ߵƽЧ
#define PWMA_CC3P_CaptureRise()    PWMA_CCER2 |= 0x02    //1 TI1F  TI2F ½
#define PWMA_CC3P_CaptureFall()    PWMA_CCER2 &= ~0x02    //0 TI1F  TI2F 
#define PWMA_CC3NE_Enable()        PWMA_CCER2 |= 0x04    //1Ƚ
#define PWMA_CC3NE_Disable()      PWMA_CCER2 &= ~0x04    //0رձȽ
#define PWMA_CC3NP_LowValid()      PWMA_CCER2 |= 0x08    //1͵ƽЧ
#define PWMA_CC3NP_HighValid()    PWMA_CCER2 &= ~0x08    //0ߵƽЧ

#define PWMA_CC4E_Enable()        PWMA_CCER2 |= 0x10    //1벶/Ƚ
#define PWMA_CC4E_Disable()        PWMA_CCER2 &= ~0x10    //0ر벶/Ƚ
#define PWMA_CC4P_LowValid()      PWMA_CCER2 |= 0x20    //1͵ƽЧ
#define PWMA_CC4P_HighValid()      PWMA_CCER2 &= ~0x20    //0ߵƽЧ
#define PWMA_CC4P_CaptureRise()    PWMA_CCER2 |= 0x20    //1 TI1F  TI2F ½
#define PWMA_CC4P_CaptureFall()    PWMA_CCER2 &= ~0x20    //0 TI1F  TI2F 
#define PWMA_CC4NE_Enable()        PWMA_CCER2 |= 0x40    //1Ƚ
#define PWMA_CC4NE_Disable()      PWMA_CCER2 &= ~0x40    //0رձȽ
#define PWMA_CC4NP_LowValid()      PWMA_CCER2 |= 0x80    //1͵ƽЧ
#define PWMA_CC4NP_HighValid()    PWMA_CCER2 &= ~0x80    //0ߵƽЧ

#define PWMB_CCER2_Disable()      PWMB_CCER2 = 0x00      //ر벶/Ƚ
#define PWMB_CC7E_Enable()        PWMB_CCER2 |= 0x01    //1벶/Ƚ
#define PWMB_CC7E_Disable()        PWMB_CCER2 &= ~0x01    //0ر벶/Ƚ
#define PWMB_CC7P_LowValid()      PWMB_CCER2 |= 0x02    //1͵ƽЧ
#define PWMB_CC7P_HighValid()      PWMB_CCER2 &= ~0x02    //0ߵƽЧ
#define PWMB_CC7P_CaptureRise()    PWMB_CCER2 |= 0x02    //1 TI1F  TI2F ½
#define PWMB_CC7P_CaptureFall()    PWMB_CCER2 &= ~0x02    //0 TI1F  TI2F 

#define PWMB_CC8E_Enable()        PWMB_CCER2 |= 0x10    //1벶/Ƚ
#define PWMB_CC8E_Disable()        PWMB_CCER2 &= ~0x10    //0ر벶/Ƚ
#define PWMB_CC8P_LowValid()      PWMB_CCER2 |= 0x20    //1͵ƽЧ
#define PWMB_CC8P_HighValid()      PWMB_CCER2 &= ~0x20    //0ߵƽЧ
#define PWMB_CC8P_CaptureRise()    PWMB_CCER2 |= 0x20    //1 TI1F  TI2F ½
#define PWMB_CC8P_CaptureFall()    PWMB_CCER2 &= ~0x20    //0 TI1F  TI2F 

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CNTRH = 0xFECEH;                   CNT1[15:8]                  0000,0000  /*  8 λ */ 
//sfr PWMB_CNTRH = 0xFEEEH;                   CNT2[15:8]                  0000,0000  /*  8 λ */ 
//sfr PWMA_CNTRL = 0xFECFH;                   CNT1[7:0]                   0000,0000  /*  8 λ */ 
//sfr PWMB_CNTRL = 0xFEEFH;                   CNT2[7:0]                   0000,0000  /*  8 λ */ 

#define PWMA_Counter(n)            PWMA_CNTR = n    //
#define PWMB_Counter(n)            PWMB_CNTR = n    //

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_PSCRH = 0xFED0H;                   PSC1[15:8]                  0000,0000  /* ԤƵ 8 λ */ 
//sfr PWMB_PSCRH = 0xFEF0H;                   PSC2[15:8]                  0000,0000  /* ԤƵ 8 λ */ 
//sfr PWMA_PSCRL = 0xFED1H;                   PSC1[7:0]                   0000,0000  /* ԤƵ 8 λ */ 
//sfr PWMB_PSCRL = 0xFEF1H;                   PSC2[7:0]                   0000,0000  /* ԤƵ 8 λ */ 

#define PWMA_Prescaler(n)          PWMA_PSCR = n    //ԤƵ
#define PWMB_Prescaler(n)          PWMB_PSCR = n    //ԤƵ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_ARRH = 0xFED2H;                    ARR1[15:8]                  0000,0000  /* ԶװؼĴ 8 λ */ 
//sfr PWMB_ARRH = 0xFEF2H;                    ARR2[15:8]                  0000,0000  /* ԶװؼĴ 8 λ */ 
//sfr PWMA_ARRL = 0xFED3H;                    ARR1[7:0]                   0000,0000  /* ԶװؼĴ 8 λ */ 
//sfr PWMB_ARRL = 0xFEF3H;                    ARR2[7:0]                   0000,0000  /* ԶװؼĴ 8 λ */ 

#define PWMA_AutoReload(n)        {PWMA_ARRH = (n>>8); PWMA_ARRL = (n);}    //ԶװؼĴ
#define PWMB_AutoReload(n)        {PWMB_ARRH = (n>>8); PWMB_ARRL = (n);}    //ԶװؼĴ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_RCR = 0xFED4H;                     REP1[7:0]                   0000,0000  /* ظĴ */ 
//sfr PWMB_RCR = 0xFEF4H;                     REP2[7:0]                   0000,0000  /* ظĴ */ 

#define PWMA_ReCounter(n)          PWMA_RCR = n    //ظĴ
#define PWMB_ReCounter(n)          PWMB_RCR = n    //ظĴ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR1H = 0xFED5H;                   CCR1[15:8]                  0000,0000  /* /ȽϼĴ 1  8 λ */ 
//sfr PWMB_CCR5H = 0xFEF5H;                   CCR5[15:8]                  0000,0000  /* /ȽϼĴ 1  8 λ */ 
//sfr PWMA_CCR1L = 0xFED6H;                   CCR1[7:0]                   0000,0000  /* /ȽϼĴ 1  8 λ */ 
//sfr PWMB_CCR5L = 0xFEF6H;                   CCR5[7:0]                   0000,0000  /* /ȽϼĴ 1  8 λ */ 

#define PWMA_Duty1(n)              {PWMA_CCR1H = (n>>8); PWMA_CCR1L = (n);}    ///ȽϼĴ 1 
#define PWMB_Duty5(n)              {PWMB_CCR5H = (n>>8); PWMB_CCR5L = (n);}    ///ȽϼĴ 1 

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR2H = 0xFED7H;                   CCR2[15:8]                  0000,0000  /* /ȽϼĴ 2  8 λ */ 
//sfr PWMB_CCR6H = 0xFEF7H;                   CCR6[15:8]                  0000,0000  /* /ȽϼĴ 2  8 λ */ 
//sfr PWMA_CCR2L = 0xFED8H;                   CCR2[7:0]                   0000,0000  /* /ȽϼĴ 2  8 λ */ 
//sfr PWMB_CCR6L = 0xFEF8H;                   CCR6[7:0]                   0000,0000  /* /ȽϼĴ 2  8 λ */ 

#define PWMA_Duty2(n)              {PWMA_CCR2H = (n>>8); PWMA_CCR2L = (n);}    ///ȽϼĴ 2 
#define PWMB_Duty6(n)              {PWMB_CCR6H = (n>>8); PWMB_CCR6L = (n);}    ///ȽϼĴ 2 

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR3H = 0xFED9H;                   CCR3[15:8]                  0000,0000  /* /ȽϼĴ 3  8 λ */ 
//sfr PWMB_CCR7H = 0xFEF9H;                   CCR7[15:8]                  0000,0000  /* /ȽϼĴ 3  8 λ */ 
//sfr PWMA_CCR3L = 0xFEDAH;                   CCR3[7:0]                   0000,0000  /* /ȽϼĴ 3  8 λ */ 
//sfr PWMB_CCR7L = 0xFEFAH;                   CCR7[7:0]                   0000,0000  /* /ȽϼĴ 3  8 λ */ 

#define PWMA_Duty3(n)              {PWMA_CCR3H = (n>>8); PWMA_CCR3L = (n);}    ///ȽϼĴ 3 
#define PWMB_Duty7(n)              {PWMB_CCR7H = (n>>8); PWMB_CCR7L = (n);}    ///ȽϼĴ 3 

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR4H = 0xFEDBH;                   CCR4[15:8]                  0000,0000  /* /ȽϼĴ 4  8 λ */ 
//sfr PWMB_CCR8H = 0xFEFBH;                   CCR8[15:8]                  0000,0000  /* /ȽϼĴ 4  8 λ */ 
//sfr PWMA_CCR4L = 0xFEDCH;                   CCR4[7:0]                   0000,0000  /* /ȽϼĴ 4  8 λ */ 
//sfr PWMB_CCR8L = 0xFEFCH;                   CCR8[7:0]                   0000,0000  /* /ȽϼĴ 4  8 λ */ 

#define PWMA_Duty4(n)              {PWMA_CCR4H = (n>>8); PWMA_CCR4L = (n);}    ///ȽϼĴ 4 
#define PWMB_Duty8(n)              {PWMB_CCR8H = (n>>8); PWMB_CCR8L = (n);}    ///ȽϼĴ 4 

//                          7    6    5    4     3     2     1      0     Reset Value
//sfr PWMA_BKR = 0xFEDDH;  MOE1 AOE1 BKP1 BKE1 OSSR1 OSSI1 LOCK11 LOCK10  0000,0000  /* ɲĴ */ 
//sfr PWMB_BKR = 0xFEFDH;  MOE2 AOE2 BKP2 BKE2 OSSR2 OSSI2 LOCK21 LOCK20  0000,0000  /* ɲĴ */ 

#define PWMA_BrakeOutputEnable(n)        (n==1?(PWMA_BKR |= 0x80):(PWMA_BKR &= ~0x80))    //1ʹ
#define PWMB_BrakeOutputEnable(n)        (n==1?(PWMB_BKR |= 0x80):(PWMB_BKR &= ~0x80))    //1ʹ
//#define PWMA_BrakeOutputEnable()        PWMA_BKR |= 0x80    //1ʹ
#define PWMA_BrakeOutputDisable()        PWMA_BKR &= ~0x80    //0ֹ
//#define PWMB_BrakeOutputEnable()        PWMB_BKR |= 0x80    //1ʹ
#define PWMB_BrakeOutputDisable()        PWMB_BKR &= ~0x80    //0ֹ

#define PWMA_BrakeAutoOutputEnable()    PWMA_BKR |= 0x40    //1Զʹ
#define PWMA_BrakeAutoOutputDisable()    PWMA_BKR &= ~0x40    //0Զֹ
#define PWMB_BrakeAutoOutputEnable()    PWMB_BKR |= 0x40    //1Զʹ
#define PWMB_BrakeAutoOutputDisable()    PWMB_BKR &= ~0x40    //0Զֹ

#define PWMA_BrakeHighValid()            PWMA_BKR |= 0x20    //1ɲߵƽЧ
#define PWMA_BrakeLowValid()            PWMA_BKR &= ~0x20    //0ɲ͵ƽЧ
#define PWMB_BrakeHighValid()            PWMB_BKR |= 0x20    //1ɲߵƽЧ
#define PWMB_BrakeLowValid()            PWMB_BKR &= ~0x20    //0ɲ͵ƽЧ

#define PWMA_BrakeEnable(n)              (n==1?(PWMA_BKR |= 0x10):(PWMA_BKR &= ~0x10))    //1ɲ
#define PWMB_BrakeEnable(n)              (n==1?(PWMB_BKR |= 0x10):(PWMB_BKR &= ~0x10))    //1ɲ
//#define PWMA_BrakeEnable()              PWMA_BKR |= 0x10    //1ɲ
#define PWMA_BrakeDisable()              PWMA_BKR &= ~0x10    //0ֹɲ
//#define PWMB_BrakeEnable()              PWMB_BKR |= 0x10    //1ɲ
#define PWMB_BrakeDisable()              PWMB_BKR &= ~0x10    //0ֹɲ

//ģʽ¡ر״̬ѡ
#define PWMA_OSSRnEnable()              PWMA_BKR |= 0x08    //1 PWM ʱһ CCiE=1  CCiNE=1ȿ OC/OCN ЧƽȻOC/OCN ʹź=1
#define PWMA_OSSRnDisable()              PWMA_BKR &= ~0x08    //0 PWM ʱֹ OC/OCN OC/OCN ʹź=0
#define PWMB_OSSRnEnable()              PWMB_BKR |= 0x08    //1 PWM ʱһ CCiE=1  CCiNE=1ȿ OC/OCN ЧƽȻOC/OCN ʹź=1
#define PWMB_OSSRnDisable()              PWMB_BKR &= ~0x08    //0 PWM ʱֹ OC/OCN OC/OCN ʹź=0
//ģʽ¡ر״̬ѡ
#define PWMA_OSSInEnable()              PWMA_BKR |= 0x04    //1 PWM ʱһ CCiE=1  CCiNE=1OC/OCN еƽȻ OC/OCNʹź=1
#define PWMA_OSSInDisable()              PWMA_BKR &= ~0x04    //0 PWM ʱֹ OC/OCN OC/OCN ʹź=0
#define PWMB_OSSInEnable()              PWMB_BKR |= 0x04    //1 PWM ʱһ CCiE=1  CCiNE=1OC/OCN еƽȻ OC/OCNʹź=1
#define PWMB_OSSInDisable()              PWMB_BKR &= ~0x04    //0 PWM ʱֹ OC/OCN OC/OCN ʹź=0

#define PWMn_lock_L0      0    //Ĵд
#define PWMn_lock_L1      1    // 1д PWMn_BKR Ĵ BKEBKPAOE λPWMn_OISR Ĵ OISI λ
#define PWMn_lock_L2      2    // 2д 1 еĸλҲд CC λԼ OSSR/OSSI λ
#define PWMn_lock_L3      3    // 3д 2 еĸλҲд CC λ

#define PWMA_LockLevelSet(n)            PWMA_BKR = (PWMA_BKR & ~0x03) | (n&3)    //áλΪֹṩдʩ
#define PWMB_LockLevelSet(n)            PWMB_BKR = (PWMB_BKR & ~0x03) | (n&3)    //áλΪֹṩдʩ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_DTR = 0xFEDEH;                     DTG1[7:0]                   0000,0000  /* Ĵ */ 
//sfr PWMB_DTR = 0xFEFEH;                     DTG2[7:0]                   0000,0000  /* Ĵ */ 

//DTGn[7:5] = 000~011: ʱ = DTGn[7:0] * tCK_PSC
//DTGn[7:5] = 100~101: ʱ = (64 + DTGn[6:0]) * 2 * tCK_PSC
//DTGn[7:5] = 110:     ʱ = (32 + DTGn[5:0]) * 8 * tCK_PSC
//DTGn[7:5] = 111:     ʱ = (32 + DTGn[4:0]) * 16 * tCK_PSC

#define PWMA_DeadTime(n)          PWMA_DTR = n    //
#define PWMB_DeadTime(n)          PWMB_DTR = n    //

//                            7    6     5    4     3    2     1    0    Reset Value
//sfr PWMA_OISR = 0xFEDFH;  OIS4N OIS4 OIS3N OIS3 OIS2N OIS2 OIS1N OIS1  0000,0000  /* ״̬Ĵ */ 
//sfr PWMB_OISR = 0xFEFFH;    -   OIS8   -   OIS7   -   OIS6   -   OIS5  x0x0,x0x0  /* ״̬Ĵ */ 

#define PWMA_OC1_OUT_0()          PWMA_OISR &= ~0x01  /*  MOE=0 ʱ OC1N ʹܣһOC1=0 */
#define PWMA_OC1_OUT_1()          PWMA_OISR |= 0x01    /*  MOE=0 ʱ OC1N ʹܣһOC1=1 */
#define PWMA_OC1N_OUT_0()          PWMA_OISR &= ~0x02  /*  MOE=0 ʱһOC1N=0 */
#define PWMA_OC1N_OUT_1()          PWMA_OISR |= 0x02    /*  MOE=0 ʱһOC1N=1 */
#define PWMA_OC2_OUT_0()          PWMA_OISR &= ~0x04  /*  MOE=0 ʱ OC2N ʹܣһOC2=0 */
#define PWMA_OC2_OUT_1()          PWMA_OISR |= 0x04    /*  MOE=0 ʱ OC2N ʹܣһOC2=1 */
#define PWMA_OC2N_OUT_0()          PWMA_OISR &= ~0x08  /*  MOE=0 ʱһOC2N=0 */
#define PWMA_OC2N_OUT_1()          PWMA_OISR |= 0x08    /*  MOE=0 ʱһOC2N=1 */
#define PWMA_OC3_OUT_0()          PWMA_OISR &= ~0x10  /*  MOE=0 ʱ OC3N ʹܣһOC3=0 */
#define PWMA_OC3_OUT_1()          PWMA_OISR |= 0x10    /*  MOE=0 ʱ OC3N ʹܣһOC3=1 */
#define PWMA_OC3N_OUT_0()          PWMA_OISR &= ~0x20  /*  MOE=0 ʱһOC3N=0 */
#define PWMA_OC3N_OUT_1()          PWMA_OISR |= 0x20    /*  MOE=0 ʱһOC3N=1 */
#define PWMA_OC4_OUT_0()          PWMA_OISR &= ~0x40  /*  MOE=0 ʱ OC4N ʹܣһOC4=0 */
#define PWMA_OC4_OUT_1()          PWMA_OISR |= 0x40    /*  MOE=0 ʱ OC4N ʹܣһOC4=1 */
#define PWMA_OC4N_OUT_0()          PWMA_OISR &= ~0x80  /*  MOE=0 ʱһOC4N=0 */
#define PWMA_OC4N_OUT_1()          PWMA_OISR |= 0x80    /*  MOE=0 ʱһOC4N=1 */

#define PWMB_OC5_OUT_0()          PWMB_OISR &= ~0x01  /*  MOE=0 ʱһOC5=0 */
#define PWMB_OC5_OUT_1()          PWMB_OISR |= 0x01    /*  MOE=0 ʱһOC5=1 */
#define PWMB_OC6_OUT_0()          PWMB_OISR &= ~0x04  /*  MOE=0 ʱһOC6=0 */
#define PWMB_OC6_OUT_1()          PWMB_OISR |= 0x04    /*  MOE=0 ʱһOC6=1 */
#define PWMB_OC7_OUT_0()          PWMB_OISR &= ~0x10  /*  MOE=0 ʱһOC7=0 */
#define PWMB_OC7_OUT_1()          PWMB_OISR |= 0x10    /*  MOE=0 ʱһOC7=1 */
#define PWMB_OC8_OUT_0()          PWMB_OISR &= ~0x40  /*  MOE=0 ʱһOC8=0 */
#define PWMB_OC8_OUT_1()          PWMB_OISR |= 0x40    /*  MOE=0 ʱһOC8=1 */

//========================================================================
//                              
//========================================================================

#define ENO1P       0x01
#define ENO1N       0x02
#define ENO2P       0x04
#define ENO2N       0x08
#define ENO3P       0x10
#define ENO3N       0x20
#define ENO4P       0x40
#define ENO4N       0x80

#define ENO5P       0x01
#define ENO6P       0x04
#define ENO7P       0x10
#define ENO8P       0x40

#define  PWM1  1
#define  PWM2  2
#define  PWM3  3
#define  PWM4  4
#define  PWM5  5
#define  PWM6  6
#define  PWM7  7
#define  PWM8  8

#define  PWMA  9
#define  PWMB  10

#define PWM_BIE     0x80
#define PWM_TIE     0x40
#define PWM_COMIE   0x20
#define PWM_CC4IE   0x10
#define PWM_CC3IE   0x08
#define PWM_CC2IE   0x04
#define PWM_CC1IE   0x02
#define PWM_CC8IE   0x10
#define PWM_CC7IE   0x08
#define PWM_CC6IE   0x04
#define PWM_CC5IE   0x02
#define PWM_UIE     0x01

typedef struct
{ 
  u8  PWM_Mode;      //ģʽ,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
  u16  PWM_Period;    //ʱ,   0~65535
  u16  PWM_Duty;      //ռձʱ, 0~Period
  u8  PWM_DeadTime;  //, 0~255
//  u8  PWM_Reload;        //ȽϵԤװʹ,   ENABLE,DISABLE
//  u8  PWM_Fast;          //ȽϿٹʹ,   ENABLE,DISABLE
//  u8  PWM_PreLoad;      //Ԥװ,     ENABLE,DISABLE
//  u8  PWM_BrakeEnable;  //ɲʹ,  ENABLE,DISABLE
  u8  PWM_EnoSelect;    //ͨѡ,  ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
  u8  PWM_CEN_Enable;    //ʹܼ, ENABLE,DISABLE
  u8  PWM_MainOutEnable;//ʹ,  ENABLE,DISABLE
} PWMx_InitDefine; 

typedef struct
{ 
  u16  PWM1_Duty;      //PWM1ռձʱ, 0~Period
  u16  PWM2_Duty;      //PWM2ռձʱ, 0~Period
  u16  PWM3_Duty;      //PWM3ռձʱ, 0~Period
  u16  PWM4_Duty;      //PWM4ռձʱ, 0~Period
  u16  PWM5_Duty;      //PWM5ռձʱ, 0~Period
  u16  PWM6_Duty;      //PWM6ռձʱ, 0~Period
  u16  PWM7_Duty;      //PWM7ռձʱ, 0~Period
  u16  PWM8_Duty;      //PWM8ռձʱ, 0~Period
} PWMx_Duty; 

typedef struct
{ 
//  u8  PWM_Mode;      //ģʽ,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
  u16  PWM_Period;    //ʱ,   0~65535
  u8  PWM_DeadTime;  //, 0~255
  u8  PWM_EnoSelect;    //ͨѡ,  ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
  u8  PWM_CEN_Enable;    //ʹܼ, ENABLE,DISABLE
  u8  PWM_MainOutEnable;//ʹ,  ENABLE,DISABLE
} HSPWMx_InitDefine; 


u8  PWM_Configuration(u8 PWM, PWMx_InitDefine *PWMx);
void UpdatePwm(u8 PWM, PWMx_Duty *PWMx);

void HSPWM_Configuration(u8 PWM, HSPWMx_InitDefine *PWMx, PWMx_Duty *DUTYx);
void UpdateHSPwm(u8 PWM, PWMx_Duty *PWMx);

#endif


#endif /* _4_DMA_STC32G_4_DMA_STC32G_LIBRARY_STC32G_PWM_H_ */
