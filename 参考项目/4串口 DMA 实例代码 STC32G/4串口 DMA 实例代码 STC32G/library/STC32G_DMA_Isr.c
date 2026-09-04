/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* Èç¹ûÒªÔÚ³ÌÐòÖÐÊ¹ÓÃ´Ë´úÂë,ÇëÔÚ³ÌÐòÖÐ×¢Ã÷Ê¹ÓÃÁËSTCµÄ×ÊÁÏ¼°³ÌÐò            */
/*---------------------------------------------------------------------*/

#include "STC32G_DMA.h"
#include "STC32G_SPI.h"
#include "STC32G_LCM.h"

bit	DmaTx1Flag;
bit	DmaRx1Flag;
bit	DmaTx2Flag;
bit	DmaRx2Flag;
bit	DmaTx3Flag;
bit	DmaRx3Flag;
bit	DmaTx4Flag;
bit	DmaRx4Flag;

u16 LCM_Cnt;
bit DmaLcmFlag;

bit DmaADCFlag = 0;
bit DmaM2MFlag = 0;
bit	DmaI2CTFlag=0;
bit	DmaI2CRFlag=0;

bit	SpiTxFlag;
bit	SpiRxFlag;

bit	u2sFlag;    //UART to SPI
bit	s2uFlag;    //SPI to UART

bit	SpiSendFlag;
bit	UartSendFlag;

//========================================================================
// º¯Êý: DMA_ADC_ISR_Handler
// ÃèÊö: DMA ADC ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_ADC_ISR_Handler (void) interrupt DMA_ADC_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_ADC_STA & 0x01)	//AD×ª»»Íê³É
	{
		DMA_ADC_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaADCFlag = 1;
	}
}

//========================================================================
// º¯Êý: DMA_M2M_ISR_Handler
// ÃèÊö: DMA M2M ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_M2M_ISR_Handler (void) interrupt DMA_M2M_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_M2M_STA & 0x01)	//M2M´«ÊäÍê³É
	{
		DMA_M2M_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaM2MFlag = 1;
		if(u2sFlag)
		{
			u2sFlag = 0;
			SpiSendFlag = 1;
		}
		if(s2uFlag)
		{
			s2uFlag = 0;
			UartSendFlag = 1;
		}
	}
}

//========================================================================
// º¯Êý: DMA_UART1TX_ISR_Handler
// ÃèÊö: DMA UART1 TX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART1TX_ISR_Handler (void) interrupt DMA_UR1T_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR1T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR1T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx1Flag = 1;
	}
	if (DMA_UR1T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR1T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART1RX_ISR_Handler
// ÃèÊö: DMA UART1 RX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART1RX_ISR_Handler (void) interrupt DMA_UR1R_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR1R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR1R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx1Flag = 1;

//		DMA_UR1T_TRIG();	//ÖØÐÂ´¥·¢UART1·¢ËÍ¹¦ÄÜ
//		DMA_UR1R_TRIG();	//ÖØÐÂ´¥·¢UART1½ÓÊÕ¹¦ÄÜ
	}
	if (DMA_UR1R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR1R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART2TX_ISR_Handler
// ÃèÊö: DMA UART2 TX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART2TX_ISR_Handler (void) interrupt DMA_UR2T_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR2T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR2T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx2Flag = 1;
	}
	if (DMA_UR2T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR2T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART2RX_ISR_Handler
// ÃèÊö: DMA UART2 RX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART2RX_ISR_Handler (void) interrupt DMA_UR2R_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR2R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR2R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx2Flag = 1;

//		DMA_UR2T_TRIG();	//ÖØÐÂ´¥·¢UART2·¢ËÍ¹¦ÄÜ
//		DMA_UR2R_TRIG();	//ÖØÐÂ´¥·¢UART2½ÓÊÕ¹¦ÄÜ
	}
	if (DMA_UR2R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR2R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART3TX_ISR_Handler
// ÃèÊö: DMA UART3 TX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART3TX_ISR_Handler (void) interrupt DMA_UR3T_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR3T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR3T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx3Flag = 1;
	}
	if (DMA_UR3T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR3T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART3RX_ISR_Handler
// ÃèÊö: DMA UART3 RX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART3RX_ISR_Handler (void) interrupt DMA_UR3R_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR3R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR3R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx3Flag = 1;

//		DMA_UR3T_TRIG();	//ÖØÐÂ´¥·¢UART3·¢ËÍ¹¦ÄÜ
//		DMA_UR3R_TRIG();	//ÖØÐÂ´¥·¢UART3½ÓÊÕ¹¦ÄÜ
	}
	if (DMA_UR3R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR3R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART4TX_ISR_Handler
// ÃèÊö: DMA UART4 TX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART4TX_ISR_Handler (void) interrupt DMA_UR4T_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR4T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR4T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx4Flag = 1;
	}
	if (DMA_UR4T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR4T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_UART4RX_ISR_Handler
// ÃèÊö: DMA UART4 RX ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_UART4RX_ISR_Handler (void) interrupt DMA_UR4R_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if (DMA_UR4R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR4R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx4Flag = 1;

//		DMA_UR4T_TRIG();	//ÖØÐÂ´¥·¢UART4·¢ËÍ¹¦ÄÜ
//		DMA_UR4R_TRIG();	//ÖØÐÂ´¥·¢UART4½ÓÊÕ¹¦ÄÜ
	}
	if (DMA_UR4R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR4R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_SPI_ISR_Handler
// ÃèÊö: DMA SPI ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_SPI_ISR_Handler (void) interrupt DMA_SPI_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_SPI_STA & 0x01)	//Í¨ÐÅÍê³É
	{
		DMA_SPI_STA &= ~0x01;	//Çå±êÖ¾Î»
		if(MSTR) 
		{ //Ö÷»úÄ£Ê½
			SpiTxFlag = 1;
			SPI_SS_2 = 1;
		}
		else 
		{ //´Ó»úÄ£Ê½
			SpiRxFlag = 1;
		}
	}
	if(DMA_SPI_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_SPI_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
	if(DMA_SPI_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_SPI_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_I2C_ISR_Handler
// ÃèÊö: DMA I2C ·¢ËÍÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-25
//========================================================================
void DMA_I2CT_ISR_Handler (void) interrupt DMA_I2CT_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_I2CT_STA & 0x01)   //·¢ËÍÍê³É
	{
		DMA_I2CT_STA &= ~0x01;  //Çå³ý±êÖ¾Î»
		DmaI2CTFlag = 0;
	}
	if(DMA_I2CT_STA & 0x04)   //Êý¾Ý¸²¸Ç
	{
		DMA_I2CT_STA &= ~0x04;  //Çå³ý±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_I2CR_ISR_Handler
// ÃèÊö: DMA I2C ½ÓÊÕÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-25
//========================================================================
void DMA_I2CR_ISR_Handler (void) interrupt DMA_I2CR_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_I2CR_STA & 0x01)   //½ÓÊÕÍê³É
	{
		DMA_I2CR_STA &= ~0x01;  //Çå³ý±êÖ¾Î»
		DmaI2CRFlag = 0;
	}
	if(DMA_I2CR_STA & 0x02)   //Êý¾Ý¶ªÆú
	{
		DMA_I2CR_STA &= ~0x02;  //Çå³ý±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_LCM_ISR_Handler
// ÃèÊö: DMA LCM ÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2022-03-23
//========================================================================
void DMA_LCM_ISR_Handler (void) interrupt DMA_LCM_VECTOR
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	if(DMA_LCM_STA & 0x01)
	{
		if(DmaLcmFlag)
		{
			DmaLcmFlag = 0;
			DMA_LCM_CR = 0;
		}
		else
		{
			LCM_Cnt--;
			if(LCM_Cnt == 0)
			{
				DMA_LCM_CR = 0;
				LCD_CS=1;
			}
			else
			{
				DMA_LCM_CR = 0xa0;	//Write dat
			}
		}
		DMA_LCM_STA = 0;		//Çå±êÖ¾Î»
	}
}

//========================================================================
// º¯Êý: DMA_ISR_Handler
// ÃèÊö: DMAÖÐ¶Ïº¯Êý.
// ²ÎÊý: none.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2021-05-25
//========================================================================
void DMA_ISR_Handler (void) interrupt 13
{
	// TODO: ÔÚ´Ë´¦Ìí¼ÓÓÃ»§´úÂë
	
	//----------- DMA ADC --------------
	if(DMA_ADC_STA & 0x01)	//AD×ª»»Íê³É
	{
		DMA_ADC_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaADCFlag = 1;
	}

	//----------- DMA M2M --------------
	if(DMA_M2M_STA & 0x01)	//M2M´«ÊäÍê³É
	{
		DMA_M2M_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaM2MFlag = 1;
		if(u2sFlag)
		{
			u2sFlag = 0;
			SpiSendFlag = 1;
		}
		if(s2uFlag)
		{
			s2uFlag = 0;
			UartSendFlag = 1;
		}
	}

	//---------- DMA UART1 -------------
	if (DMA_UR1T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR1T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx1Flag = 1;
	}
	if (DMA_UR1T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR1T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
	
	if (DMA_UR1R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR1R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx1Flag = 1;
	}
	if (DMA_UR1R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR1R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
	//---------- DMA UART2 -------------
	if (DMA_UR2T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR2T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx2Flag = 1;
	}
	if (DMA_UR2T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR2T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
	
	if (DMA_UR2R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR2R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx2Flag = 1;
	}
	if (DMA_UR2R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR2R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
	//---------- DMA UART3 -------------
	if (DMA_UR3T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR3T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx3Flag = 1;
	}
	if (DMA_UR3T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR3T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
	
	if (DMA_UR3R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR3R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx3Flag = 1;
	}
	if (DMA_UR3R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR3R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
	//---------- DMA UART4 -------------
	if (DMA_UR4T_STA & 0x01)	//·¢ËÍÍê³É
	{
		DMA_UR4T_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaTx4Flag = 1;
	}
	if (DMA_UR4T_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_UR4T_STA &= ~0x04;	//Çå±êÖ¾Î»
	}
	
	if (DMA_UR4R_STA & 0x01)	//½ÓÊÕÍê³É
	{
		DMA_UR4R_STA &= ~0x01;	//Çå±êÖ¾Î»
		DmaRx4Flag = 1;
	}
	if (DMA_UR4R_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_UR4R_STA &= ~0x02;	//Çå±êÖ¾Î»
	}

	//---------- DMA SPI -------------
	if(DMA_SPI_STA & 0x01)	//Í¨ÐÅÍê³É
	{
		DMA_SPI_STA &= ~0x01;	//Çå±êÖ¾Î»
		if(MSTR) 
		{ //Ö÷»úÄ£Ê½
			SpiTxFlag = 1;
			SPI_SS_2 = 1;
		}
		else 
		{ //´Ó»úÄ£Ê½
			SpiRxFlag = 1;
		}
	}
	if(DMA_SPI_STA & 0x02)	//Êý¾Ý¶ªÆú
	{
		DMA_SPI_STA &= ~0x02;	//Çå±êÖ¾Î»
	}
	if(DMA_SPI_STA & 0x04)	//Êý¾Ý¸²¸Ç
	{
		DMA_SPI_STA &= ~0x04;	//Çå±êÖ¾Î»
	}

	//------------- LCM --------------
	if(LCMIFSTA & 0x01)
	{
		LCMIFSTA = 0x00;
		LcmFlag = 0;
	}
	
	//---------- DMA LCM -------------
	if(DMA_LCM_STA & 0x01)
	{
		if(DmaLcmFlag)
		{
			DmaLcmFlag = 0;
			DMA_LCM_CR = 0;
		}
		else
		{
			LCM_Cnt--;
			if(LCM_Cnt == 0)
			{
				DMA_LCM_CR = 0;
				LCD_CS=1;
			}
			else
			{
				DMA_LCM_CR = 0xa0;	//Write dat
			}
		}
		DMA_LCM_STA = 0;		//Çå±êÖ¾Î»
	}
}
