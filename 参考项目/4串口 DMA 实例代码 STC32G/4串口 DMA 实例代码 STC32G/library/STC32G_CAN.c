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

#include "STC32G_CAN.h"

CAN_DataDef CAN1_Tx;
CAN_DataDef CAN1_Rx[8];

CAN_DataDef CAN2_Tx;
CAN_DataDef CAN2_Rx[8];

//========================================================================
// º¯Êý: u8 ReadReg(u8 addr)
// ÃèÊö: CAN¹¦ÄÜ¼Ä´æÆ÷¶ÁÈ¡º¯Êý¡£
// ²ÎÊý: CAN¹¦ÄÜ¼Ä´æÆ÷µØÖ·.
// ·µ»Ø: CAN¹¦ÄÜ¼Ä´æÆ÷Êý¾Ý.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2020-11-16
// ±¸×¢: 
//========================================================================
u8 CanReadReg(u8 addr)
{
    u8 dat;
    CANAR = addr;
    dat = CANDR;
    return dat;
}

//========================================================================
// º¯Êý: void WriteReg(u8 addr, u8 dat)
// ÃèÊö: CAN¹¦ÄÜ¼Ä´æÆ÷ÅäÖÃº¯Êý¡£
// ²ÎÊý: CAN¹¦ÄÜ¼Ä´æÆ÷µØÖ·, CAN¹¦ÄÜ¼Ä´æÆ÷Êý¾Ý.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2020-11-16
// ±¸×¢: 
//========================================================================
void CanWriteReg(u8 addr, u8 dat)
{
    CANAR = addr;
    CANDR = dat;
}

//========================================================================
// º¯Êý: void CAN_Inilize(u8 CANx, CAN_InitTypeDef *CAN)
// ÃèÊö: CAN ³õÊ¼»¯³ÌÐò.
// ²ÎÊý: CAN: ½á¹¹²ÎÊý,Çë²Î¿¼CAN.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2021-06-02
//========================================================================
void CAN_Inilize(u8 CANx, CAN_InitTypeDef *CAN)
{
    if(CANx == CAN1)
    {
        CANSEL = CAN1;		//Ñ¡ÔñCAN1Ä£¿é
        CanWriteReg(MR  ,0x04);		//Ê¹ÄÜ Reset Mode

        if(CAN->CAN_Enable == ENABLE)	CANEN = 1;		//Ê¹ÄÜCAN1Ä£¿é
        else								CANEN = 0;		//¹Ø±ÕCAN1Ä£¿é
        
        CanWriteReg(BTR0,(u8)((CAN->CAN_SJW << 6) + CAN->CAN_BRP));
        CanWriteReg(BTR1,(u8)((CAN->CAN_SAM << 7) + (CAN->CAN_TSG2 << 4) + CAN->CAN_TSG1));

        CanWriteReg(ACR0,CAN->CAN_ACR0);		//×ÜÏßÑéÊÕ´úÂë¼Ä´æÆ÷
        CanWriteReg(ACR1,CAN->CAN_ACR1);
        CanWriteReg(ACR2,CAN->CAN_ACR2);
        CanWriteReg(ACR3,CAN->CAN_ACR3);
        CanWriteReg(AMR0,CAN->CAN_AMR0);		//×ÜÏßÑéÊÕÆÁ±Î¼Ä´æÆ÷
        CanWriteReg(AMR1,CAN->CAN_AMR1);
        CanWriteReg(AMR2,CAN->CAN_AMR2);
        CanWriteReg(AMR3,CAN->CAN_AMR3);

        CanWriteReg(ISR ,0xff);		//ÇåÖÐ¶Ï±êÖ¾
        CanWriteReg(IMR ,CAN->CAN_IMR);			//ÖÐ¶Ï¼Ä´æÆ÷ÉèÖÃ
        CanWriteReg(MR  ,0x00);		//ÍË³ö Reset Mode
    }
    else if(CANx == CAN2)
    {
        CANSEL = CAN2;		//Ñ¡ÔñCAN2Ä£¿é
        
        CanWriteReg(MR  ,0x04);		//Ê¹ÄÜ Reset Mode

        if(CAN->CAN_Enable == ENABLE)	CAN2EN = 1;		//Ê¹ÄÜCAN2Ä£¿é
        else								CAN2EN = 0;		//¹Ø±ÕCAN2Ä£¿é
        
        CanWriteReg(BTR0,(u8)((CAN->CAN_SJW << 6) + CAN->CAN_BRP));
        CanWriteReg(BTR1,(u8)((CAN->CAN_SAM << 7) + (CAN->CAN_TSG2 << 4) + CAN->CAN_TSG1));

        CanWriteReg(ACR0,CAN->CAN_ACR0);		//×ÜÏßÑéÊÕ´úÂë¼Ä´æÆ÷
        CanWriteReg(ACR1,CAN->CAN_ACR1);
        CanWriteReg(ACR2,CAN->CAN_ACR2);
        CanWriteReg(ACR3,CAN->CAN_ACR3);
        CanWriteReg(AMR0,CAN->CAN_AMR0);		//×ÜÏßÑéÊÕÆÁ±Î¼Ä´æÆ÷
        CanWriteReg(AMR1,CAN->CAN_AMR1);
        CanWriteReg(AMR2,CAN->CAN_AMR2);
        CanWriteReg(AMR3,CAN->CAN_AMR3);

        CanWriteReg(ISR ,0xff);		//ÇåÖÐ¶Ï±êÖ¾
        CanWriteReg(IMR ,CAN->CAN_IMR);			//ÖÐ¶Ï¼Ä´æÆ÷ÉèÖÃ
        CanWriteReg(MR  ,0x00);		//ÍË³ö Reset Mode
    }
}

//========================================================================
// º¯Êý: void CanReadFifo(CAN_DataDef *CANx)
// ÃèÊö: ¶ÁÈ¡CAN»º³åÇøÊý¾Ýº¯Êý¡£
// ²ÎÊý: *CANx: ´æ·ÅCAN×ÜÏß¶ÁÈ¡Êý¾Ý.
// ·µ»Ø: none.
// °æ±¾: VER2.0
// ÈÕÆÚ: 2023-01-31
// ±¸×¢: 
//========================================================================
void CanReadFifo(CAN_DataDef *CAN)
{
    u8 i;
    u8 pdat[5];
    u8 RX_Index=0;

    pdat[0] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));

    if(pdat[0] & 0x80)  //ÅÐ¶ÏÊÇ±ê×¼Ö¡»¹ÊÇÀ©Õ¹Ö¡
    {
        pdat[1] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));   //À©Õ¹Ö¡IDÕ¼4¸ö×Ö½Ú
        pdat[2] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));
        pdat[3] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));
        pdat[4] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));
        CAN->ID = (((u32)pdat[1] << 24) + ((u32)pdat[2] << 16) + ((u32)pdat[3] << 8) + pdat[4]) >> 3;
    }
    else
    {
        pdat[1] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));   //±ê×¼Ö¡IDÕ¼2¸ö×Ö½Ú
        pdat[2] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));
        CAN->ID = ((pdat[1] << 8) + pdat[2]) >> 5;
    }
    
    CAN->FF = pdat[0] >> 7;     //Ö¡¸ñÊ½
    CAN->RTR = pdat[0] >> 6;    //Ö¡ÀàÐÍ
    CAN->DLC = pdat[0];         //Êý¾Ý³¤¶È

    for(i=0;((i<CAN->DLC) && (i<8));i++)        //¶ÁÈ¡Êý¾Ý³¤¶ÈÎªlen£¬×î¶à²»³¬¹ý8
    {
        CAN->DataBuffer[i] = CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));   //¶ÁÈ¡ÓÐÐ§Êý¾Ý
    }
    while(RX_Index&3)   //ÅÐ¶ÏÒÑ¶ÁÊý¾Ý³¤¶ÈÊÇ·ñ4µÄÕûÊý±¶
    {
        CanReadReg((u8)(RX_BUF0 + (RX_Index++&3)));  //¶ÁÈ¡Ìî³äÊý¾Ý£¬Ò»Ö¡Êý¾ÝÕ¼¾Ý4µÄÕûÊý±¶»º³åÇø¿Õ¼ä£¬²»×ã²¹0
    }
}

//========================================================================
// º¯Êý: u8 CanReadMsg(void)
// ÃèÊö: CAN½ÓÊÕÊý¾Ýº¯Êý¡£
// ²ÎÊý: *CANx: ´æ·ÅCAN×ÜÏß¶ÁÈ¡Êý¾Ý..
// ·µ»Ø: Ö¡¸öÊý.
// °æ±¾: VER2.0
// ÈÕÆÚ: 2023-01-31
// ±¸×¢: 
//========================================================================
u8 CanReadMsg(CAN_DataDef *CAN)
{
    u8 i;
    u8 n=0;

    do{
        CanReadFifo(&CAN[n++]);  //¶ÁÈ¡½ÓÊÕ»º³åÇøÊý¾Ý
        i = CanReadReg(SR);
    }while(i&0x80);     //ÅÐ¶Ï½ÓÊÕ»º³åÇøÀïÊÇ·ñ»¹ÓÐÊý¾Ý£¬ÓÐµÄ»°¼ÌÐø¶ÁÈ¡

    return n;   //·µ»ØÖ¡¸öÊý
}

//========================================================================
// º¯Êý: void CanSendMsg(CAN_DataDef *CAN)
// ÃèÊö: CAN·¢ËÍ±ê×¼Ö¡º¯Êý¡£
// ²ÎÊý: *CANx: ´æ·ÅCAN×ÜÏß·¢ËÍÊý¾Ý..
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2020-11-19
// ±¸×¢: 
//========================================================================
void CanSendMsg(CAN_DataDef *CAN)
{
	u32 CanID;
    u8 RX_Index,i;

    if(CAN->FF)     //ÅÐ¶ÏÊÇ·ñÀ©Õ¹Ö¡
    {
        CanID = CAN->ID << 3;
        CanWriteReg(TX_BUF0,CAN->DLC|((u8)CAN->RTR<<6)|0x80);	//bit7: ±ê×¼Ö¡(0)/À©Õ¹Ö¡(1), bit6: Êý¾ÝÖ¡(0)/Ô¶³ÌÖ¡(1), bit3~bit0: Êý¾Ý³¤¶È(DLC)
        CanWriteReg(TX_BUF1,(u8)(CanID>>24));
        CanWriteReg(TX_BUF2,(u8)(CanID>>16));
        CanWriteReg(TX_BUF3,(u8)(CanID>>8));

        CanWriteReg(TX_BUF0,(u8)CanID);

        RX_Index = 1;
        for(i=0;((i<CAN->DLC) && (i<8));i++)        //Êý¾Ý³¤¶ÈÎªDLC£¬×î¶à²»³¬¹ý8
        {
            CanWriteReg((u8)(TX_BUF0 + (RX_Index++&3)),CAN->DataBuffer[i]);   //Ð´ÈëÓÐÐ§Êý¾Ý
        }
        while(RX_Index&3)   //ÅÐ¶ÏÒÑ¶ÁÊý¾Ý³¤¶ÈÊÇ·ñ4µÄÕûÊý±¶
        {
            CanWriteReg((u8)(TX_BUF0 + (RX_Index++&3)),0x00);  //Ð´ÈëÌî³äÊý¾Ý£¬Ò»Ö¡Êý¾ÝÕ¼¾Ý4µÄÕûÊý±¶»º³åÇø¿Õ¼ä£¬²»×ã²¹0
        }
    }
    else    //·¢ËÍ±ê×¼Ö¡
    {
        CanID = (u16)(CAN->ID << 5);
        CanWriteReg(TX_BUF0,CAN->DLC|((u8)CAN->RTR<<6));  //bit7: ±ê×¼Ö¡(0)/À©Õ¹Ö¡(1), bit6: Êý¾ÝÖ¡(0)/Ô¶³ÌÖ¡(1), bit3~bit0: Êý¾Ý³¤¶È(DLC)
        CanWriteReg(TX_BUF1,(u8)(CanID>>8));
        CanWriteReg(TX_BUF2,(u8)CanID);

        RX_Index = 3;
        for(i=0;((i<CAN->DLC) && (i<8));i++)        //Êý¾Ý³¤¶ÈÎªDLC£¬×î¶à²»³¬¹ý8
        {
            CanWriteReg((u8)(TX_BUF0 + (RX_Index++&3)),CAN->DataBuffer[i]);   //Ð´ÈëÓÐÐ§Êý¾Ý
        }
        while(RX_Index&3)   //ÅÐ¶ÏÒÑ¶ÁÊý¾Ý³¤¶ÈÊÇ·ñ4µÄÕûÊý±¶
        {
            CanWriteReg((u8)(TX_BUF0 + (RX_Index++&3)),0x00);  //Ð´ÈëÌî³äÊý¾Ý£¬Ò»Ö¡Êý¾ÝÕ¼¾Ý4µÄÕûÊý±¶»º³åÇø¿Õ¼ä£¬²»×ã²¹0
        }
    }
	CanWriteReg(CMR ,0x04);		//·¢ÆðÒ»´ÎÖ¡´«Êä
}
