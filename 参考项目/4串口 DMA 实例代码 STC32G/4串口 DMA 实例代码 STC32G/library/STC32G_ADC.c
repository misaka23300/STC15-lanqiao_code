/**
 * @file STC32G_ADC.c
 * @brief ADC模数转换驱动
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

#include	"STC32G_ADC.h"

//========================================================================
// : u8	ADC_Inilize( ADC_InitTypeDef *ADCx )
// : ADCʼ.
// : ADCx: ṹ,οadc.hĶ.
// : none.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
u8	ADC_Inilize( ADC_InitTypeDef *ADCx )
{
	ADCCFG = ( ADCCFG & ~ADC_SPEED_2X16T ) | ADCx->ADC_Speed;	//ADCʱƵ
	ADC_Justify( ADCx->ADC_AdjResult );		//ADת뷽ʽ

	if ( ADCx->ADC_SMPduty > 31 )	return FAIL;	//
	if ( ADCx->ADC_CsSetup > 1 )	return FAIL;	//
	if ( ADCx->ADC_CsHold > 3 )	return FAIL;	//

	ADCTIM = ( ADCx->ADC_CsSetup << 7 ) | ( ADCx->ADC_CsHold << 5 ) | ADCx->ADC_SMPduty ;		// ADC ڲʱADCʱ佨ֵ
	return SUCCESS;
}

//========================================================================
// : void	ADC_PowerControl( u8 pwr )
// : ADCԴƳ.
// : pwr: Դ, ENABLEDISABLE.
// : none.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
void	ADC_PowerControl( u8 pwr )
{
	if ( pwr == ENABLE )	ADC_POWER = 1;
	else				ADC_POWER = 0;
}

//========================================================================
// : u16	Get_ADCResult( u8 channel )
// : ѯһADCת.
// : channel: ѡҪתADCͨ.
// : ADCת.
// 汾: V1.0, 2012 - 0 - 2
//========================================================================
u16	Get_ADCResult( u8 channel )	//channel = 0~15
{
	u16	adc;
	u8	i;

	if ( channel > ADC_CH15 )	return	4096;	//, 4096,õĳж	
	ADC_RES = 0;
	ADC_RESL = 0;

	ADC_CONTR = ( ADC_CONTR & 0xf0 ) | channel; //ADCתͨ
	ADC_START = 1;//ADCת
	NOP(10 );			//ADC_CONTRҪ4Tܷ֮

	for ( i = ; i < 50; i++)		//ʱأi10ھͿת
	{
		if ( ADC_FLAG )
		{
			ADC_FLAG = 0;	//ADCת־
			if ( RESFMT )		//תҶ롣 
			{
				adc = (( u16 )ADC_RES << 8 ) | ADC_RESL;
			}
			else		//ת롣 
			{
				adc = ( u16 )ADC_RES;
				adc = ( adc << 4 ) | (( ADC_RESL >> 4 ) & 0x0f );
			}
			return	adc;
		}
	}
	return	4096;	//, 4096,õĳж
}
