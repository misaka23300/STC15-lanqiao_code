/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* ﺫﻝﺗﻳﺻ۹ﺿﻌﺏﮊﺷﮨﻅﺷﮌﺗﺽﺣﺑﺯﺑﻲﺡﻣ,ﮄﻣﺿﻌﺏﮊﺷﮨﻅﺷﻉ۱ﺣﺊﮌﺗﺽﺣﭼﺯSTCﭖﺥﻉﮌﭼﺵﺙﺍﺏﮊﺷﮨ            */
/*---------------------------------------------------------------------*/


/*************  ﺗ۵ﺥﻎﺯﭖﺣﺊ    **************

ﺎﺝﭺﮮﺏﮊﭨﻱﺽﻌSTC32Gﺳ۹ﻅﺊﺟﻊﺷﺝﺩ؛ﭖﺥﮌﭖﺹﻠﺵﻛ9ﺛﺋﺷﺷﺎﻓﺷﺑﺎﻗﮌﺿ.

ﺕﻑﺙﭘPWMBﭘ۷ﮌﺎﺩﺊ PWM5,PWM6,PWM7,PWM8 ﺣﺟﺕﺉﺱ۷ﭖﭺﭘﺙﺟﺭﭘﭺﭼ۱ﮌﭖﺵﻅPWMﮌﻛﺏﺉ.

4ﺕﺉﺱ۷ﭖﭺPWMﺕﻱﺝﻏﺷﻟﺻ۹ﺭﻟﻅﺣﭘﺿﺽ۵ﮌﻛﺏﺉﺟﻌ۲؛ﺟﺭﺱ۷ﺗﮮﮌﺝﺎ۷ﺩﺊﺗﻍﺎﮞﮌﻛﺏﺉﭦﮪﺳﮰﭖﺩﺷ۶ﺗﻳﭖﺥﺡﺉﺏﮒﺷﺧﭦﺧ.

PWMﻅﻎﺩﻌﭦﺱﻁﺙﺟﻁﺎﺫﺟﺭﺻﺿﻉﺿﭘ۷ﺻﮒﺭﻟﻅﺣ۲؛ﻉﻧﺕﻑﺟﺭﺑﺅ65535.

******************************************/

#include "FreeRTOS.h"
#include "task.h"
#include "STC32G_PWM.h"
#include "STC32G_NVIC.h"
#include "pwmb.h"

#define PWMB_PERIOD     2047  //ﭘ۷ﺻﮒPWMﻅﻎﺩﻌ

PWMx_Duty PWMB_Duty;
bit PWM5_Flag;
bit PWM6_Flag;
bit PWM7_Flag;
bit PWM8_Flag;

void PWMB_Output_init(void);

/* PWMBﺫﺳﺳﮦﭦﺁﮌﮮ */
portTASK_FUNCTION( vPWMB_LedTask, pvParameters )
{
    UNUSED( pvParameters );

	PWMB_Output_init();

    while(1)
    {
        if(!PWM5_Flag)
        {
            PWMB_Duty.PWM5_Duty++;
            if(PWMB_Duty.PWM5_Duty >= PWMB_PERIOD) PWM5_Flag = 1;
        }
        else
        {
            PWMB_Duty.PWM5_Duty--;
            if(PWMB_Duty.PWM5_Duty <= 0) PWM5_Flag = 0;
        }

        if(!PWM6_Flag)
        {
            PWMB_Duty.PWM6_Duty++;
            if(PWMB_Duty.PWM6_Duty >= PWMB_PERIOD) PWM6_Flag = 1;
        }
        else
        {
            PWMB_Duty.PWM6_Duty--;
            if(PWMB_Duty.PWM6_Duty <= 0) PWM6_Flag = 0;
        }

        if(!PWM7_Flag)
        {
            PWMB_Duty.PWM7_Duty++;
            if(PWMB_Duty.PWM7_Duty >= PWMB_PERIOD) PWM7_Flag = 1;
        }
        else
        {
            PWMB_Duty.PWM7_Duty--;
            if(PWMB_Duty.PWM7_Duty <= 0) PWM7_Flag = 0;
        }

        if(!PWM8_Flag)
        {
            PWMB_Duty.PWM8_Duty++;
            if(PWMB_Duty.PWM8_Duty >= PWMB_PERIOD) PWM8_Flag = 1;
        }
        else
        {
            PWMB_Duty.PWM8_Duty--;
            if(PWMB_Duty.PWM8_Duty <= 0) PWM8_Flag = 0;
        }
        
        UpdatePwm(PWMB, &PWMB_Duty);
        
        vTaskDelay(1);
    }
    
    vTaskDelete(NULL);
}   

//========================================================================
// ﭦﺁﮌﮮ: PWMB_Output_init
// ﺣﻟﮌﺉ: ﺽﺣﭨ۶ﺏﺀﮌﺙﭨﺁﺏﮊﺷﮨ.
// ﺎﺳﮌﮮ: None.
// ﺓﭖﭨﻊ: None.
// ﺍﮔﺎﺝ: V1.0, 2020-09-28
//========================================================================
void PWMB_Output_init(void)
{
	PWMx_InitDefine		PWMx_InitStructure;
	
	PWMB_Duty.PWM5_Duty = 128;
	PWMB_Duty.PWM6_Duty = 256;
	PWMB_Duty.PWM7_Duty = 512;
	PWMB_Duty.PWM8_Duty = 1024;

	PWMx_InitStructure.PWM_Mode    =	CCMRn_PWM_MODE1;	//ﺥ۲ﮌﺛ,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	PWMx_InitStructure.PWM_Duty    = PWMB_Duty.PWM5_Duty;	//PWMﻁﺙﺟﻁﺎﺫﮌﺎﺙﻛ, 0~Period
	PWMx_InitStructure.PWM_EnoSelect   = ENO5P;				//ﮌﻛﺏﺉﺱ۷ﭖﭺﺹ۰ﺿﮦ,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	PWM_Configuration(PWM5, &PWMx_InitStructure);			//ﺏﺀﮌﺙﭨﺁPWM,  PWMA,PWMB

	PWMx_InitStructure.PWM_Mode    =	CCMRn_PWM_MODE1;	//ﺥ۲ﮌﺛ,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	PWMx_InitStructure.PWM_Duty    = PWMB_Duty.PWM6_Duty;	//PWMﻁﺙﺟﻁﺎﺫﮌﺎﺙﻛ, 0~Period
	PWMx_InitStructure.PWM_EnoSelect   = ENO6P;				//ﮌﻛﺏﺉﺱ۷ﭖﭺﺹ۰ﺿﮦ,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	PWM_Configuration(PWM6, &PWMx_InitStructure);			//ﺏﺀﮌﺙﭨﺁPWM,  PWMA,PWMB

	PWMx_InitStructure.PWM_Mode    =	CCMRn_PWM_MODE1;	//ﺥ۲ﮌﺛ,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	PWMx_InitStructure.PWM_Duty    = PWMB_Duty.PWM7_Duty;	//PWMﻁﺙﺟﻁﺎﺫﮌﺎﺙﻛ, 0~Period
	PWMx_InitStructure.PWM_EnoSelect   = ENO7P;				//ﮌﻛﺏﺉﺱ۷ﭖﭺﺹ۰ﺿﮦ,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	PWM_Configuration(PWM7, &PWMx_InitStructure);			//ﺏﺀﮌﺙﭨﺁPWM,  PWMA,PWMB

	PWMx_InitStructure.PWM_Mode    =	CCMRn_PWM_MODE1;	//ﺥ۲ﮌﺛ,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	PWMx_InitStructure.PWM_Duty    = PWMB_Duty.PWM8_Duty;	//PWMﻁﺙﺟﻁﺎﺫﮌﺎﺙﻛ, 0~Period
	PWMx_InitStructure.PWM_EnoSelect   = ENO8P;				//ﮌﻛﺏﺉﺱ۷ﭖﭺﺹ۰ﺿﮦ,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	PWM_Configuration(PWM8, &PWMx_InitStructure);			//ﺏﺀﮌﺙﭨﺁPWM,  PWMA,PWMB

	PWMx_InitStructure.PWM_Period   = PWMB_PERIOD;			//ﻅﻎﺩﻌﮌﺎﺙﻛ,   0~65535
	PWMx_InitStructure.PWM_DeadTime = 0;					//ﺯﭺﮄﺋﺓ۱ﺭﻲﺩﺊﺭﻟﻅﺣ, 0~255
	PWMx_InitStructure.PWM_MainOutEnable= ENABLE;			//ﻅﺊﮌﻛﺏﺉﮌﺗﺥﻎ, ENABLE,DISABLE
	PWMx_InitStructure.PWM_CEN_Enable   = ENABLE;			//ﮌﺗﺥﻎﺙﺩﮌﮮﺩﺊ, ENABLE,DISABLE
	PWM_Configuration(PWMB, &PWMx_InitStructure);			//ﺏﺀﮌﺙﭨﺁPWMﺱ۷ﺽﺣﺙﺥﺑﮔﺩﺊ,  PWMA,PWMB

	PWM5_USE_P20();
	PWM6_USE_P21();
	PWM7_USE_P22();
	PWM8_USE_P23();

	NVIC_PWM_Init(PWMB,DISABLE,Priority_0);
}
