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
/* Èç¹ûÒªÔÚ³ÌÐòÖÐÊ¹ÓÃ´Ë´úÂë,ÇëÔÚ³ÌÐòÖÐ×¢Ã÷Ê¹ÓÃÁËSTCµÄ×ÊÁÏ¼°³ÌÐò            */
/*---------------------------------------------------------------------*/

#ifndef __STC32G_PWM_H
#define __STC32G_PWM_H   

#include  "config.h"

//========================================================================
//                               PWMÉèÖÃ
//========================================================================

//                           7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_ENO = 0xFEB1H;  ENO4N ENO4P ENO3N ENO3P ENO2N ENO2P ENO1N ENO1P  0000,0000  /* Êä³öÊ¹ÄÜ¼Ä´æÆ÷ */ 
//sfr PWMB_ENO = 0xFEB5H;    -   ENO8P   -   ENO7P   -   ENO6P   -   ENO5P  0000,0000  /* Êä³öÊ¹ÄÜ¼Ä´æÆ÷ */ 
#define    PWM1P_OUT_EN()  PWMA_ENO |= 0x01  /* Ê¹ÄÜ PWM1P Êä³ö */
#define    PWM1P_OUT_DIS()  PWMA_ENO &= ~0x01  /* ½ûÖ¹ PWM1P Êä³ö */
#define    PWM1N_OUT_EN()  PWMA_ENO |= 0x02  /* Ê¹ÄÜ PWM1N Êä³ö */
#define    PWM1N_OUT_DIS()  PWMA_ENO &= ~0x02  /* ½ûÖ¹ PWM1N Êä³ö */
#define    PWM2P_OUT_EN()  PWMA_ENO |= 0x04  /* Ê¹ÄÜ PWM2P Êä³ö */
#define    PWM2P_OUT_DIS()  PWMA_ENO &= ~0x04  /* ½ûÖ¹ PWM2P Êä³ö */
#define    PWM2N_OUT_EN()  PWMA_ENO |= 0x08  /* Ê¹ÄÜ PWM2N Êä³ö */
#define    PWM2N_OUT_DIS()  PWMA_ENO &= ~0x08  /* ½ûÖ¹ PWM2N Êä³ö */
#define    PWM3P_OUT_EN()  PWMA_ENO |= 0x10  /* Ê¹ÄÜ PWM3P Êä³ö */
#define    PWM3P_OUT_DIS()  PWMA_ENO &= ~0x10  /* ½ûÖ¹ PWM3P Êä³ö */
#define    PWM3N_OUT_EN()  PWMA_ENO |= 0x20  /* Ê¹ÄÜ PWM3N Êä³ö */
#define    PWM3N_OUT_DIS()  PWMA_ENO &= ~0x20  /* ½ûÖ¹ PWM3N Êä³ö */
#define    PWM4P_OUT_EN()  PWMA_ENO |= 0x40  /* Ê¹ÄÜ PWM3P Êä³ö */
#define    PWM4P_OUT_DIS()  PWMA_ENO &= ~0x40  /* ½ûÖ¹ PWM3P Êä³ö */
#define    PWM4N_OUT_EN()  PWMA_ENO |= 0x80  /* Ê¹ÄÜ PWM3N Êä³ö */
#define    PWM4N_OUT_DIS()  PWMA_ENO &= ~0x80  /* ½ûÖ¹ PWM3N Êä³ö */

#define    PWM5P_OUT_EN()  PWMB_ENO |= 0x01  /* Ê¹ÄÜ PWM5P Êä³ö */
#define    PWM5P_OUT_DIS()  PWMB_ENO &= ~0x01  /* ½ûÖ¹ PWM5P Êä³ö */
#define    PWM6P_OUT_EN()  PWMB_ENO |= 0x04  /* Ê¹ÄÜ PWM6P Êä³ö */
#define    PWM6P_OUT_DIS()  PWMB_ENO &= ~0x04  /* ½ûÖ¹ PWM6P Êä³ö */
#define    PWM7P_OUT_EN()  PWMB_ENO |= 0x10  /* Ê¹ÄÜ PWM7P Êä³ö */
#define    PWM7P_OUT_DIS()  PWMB_ENO &= ~0x10  /* ½ûÖ¹ PWM7P Êä³ö */
#define    PWM8P_OUT_EN()  PWMB_ENO |= 0x40  /* Ê¹ÄÜ PWM8P Êä³ö */
#define    PWM8P_OUT_DIS()  PWMB_ENO &= ~0x40  /* ½ûÖ¹ PWM8P Êä³ö */

#define    PWMA_OutChannelSel(n)    PWMA_ENO = n  //Ñ¡ÔñÊä³öÍ¨µÀ
#define    PWMB_OutChannelSel(n)    PWMB_ENO = n  //Ñ¡ÔñÊä³öÍ¨µÀ

//                          7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_PS = 0xFEB2H;  C4PS1 C4PS0 C3PS1 C3PS0 C2PS1 C2PS0 C1PS1 C1PS0  0000,0000  /* Êä³öÊ¹ÄÜ¼Ä´æÆ÷ */ 
//sfr PWMB_PS = 0xFEB6H;  C8PS1 C8PS0 C7PS1 C7PS0 C6PS1 C6PS0 C5PS1 C5PS0  0000,0000  /* Êä³öÊ¹ÄÜ¼Ä´æÆ÷ */ 

#define    PWM1_USE_P10P11()    PWMA_PS = (PWMA_PS & ~0x03)        /* PWM Í¨µÀ 1 Êä³ö½ÅÇÐ»»µ½P10(PWM1P) P11(PWM1N) */ 
#define    PWM1_USE_P20P21()    PWMA_PS = (PWMA_PS & ~0x03) | 0x01  /* PWM Í¨µÀ 1 Êä³ö½ÅÇÐ»»µ½P20(PWM1P) P21(PWM1N) */ 
#define    PWM1_USE_P60P61()    PWMA_PS = (PWMA_PS & ~0x03) | 0x02  /* PWM Í¨µÀ 1 Êä³ö½ÅÇÐ»»µ½P60(PWM1P) P61(PWM1N) */ 

#define    PWM2_USE_P12P13()    PWMA_PS = (PWMA_PS & ~0x0C)          /* PWM Í¨µÀ 2 Êä³ö½ÅÇÐ»»µ½P12/P54(PWM2P) P13(PWM2N) */ 
#define    PWM2_USE_P22P23()    PWMA_PS = (PWMA_PS & ~0x0C) | 0x04  /* PWM Í¨µÀ 2 Êä³ö½ÅÇÐ»»µ½P22(PWM2P) P23(PWM2N) */ 
#define    PWM2_USE_P62P63()    PWMA_PS = (PWMA_PS & ~0x0C) | 0x08  /* PWM Í¨µÀ 2 Êä³ö½ÅÇÐ»»µ½P62(PWM2P) P63(PWM2N) */ 

#define    PWM3_USE_P14P15()    PWMA_PS = (PWMA_PS & ~0x30)          /* PWM Í¨µÀ 3 Êä³ö½ÅÇÐ»»µ½P14(PWM3P) P15(PWM3N) */ 
#define    PWM3_USE_P24P25()    PWMA_PS = (PWMA_PS & ~0x30) | 0x10  /* PWM Í¨µÀ 3 Êä³ö½ÅÇÐ»»µ½P24(PWM3P) P25(PWM3N) */ 
#define    PWM3_USE_P64P65()    PWMA_PS = (PWMA_PS & ~0x30) | 0x20  /* PWM Í¨µÀ 3 Êä³ö½ÅÇÐ»»µ½P64(PWM3P) P65(PWM3N) */ 

#define    PWM4_USE_P16P17()    PWMA_PS = (PWMA_PS & ~0xC0)          /* PWM Í¨µÀ 4 Êä³ö½ÅÇÐ»»µ½P16(PWM4P) P17(PWM4N) */ 
#define    PWM4_USE_P26P27()    PWMA_PS = (PWMA_PS & ~0xC0) | 0x40  /* PWM Í¨µÀ 4 Êä³ö½ÅÇÐ»»µ½P26(PWM4P) P27(PWM4N) */ 
#define    PWM4_USE_P66P67()    PWMA_PS = (PWMA_PS & ~0xC0) | 0x80  /* PWM Í¨µÀ 4 Êä³ö½ÅÇÐ»»µ½P66(PWM4P) P67(PWM4N) */ 
#define    PWM4_USE_P34P33()    PWMA_PS = (PWMA_PS | 0xC0)          /* PWM Í¨µÀ 4 Êä³ö½ÅÇÐ»»µ½P34(PWM4P) P33(PWM4N) */ 

#define    PWM5_USE_P20()      PWMB_PS = (PWMB_PS & ~0x03)          /* PWM Í¨µÀ 5 Êä³ö½ÅÇÐ»»µ½P20(PWM5) */ 
#define    PWM5_USE_P17()      PWMB_PS = (PWMB_PS & ~0x03) | 0x01  /* PWM Í¨µÀ 5 Êä³ö½ÅÇÐ»»µ½P17(PWM5) */ 
#define    PWM5_USE_P00()      PWMB_PS = (PWMB_PS & ~0x03) | 0x02  /* PWM Í¨µÀ 5 Êä³ö½ÅÇÐ»»µ½P00(PWM5) */ 
#define    PWM5_USE_P74()      PWMB_PS = (PWMB_PS | 0x03)          /* PWM Í¨µÀ 5 Êä³ö½ÅÇÐ»»µ½P74(PWM5) */ 

#define    PWM6_USE_P21()      PWMB_PS = (PWMB_PS & ~0x0C)          /* PWM Í¨µÀ 6 Êä³ö½ÅÇÐ»»µ½P21(PWM6) */ 
#define    PWM6_USE_P54()      PWMB_PS = (PWMB_PS & ~0x0C) | 0x04  /* PWM Í¨µÀ 6 Êä³ö½ÅÇÐ»»µ½P54(PWM6) */ 
#define    PWM6_USE_P01()      PWMB_PS = (PWMB_PS & ~0x0C) | 0x08  /* PWM Í¨µÀ 6 Êä³ö½ÅÇÐ»»µ½P01(PWM6) */ 
#define    PWM6_USE_P75()      PWMB_PS = (PWMB_PS | 0x0C)          /* PWM Í¨µÀ 6 Êä³ö½ÅÇÐ»»µ½P75(PWM6) */ 

#define    PWM7_USE_P22()      PWMB_PS = (PWMB_PS & ~0x30)          /* PWM Í¨µÀ 7 Êä³ö½ÅÇÐ»»µ½P22(PWM7) */ 
#define    PWM7_USE_P33()      PWMB_PS = (PWMB_PS & ~0x30) | 0x10  /* PWM Í¨µÀ 7 Êä³ö½ÅÇÐ»»µ½P33(PWM7) */ 
#define    PWM7_USE_P02()      PWMB_PS = (PWMB_PS & ~0x30) | 0x20  /* PWM Í¨µÀ 7 Êä³ö½ÅÇÐ»»µ½P02(PWM7) */ 
#define    PWM7_USE_P76()      PWMB_PS = (PWMB_PS | 0x30)          /* PWM Í¨µÀ 7 Êä³ö½ÅÇÐ»»µ½P76(PWM7) */ 

#define    PWM8_USE_P23()      PWMB_PS = (PWMB_PS & ~0xC0)          /* PWM Í¨µÀ 8 Êä³ö½ÅÇÐ»»µ½P23(PWM8) */ 
#define    PWM8_USE_P34()      PWMB_PS = (PWMB_PS & ~0xC0) | 0x40  /* PWM Í¨µÀ 8 Êä³ö½ÅÇÐ»»µ½P34(PWM8) */ 
#define    PWM8_USE_P03()      PWMB_PS = (PWMB_PS & ~0xC0) | 0x80  /* PWM Í¨µÀ 8 Êä³ö½ÅÇÐ»»µ½P03(PWM8) */ 
#define    PWM8_USE_P77()      PWMB_PS = (PWMB_PS | 0xC0)          /* PWM Í¨µÀ 8 Êä³ö½ÅÇÐ»»µ½P77(PWM8) */ 

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_IOAUX = 0xFEB3H;  AUX4N AUX4P AUX3N AUX3P AUX2N AUX2P AUX1N AUX1P  0000,0000  /* Êä³ö¸½¼ÓÊ¹ÄÜ¼Ä´æÆ÷ */ 
//sfr PWMB_IOAUX = 0xFEB7H;    -   AUX8P   -   AUX7P   -   AUX6P   -   AUX5P  0000,0000  /* Êä³ö¸½¼ÓÊ¹ÄÜ¼Ä´æÆ÷ */ 
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
//sfr PWMA_CR1 = 0xFEC0H;  ARPEA CMSA1 CMSA0 DIRA OPMA URSA UDISA CENA  0000,0000  /* ¿ØÖÆ¼Ä´æÆ÷ 1 */ 
//sfr PWMB_CR1 = 0xFEE0H;  ARPEB CMSB1 CMSB0 DIRB OPMB URSB UDISB CENB  0000,0000  /* ¿ØÖÆ¼Ä´æÆ÷ 1 */ 
#define ARPE1      (1<<7)
#define ARPE2      (1<<7)
#define PWMA_AlignMode_Edge()      PWMA_CR1 = (PWMA_CR1 & ~0x60)
#define PWMA_AlignMode_Mid1()      PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x20
#define PWMA_AlignMode_Mid2()      PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x40
#define PWMA_AlignMode_Mid3()      PWMA_CR1 = (PWMA_CR1 | 0x60)
#define PWMA_DIR_UP()              PWMA_CR1 &= ~0x10
#define PWMA_DIR_DN()              PWMA_CR1 |= 0x10
#define PWMA_OPMA(n)              (n==1?(PWMA_CR1 |= 0x08):(PWMA_CR1 &= ~0x08))  //µ¥Âö³åÄ£Ê½ 0£ºÔÚ·¢Éú¸üÐÂÊÂ¼þÊ±£¬¼ÆÊýÆ÷²»Í£Ö¹£»1£ºÔÚ·¢ÉúÏÂÒ»´Î¸üÐÂÊÂ¼þÊ±£¬Çå³ý CEN Î»£¬¼ÆÊýÆ÷Í£Ö¹
#define PWMA_URSA(n)              (n==1?(PWMA_CR1 |= 0x04):(PWMA_CR1 &= ~0x04))  //¸üÐÂÇëÇóÔ´
#define PWMA_UDISA(n)              (n==1?(PWMA_CR1 |= 0x02):(PWMA_CR1 &= ~0x02))  //½ûÖ¹¸üÐÂ 0£º²úÉú¸üÐÂ£¨UEV£©ÊÂ¼þ£»1£º²»²úÉú¸üÐÂÊÂ¼þ
//#define PWMA_CEN_Enable()          PWMA_CR1 |= 0x01    //1£ºÊ¹ÄÜ¼ÆÊýÆ÷
#define PWMA_CEN_Disable()        PWMA_CR1 &= ~0x01    //0£º½ûÖ¹¼ÆÊýÆ÷
#define PWMA_CEN_Enable(n)        (n==1?(PWMA_CR1 |= 0x01):(PWMA_CR1 &= ~0x01))    //1£ºÊ¹ÄÜ¼ÆÊýÆ÷

#define PWMB_AlignMode_Edge()      PWMB_CR1 = (PWMB_CR1 & ~0x60)
#define PWMB_AlignMode_Mid1()      PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x20
#define PWMB_AlignMode_Mid2()      PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x40
#define PWMB_AlignMode_Mid3()      PWMB_CR1 = (PWMB_CR1 | 0x60)
#define PWMB_DIR_UP()              PWMB_CR1 &= ~0x10
#define PWMB_DIR_DN()              PWMB_CR1 |= 0x10
#define PWMB_OPMB(n)              (n==1?(PWMB_CR1 |= 0x08):(PWMB_CR1 &= ~0x08))  //µ¥Âö³åÄ£Ê½ 0£ºÔÚ·¢Éú¸üÐÂÊÂ¼þÊ±£¬¼ÆÊýÆ÷²»Í£Ö¹£»1£ºÔÚ·¢ÉúÏÂÒ»´Î¸üÐÂÊÂ¼þÊ±£¬Çå³ý CEN Î»£¬¼ÆÊýÆ÷Í£Ö¹
#define PWMB_URSB(n)              (n==1?(PWMB_CR1 |= 0x04):(PWMB_CR1 &= ~0x04))  //¸üÐÂÇëÇóÔ´
#define PWMB_UDISB(n)              (n==1?(PWMB_CR1 |= 0x02):(PWMB_CR1 &= ~0x02))  //½ûÖ¹¸üÐÂ 0£º²úÉú¸üÐÂ£¨UEV£©ÊÂ¼þ£»1£º²»²úÉú¸üÐÂÊÂ¼þ
//#define PWMB_CEN_Enable()          PWMB_CR1 |= 0x01    //1£ºÊ¹ÄÜ¼ÆÊýÆ÷
#define PWMB_CEN_Disable()        PWMB_CR1 &= ~0x01    //0£º½ûÖ¹¼ÆÊýÆ÷
#define PWMB_CEN_Enable(n)        (n==1?(PWMB_CR1 |= 0x01):(PWMB_CR1 &= ~0x01))    //1£ºÊ¹ÄÜ¼ÆÊýÆ÷


//                           7     6     5    4    3    2    1    0    Reset Value
//sfr PWMA_CR2 = 0xFEC1H;  TI1S MMSA2 MMSA1 MMSA0  -  COMSA  -  CCPCA  0000,x0x0  /* ¿ØÖÆ¼Ä´æÆ÷ 2 */ 
//sfr PWMB_CR2 = 0xFEE1H;  TI5S MMSB2 MMSB1 MMSB0  -  COMSB  -  CCPCB  0000,x0xx  /* ¿ØÖÆ¼Ä´æÆ÷ 2 */ 
#define PWM1P_TI1()              PWMA_CR2 &= ~0x80
#define PWM1P2P3P_XOR_TI1()      PWMA_CR2 |= 0x80
#define PWM5P_TI2()              PWMB_CR2 &= ~0x80
#define PWM5P6P7P_XOR_TI2()      PWMB_CR2 |= 0x80

#define MMSn_RESET          0    //¸´Î»
#define MMSn_ENABLE          1    //Ê¹ÄÜ
#define MMSn_UPDATE          2    //¸üÐÂ
#define MMSn_COMP_TRGO      3    //±È½ÏÂö³å
#define MMSn_OC1REF_TRGO    4    //±È½Ï
#define MMSn_OC2REF_TRGO    5    //±È½Ï
#define MMSn_OC3REF_TRGO    6    //±È½Ï
#define MMSn_OC4REF_TRGO    7    //±È½Ï

#define PWMA_MainModeSel(n)    PWMA_CR2 = (PWMA_CR2 & ~0x70) | (n<<4)  //Ö÷Ä£Ê½Ñ¡Ôñ
#define PWMB_MainModeSel(n)    PWMB_CR2 = (PWMB_CR2 & ~0x70) | (n<<4)  //Ö÷Ä£Ê½Ñ¡Ôñ

//0£ºµ± CCPC=1 Ê±£¬Ö»ÓÐÔÚ COMG Î»ÖÃ 1 µÄÊ±ºòÕâÐ©¿ØÖÆÎ»²Å±»¸üÐÂ
//1£ºµ± CCPC=1 Ê±£¬Ö»ÓÐÔÚ COMG Î»ÖÃ 1 »ò TRGI ·¢ÉúÉÏÉýÑØµÄÊ±ºòÕâÐ©¿ØÖÆÎ»²Å±»¸üÐÂ
#define PWMA_COMSUpdateCtrl(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x04):(PWMA_CR2 &= ~0x04))  //²¶»ñ/±È½Ï¿ØÖÆÎ»µÄ¸üÐÂ¿ØÖÆÑ¡Ôñ
#define PWMB_COMSUpdateCtrl(n)    PWMB_CR2 = (n==1?(PWMB_CR2 |= 0x04):(PWMB_CR2 &= ~0x04))  //²¶»ñ/±È½Ï¿ØÖÆÎ»µÄ¸üÐÂ¿ØÖÆÑ¡Ôñ
//0£º CCIE£¬ CCINE£¬ CCiP£¬ CCiNP ºÍ OCIM Î»²»ÊÇÔ¤×°ÔØµÄ
//1£º CCIE£¬ CCINE£¬ CCiP£¬ CCiNP ºÍ OCIM Î»ÊÇÔ¤×°ÔØµÄ£»ÉèÖÃ¸ÃÎ»ºó£¬ËüÃÇÖ»ÔÚÉèÖÃÁË COMGÎ»ºó±»¸üÐÂ¡£
#define PWMA_CCPCAPreloaded(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x01):(PWMA_CR2 &= ~0x01))  //²¶»ñ/±È½ÏÔ¤×°ÔØ¿ØÖÆÎ»(¸ÃÎ»Ö»¶Ô¾ßÓÐ»¥²¹Êä³öµÄÍ¨µÀÆð×÷ÓÃ)
#define PWMB_CCPCBPreloaded(n)    PWMA_CR2 = (n==1?(PWMA_CR2 |= 0x01):(PWMA_CR2 &= ~0x01))  //²¶»ñ/±È½ÏÔ¤×°ÔØ¿ØÖÆÎ»(¸ÃÎ»Ö»¶Ô¾ßÓÐ»¥²¹Êä³öµÄÍ¨µÀÆð×÷ÓÃ)


//                           7    6    5    4    3    2     1     0    Reset Value
//sfr PWMA_SMCR = 0xFEC2H;  MSMA TSA2 TSA1 TSA0  -  SMSA2 SMSA1 SMSA0  0000,x000  /* ´ÓÄ£Ê½¿ØÖÆ¼Ä´æÆ÷ */ 
//sfr PWMB_SMCR = 0xFEE2H;  MSMB TSB2 TSB1 TSB0  -  SMSB2 SMSB1 SMSB0  0000,x000  /* ´ÓÄ£Ê½¿ØÖÆ¼Ä´æÆ÷ */ 
#define SMCR_TSn_ITR2        2
#define SMCR_TSn_EDGE        4
#define SMCR_TSn_TIMER1      5
#define SMCR_TSn_TIMER2      6
#define SMCR_TSn_ETRF        7

#define PWMA_SMCR_Source(n)    PWMA_SMCR = (PWMA_SMCR & ~0x70) | (n<<4)  //´¥·¢Ô´Ñ¡Ôñ
#define PWMB_SMCR_Source(n)    PWMB_SMCR = (PWMB_SMCR & ~0x70) | (n<<4)  //´¥·¢Ô´Ñ¡Ôñ

#define SMCR_SMSA_INSIDE_CLK      0
#define SMCR_SMSA_ENCODER_M1      1
#define SMCR_SMSA_ENCODER_M2      2
#define SMCR_SMSA_ENCODER_M3      3
#define SMCR_SMSA_RESET            4
#define SMCR_SMSA_GATE            5
#define SMCR_SMSA_TRIG            6
#define SMCR_SMSA_EXT_CLK          7

#define PWMA_SMCR_SMS(n)    PWMA_SMCR = (PWMA_SMCR & ~0x07) | (n & 7)  //Ê±ÖÓ/´¥·¢/´ÓÄ£Ê½Ñ¡Ôñ
#define PWMB_SMCR_SMS(n)    PWMB_SMCR = (PWMB_SMCR & ~0x07) | (n & 7)  //Ê±ÖÓ/´¥·¢/´ÓÄ£Ê½Ñ¡Ôñ

//                           7    6    5      4     3     2     1     0     Reset Value
//sfr PWMA_ETR = 0xFEC3H;  ETP1 ECE1 ETPS11 ETPS10 ETF13 ETF12 ETF11 ETF10  0000,0000  /* Íâ²¿´¥·¢¼Ä´æÆ÷ */ 
//sfr PWMB_ETR = 0xFEE3H;  ETP2 ECE2 ETPS21 ETPS20 ETF23 ETF22 ETF21 ETF20  0000,0000  /* Íâ²¿´¥·¢¼Ä´æÆ÷ */ 

//                           7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_IER = 0xFEC4H;  BIEA TIEA COMIEA CC4IE CC3IE CC2IE CC1IE UIEA  0000,0000  /* ÖÐ¶ÏÊ¹ÄÜ¼Ä´æÆ÷ */ 
//sfr PWMB_IER = 0xFEE4H;  BIEB TIEB COMIEB CC8IE CC7IE CC6IE CC5IE UIEB  0000,0000  /* ÖÐ¶ÏÊ¹ÄÜ¼Ä´æÆ÷ */ 
#define PWMA_UIEA_Enable()    PWMA_IER |= 0x01    //1£ºÔÊÐí¸üÐÂÖÐ¶Ï
#define PWMA_UIEA_Disable()    PWMA_IER &= ~0x01    //0£º½ûÖ¹¸üÐÂÖÐ¶Ï
#define PWMA_CC1IE_Enable()    PWMA_IER |= 0x02    //1£ºÔÊÐí²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC1IE_Disable()  PWMA_IER &= ~0x02    //0£º½ûÖ¹²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC2IE_Enable()    PWMA_IER |= 0x04    //1£ºÔÊÐí²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC2IE_Disable()  PWMA_IER &= ~0x04    //0£º½ûÖ¹²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC3IE_Enable()    PWMA_IER |= 0x08    //1£ºÔÊÐí²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC3IE_Disable()  PWMA_IER &= ~0x08    //0£º½ûÖ¹²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC4IE_Enable()    PWMA_IER |= 0x10    //1£ºÔÊÐí²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_CC4IE_Disable()  PWMA_IER &= ~0x10    //0£º½ûÖ¹²¶»ñ/±È½ÏÖÐ¶Ï
#define PWMA_COMIEA_Enable()  PWMA_IER |= 0x20    //1£ºÔÊÐíCOMÖÐ¶Ï
#define PWMA_COMIEA_Disable()  PWMA_IER &= ~0x20    //0£º½ûÖ¹COMÖÐ¶Ï
#define PWMA_TIEA_Enable()    PWMA_IER |= 0x40    //1£ºÔÊÐí´¥·¢ÖÐ¶Ï
#define PWMA_TIEA_Disable()    PWMA_IER &= ~0x40    //0£º½ûÖ¹´¥·¢ÖÐ¶Ï
#define PWMA_BIEA_Enable()    PWMA_IER |= 0x80    //1£ºÔÊÐíÉ²³µÖÐ¶Ï
#define PWMA_BIEA_Disable()    PWMA_IER &= ~0x80    //0£º½ûÖ¹É²³µÖÐ¶Ï

//                           7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_SR1 = 0xFEC5H;  BIF1 TIF1 COMIF1 CC4IF CC3IF CC2IF CC1IF UIF1  0000,0000  /* ×´Ì¬¼Ä´æÆ÷ 1 */ 
//sfr PWMB_SR1 = 0xFEE5H;  BIF2 TIF2 COMIF2 CC8IF CC7IF CC6IF CC5IF UIF2  0000,0000  /* ×´Ì¬¼Ä´æÆ÷ 1 */ 
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
//sfr PWMA_SR2 = 0xFEC6H;   -   -   -  CC4OF CC3OF CC2OF CC1OF  -   xxx0,000x  /* ×´Ì¬¼Ä´æÆ÷ 2 */ 
//sfr PWMB_SR2 = 0xFEE6H;   -   -   -  CC8OF CC7OF CC6OF CC5OF  -   xxx0,000x  /* ×´Ì¬¼Ä´æÆ÷ 2 */ 

//                          7   6    5    4    3    2    1    0   Reset Value
//sfr PWMA_EGR = 0xFEC7H;  BG1 TG1 COMG1 CC4G CC3G CC2G CC1G UG1  0000,0000  /* ÊÂ¼þ²úÉú¼Ä´æÆ÷ */ 
//sfr PWMB_EGR = 0xFEE7H;  BG2 TG2 COMG2 CC8G CC7G CC6G CC5G UG2  0000,0000  /* ÊÂ¼þ²úÉú¼Ä´æÆ÷ */ 

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  OC1CE OC1M2 OC1M1 OC1M0 OC1PE OC1FE CC1S1 CC1S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 1 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  OC5CE OC5M2 OC5M1 OC5M0 OC5PE OC5FE CC5S1 CC5S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 1 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 
#define OCnCE      (1<<7)

#define CCMRn_FREEZE              0x00    //¶³½á
#define CCMRn_MATCH_VALID          0x10    //Æ¥ÅäÊ±ÉèÖÃÍ¨µÀ n µÄÊä³öÎªÓÐÐ§µçÆ½
#define CCMRn_MATCH_INVALID        0x20    //Æ¥ÅäÊ±ÉèÖÃÍ¨µÀ n µÄÊä³öÎªÎÞÐ§µçÆ½
#define CCMRn_ROLLOVER            0x30    //·­×ª
#define CCMRn_FORCE_INVALID        0x40    //Ç¿ÖÆÎªÎÞÐ§µçÆ½
#define CCMRn_FORCE_VALID          0x50    //Ç¿ÖÆÎªÓÐÐ§µçÆ½
#define CCMRn_PWM_MODE1            0x60    //PWM Ä£Ê½ 1
#define CCMRn_PWM_MODE2            0x70    //PWM Ä£Ê½ 2

#define PWMA_OC1ModeSet(n)        PWMA_CCMR1 = (PWMA_CCMR1 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ
#define PWMB_OC5ModeSet(n)        PWMB_CCMR1 = (PWMB_CCMR1 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ

#define PWMA_OC1_ReloadEnable(n)  (n==1?(PWMA_CCMR1 |= 0x08):(PWMA_CCMR1 &= ~0x08))    //¿ªÆô OC1PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC5_ReloadEnable(n)  (n==1?(PWMB_CCMR1 |= 0x08):(PWMB_CCMR1 &= ~0x08))    //¿ªÆô OC5PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
//#define PWMA_OC1_ReloadEnable()    PWMA_CCMR1 |= 0x08    //1£º¿ªÆô OC1PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
//#define PWMA_OC1_RelosdDisable()  PWMA_CCMR1 &= ~0x08    //0£º½ûÖ¹ OC1PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
//#define PWMB_OC5_ReloadEnable()    PWMB_CCMR1 |= 0x08    //1£º¿ªÆô OC5PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
//#define PWMB_OC5_RelosdDisable()  PWMB_CCMR1 &= ~0x08    //0£º½ûÖ¹ OC5PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ

#define PWMA_OC1_FastEnable(n)    (n==1?(PWMA_CCMR1 |= 0x04):(PWMA_CCMR1 &= ~0x04))    //1£º¿ªÆô OC1FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC5_FastEnable(n)    (n==1?(PWMB_CCMR1 |= 0x04):(PWMB_CCMR1 &= ~0x04))    //1£º¿ªÆô OC5FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
//#define PWMA_OC1_FastEnable()      PWMA_CCMR1 |= 0x04    //1£º¿ªÆô OC1FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
//#define PWMA_OC1_FastDisable()    PWMA_CCMR1 &= ~0x04    //0£º½ûÖ¹ OC1FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
//#define PWMB_OC5_FastEnable()      PWMB_CCMR1 |= 0x04    //1£º¿ªÆô OC5FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
//#define PWMB_OC5_FastDisable()    PWMB_CCMR1 &= ~0x04    //0£º½ûÖ¹ OC5FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ

#define CCAS_OUTPUT            0x00    //Êä³ö
#define CCAS_IUTPUT_TI1FP1    0x01    //ÊäÈë£¬IC1/IC2/IC3/IC4 Ó³ÉäÔÚ TI1FP1 ÉÏ
#define CCAS_IUTPUT_TI2FP1    0x02    //ÊäÈë£¬IC1/IC2/IC3/IC4 Ó³ÉäÔÚ TI2FP1 ÉÏ
#define CCAS_IUTPUT_TRC        0x03    //ÊäÈë£¬IC1/IC2/IC3/IC4 Ó³ÉäÔÚ TRC ÉÏ
#define CCBS_OUTPUT            0x00    //Êä³ö
#define CCBS_IUTPUT_TI5FP5    0x01    //ÊäÈë£¬IC5/IC6/IC7/IC8 Ó³ÉäÔÚ TI5FP5 ÉÏ
#define CCBS_IUTPUT_TI6FP5    0x02    //ÊäÈë£¬IC5/IC6/IC7/IC8 Ó³ÉäÔÚ TI6FP5 ÉÏ
#define CCBS_IUTPUT_TRC        0x03    //ÊäÈë£¬IC5/IC6/IC7/IC8 Ó³ÉäÔÚ TRC ÉÏ

#define PWMA_CC1S_Direction(n)    PWMA_CCMR1 = (PWMA_CCMR1 & ~0x03) | (n)    //²¶»ñ/±È½Ï 1 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ
#define PWMB_CC5S_Direction(n)    PWMB_CCMR1 = (PWMB_CCMR1 & ~0x03) | (n)    //²¶»ñ/±È½Ï 5 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  IC1F3 IC1F2 IC1F1 IC1F0 IC1PSC1 IC1PSC0 CC1S1 CC1S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 1 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  IC5F3 IC5F2 IC5F1 IC5F0 IC5PSC1 IC5PSC0 CC5S1 CC5S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 1 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 

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

#define PWMA_IC1F_FilterClock(n)  PWMA_CCMR1 = (PWMA_CCMR1 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 1 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È
#define PWMB_IC5F_FilterClock(n)  PWMB_CCMR1 = (PWMB_CCMR1 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 5 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È

#define PWMA_IC1PSC_PrescalerSet(n)    PWMA_CCMR1 = (PWMA_CCMR1 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 1 Ô¤·ÖÆµÆ÷£¬0~3
#define PWMB_IC5PSC_PrescalerSet(n)    PWMB_CCMR1 = (PWMB_CCMR1 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 5 Ô¤·ÖÆµÆ÷£¬0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  OC2CE OC2M2 OC2M1 OC2M0 OC2PE OC2FE CC2S1 CC2S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 2 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  OC6CE OC6M2 OC6M1 OC6M0 OC6PE OC6FE CC6S1 CC6S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 2 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 

#define PWMA_OC2ModeSet(n)        PWMA_CCMR2 = (PWMA_CCMR2 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ
#define PWMB_OC6ModeSet(n)        PWMB_CCMR2 = (PWMB_CCMR2 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ

#define PWMA_OC2_ReloadEnable()    PWMA_CCMR2 |= 0x08    //1£º¿ªÆô OC2PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMA_OC2_RelosdDisable()  PWMA_CCMR2 &= ~0x08    //0£º½ûÖ¹ OC2PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC6_ReloadEnable()    PWMB_CCMR2 |= 0x08    //1£º¿ªÆô OC6PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC6_RelosdDisable()  PWMB_CCMR2 &= ~0x08    //0£º½ûÖ¹ OC6PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ

#define PWMA_OC2_FastEnable()      PWMA_CCMR2 |= 0x04    //1£º¿ªÆô OC2FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMA_OC2_FastDisable()    PWMA_CCMR2 &= ~0x04    //0£º½ûÖ¹ OC2FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC6_FastEnable()      PWMB_CCMR2 |= 0x04    //1£º¿ªÆô OC6FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC6_FastDisable()    PWMB_CCMR2 &= ~0x04    //0£º½ûÖ¹ OC6FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ

#define PWMA_CC2S_Direction(n)    PWMA_CCMR2 = (PWMA_CCMR2 & ~0x03) | (n)    //²¶»ñ/±È½Ï 2 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ
#define PWMB_CC6S_Direction(n)    PWMB_CCMR2 = (PWMB_CCMR2 & ~0x03) | (n)    //²¶»ñ/±È½Ï 6 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  IC2F3 IC2F2 IC2F1 IC2F0 IC2PSC1 IC2PSC0 CC2S1 CC2S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 2 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  IC6F3 IC6F2 IC6F1 IC6F0 IC6PSC1 IC6PSC0 CC6S1 CC6S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 2 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 

#define PWMA_IC2F_FilterClock(n)  PWMA_CCMR2 = (PWMA_CCMR2 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 2 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È
#define PWMB_IC6F_FilterClock(n)  PWMB_CCMR2 = (PWMB_CCMR2 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 6 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È

#define PWMA_IC2PSC_PrescalerSet(n)    PWMA_CCMR2 = (PWMA_CCMR2 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 2 Ô¤·ÖÆµÆ÷£¬0~3
#define PWMB_IC6PSC_PrescalerSet(n)    PWMB_CCMR2 = (PWMB_CCMR2 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 6 Ô¤·ÖÆµÆ÷£¬0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  OC3CE OC3M2 OC3M1 OC3M0 OC3PE OC3FE CC3S1 CC3S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 3 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  OC7CE OC7M2 OC7M1 OC7M0 OC7PE OC7FE CC7S1 CC7S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 3 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 

#define PWMA_OC3ModeSet(n)        PWMA_CCMR3 = (PWMA_CCMR3 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ
#define PWMB_OC7ModeSet(n)        PWMB_CCMR3 = (PWMB_CCMR3 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ

#define PWMA_OC3_ReloadEnable()    PWMA_CCMR3 |= 0x08    //1£º¿ªÆô OC3PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMA_OC3_RelosdDisable()  PWMA_CCMR3 &= ~0x08    //0£º½ûÖ¹ OC3PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC7_ReloadEnable()    PWMB_CCMR3 |= 0x08    //1£º¿ªÆô OC7PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC7_RelosdDisable()  PWMB_CCMR3 &= ~0x08    //0£º½ûÖ¹ OC7PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ

#define PWMA_OC3_FastEnable()      PWMA_CCMR3 |= 0x04    //1£º¿ªÆô OC3FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMA_OC3_FastDisable()    PWMA_CCMR3 &= ~0x04    //0£º½ûÖ¹ OC3FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC7_FastEnable()      PWMB_CCMR3 |= 0x04    //1£º¿ªÆô OC7FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC7_FastDisable()    PWMB_CCMR3 &= ~0x04    //0£º½ûÖ¹ OC7FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ

#define PWMA_CC3S_Direction(n)    PWMA_CCMR3 = (PWMA_CCMR3 & ~0x03) | (n)    //²¶»ñ/±È½Ï 3 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ
#define PWMB_CC7S_Direction(n)    PWMB_CCMR3 = (PWMB_CCMR3 & ~0x03) | (n)    //²¶»ñ/±È½Ï 7 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  IC3F3 IC3F2 IC3F1 IC3F0 IC3PSC1 IC3PSC0 CC3S1 CC3S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 3 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  IC7F3 IC7F2 IC7F1 IC7F0 IC7PSC1 IC7PSC0 CC7S1 CC7S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 3 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 

#define PWMA_IC3F_FilterClock(n)  PWMA_CCMR3 = (PWMA_CCMR3 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 3 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È
#define PWMB_IC7F_FilterClock(n)  PWMB_CCMR3 = (PWMB_CCMR3 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 7 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È

#define PWMA_IC3PSC_PrescalerSet(n)    PWMA_CCMR3 = (PWMA_CCMR3 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 3 Ô¤·ÖÆµÆ÷£¬0~3
#define PWMB_IC7PSC_PrescalerSet(n)    PWMB_CCMR3 = (PWMB_CCMR3 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 7 Ô¤·ÖÆµÆ÷£¬0~3

//                             7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  OC4CE OC4M2 OC4M1 OC4M0 OC4PE OC4FE CC4S1 CC4S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 4 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  OC8CE OC8M2 OC8M1 OC8M0 OC8PE OC8FE CC8S1 CC8S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 4 - Í¨µÀÅäÖÃÎª±È½ÏÊä³öÄ£Ê½ */ 

#define PWMA_OC4ModeSet(n)        PWMA_CCMR4 = (PWMA_CCMR4 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ
#define PWMB_OC8ModeSet(n)        PWMB_CCMR4 = (PWMB_CCMR4 & ~0x70) | (n)    //Êä³ö±È½ÏÄ£Ê½ÉèÖÃ

#define PWMA_OC4_ReloadEnable()    PWMA_CCMR4 |= 0x08    //1£º¿ªÆô OC4PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMA_OC4_RelosdDisable()  PWMA_CCMR4 &= ~0x08    //0£º½ûÖ¹ OC4PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC8_ReloadEnable()    PWMB_CCMR4 |= 0x08    //1£º¿ªÆô OC8PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ
#define PWMB_OC8_RelosdDisable()  PWMB_CCMR4 &= ~0x08    //0£º½ûÖ¹ OC8PE Êä³ö±È½ÏµÄÔ¤×°ÔØ¹¦ÄÜ

#define PWMA_OC4_FastEnable()      PWMA_CCMR4 |= 0x04    //1£º¿ªÆô OC4FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMA_OC4_FastDisable()    PWMA_CCMR4 &= ~0x04    //0£º½ûÖ¹ OC4FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC8_FastEnable()      PWMB_CCMR4 |= 0x04    //1£º¿ªÆô OC8FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ
#define PWMB_OC8_FastDisable()    PWMB_CCMR4 &= ~0x04    //0£º½ûÖ¹ OC8FE Êä³ö±È½Ï¿ìËÙ¹¦ÄÜ

#define PWMA_CC4S_Direction(n)    PWMA_CCMR4 = (PWMA_CCMR4 & ~0x03) | (n)    //²¶»ñ/±È½Ï 4 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ
#define PWMB_CC8S_Direction(n)    PWMB_CCMR4 = (PWMB_CCMR4 & ~0x03) | (n)    //²¶»ñ/±È½Ï 8 Ñ¡Ôñ¡£ÕâÁ½Î»¶¨ÒåÍ¨µÀµÄ·½Ïò£¨ÊäÈë/Êä³ö£©£¬¼°ÊäÈë½ÅµÄÑ¡Ôñ

//                             7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  IC4F3 IC4F2 IC4F1 IC4F0 IC4PSC1 IC4PSC0 CC4S1 CC4S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 4 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  IC8F3 IC8F2 IC8F1 IC8F0 IC8PSC1 IC8PSC0 CC8S1 CC8S0  0000,0000  /* ²¶»ñ/±È½ÏÄ£Ê½¼Ä´æÆ÷ 4 - Í¨µÀÅäÖÃÎª²¶»ñÊäÈëÄ£Ê½ */ 

#define PWMA_IC4F_FilterClock(n)  PWMA_CCMR4 = (PWMA_CCMR4 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 4 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È
#define PWMB_IC8F_FilterClock(n)  PWMB_CCMR4 = (PWMB_CCMR4 & 0x0F) | (n<<4)    //ÊäÈë²¶»ñ 8 ÂË²¨Æ÷Ñ¡Ôñ£¬¸ÃÎ»Óò¶¨ÒåÁË TIn µÄ²ÉÑùÆµÂÊ¼°Êý×ÖÂË²¨Æ÷³¤¶È

#define PWMA_IC4PSC_PrescalerSet(n)    PWMA_CCMR4 = (PWMA_CCMR4 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 4 Ô¤·ÖÆµÆ÷£¬0~3
#define PWMB_IC8PSC_PrescalerSet(n)    PWMB_CCMR4 = (PWMB_CCMR4 & 0xF3) | ((n&3)<<2)    //ÊäÈë/²¶»ñ 8 Ô¤·ÖÆµÆ÷£¬0~3

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER1 = 0xFECCH;  CC2NP CC2NE CC2P CC2E CC1NP CC1NE CC1P CC1E  0000,0000  /* ²¶»ñ/±È½ÏÊ¹ÄÜ¼Ä´æÆ÷ 1 */ 
//sfr PWMB_CCER1 = 0xFEECH;    -     -   CC6P CC6E   -     -   CC5P CC5E  0000,0000  /* ²¶»ñ/±È½ÏÊ¹ÄÜ¼Ä´æÆ÷ 1 */ 

//#define PWMA_CC1E_Enable(n)        PWMA_CCER1 = (PWMA_CCER1 & ~0x01) | (n)        //¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
//#define PWMA_CC1NE_Enable(n)      PWMA_CCER1 = (PWMA_CCER1 & ~0x04) | (n << 2)  //¿ªÆô±È½ÏÊä³ö

#define PWMA_CCER1_Disable()      PWMA_CCER1 = 0x00      //¹Ø±ÕËùÓÐÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC1E_Enable()        PWMA_CCER1 |= 0x01    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC1E_Disable()        PWMA_CCER1 &= ~0x01    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC1P_LowValid()      PWMA_CCER1 |= 0x02    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC1P_HighValid()      PWMA_CCER1 &= ~0x02    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMA_CC1P_CaptureRise()    PWMA_CCER1 |= 0x02    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMA_CC1P_CaptureFall()    PWMA_CCER1 &= ~0x02    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ
#define PWMA_CC1NE_Enable()        PWMA_CCER1 |= 0x04    //1£º¿ªÆô±È½ÏÊä³ö
#define PWMA_CC1NE_Disable()      PWMA_CCER1 &= ~0x04    //0£º¹Ø±Õ±È½ÏÊä³ö
#define PWMA_CC1NP_LowValid()      PWMA_CCER1 |= 0x08    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC1NP_HighValid()    PWMA_CCER1 &= ~0x08    //0£º¸ßµçÆ½ÓÐÐ§

#define PWMA_CC2E_Enable()        PWMA_CCER1 |= 0x10    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC2E_Disable()        PWMA_CCER1 &= ~0x10    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC2P_LowValid()      PWMA_CCER1 |= 0x20    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC2P_HighValid()      PWMA_CCER1 &= ~0x20    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMA_CC2P_CaptureRise()    PWMA_CCER1 |= 0x20    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMA_CC2P_CaptureFall()    PWMA_CCER1 &= ~0x20    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ
#define PWMA_CC2NE_Enable()        PWMA_CCER1 |= 0x40    //1£º¿ªÆô±È½ÏÊä³ö
#define PWMA_CC2NE_Disable()      PWMA_CCER1 &= ~0x40    //0£º¹Ø±Õ±È½ÏÊä³ö
#define PWMA_CC2NP_LowValid()      PWMA_CCER1 |= 0x80    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC2NP_HighValid()    PWMA_CCER1 &= ~0x80    //0£º¸ßµçÆ½ÓÐÐ§

#define PWMB_CCER1_Disable()      PWMB_CCER1 = 0x00      //¹Ø±ÕËùÓÐÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC5E_Enable()        PWMB_CCER1 |= 0x01    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC5E_Disable()        PWMB_CCER1 &= ~0x01    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC5P_LowValid()      PWMB_CCER1 |= 0x02    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMB_CC5P_HighValid()      PWMB_CCER1 &= ~0x02    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMB_CC5P_CaptureRise()    PWMB_CCER1 |= 0x02    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMB_CC5P_CaptureFall()    PWMB_CCER1 &= ~0x02    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ

#define PWMB_CC6E_Enable()        PWMB_CCER1 |= 0x10    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC6E_Disable()        PWMB_CCER1 &= ~0x10    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC6P_LowValid()      PWMB_CCER1 |= 0x20    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMB_CC6P_HighValid()      PWMB_CCER1 &= ~0x20    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMB_CC6P_CaptureRise()    PWMB_CCER1 |= 0x20    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMB_CC6P_CaptureFall()    PWMB_CCER1 &= ~0x20    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER2 = 0xFECDH;  CC4NP CC4NE CC4P CC4E CC3NP CC3NE CC3P CC3E  0000,0000  /* ²¶»ñ/±È½ÏÊ¹ÄÜ¼Ä´æÆ÷ 2 */ 
//sfr PWMB_CCER2 = 0xFEEDH;    -     -   CC8P CC8E   -     -   CC7P CC7E  0000,0000  /* ²¶»ñ/±È½ÏÊ¹ÄÜ¼Ä´æÆ÷ 2 */ 

#define PWMA_CCER2_Disable()      PWMA_CCER2 = 0x00      //¹Ø±ÕËùÓÐÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC3E_Enable()        PWMA_CCER2 |= 0x01    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC3E_Disable()        PWMA_CCER2 &= ~0x01    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC3P_LowValid()      PWMA_CCER2 |= 0x02    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC3P_HighValid()      PWMA_CCER2 &= ~0x02    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMA_CC3P_CaptureRise()    PWMA_CCER2 |= 0x02    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMA_CC3P_CaptureFall()    PWMA_CCER2 &= ~0x02    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ
#define PWMA_CC3NE_Enable()        PWMA_CCER2 |= 0x04    //1£º¿ªÆô±È½ÏÊä³ö
#define PWMA_CC3NE_Disable()      PWMA_CCER2 &= ~0x04    //0£º¹Ø±Õ±È½ÏÊä³ö
#define PWMA_CC3NP_LowValid()      PWMA_CCER2 |= 0x08    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC3NP_HighValid()    PWMA_CCER2 &= ~0x08    //0£º¸ßµçÆ½ÓÐÐ§

#define PWMA_CC4E_Enable()        PWMA_CCER2 |= 0x10    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC4E_Disable()        PWMA_CCER2 &= ~0x10    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMA_CC4P_LowValid()      PWMA_CCER2 |= 0x20    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC4P_HighValid()      PWMA_CCER2 &= ~0x20    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMA_CC4P_CaptureRise()    PWMA_CCER2 |= 0x20    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMA_CC4P_CaptureFall()    PWMA_CCER2 &= ~0x20    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ
#define PWMA_CC4NE_Enable()        PWMA_CCER2 |= 0x40    //1£º¿ªÆô±È½ÏÊä³ö
#define PWMA_CC4NE_Disable()      PWMA_CCER2 &= ~0x40    //0£º¹Ø±Õ±È½ÏÊä³ö
#define PWMA_CC4NP_LowValid()      PWMA_CCER2 |= 0x80    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMA_CC4NP_HighValid()    PWMA_CCER2 &= ~0x80    //0£º¸ßµçÆ½ÓÐÐ§

#define PWMB_CCER2_Disable()      PWMB_CCER2 = 0x00      //¹Ø±ÕËùÓÐÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC7E_Enable()        PWMB_CCER2 |= 0x01    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC7E_Disable()        PWMB_CCER2 &= ~0x01    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC7P_LowValid()      PWMB_CCER2 |= 0x02    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMB_CC7P_HighValid()      PWMB_CCER2 &= ~0x02    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMB_CC7P_CaptureRise()    PWMB_CCER2 |= 0x02    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMB_CC7P_CaptureFall()    PWMB_CCER2 &= ~0x02    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ

#define PWMB_CC8E_Enable()        PWMB_CCER2 |= 0x10    //1£º¿ªÆôÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC8E_Disable()        PWMB_CCER2 &= ~0x10    //0£º¹Ø±ÕÊäÈë²¶»ñ/±È½ÏÊä³ö
#define PWMB_CC8P_LowValid()      PWMB_CCER2 |= 0x20    //1£ºµÍµçÆ½ÓÐÐ§
#define PWMB_CC8P_HighValid()      PWMB_CCER2 &= ~0x20    //0£º¸ßµçÆ½ÓÐÐ§
#define PWMB_CC8P_CaptureRise()    PWMB_CCER2 |= 0x20    //1£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÏÂ½µÑØ
#define PWMB_CC8P_CaptureFall()    PWMB_CCER2 &= ~0x20    //0£º²¶»ñ·¢ÉúÔÚ TI1F »ò TI2F µÄÉÏÉýÑØ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CNTRH = 0xFECEH;                   CNT1[15:8]                  0000,0000  /* ¼ÆÊýÆ÷¸ß 8 Î» */ 
//sfr PWMB_CNTRH = 0xFEEEH;                   CNT2[15:8]                  0000,0000  /* ¼ÆÊýÆ÷¸ß 8 Î» */ 
//sfr PWMA_CNTRL = 0xFECFH;                   CNT1[7:0]                   0000,0000  /* ¼ÆÊýÆ÷µÍ 8 Î» */ 
//sfr PWMB_CNTRL = 0xFEEFH;                   CNT2[7:0]                   0000,0000  /* ¼ÆÊýÆ÷µÍ 8 Î» */ 

#define PWMA_Counter(n)            PWMA_CNTR = n    //¼ÆÊýÆ÷ÉèÖÃ
#define PWMB_Counter(n)            PWMB_CNTR = n    //¼ÆÊýÆ÷ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_PSCRH = 0xFED0H;                   PSC1[15:8]                  0000,0000  /* Ô¤·ÖÆµÆ÷¸ß 8 Î» */ 
//sfr PWMB_PSCRH = 0xFEF0H;                   PSC2[15:8]                  0000,0000  /* Ô¤·ÖÆµÆ÷¸ß 8 Î» */ 
//sfr PWMA_PSCRL = 0xFED1H;                   PSC1[7:0]                   0000,0000  /* Ô¤·ÖÆµÆ÷µÍ 8 Î» */ 
//sfr PWMB_PSCRL = 0xFEF1H;                   PSC2[7:0]                   0000,0000  /* Ô¤·ÖÆµÆ÷µÍ 8 Î» */ 

#define PWMA_Prescaler(n)          PWMA_PSCR = n    //Ô¤·ÖÆµÆ÷ÉèÖÃ
#define PWMB_Prescaler(n)          PWMB_PSCR = n    //Ô¤·ÖÆµÆ÷ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_ARRH = 0xFED2H;                    ARR1[15:8]                  0000,0000  /* ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷¸ß 8 Î» */ 
//sfr PWMB_ARRH = 0xFEF2H;                    ARR2[15:8]                  0000,0000  /* ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷¸ß 8 Î» */ 
//sfr PWMA_ARRL = 0xFED3H;                    ARR1[7:0]                   0000,0000  /* ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷µÍ 8 Î» */ 
//sfr PWMB_ARRL = 0xFEF3H;                    ARR2[7:0]                   0000,0000  /* ×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷µÍ 8 Î» */ 

#define PWMA_AutoReload(n)        {PWMA_ARRH = (n>>8); PWMA_ARRL = (n);}    //×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÉèÖÃ
#define PWMB_AutoReload(n)        {PWMB_ARRH = (n>>8); PWMB_ARRL = (n);}    //×Ô¶¯ÖØ×°ÔØ¼Ä´æÆ÷ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_RCR = 0xFED4H;                     REP1[7:0]                   0000,0000  /* ÖØ¸´¼ÆÊýÆ÷¼Ä´æÆ÷ */ 
//sfr PWMB_RCR = 0xFEF4H;                     REP2[7:0]                   0000,0000  /* ÖØ¸´¼ÆÊýÆ÷¼Ä´æÆ÷ */ 

#define PWMA_ReCounter(n)          PWMA_RCR = n    //ÖØ¸´¼ÆÊýÆ÷¼Ä´æÆ÷ÉèÖÃ
#define PWMB_ReCounter(n)          PWMB_RCR = n    //ÖØ¸´¼ÆÊýÆ÷¼Ä´æÆ÷ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR1H = 0xFED5H;                   CCR1[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 ¸ß 8 Î» */ 
//sfr PWMB_CCR5H = 0xFEF5H;                   CCR5[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 ¸ß 8 Î» */ 
//sfr PWMA_CCR1L = 0xFED6H;                   CCR1[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 µÍ 8 Î» */ 
//sfr PWMB_CCR5L = 0xFEF6H;                   CCR5[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 µÍ 8 Î» */ 

#define PWMA_Duty1(n)              {PWMA_CCR1H = (n>>8); PWMA_CCR1L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 ÉèÖÃ
#define PWMB_Duty5(n)              {PWMB_CCR5H = (n>>8); PWMB_CCR5L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 1 ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR2H = 0xFED7H;                   CCR2[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 ¸ß 8 Î» */ 
//sfr PWMB_CCR6H = 0xFEF7H;                   CCR6[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 ¸ß 8 Î» */ 
//sfr PWMA_CCR2L = 0xFED8H;                   CCR2[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 µÍ 8 Î» */ 
//sfr PWMB_CCR6L = 0xFEF8H;                   CCR6[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 µÍ 8 Î» */ 

#define PWMA_Duty2(n)              {PWMA_CCR2H = (n>>8); PWMA_CCR2L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 ÉèÖÃ
#define PWMB_Duty6(n)              {PWMB_CCR6H = (n>>8); PWMB_CCR6L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 2 ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR3H = 0xFED9H;                   CCR3[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 ¸ß 8 Î» */ 
//sfr PWMB_CCR7H = 0xFEF9H;                   CCR7[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 ¸ß 8 Î» */ 
//sfr PWMA_CCR3L = 0xFEDAH;                   CCR3[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 µÍ 8 Î» */ 
//sfr PWMB_CCR7L = 0xFEFAH;                   CCR7[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 µÍ 8 Î» */ 

#define PWMA_Duty3(n)              {PWMA_CCR3H = (n>>8); PWMA_CCR3L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 ÉèÖÃ
#define PWMB_Duty7(n)              {PWMB_CCR7H = (n>>8); PWMB_CCR7L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 3 ÉèÖÃ

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR4H = 0xFEDBH;                   CCR4[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 ¸ß 8 Î» */ 
//sfr PWMB_CCR8H = 0xFEFBH;                   CCR8[15:8]                  0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 ¸ß 8 Î» */ 
//sfr PWMA_CCR4L = 0xFEDCH;                   CCR4[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 µÍ 8 Î» */ 
//sfr PWMB_CCR8L = 0xFEFCH;                   CCR8[7:0]                   0000,0000  /* ²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 µÍ 8 Î» */ 

#define PWMA_Duty4(n)              {PWMA_CCR4H = (n>>8); PWMA_CCR4L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 ÉèÖÃ
#define PWMB_Duty8(n)              {PWMB_CCR8H = (n>>8); PWMB_CCR8L = (n);}    //²¶»ñ/±È½Ï¼Ä´æÆ÷ 4 ÉèÖÃ

//                          7    6    5    4     3     2     1      0     Reset Value
//sfr PWMA_BKR = 0xFEDDH;  MOE1 AOE1 BKP1 BKE1 OSSR1 OSSI1 LOCK11 LOCK10  0000,0000  /* É²³µ¼Ä´æÆ÷ */ 
//sfr PWMB_BKR = 0xFEFDH;  MOE2 AOE2 BKP2 BKE2 OSSR2 OSSI2 LOCK21 LOCK20  0000,0000  /* É²³µ¼Ä´æÆ÷ */ 

#define PWMA_BrakeOutputEnable(n)        (n==1?(PWMA_BKR |= 0x80):(PWMA_BKR &= ~0x80))    //1£ºÖ÷Êä³öÊ¹ÄÜ
#define PWMB_BrakeOutputEnable(n)        (n==1?(PWMB_BKR |= 0x80):(PWMB_BKR &= ~0x80))    //1£ºÖ÷Êä³öÊ¹ÄÜ
//#define PWMA_BrakeOutputEnable()        PWMA_BKR |= 0x80    //1£ºÖ÷Êä³öÊ¹ÄÜ
#define PWMA_BrakeOutputDisable()        PWMA_BKR &= ~0x80    //0£ºÖ÷Êä³ö½ûÖ¹
//#define PWMB_BrakeOutputEnable()        PWMB_BKR |= 0x80    //1£ºÖ÷Êä³öÊ¹ÄÜ
#define PWMB_BrakeOutputDisable()        PWMB_BKR &= ~0x80    //0£ºÖ÷Êä³ö½ûÖ¹

#define PWMA_BrakeAutoOutputEnable()    PWMA_BKR |= 0x40    //1£º×Ô¶¯Êä³öÊ¹ÄÜ
#define PWMA_BrakeAutoOutputDisable()    PWMA_BKR &= ~0x40    //0£º×Ô¶¯Êä³ö½ûÖ¹
#define PWMB_BrakeAutoOutputEnable()    PWMB_BKR |= 0x40    //1£º×Ô¶¯Êä³öÊ¹ÄÜ
#define PWMB_BrakeAutoOutputDisable()    PWMB_BKR &= ~0x40    //0£º×Ô¶¯Êä³ö½ûÖ¹

#define PWMA_BrakeHighValid()            PWMA_BKR |= 0x20    //1£ºÉ²³µÊäÈë¸ßµçÆ½ÓÐÐ§
#define PWMA_BrakeLowValid()            PWMA_BKR &= ~0x20    //0£ºÉ²³µÊäÈëµÍµçÆ½ÓÐÐ§
#define PWMB_BrakeHighValid()            PWMB_BKR |= 0x20    //1£ºÉ²³µÊäÈë¸ßµçÆ½ÓÐÐ§
#define PWMB_BrakeLowValid()            PWMB_BKR &= ~0x20    //0£ºÉ²³µÊäÈëµÍµçÆ½ÓÐÐ§

#define PWMA_BrakeEnable(n)              (n==1?(PWMA_BKR |= 0x10):(PWMA_BKR &= ~0x10))    //1£º¿ªÆôÉ²³µÊäÈë
#define PWMB_BrakeEnable(n)              (n==1?(PWMB_BKR |= 0x10):(PWMB_BKR &= ~0x10))    //1£º¿ªÆôÉ²³µÊäÈë
//#define PWMA_BrakeEnable()              PWMA_BKR |= 0x10    //1£º¿ªÆôÉ²³µÊäÈë
#define PWMA_BrakeDisable()              PWMA_BKR &= ~0x10    //0£º½ûÖ¹É²³µÊäÈë
//#define PWMB_BrakeEnable()              PWMB_BKR |= 0x10    //1£º¿ªÆôÉ²³µÊäÈë
#define PWMB_BrakeDisable()              PWMB_BKR &= ~0x10    //0£º½ûÖ¹É²³µÊäÈë

//ÔËÐÐÄ£Ê½ÏÂ¡°¹Ø±Õ×´Ì¬¡±Ñ¡Ôñ
#define PWMA_OSSRnEnable()              PWMA_BKR |= 0x08    //1£ºµ± PWM ²»¹¤×÷Ê±£¬Ò»µ© CCiE=1 »ò CCiNE=1£¬Ê×ÏÈ¿ªÆô OC/OCN ²¢Êä³öÎÞÐ§µçÆ½£¬È»ºóÖÃOC/OCN Ê¹ÄÜÊä³öÐÅºÅ=1
#define PWMA_OSSRnDisable()              PWMA_BKR &= ~0x08    //0£ºµ± PWM ²»¹¤×÷Ê±£¬½ûÖ¹ OC/OCN Êä³ö£¨OC/OCN Ê¹ÄÜÊä³öÐÅºÅ=0£©
#define PWMB_OSSRnEnable()              PWMB_BKR |= 0x08    //1£ºµ± PWM ²»¹¤×÷Ê±£¬Ò»µ© CCiE=1 »ò CCiNE=1£¬Ê×ÏÈ¿ªÆô OC/OCN ²¢Êä³öÎÞÐ§µçÆ½£¬È»ºóÖÃOC/OCN Ê¹ÄÜÊä³öÐÅºÅ=1
#define PWMB_OSSRnDisable()              PWMB_BKR &= ~0x08    //0£ºµ± PWM ²»¹¤×÷Ê±£¬½ûÖ¹ OC/OCN Êä³ö£¨OC/OCN Ê¹ÄÜÊä³öÐÅºÅ=0£©
//¿ÕÏÐÄ£Ê½ÏÂ¡°¹Ø±Õ×´Ì¬¡±Ñ¡Ôñ
#define PWMA_OSSInEnable()              PWMA_BKR |= 0x04    //1£ºµ± PWM ²»¹¤×÷Ê±£¬Ò»µ© CCiE=1 »ò CCiNE=1£¬OC/OCN Ê×ÏÈÊä³öÆä¿ÕÏÐµçÆ½£¬È»ºó OC/OCNÊ¹ÄÜÊä³öÐÅºÅ=1
#define PWMA_OSSInDisable()              PWMA_BKR &= ~0x04    //0£ºµ± PWM ²»¹¤×÷Ê±£¬½ûÖ¹ OC/OCN Êä³ö£¨OC/OCN Ê¹ÄÜÊä³öÐÅºÅ=0£©
#define PWMB_OSSInEnable()              PWMB_BKR |= 0x04    //1£ºµ± PWM ²»¹¤×÷Ê±£¬Ò»µ© CCiE=1 »ò CCiNE=1£¬OC/OCN Ê×ÏÈÊä³öÆä¿ÕÏÐµçÆ½£¬È»ºó OC/OCNÊ¹ÄÜÊä³öÐÅºÅ=1
#define PWMB_OSSInDisable()              PWMB_BKR &= ~0x04    //0£ºµ± PWM ²»¹¤×÷Ê±£¬½ûÖ¹ OC/OCN Êä³ö£¨OC/OCN Ê¹ÄÜÊä³öÐÅºÅ=0£©

#define PWMn_lock_L0      0    //¼Ä´æÆ÷ÎÞÐ´±£»¤
#define PWMn_lock_L1      1    //Ëø¶¨¼¶±ð 1£º²»ÄÜÐ´Èë PWMn_BKR ¼Ä´æÆ÷µÄ BKE¡¢BKP¡¢AOE Î»ºÍPWMn_OISR ¼Ä´æÆ÷µÄ OISI Î»
#define PWMn_lock_L2      2    //Ëø¶¨¼¶±ð 2£º²»ÄÜÐ´ÈëËø¶¨¼¶±ð 1 ÖÐµÄ¸÷Î»£¬Ò²²»ÄÜÐ´Èë CC ¼«ÐÔÎ»ÒÔ¼° OSSR/OSSI Î»
#define PWMn_lock_L3      3    //Ëø¶¨¼¶±ð 3£º²»ÄÜÐ´ÈëËø¶¨¼¶±ð 2 ÖÐµÄ¸÷Î»£¬Ò²²»ÄÜÐ´Èë CC ¿ØÖÆÎ»

#define PWMA_LockLevelSet(n)            PWMA_BKR = (PWMA_BKR & ~0x03) | (n&3)    //Ëø¶¨ÉèÖÃ¡£¸ÃÎ»Îª·ÀÖ¹Èí¼þ´íÎó¶øÌá¹©µÄÐ´±£»¤´ëÊ©
#define PWMB_LockLevelSet(n)            PWMB_BKR = (PWMB_BKR & ~0x03) | (n&3)    //Ëø¶¨ÉèÖÃ¡£¸ÃÎ»Îª·ÀÖ¹Èí¼þ´íÎó¶øÌá¹©µÄÐ´±£»¤´ëÊ©

//                             7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_DTR = 0xFEDEH;                     DTG1[7:0]                   0000,0000  /* ËÀÇø¼Ä´æÆ÷ */ 
//sfr PWMB_DTR = 0xFEFEH;                     DTG2[7:0]                   0000,0000  /* ËÀÇø¼Ä´æÆ÷ */ 

//DTGn[7:5] = 000~011: ËÀÇøÊ±¼ä = DTGn[7:0] * tCK_PSC
//DTGn[7:5] = 100~101: ËÀÇøÊ±¼ä = (64 + DTGn[6:0]) * 2 * tCK_PSC
//DTGn[7:5] = 110:     ËÀÇøÊ±¼ä = (32 + DTGn[5:0]) * 8 * tCK_PSC
//DTGn[7:5] = 111:     ËÀÇøÊ±¼ä = (32 + DTGn[4:0]) * 16 * tCK_PSC

#define PWMA_DeadTime(n)          PWMA_DTR = n    //ËÀÇø·¢ÉúÆ÷ÉèÖÃ
#define PWMB_DeadTime(n)          PWMB_DTR = n    //ËÀÇø·¢ÉúÆ÷ÉèÖÃ

//                            7    6     5    4     3    2     1    0    Reset Value
//sfr PWMA_OISR = 0xFEDFH;  OIS4N OIS4 OIS3N OIS3 OIS2N OIS2 OIS1N OIS1  0000,0000  /* Êä³ö¿ÕÏÐ×´Ì¬¼Ä´æÆ÷ */ 
//sfr PWMB_OISR = 0xFEFFH;    -   OIS8   -   OIS7   -   OIS6   -   OIS5  x0x0,x0x0  /* Êä³ö¿ÕÏÐ×´Ì¬¼Ä´æÆ÷ */ 

#define PWMA_OC1_OUT_0()          PWMA_OISR &= ~0x01  /* µ± MOE=0 Ê±£¬Èç¹û OC1N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC1=0 */
#define PWMA_OC1_OUT_1()          PWMA_OISR |= 0x01    /* µ± MOE=0 Ê±£¬Èç¹û OC1N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC1=1 */
#define PWMA_OC1N_OUT_0()          PWMA_OISR &= ~0x02  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC1N=0 */
#define PWMA_OC1N_OUT_1()          PWMA_OISR |= 0x02    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC1N=1 */
#define PWMA_OC2_OUT_0()          PWMA_OISR &= ~0x04  /* µ± MOE=0 Ê±£¬Èç¹û OC2N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC2=0 */
#define PWMA_OC2_OUT_1()          PWMA_OISR |= 0x04    /* µ± MOE=0 Ê±£¬Èç¹û OC2N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC2=1 */
#define PWMA_OC2N_OUT_0()          PWMA_OISR &= ~0x08  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC2N=0 */
#define PWMA_OC2N_OUT_1()          PWMA_OISR |= 0x08    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC2N=1 */
#define PWMA_OC3_OUT_0()          PWMA_OISR &= ~0x10  /* µ± MOE=0 Ê±£¬Èç¹û OC3N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC3=0 */
#define PWMA_OC3_OUT_1()          PWMA_OISR |= 0x10    /* µ± MOE=0 Ê±£¬Èç¹û OC3N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC3=1 */
#define PWMA_OC3N_OUT_0()          PWMA_OISR &= ~0x20  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC3N=0 */
#define PWMA_OC3N_OUT_1()          PWMA_OISR |= 0x20    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC3N=1 */
#define PWMA_OC4_OUT_0()          PWMA_OISR &= ~0x40  /* µ± MOE=0 Ê±£¬Èç¹û OC4N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC4=0 */
#define PWMA_OC4_OUT_1()          PWMA_OISR |= 0x40    /* µ± MOE=0 Ê±£¬Èç¹û OC4N Ê¹ÄÜ£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC4=1 */
#define PWMA_OC4N_OUT_0()          PWMA_OISR &= ~0x80  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC4N=0 */
#define PWMA_OC4N_OUT_1()          PWMA_OISR |= 0x80    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC4N=1 */

#define PWMB_OC5_OUT_0()          PWMB_OISR &= ~0x01  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC5=0 */
#define PWMB_OC5_OUT_1()          PWMB_OISR |= 0x01    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC5=1 */
#define PWMB_OC6_OUT_0()          PWMB_OISR &= ~0x04  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC6=0 */
#define PWMB_OC6_OUT_1()          PWMB_OISR |= 0x04    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC6=1 */
#define PWMB_OC7_OUT_0()          PWMB_OISR &= ~0x10  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC7=0 */
#define PWMB_OC7_OUT_1()          PWMB_OISR |= 0x10    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC7=1 */
#define PWMB_OC8_OUT_0()          PWMB_OISR &= ~0x40  /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC8=0 */
#define PWMB_OC8_OUT_1()          PWMB_OISR |= 0x40    /* µ± MOE=0 Ê±£¬ÔòÔÚÒ»¸öËÀÇøºó£¬OC8=1 */

//========================================================================
//                              ¶¨ÒåÉùÃ÷
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
  u8  PWM_Mode;      //Ä£Ê½,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
  u16  PWM_Period;    //ÖÜÆÚÊ±¼ä,   0~65535
  u16  PWM_Duty;      //Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u8  PWM_DeadTime;  //ËÀÇø·¢ÉúÆ÷ÉèÖÃ, 0~255
//  u8  PWM_Reload;        //Êä³ö±È½ÏµÄÔ¤×°ÔØÊ¹ÄÜ,   ENABLE,DISABLE
//  u8  PWM_Fast;          //Êä³ö±È½Ï¿ìËÙ¹¦ÄÜÊ¹ÄÜ,   ENABLE,DISABLE
//  u8  PWM_PreLoad;      //Ô¤×°ÔØ,     ENABLE,DISABLE
//  u8  PWM_BrakeEnable;  //É²³µÊäÈëÊ¹ÄÜ,  ENABLE,DISABLE
  u8  PWM_EnoSelect;    //Êä³öÍ¨µÀÑ¡Ôñ,  ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
  u8  PWM_CEN_Enable;    //Ê¹ÄÜ¼ÆÊýÆ÷, ENABLE,DISABLE
  u8  PWM_MainOutEnable;//Ö÷Êä³öÊ¹ÄÜ,  ENABLE,DISABLE
} PWMx_InitDefine; 

typedef struct
{ 
  u16  PWM1_Duty;      //PWM1Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM2_Duty;      //PWM2Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM3_Duty;      //PWM3Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM4_Duty;      //PWM4Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM5_Duty;      //PWM5Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM6_Duty;      //PWM6Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM7_Duty;      //PWM7Õ¼¿Õ±ÈÊ±¼ä, 0~Period
  u16  PWM8_Duty;      //PWM8Õ¼¿Õ±ÈÊ±¼ä, 0~Period
} PWMx_Duty; 

typedef struct
{ 
//  u8  PWM_Mode;      //Ä£Ê½,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
  u16  PWM_Period;    //ÖÜÆÚÊ±¼ä,   0~65535
  u8  PWM_DeadTime;  //ËÀÇø·¢ÉúÆ÷ÉèÖÃ, 0~255
  u8  PWM_EnoSelect;    //Êä³öÍ¨µÀÑ¡Ôñ,  ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
  u8  PWM_CEN_Enable;    //Ê¹ÄÜ¼ÆÊýÆ÷, ENABLE,DISABLE
  u8  PWM_MainOutEnable;//Ö÷Êä³öÊ¹ÄÜ,  ENABLE,DISABLE
} HSPWMx_InitDefine; 


u8  PWM_Configuration(u8 PWM, PWMx_InitDefine *PWMx);
void UpdatePwm(u8 PWM, PWMx_Duty *PWMx);

void HSPWM_Configuration(u8 PWM, HSPWMx_InitDefine *PWMx, PWMx_Duty *DUTYx);
void UpdateHSPwm(u8 PWM, PWMx_Duty *PWMx);

#endif

