/**
 * @file STC32G_EEPROM.c
 * @brief 未指定描述
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

#include "STC32G_EEPROM.h"

//========================================================================
// : void ISP_Disable( void )
// : ֹISP / AP.
// : non.
// : non.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
void DisableEEPROM( void )
{
	IAP_CONTR = 0;			//ֹIAP
	IAP_CMD   = 0;			//ȥIAP
	IAP_TRIG  = 0;			//ֹIAP󴥷
	IAP_ADDRE = 0xff;   //ַõ IAP 
	IAP_ADDRH = 0xff;   //ַõ IAP 
	IAP_ADDRL = 0xff;
}

//========================================================================
// : void EEPROM_Trig( void )
// : EEPROM.
// : none.
// : none.
// 汾: V1.0, 2014 - -30
//========================================================================
void EEPROM_Trig( void )
{
	F0 = EA;    //ȫж
	EA = 0;     //ֹж, ⴥЧ
	IAP_TRIG = 0x5A;
	IAP_TRIG = 0xA5;                    //5AHA5HIAPĴÿζҪ
																			//A5HIAP
																			//CPUȴIAPɺ󣬲Żִг
	_nop_();   //STC32GǶ༶ˮߵָϵͳ4NOP֤IAP_DATA׼
	_nop_();
	_nop_();
	_nop_();
	EA = F0;    //ָȫж
}

//========================================================================
// : void EEPROM_read_n( u32 EE_address, u8 *DataAddress, u16 number )
// : ָEEPROM׵ַnֽڷָĻ.
// : EE_address:  EEPROM׵ַ.
//       DataAddress: ݷŻ׵ַ.
//       number:      ֽڳ.
// : non.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
void EEPROM_read_n( u32 EE_address, u8 *DataAddress, u16 number )
{
	IAP_ENABLE();                           //õȴʱ䣬IAPһξ͹
	IAP_READ();                             //ֽڶıʱ
	do
	{
		IAP_ADDRE = ( u8 )( EE_address >> 16 ); //͵ַֽڣַҪıʱ͵ַ
		IAP_ADDRH = ( u8 )( EE_address >> 8 );  //͵ַֽڣַҪıʱ͵ַ
		IAP_ADDRL = ( u8 )EE_address;         //͵ַֽڣַҪıʱ͵ַ
		EEPROM_Trig();                      //EEPROM
		*DataAddress = IAP_DATA;            //
		EE_address++;
		DataAddress++;
	}while (--number );

	DisableEEPROM();
}

//========================================================================
// : void EEPROM_SectorErase( u32 EE_address )
// : ַָEEPROM.
// : EE_address:  ҪEEPROMĵַ.
// : non.
// 汾: V1.0, 2013 - -10
//========================================================================
void EEPROM_SectorErase( u32 EE_address )
{
	IAP_ENABLE();                       //õȴʱ䣬IAPһξ͹
	IAP_ERASE();                        //, ıʱ
																			//ֻûֽڲ512ֽ/
																			//һֽڵַַ
	IAP_ADDRE = ( u8 )( EE_address >> 16 ); //ַֽڣַҪıʱ͵ַ
	IAP_ADDRH = ( u8 )( EE_address >> 8 );  //ַֽڣַҪıʱ͵ַ
	IAP_ADDRL = ( u8 )EE_address;         //ַֽڣַҪıʱ͵ַ
	EEPROM_Trig();                      //EEPROM
	DisableEEPROM();                    //ֹEEPROM
}

//========================================================================
// : void EEPROM_write_n( u32 EE_address, u8 *DataAddress, u16 number )
// : ѻnֽдָ׵ַEEPROM.
// : EE_address:  дEEPROM׵ַ.
//       DataAddress: дԴݵĻ׵ַ.
//       number:      дֽڳ.
// : non.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
void EEPROM_write_n( u32 EE_address, u8 *DataAddress, u16 number )
{
	IAP_ENABLE();                       //õȴʱ䣬IAPһξ͹
	IAP_WRITE();                        //, ֽд
	do
	{
		IAP_ADDRE = ( u8 )( EE_address >> 16 ); //͵ַֽڣַҪıʱ͵ַ
		IAP_ADDRH = ( u8 )( EE_address >> 8 );  //͵ַֽڣַҪıʱ͵ַ
		IAP_ADDRL = ( u8 )EE_address;         //͵ַֽڣַҪıʱ͵ַ
		IAP_DATA  = *DataAddress;         //ݵIAP_DATAֻݸıʱ
		EEPROM_Trig();                    //EEPROM
		EE_address++;                     //һַ
		DataAddress++;                    //һ
	}while (--number );                   //ֱ
	DisableEEPROM();
}

