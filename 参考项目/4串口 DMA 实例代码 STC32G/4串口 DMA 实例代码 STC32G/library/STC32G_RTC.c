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

#include	"STC32G_RTC.h"

//========================================================================
// º¯Êý: u8	ADC_Inilize(ADC_InitTypeDef *ADCx)
// ÃèÊö: ADC³õÊ¼»¯³ÌÐò.
// ²ÎÊý: ADCx: ½á¹¹²ÎÊý,Çë²Î¿¼adc.hÀïµÄ¶¨Òå.
// ·µ»Ø: none.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
u8	RTC_Inilize(RTC_InitTypeDef *RTCx)
{
	if(RTCx->RTC_Year > 99)	return FAIL;	//´íÎó
	if(RTCx->RTC_Month > 12)	return FAIL;	//´íÎó
	if(RTCx->RTC_Day > 31)	return FAIL;	//´íÎó
	if(RTCx->RTC_Hour > 23)	return FAIL;	//´íÎó
	if(RTCx->RTC_Min > 59)	return FAIL;	//´íÎó
	if(RTCx->RTC_Sec > 59)	return FAIL;	//´íÎó
	if(RTCx->RTC_Ssec > 127)	return FAIL;	//´íÎó
	if(RTCx->RTC_ALAHour > 23)	return FAIL;	//´íÎó
	if(RTCx->RTC_ALAMin > 59)	return FAIL;	//´íÎó
	if(RTCx->RTC_ALASec > 59)	return FAIL;	//´íÎó
	if(RTCx->RTC_ALASsec > 127)	return FAIL;	//´íÎó

	INIYEAR = RTCx->RTC_Year;
	INIMONTH = RTCx->RTC_Month;
	INIDAY = RTCx->RTC_Day;
	INIHOUR = RTCx->RTC_Hour;
	INIMIN = RTCx->RTC_Min;
	INISEC = RTCx->RTC_Sec;
	INISSEC = RTCx->RTC_Ssec;

	ALAHOUR = RTCx->RTC_ALAHour;	//ÄÖÖÓÐ¡Ê±
	ALAMIN  = RTCx->RTC_ALAMin;		//ÄÖÖÓ·ÖÖÓ
	ALASEC  = RTCx->RTC_ALASec;		//ÄÖÖÓÃë
	ALASSEC = RTCx->RTC_ALASsec;	//ÄÖÖÓ1/128Ãë

	if(RTCx->RTC_Clock == RTC_IRC32KCR)
	{
    //STC32G Ð¾Æ¬Ê¹ÓÃÄÚ²¿32KÊ±ÖÓ£¬ÐÝÃßÎÞ·¨»½ÐÑ
		IRC32KCR = 0x80;   //Æô¶¯ÄÚ²¿32K¾§Õñ.
		while (!(IRC32KCR & 1));  //µÈ´ýÊ±ÖÓÎÈ¶¨
		RTCCFG = 0x03;    //Ñ¡ÔñÄÚ²¿32KÊ±ÖÓÔ´£¬´¥·¢RTC¼Ä´æÆ÷³õÊ¼»¯
	}
	else
	{
		X32KCR = 0x80 + 0x40;   //Æô¶¯Íâ²¿32K¾§Õñ, µÍÔöÒæ+0x00, ¸ßÔöÒæ+0x40.
		while (!(X32KCR & 1));  //µÈ´ýÊ±ÖÓÎÈ¶¨
		RTCCFG = 0x01;    //Ñ¡ÔñÍâ²¿32KÊ±ÖÓÔ´£¬´¥·¢RTC¼Ä´æÆ÷³õÊ¼»¯
	}

	if(RTCx->RTC_Enable == ENABLE)
	{
		RTCCR = 0x01;     //RTCÊ¹ÄÜ
		while(RTCCFG & 0x01);	//µÈ´ý³õÊ¼»¯Íê³É,ÐèÒªÔÚ "RTCÊ¹ÄÜ" Ö®ºóÅÐ¶Ï. 
		//ÉèÖÃRTCÊ±¼äÐèÒª32768HzµÄ1¸öÖÜÆÚÊ±¼ä,´óÔ¼30.5us. ÓÉÓÚÍ¬²½, ËùÒÔÊµ¼ÊµÈ´ýÊ±¼äÊÇ0~30.5us.
		//Èç¹û²»µÈ´ýÉèÖÃÍê³É¾ÍË¯Ãß, ÔòRTC»áÓÉÓÚÉèÖÃÃ»Íê³É, Í£Ö¹¼ÆÊý, »½ÐÑºó²Å¼ÌÐøÍê³ÉÉèÖÃ²¢¼ÌÐø¼ÆÊý.
	}
	else
	{
		RTCCR = 0x00;     //RTC¹Ø±Õ
	}
	
	return SUCCESS;
}


