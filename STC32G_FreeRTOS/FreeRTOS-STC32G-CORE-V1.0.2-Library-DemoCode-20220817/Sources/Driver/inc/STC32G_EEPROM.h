/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺑﻫ٩ﻝﺯﺕﺷﻏ٣ﺟﺫﻥﺿﺫﺗ٩ﺳﺃ٤ﺛ٤ﻶﺁﺽ,ﺍﺽﺷﻏ٣ﺟﺫﻥﺿﺫﻁﺂﺃﻐﺗ٩ﺳﺃﺀﺛSTC٥ﺅﻁﺗﺀﺩﺱ٠٣ﺟﺫﻥ            */
/*---------------------------------------------------------------------*/

#ifndef	__STC32G_EEPROM_H
#define	__STC32G_EEPROM_H

#include	"FreeRTOS.h"

//========================================================================
//                              ٦ﺎﺯﻣﺓﻵﺃﻐ
//========================================================================


//========================================================================
//                               IAPﺓﻭﺿﺃ
//========================================================================

#define		IAP_STANDBY()	IAP_CMD = 0		//IAP؟ﺻﺩﺫﺃﻙﺀﻍ£ﺎﺵﻝﺿ٩£ﺏ
#define		IAP_READ()		IAP_CMD = 1		//IAP٦ﺀ٣ﻲﺃﻙﺀﻍ
#define		IAP_WRITE()		IAP_CMD = 2		//IAPﺫ٤ﺑﺽﺃﻙﺀﻍ
#define		IAP_ERASE()		IAP_CMD = 3		//IAP٢ﺀ٣ﻱﺃﻙﺀﻍ

#define	IAP_ENABLE()		IAPEN = 1; IAP_TPS = MAIN_Fosc / 1000000
#define	IAP_DISABLE()		IAP_CONTR = 0; IAP_CMD = 0; IAP_TRIG = 0; IAP_ADDRH = 0xff; IAP_ADDRL = 0xff


void	DisableEEPROM(void);
void 	EEPROM_read_n(uint32_t EE_address,uint8_t *DataAddress,uint16_t number);
void 	EEPROM_write_n(uint32_t EE_address,uint8_t *DataAddress,uint16_t number);
void	EEPROM_SectorErase(uint32_t EE_address);


#endif