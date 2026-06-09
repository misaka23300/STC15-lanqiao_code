/**
 * @file STC32G_LIN.c
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

#include "STC32G_LIN.h"

//========================================================================
// : u8 ReadReg( u8 addr )
// : LinܼĴȡ
// : LinܼĴַ.
// : LinܼĴ.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
u8 LinReadReg( u8 addr )
{
	u8 dat;
	LINAR = addr;
	dat = LINDR;
	return dat;
}

//========================================================================
// : void WriteReg( u8 addr, u8 dat )
// : LinܼĴú
// : LinܼĴַ, LinܼĴ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinWriteReg( u8 addr, u8 dat )
{
	LINAR = addr;
	LINDR = dat;
}

//========================================================================
// : void LinReadMsg( u8 *pdat )
// : Linȡݺ
// : *pdat: ݻ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinReadMsg( u8 *pdat )
{
	u8 i;

	LinWriteReg( LSEL, 0x80 );	//ַ0ʼ
	for ( i = ;i < RAME_LEN;i++)
	{
		pdat[i] = LinReadReg( LBUF );
	}
}

//========================================================================
// : void LinSendMsg( u8 *pdat )
// : Linݺ
// : *pdat: ݻ.
// : Lin ID.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSendMsg( u8 *pdat )
{
	u8 i;

	LinWriteReg( LSEL, 0x80 );		//ַ0ʼ
	for ( i = ;i < RAME_LEN;i++)
	{
		LinWriteReg( LBUF, pdat[i]);
	}
}

//========================================================================
// : void LinSetID( u8 lid )
// : LIN ID
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSetID( u8 lid )
{
	LinWriteReg( LID, lid );			//ID
}

//========================================================================
// : u8 GetLinError( void )
// : ȡLINߴĴ״̬
// : none.
// : Ĵ״̬.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
u8 GetLinError( void )
{
	u8 sta;
	sta = LinReadReg( LER );		//ȡĴ
	return sta;
}

//========================================================================
// : u8 WaitLinReady( void )
// : ȴLIN߾
// : none.
// : LIN״̬.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
u8 WaitLinReady( void )
{
	u8 lsr;
	do{
		lsr = LinReadReg( LSR );
	}while (!( lsr & 0x02 ));		//жready״̬
	return lsr;
}

//========================================================================
// : void SendAbortCmd( void )
// : ģʽLinAbort
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void SendAbortCmd( void )
{
	LinWriteReg( LCR, 0x80 );		//ģʽ Send Abort
}

//========================================================================
// : void SendHeadCmd( void )
// : ģʽLinHeader
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void SendHeadCmd( void )
{
	LinWriteReg( LCR, 0x81 );		//ģʽ Send Header
}

//========================================================================
// : void SendDatCmd( void )
// : ģʽLinݺ
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void SendDatCmd( void )
{
	u8 lcr_val;
	lcr_val = 0x82+( LIN_MODE<<6 )+( FRAME_LEN<<2 );
	LinWriteReg( LCR, lcr_val );
}

//========================================================================
// : void ResponseTxCmd( void )
// : ģʽLinTx Response
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void ResponseTxCmd( void )
{
	u8 lcr_val;
	lcr_val = 0x02+( LIN_MODE<<6 )+( FRAME_LEN<<2 );
	LinWriteReg( LCR, lcr_val );
}

//========================================================================
// : void ResponseRxCmd( void )
// : ģʽLinRx Response
// : none.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void ResponseRxCmd( void )
{
	u8 lcr_val;
	lcr_val = 0x03+( LIN_MODE<<6 )+( FRAME_LEN<<2 );
	LinWriteReg( LCR, lcr_val );
}

//========================================================================
// : void LinTxResponse( u8 *pdat )
// : LinӻӦݣ͵Headerƴһ֡
// : *pdat: ݻ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinTxResponse( u8 *pdat )
{
	LinSendMsg( pdat );
	ResponseTxCmd();					//TX response
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ
}

//========================================================================
// : void LinReadFrame( u8 *pdat )
// : Linӻ֡
// : *pdat: ݻ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinReadFrame( u8 *pdat )
{
	ResponseRxCmd();					//RX response
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ

	LinReadMsg( pdat );					//Lin
}

//========================================================================
// : void LinSendFrame( u8 lid, u8 *pdat )
// : Lin֡
// : lid: Lin ID; *pdat: ݻ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSendFrame( u8 lid, u8 *pdat )
{
	LinSetID( lid );						//ID
	LinSendMsg( pdat );

	SendHeadCmd();						//ģʽ Send Seader
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ

	SendDatCmd();							//Send Data
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ
}

//========================================================================
// : void LinSendHeaderRead( u8 lid, u8 *pdat )
// : LinHeaderɴӻӦݣƴһ֡
// : lid: ӦӻID; *pdat: ݻ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSendHeaderRead( u8 lid, u8 *pdat )
{
	LinSetID( lid );						//÷ResponseӻID

	SendHeadCmd();						//ģʽ send header
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ
	
	ResponseRxCmd();					//RX response
	WaitLinReady();						//ȴready״̬
	GetLinError();						//ȡĴ

	LinReadMsg( pdat );				//Linߴӻ͵Ӧ
}

//========================================================================
// : void LinSetBaudrate( u16 brt )
// : Lin߲ú
// : brt: .
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSetBaudrate( u16 brt )
{
	u16 tmp;
	tmp = ( MAIN_Fosc >> 4 ) / brt;
	LinWriteReg( DLH,( u8 )( tmp>>8 ));
	LinWriteReg( DLL,( u8 )tmp );
}

//========================================================================
// : void LinSetHeadDelay( u8 base_ms, u8 prescaler )
// : Lin֡ͷʱ
// : base_ms:ʱ, prescaler:ʱƵ.
// : none.
// 汾: VER1.0
// : 2021 - 1 - 5
// ע: 
//========================================================================
void LinSetHeadDelay( u8 base_ms, u8 prescaler )
{
	u16 tmp;
	tmp = ( MAIN_Fosc * base_ms ) / 1000;
	LinWriteReg( HDRH,( u8 )( tmp>>8 ));
	LinWriteReg( HDRL,( u8 )tmp );		//֡ͷʱ

	LinWriteReg( HDP, prescaler );		//֡ͷʱƵ
}

//========================================================================
// : void LIN_Inilize( LIN_InitTypeDef *LIN )
// : LIN ʼ.
// : LIN: ṹ,οLIN.hĶ.
// : none.
// 汾: V1.0, 2021 - 6 - 2
//========================================================================
void LIN_Inilize( LIN_InitTypeDef *LIN )
{
	if ( LIN->LIN_Enable == ENABLE )	LINEN = 1;		//ʹLINģ
	else								LINEN = 0;		//رLINģ

	GetLinError();						//ȡĴ
	LinWriteReg( LIE, LIN->LIN_IE );		//LIEжʹܼĴ
	LinSetBaudrate( LIN->LIN_Baudrate );	//ò
	LinSetHeadDelay( LIN->LIN_HeadDelay, LIN->LIN_HeadPrescaler );	//֡ͷʱ
}
