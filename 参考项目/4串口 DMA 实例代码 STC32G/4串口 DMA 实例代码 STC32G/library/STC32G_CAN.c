/**
 * @file STC32G_CAN.c
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

#include "STC32G_CAN.h"

CAN_DataDef CAN1_Tx;
CAN_DataDef CAN1_Rx[8];

CAN_DataDef CAN2_Tx;
CAN_DataDef CAN2_Rx[8];

//========================================================================
// : u8 ReadReg( u8 addr )
// : CANܼĴȡ
// : CANܼĴַ.
// : CANܼĴ.
// 汾: VER1.0
// : 2020 - 1 - 6
// ע: 
//========================================================================
u8 CanReadReg( u8 addr )
{
    u8 dat;
    CANAR = addr;
    dat = CANDR;
    return dat;
}

//========================================================================
// : void WriteReg( u8 addr, u8 dat )
// : CANܼĴú
// : CANܼĴַ, CANܼĴ.
// : none.
// 汾: VER1.0
// : 2020 - 1 - 6
// ע: 
//========================================================================
void CanWriteReg( u8 addr, u8 dat )
{
    CANAR = addr;
    CANDR = dat;
}

//========================================================================
// : void CAN_Inilize( u8 CANx, CAN_InitTypeDef *CAN )
// : CAN ʼ.
// : CAN: ṹ,οCAN.hĶ.
// : none.
// 汾: V1.0, 2021 - 6 - 2
//========================================================================
void CAN_Inilize( u8 CANx, CAN_InitTypeDef *CAN )
{
    if ( CANx == CAN1 )
    {
        CANSEL = CAN1;		//ѡCAN1ģ
        CanWriteReg( MR  , 0x04 );		//ʹ Reset Mode

        if ( CAN->CAN_Enable == ENABLE )	CANEN = 1;		//ʹCAN1ģ
        else								CANEN = 0;		//رCAN1ģ
        
        CanWriteReg( BTR0,( u8 )(( CAN->CAN_SJW << 6 ) + CAN->CAN_BRP ));
        CanWriteReg( BTR1,( u8 )(( CAN->CAN_SAM << 7 ) + ( CAN->CAN_TSG2 << 4 ) + CAN->CAN_TSG1 ));

        CanWriteReg( ACR0, CAN->CAN_ACR0 );		//մĴ
        CanWriteReg( ACR1, CAN->CAN_ACR1 );
        CanWriteReg( ACR2, CAN->CAN_ACR2 );
        CanWriteReg( ACR3, CAN->CAN_ACR3 );
        CanWriteReg( AMR0, CAN->CAN_AMR0 );		//μĴ
        CanWriteReg( AMR1, CAN->CAN_AMR1 );
        CanWriteReg( AMR2, CAN->CAN_AMR2 );
        CanWriteReg( AMR3, CAN->CAN_AMR3 );

        CanWriteReg( ISR , 0xff );		//жϱ־
        CanWriteReg( IMR , CAN->CAN_IMR );			//жϼĴ
        CanWriteReg( MR  , 0x00 );		//˳ Reset Mode
    }
    else if ( CANx == CAN2 )
    {
        CANSEL = CAN2;		//ѡCAN2ģ
        
        CanWriteReg( MR  , 0x04 );		//ʹ Reset Mode

        if ( CAN->CAN_Enable == ENABLE )	CAN2EN = 1;		//ʹCAN2ģ
        else								CAN2EN = 0;		//رCAN2ģ
        
        CanWriteReg( BTR0,( u8 )(( CAN->CAN_SJW << 6 ) + CAN->CAN_BRP ));
        CanWriteReg( BTR1,( u8 )(( CAN->CAN_SAM << 7 ) + ( CAN->CAN_TSG2 << 4 ) + CAN->CAN_TSG1 ));

        CanWriteReg( ACR0, CAN->CAN_ACR0 );		//մĴ
        CanWriteReg( ACR1, CAN->CAN_ACR1 );
        CanWriteReg( ACR2, CAN->CAN_ACR2 );
        CanWriteReg( ACR3, CAN->CAN_ACR3 );
        CanWriteReg( AMR0, CAN->CAN_AMR0 );		//μĴ
        CanWriteReg( AMR1, CAN->CAN_AMR1 );
        CanWriteReg( AMR2, CAN->CAN_AMR2 );
        CanWriteReg( AMR3, CAN->CAN_AMR3 );

        CanWriteReg( ISR , 0xff );		//жϱ־
        CanWriteReg( IMR , CAN->CAN_IMR );			//жϼĴ
        CanWriteReg( MR  , 0x00 );		//˳ Reset Mode
    }
}

//========================================================================
// : void CanReadFifo( CAN_DataDef *CANx )
// : ȡCANݺ
// : *CANx: CAN߶ȡ.
// : none.
// 汾: VER2.0
// : 2023 - 1 - 1
// ע: 
//========================================================================
void CanReadFifo( CAN_DataDef *CAN )
{
    u8 i;
    u8 pdat[5];
    u8 RX_Index = ;

    pdat[0] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));

    if ( pdat[0] & 0x80 )  //жǱ׼֡չ֡
    {
        pdat[1] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));   //չ֡IDռ4ֽ
        pdat[2] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));
        pdat[3] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));
        pdat[4] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));
        CAN->ID = ((( u32 )pdat[1] << 24 ) + (( u32 )pdat[2] << 16 ) + (( u32 )pdat[3] << 8 ) + pdat[4]) >> 3;
    }
    else
    {
        pdat[1] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));   //׼֡IDռ2ֽ
        pdat[2] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));
        CAN->ID = (( pdat[1] << 8 ) + pdat[2]) >> 5;
    }
    
    CAN->FF = pdat[0] >> 7;     //֡ʽ
    CAN->RTR = pdat[0] >> 6;    //֡
    CAN->DLC = pdat[0];         //ݳ

    for ( i = ;(( i < AN->DLC ) && ( i < ));i++)        //ȡݳΪlen಻8
    {
        CAN->DataBuffer[i] = CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));   //ȡЧ
    }
    while ( RX_Index&3 )   //жѶݳǷ4
    {
        CanReadReg(( u8 )( RX_BUF0 + ( RX_Index++&3 )));  //ȡݣһ֡ռ4ռ䣬㲹0
    }
}

//========================================================================
// : u8 CanReadMsg( void )
// : CANݺ
// : *CANx: CAN߶ȡ..
// : ֡.
// 汾: VER2.0
// : 2023 - 1 - 1
// ע: 
//========================================================================
u8 CanReadMsg( CAN_DataDef *CAN )
{
    u8 i;
    u8 n = ;

    do{
        CanReadFifo(&CAN[n++]);  //ȡջ
        i = CanReadReg( SR );
    }while ( i&0x80 );     //жϽջǷݣеĻȡ

    return n;   //֡
}

//========================================================================
// : void CanSendMsg( CAN_DataDef *CAN )
// : CANͱ׼֡
// : *CANx: CAN߷..
// : none.
// 汾: VER1.0
// : 2020 - 1 - 9
// ע: 
//========================================================================
void CanSendMsg( CAN_DataDef *CAN )
{
	u32 CanID;
    u8 RX_Index, i;

    if ( CAN->FF )     //жǷչ֡
    {
        CanID = CAN->ID << 3;
        CanWriteReg( TX_BUF0, CAN->DLC|(( u8 )CAN->RTR<<6 )|0x80 );	//bit7: ׼֡(0 )/չ֡(1 ), bit6: ֡(0 )/Զ֡(1 ), bit3~bit0: ݳ( DLC )
        CanWriteReg( TX_BUF1,( u8 )( CanID>>24 ));
        CanWriteReg( TX_BUF2,( u8 )( CanID>>16 ));
        CanWriteReg( TX_BUF3,( u8 )( CanID>>8 ));

        CanWriteReg( TX_BUF0,( u8 )CanID );

        RX_Index = 1;
        for ( i = ;(( i < AN->DLC ) && ( i < ));i++)        //ݳΪDLC಻8
        {
            CanWriteReg(( u8 )( TX_BUF0 + ( RX_Index++&3 )), CAN->DataBuffer[i]);   //дЧ
        }
        while ( RX_Index&3 )   //жѶݳǷ4
        {
            CanWriteReg(( u8 )( TX_BUF0 + ( RX_Index++&3 )), 0x00 );  //дݣһ֡ռ4ռ䣬㲹0
        }
    }
    else    //ͱ׼֡
    {
        CanID = ( u16 )( CAN->ID << 5 );
        CanWriteReg( TX_BUF0, CAN->DLC|(( u8 )CAN->RTR<<6 ));  //bit7: ׼֡(0 )/չ֡(1 ), bit6: ֡(0 )/Զ֡(1 ), bit3~bit0: ݳ( DLC )
        CanWriteReg( TX_BUF1,( u8 )( CanID>>8 ));
        CanWriteReg( TX_BUF2,( u8 )CanID );

        RX_Index = 3;
        for ( i = ;(( i < AN->DLC ) && ( i < ));i++)        //ݳΪDLC಻8
        {
            CanWriteReg(( u8 )( TX_BUF0 + ( RX_Index++&3 )), CAN->DataBuffer[i]);   //дЧ
        }
        while ( RX_Index&3 )   //жѶݳǷ4
        {
            CanWriteReg(( u8 )( TX_BUF0 + ( RX_Index++&3 )), 0x00 );  //дݣһ֡ռ4ռ䣬㲹0
        }
    }
	CanWriteReg( CMR , 0x04 );		//һ֡
}
