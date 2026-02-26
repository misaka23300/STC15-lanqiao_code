#ifndef __STC15F_DEF_H__
#define __STC15F_DEF_H__

/////////////////////////////////////////////////

#include "stc15.h"
#include "def.h"

/////////////////////////////////////////////////

#define PORT_SetInitLevelLow(p, b)      CLR_REG_BIT(P##p, (b))
#define PORT_SetInitLevelHigh(p, b)     SET_REG_BIT(P##p, (b))

#define PORT_SetQuasiMode(p, b)         CLR_REG_BIT(P##p##M0, (b)); \
                                        CLR_REG_BIT(P##p##M1, (b))

#define PORT_SetPushPullMode(p, b)      SET_REG_BIT(P##p##M0, (b)); \
                                        CLR_REG_BIT(P##p##M1, (b))

#define PORT_SetHighZInputMode(p, b)    CLR_REG_BIT(P##p##M0, (b)); \
                                        SET_REG_BIT(P##p##M1, (b))

#define PORT_SetOpenDrainMode(p, b)     SET_REG_BIT(P##p##M0, (b)); \
                                        SET_REG_BIT(P##p##M1, (b))

#define PORT_SetAnalogInput(p, b)       SET_REG_BIT(P##p##ASF, (b))
#define PORT_SetDigitalInput(p, b)      CLR_REG_BIT(P##p##ASF, (b))

#define SetP0nInitLevelLow(b)           PORT_SetInitLevelLow(0, (b))
#define SetP1nInitLevelLow(b)           PORT_SetInitLevelLow(1, (b))
#define SetP2nInitLevelLow(b)           PORT_SetInitLevelLow(2, (b))
#define SetP3nInitLevelLow(b)           PORT_SetInitLevelLow(3, (b))
#define SetP4nInitLevelLow(b)           PORT_SetInitLevelLow(4, (b))
#define SetP5nInitLevelLow(b)           PORT_SetInitLevelLow(5, (b))
#define SetP6nInitLevelLow(b)           PORT_SetInitLevelLow(6, (b))
#define SetP7nInitLevelLow(b)           PORT_SetInitLevelLow(7, (b))

#define SetP0nInitLevelHigh(b)          PORT_SetInitLevelHigh(0, (b))
#define SetP1nInitLevelHigh(b)          PORT_SetInitLevelHigh(1, (b))
#define SetP2nInitLevelHigh(b)          PORT_SetInitLevelHigh(2, (b))
#define SetP3nInitLevelHigh(b)          PORT_SetInitLevelHigh(3, (b))
#define SetP4nInitLevelHigh(b)          PORT_SetInitLevelHigh(4, (b))
#define SetP5nInitLevelHigh(b)          PORT_SetInitLevelHigh(5, (b))
#define SetP6nInitLevelHigh(b)          PORT_SetInitLevelHigh(6, (b))
#define SetP7nInitLevelHigh(b)          PORT_SetInitLevelHigh(7, (b))

#define SetP0nQuasiMode(b)              PORT_SetQuasiMode(0, (b))
#define SetP1nQuasiMode(b)              PORT_SetQuasiMode(1, (b))
#define SetP2nQuasiMode(b)              PORT_SetQuasiMode(2, (b))
#define SetP3nQuasiMode(b)              PORT_SetQuasiMode(3, (b))
#define SetP4nQuasiMode(b)              PORT_SetQuasiMode(4, (b))
#define SetP5nQuasiMode(b)              PORT_SetQuasiMode(5, (b))
#define SetP6nQuasiMode(b)              PORT_SetQuasiMode(6, (b))
#define SetP7nQuasiMode(b)              PORT_SetQuasiMode(7, (b))

#define SetP0nPushPullMode(b)           PORT_SetPushPullMode(0, (b))
#define SetP1nPushPullMode(b)           PORT_SetPushPullMode(1, (b))
#define SetP2nPushPullMode(b)           PORT_SetPushPullMode(2, (b))
#define SetP3nPushPullMode(b)           PORT_SetPushPullMode(3, (b))
#define SetP4nPushPullMode(b)           PORT_SetPushPullMode(4, (b))
#define SetP5nPushPullMode(b)           PORT_SetPushPullMode(5, (b))
#define SetP6nPushPullMode(b)           PORT_SetPushPullMode(6, (b))
#define SetP7nPushPullMode(b)           PORT_SetPushPullMode(7, (b))

#define SetP0nHighZInputMode(b)         PORT_SetHighZInputMode(0, (b))
#define SetP1nHighZInputMode(b)         PORT_SetHighZInputMode(1, (b))
#define SetP2nHighZInputMode(b)         PORT_SetHighZInputMode(2, (b))
#define SetP3nHighZInputMode(b)         PORT_SetHighZInputMode(3, (b))
#define SetP4nHighZInputMode(b)         PORT_SetHighZInputMode(4, (b))
#define SetP5nHighZInputMode(b)         PORT_SetHighZInputMode(5, (b))
#define SetP6nHighZInputMode(b)         PORT_SetHighZInputMode(6, (b))
#define SetP7nHighZInputMode(b)         PORT_SetHighZInputMode(7, (b))

#define SetP0nOpenDrainMode(b)          PORT_SetOpenDrainMode(0, (b))
#define SetP1nOpenDrainMode(b)          PORT_SetOpenDrainMode(1, (b))
#define SetP2nOpenDrainMode(b)          PORT_SetOpenDrainMode(2, (b))
#define SetP3nOpenDrainMode(b)          PORT_SetOpenDrainMode(3, (b))
#define SetP4nOpenDrainMode(b)          PORT_SetOpenDrainMode(4, (b))
#define SetP5nOpenDrainMode(b)          PORT_SetOpenDrainMode(5, (b))
#define SetP6nOpenDrainMode(b)          PORT_SetOpenDrainMode(6, (b))
#define SetP7nOpenDrainMode(b)          PORT_SetOpenDrainMode(7, (b))

#define SetP1nAnalogInput(b)            PORT_SetAnalogInput(1, (b))
#define SetP1nDigitalInput(b)           PORT_SetDigitalInput(1, (b))

/////////////////////////////////////////////////

#define EnableGlobalInt()               (EA = 1)
#define DisableGlobalInt()              (EA = 0)

#define INT0_EnableInt()                (EX0 = 1)
#define INT0_DisableInt()               (EX0 = 0)

#define INT1_EnableInt()                (EX1 = 1)
#define INT1_DisableInt()               (EX1 = 0)

#define INTCLKO_EX2_MSK                 BIT4
#define INT2_EnableInt()                SET_REG_BIT(INT_CLKO, INTCLKO_EX2_MSK)
#define INT2_DisableInt()               CLR_REG_BIT(INT_CLKO, INTCLKO_EX2_MSK)

#define INTCLKO_EX3_MSK                 BIT5
#define INT3_EnableInt()                SET_REG_BIT(INT_CLKO, INTCLKO_EX3_MSK)
#define INT3_DisableInt()               CLR_REG_BIT(INT_CLKO, INTCLKO_EX3_MSK)

#define INTCLKO_EX4_MSK                 BIT6
#define INT4_EnableInt()                SET_REG_BIT(INT_CLKO, INTCLKO_EX4_MSK)
#define INT4_DisableInt()               CLR_REG_BIT(INT_CLKO, INTCLKO_EX4_MSK)

#define TIMER0_EnableInt()              (ET0 = 1)
#define TIMER0_DisableInt()             (ET0 = 0)

#define TIMER1_EnableInt()              (ET1 = 1)
#define TIMER1_DisableInt()             (ET1 = 0)

#define IE2_ET2_MSK                     BIT2
#define TIMER2_EnableInt()              SET_REG_BIT(IE2, IE2_ET2_MSK)
#define TIMER2_DisableInt()             CLR_REG_BIT(IE2, IE2_ET2_MSK)

#define UART1_EnableInt()               (ES = 1)
#define UART1_DisableInt()              (ES = 0)

#define IE2_ES2_MSK                     BIT0
#define UART2_EnableInt()               SET_REG_BIT(IE2, IE2_ES2_MSK)
#define UART2_DisableInt()              CLR_REG_BIT(IE2, IE2_ES2_MSK)

#define LVD_EnableInt()                 (ELVD = 1)
#define LVD_DisableInt()                (ELVD = 0)

#define ADC_EnableInt()                 (EADC = 1)
#define ADC_DisableInt()                (EADC = 0)

#define IE2_ESPI_MSK                    BIT1
#define SPI_EnableInt()                 SET_REG_BIT(IE2, IE2_ESPI_MSK)
#define SPI_DisableInt()                CLR_REG_BIT(IE2, IE2_ESPI_MSK)

#define CMOD_ECF_MSK                    BIT0
#define PCA_EnableCounterInt()          SET_REG_BIT(CMOD, CMOD_ECF_MSK)
#define PCA_DisableCounterInt()         CLR_REG_BIT(CMOD, CMOD_ECF_MSK)

#define CCAPM0_ECCF0_MSK                BIT0
#define CCAPM1_ECCF1_MSK                BIT0
#define CCAPM2_ECCF2_MSK                BIT0
#define PCA_EnableCCF0Int()             SET_REG_BIT(CCAPM0, CCAPM0_ECCF0_MSK)
#define PCA_EnableCCF1Int()             SET_REG_BIT(CCAPM1, CCAPM1_ECCF1_MSK)
#define PCA_EnableCCF2Int()             SET_REG_BIT(CCAPM2, CCAPM2_ECCF2_MSK)
#define PCA_DisableCCF0Int()            CLR_REG_BIT(CCAPM0, CCAPM0_ECCF0_MSK)
#define PCA_DisableCCF1Int()            CLR_REG_BIT(CCAPM1, CCAPM1_ECCF1_MSK)
#define PCA_DisableCCF2Int()            CLR_REG_BIT(CCAPM2, CCAPM2_ECCF2_MSK)

#define INT0_FallingRisingInt()         (IT0 = 0)
#define INT0_FallingInt()               (IT0 = 1)

#define INT0_CheckFlag()                (IE0)
#define INT0_ClearFlag()                (IE0 = 0)

#define INT1_FallingRisingInt()         (IT1 = 0)
#define INT1_FallingInt()               (IT1 = 1)

#define INT1_CheckFlag()                (IE1)
#define INT1_ClearFlag()                (IE1 = 0)

#define TIMER0_CheckFlag()              (TF0)
#define TIMER0_ClearFlag()              (TF0 = 0)

#define TIMER1_CheckFlag()              (TF1)
#define TIMER1_ClearFlag()              (TF1 = 0)

#define UART1_CheckRxFlag()             (RI)
#define UART1_CheckTxFlag()             (TI)
#define UART1_ClearRxFlag()             (RI = 0)
#define UART1_ClearTxFlag()             (TI = 0)
#define UART1_SetRxFlag()               (RI = 1)
#define UART1_SetTxFlag()               (TI = 1)

#define S2CON_S2TI_MSK                  BIT1
#define S2CON_S2RI_MSK                  BIT0
#define UART2_CheckRxFlag()             READ_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_CheckTxFlag()             READ_REG_BIT(S2CON, S2CON_S2TI_MSK)
#define UART2_ClearRxFlag()             CLR_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_ClearTxFlag()             CLR_REG_BIT(S2CON, S2CON_S2TI_MSK)
#define UART2_SetRxFlag()               SET_REG_BIT(S2CON, S2CON_S2RI_MSK)
#define UART2_SetTxFlag()               SET_REG_BIT(S2CON, S2CON_S2TI_MSK)

#define PCON_LVDF_MSK                   BIT5
#define LVD_CheckFlag()                 READ_REG_BIT(PCON, PCON_LVDF_MSK)
#define LVD_ClearFlag()                 CLR_REG_BIT(PCON, PCON_LVDF_MSK)

#define ADCCONTR_ADCFLAG_MSK            BIT4
#define ADC_CheckFlag()                 READ_REG_BIT(ADC_CONTR, ADCCONTR_ADCFLAG_MSK)
#define ADC_ClearFlag()                 CLR_REG_BIT(ADC_CONTR, ADCCONTR_ADCFLAG_MSK)

#define SPSTAT_SPIF_MSK                 BIT7
#define SPSTAT_WCOL_MSK                 BIT6
#define SPI_CheckFlag()                 READ_REG_BIT(SPSTAT, SPSTAT_SPIF_MSK)
#define SPI_ClearFlag()                 SET_REG_BIT(SPSTAT, SPSTAT_SPIF_MSK | SPSTAT_WCOL_MSK)

#define CCON_CF_MSK                     BIT7
#define PCA_CheckCounterFlag()          READ_REG_BIT(CCON, CCON_CF_MSK)
#define PCA_ClearCounterFlag()          CLR_REG_BIT(CCON, CCON_CF_MSK)

#define CCON_CCF0_MSK                   BIT0
#define CCON_CCF1_MSK                   BIT1
#define CCON_CCF2_MSK                   BIT2
#define PCA_CheckCCF0Flag()             READ_REG_BIT(CCON, CCON_CCF0_MSK)
#define PCA_CheckCCF1Flag()             READ_REG_BIT(CCON, CCON_CCF1_MSK)
#define PCA_CheckCCF2Flag()             READ_REG_BIT(CCON, CCON_CCF2_MSK)
#define PCA_ClearCCF0Flag()             CLR_REG_BIT(CCON, CCON_CCF0_MSK)
#define PCA_ClearCCF1Flag()             CLR_REG_BIT(CCON, CCON_CCF1_MSK)
#define PCA_ClearCCF2Flag()             CLR_REG_BIT(CCON, CCON_CCF2_MSK)

#define INT0_SetIntPriority(n)          PX0 = ((n) & 1)

#define INT1_SetIntPriority(n)          PX1 = ((n) & 1)

#define IP2_PX4_MSK                     BIT4
#define INT4_SetIntPriority(n)          MODIFY_REG(IP2, IP2_PX4_MSK, (((n) & 1) << 4))

#define TIMER0_SetIntPriority(n)        PT0 = ((n) & 1)

#define TIMER1_SetIntPriority(n)        PT1 = ((n) & 1)

#define UART1_SetIntPriority(n)         PS = ((n) & 1)

#define IP2_PS2_MSK                     BIT0
#define UART2_SetIntPriority(n)         MODIFY_REG(IP2, IP2_PS2_MSK, (((n) & 1) << 0))

#define LVD_SetIntPriority(n)           PLVD = ((n) & 1)

#define ADC_SetIntPriority(n)           PADC = ((n) & 1)

#define IP2_PSPI_MSK                    BIT1
#define SPI_SetIntPriority(n)           MODIFY_REG(IP2, IP2_PSPI_MSK, (((n) & 1) << 1))

#define PCA_SetIntPriority(n)           PPCA = ((n) & 1)

/////////////////////////////////////////////////

#define EAXFR_MSK                       BIT7
#define EnableAccessXFR()               SET_REG_BIT(P_SW2, EAXFR_MSK)

#define UART1_PS_MSK                    (BIT7 | BIT6)
#define UART1_SwitchP3031()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((0) << 6))
#define UART1_SwitchP3637()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((1) << 6))
#define UART1_SwitchP1617()             MODIFY_REG(P_SW1, UART1_PS_MSK, ((2) << 6))

#define UART2_PS_MSK                    (BIT0)
#define UART2_SwitchP1011()             CLR_REG_BIT(P_SW2, UART2_PS_MSK)
#define UART2_SwitchP4647()             SET_REG_BIT(P_SW2, UART2_PS_MSK)

#define SPI_PS_MSK                      (BIT3 | BIT2)
#define SPI_SwitchP1n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((0) << 2))
#define SPI_SwitchP2n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((1) << 2))
#define SPI_SwitchP4n()                 MODIFY_REG(P_SW1, SPI_PS_MSK, ((2) << 2))

#define MCLKO_PS_MSK                    (BIT3)
#define CLK_SYSCLKO_SwitchP54()         CLR_REG_BIT(CLK_DIV, MCLKO_PS_MSK)
#define CLK_SYSCLKO_SwitchP16()         SET_REG_BIT(CLK_DIV, MCLKO_PS_MSK)

#define PCA_PS_MSK                      (BIT5 | BIT4)
#define PCA_SwitchP1n()                 MODIFY_REG(P_SW1, PCA_PS_MSK, ((0) << 4))
#define PCA_SwitchP3n()                 MODIFY_REG(P_SW1, PCA_PS_MSK, ((1) << 4))
#define PCA_SwitchP2n()                 MODIFY_REG(P_SW1, PCA_PS_MSK, ((2) << 4))

/////////////////////////////////////////////////

#define MCLKODIV_MSK                    (BIT7 | BIT6)
#define CLK_SYSCLKO_Divider(n)          MODIFY_REG(CLK_DIV, MCLKODIV_MSK, ((n) << 6))
#define CLK_SYSCLKO_Divider1()			CLK_SYSCLKO_Divider(1)
#define CLK_SYSCLKO_Divider2()			CLK_SYSCLKO_Divider(2)
#define CLK_SYSCLKO_Divider4()			CLK_SYSCLKO_Divider(3)

/////////////////////////////////////////////////

#define WDTCONTR_FLAG_MSK               BIT7
#define WDTCONTR_EN_MSK                 BIT5
#define WDTCONTR_CLR_MSK                BIT4
#define WDTCONTR_IDL_MSK                BIT3
#define WDTCONTR_PS_MSK                 (BIT2 | BIT1 | BIT0)

#define WDT_Enable()                    SET_REG_BIT(WDT_CONTR, WDTCONTR_EN_MSK)
#define WDT_Clear()                     SET_REG_BIT(WDT_CONTR, WDTCONTR_CLR_MSK)
#define WDT_CheckWDTReset()             READ_REG_BIT(WDT_CONTR, WDTCONTR_FLAG_MSK)
#define WDT_IdlePause()                 CLR_REG_BIT(WDT_CONTR, WDTCONTR_IDL_MSK)
#define WDT_IdleContinue()              SET_REG_BIT(WDT_CONTR, WDTCONTR_IDL_MSK)

#define WDT_SetPrescale(n)              MODIFY_REG(WDT_CONTR, WDTCONTR_PS_MSK, ((n) << 0))
#define WDT_SetPrescale2()              WDT_SetPrescale(0)
#define WDT_SetPrescale4()              WDT_SetPrescale(1)
#define WDT_SetPrescale8()              WDT_SetPrescale(2)
#define WDT_SetPrescale16()             WDT_SetPrescale(3)
#define WDT_SetPrescale32()             WDT_SetPrescale(4)
#define WDT_SetPrescale64()             WDT_SetPrescale(5)
#define WDT_SetPrescale128()            WDT_SetPrescale(6)
#define WDT_SetPrescale256()            WDT_SetPrescale(7)

/////////////////////////////////////////////////

#define TIMER0_Run()                    (TR0 = 1)
#define TIMER0_Stop()                   (TR0 = 0)

#define TIMER0_SetReload8(n)            (TH0 = LOBYTE(n), TL0 = LOBYTE(n))
#define TIMER0_SetReload16(n)           (TH0 = HIBYTE(n), TL0 = LOBYTE(n))

#define TMOD_T0M_MSK                    (BIT1 | BIT0)
#define TIMER0_Mode0()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((0) << 0))
#define TIMER0_Mode1()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((1) << 0))
#define TIMER0_Mode2()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((2) << 0))
#define TIMER0_Mode3()                  MODIFY_REG(TMOD, TMOD_T0M_MSK, ((3) << 0))

#define AUXR_T0X12_MSK                  BIT7
#define TIMER0_1TMode()                 SET_REG_BIT(AUXR, AUXR_T0X12_MSK)
#define TIMER0_12TMode()                CLR_REG_BIT(AUXR, AUXR_T0X12_MSK)

#define TMOD_T0CT_MSK                   BIT2
#define TIMER0_TimerMode()              CLR_REG_BIT(TMOD, TMOD_T0CT_MSK)
#define TIMER0_CounterMode()            SET_REG_BIT(TMOD, TMOD_T0CT_MSK)

#define TMOD_T0GATE_MSK                 BIT3
#define TIMER0_EnableGateINT0()         SET_REG_BIT(TMOD, TMOD_T0GATE_MSK)
#define TIMER0_DisableGateINT0()        CLR_REG_BIT(TMOD, TMOD_T0GATE_MSK)

#define INTCLKO_T0CLKO_MSK              BIT0
#define TIMER0_EnableCLKO()             SET_REG_BIT(INT_CLKO, INTCLKO_T0CLKO_MSK)
#define TIMER0_DisableCLKO()            CLR_REG_BIT(INT_CLKO, INTCLKO_T0CLKO_MSK)

////////////////////////

#define TIMER1_Run()                    (TR1 = 1)
#define TIMER1_Stop()                   (TR1 = 0)

#define TIMER1_SetReload8(n)            (TH1 = LOBYTE(n), TL1 = LOBYTE(n))
#define TIMER1_SetReload16(n)           (TH1 = HIBYTE(n), TL1 = LOBYTE(n))

#define TMOD_T1M_MSK                    (BIT5 | BIT4)
#define TIMER1_Mode0()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((0) << 4))
#define TIMER1_Mode1()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((1) << 4))
#define TIMER1_Mode2()                  MODIFY_REG(TMOD, TMOD_T1M_MSK, ((2) << 4))

#define AUXR_T1X12_MSK                  BIT6
#define TIMER1_1TMode()                 SET_REG_BIT(AUXR, AUXR_T1X12_MSK)
#define TIMER1_12TMode()                CLR_REG_BIT(AUXR, AUXR_T1X12_MSK)

#define TMOD_T1CT_MSK                   BIT6
#define TIMER1_TimerMode()              CLR_REG_BIT(TMOD, TMOD_T1CT_MSK)
#define TIMER1_CounterMode()            SET_REG_BIT(TMOD, TMOD_T1CT_MSK)

#define TMOD_T1GATE_MSK                 BIT7
#define TIMER1_EnableGateINT1()         SET_REG_BIT(TMOD, TMOD_T1GATE_MSK)
#define TIMER1_DisableGateINT1()        CLR_REG_BIT(TMOD, TMOD_T1GATE_MSK)

#define INTCLKO_T1CLKO_MSK              BIT1
#define TIMER1_EnableCLKO()             SET_REG_BIT(INT_CLKO, INTCLKO_T1CLKO_MSK)
#define TIMER1_DisableCLKO()            CLR_REG_BIT(INT_CLKO, INTCLKO_T1CLKO_MSK)

////////////////////////

#define AUXR_T2R_MSK                    BIT4
#define TIMER2_Run()                    SET_REG_BIT(AUXR, AUXR_T2R_MSK)
#define TIMER2_Stop()                   CLR_REG_BIT(AUXR, AUXR_T2R_MSK)

#define TIMER2_SetReload16(n)           (T2H = HIBYTE(n), T2L = LOBYTE(n))

#define AUXR_T2X12_MSK                  BIT2
#define TIMER2_1TMode()                 SET_REG_BIT(AUXR, AUXR_T2X12_MSK)
#define TIMER2_12TMode()                CLR_REG_BIT(AUXR, AUXR_T2X12_MSK)

#define AUXR_T2CT_MSK                   BIT3
#define TIMER2_TimerMode()              CLR_REG_BIT(AUXR, AUXR_T2CT_MSK)
#define TIMER2_CounterMode()            SET_REG_BIT(AUXR, AUXR_T2CT_MSK)

#define INTCLKO_T2CLKO_MSK              BIT2
#define TIMER2_EnableCLKO()             SET_REG_BIT(INT_CLKO, INTCLKO_T2CLKO_MSK)
#define TIMER2_DisableCLKO()            CLR_REG_BIT(INT_CLKO, INTCLKO_T2CLKO_MSK)

/////////////////////////////////////////////////

#define SCON_SM_MSK                     (BIT7 | BIT6)
#define UART1_SetMode(n)                MODIFY_REG(SCON, SCON_SM_MSK, ((n) << 6))
#define UART1_Mode0()                   UART1_SetMode(0)
#define UART1_Mode1()                   UART1_SetMode(1)
#define UART1_Mode2()                   UART1_SetMode(2)
#define UART1_Mode3()                   UART1_SetMode(3)

#define UART1_EnableRx()                (REN = 1)
#define UART1_DisableRx()               (REN = 0)
#define UART1_SetTB8(b)                 (TB8 = (b))
#define UART1_ReadRB8()                 (RB8)

#define UART1_SendData(d)               (SBUF = (d))
#define UART1_ReadData()                (SBUF)

#define PCON_SMOD_MSK                   BIT7
#define UART1_BaudrateX2()              SET_REG_BIT(PCON, PCON_SMOD_MSK)

#define AUXR_M0X6_MSK                   BIT5
#define UART1_Mode0BaudrateX6()         SET_REG_BIT(AUXR, AUXR_M0X6_MSK)


#define AUXR_S1BRT_MSK                  BIT0
#define UART1_Timer1BRT()               CLR_REG_BIT(AUXR, AUXR_S1BRT_MSK)
#define UART1_Timer2BRT()               SET_REG_BIT(AUXR, AUXR_S1BRT_MSK)

////////////////////////

#define S2CON_S2SM_MSK                  BIT7
#define UART2_SetMode(n)                MODIFY_REG(S2CON, S2CON_S2SM_MSK, ((n) << 7))
#define UART2_Mode0()                   CLR_REG_BIT(S2CON, S2CON_S2SM_MSK)
#define UART2_Mode1()                   SET_REG_BIT(S2CON, S2CON_S2SM_MSK)

#define S2CON_S2REN_MSK                 BIT4
#define UART2_EnableRx()                SET_REG_BIT(S2CON, S2CON_S2REN_MSK)
#define UART2_DisableRx()               CLR_REG_BIT(S2CON, S2CON_S2REN_MSK)

#define S2CON_S2TB8_MSK                 BIT3
#define UART2_SetTB8(b)                 MODIFY_REG(S2CON, S2CON_S2TB8_MSK, ((b) << 3))

#define S2CON_S2RB8_MSK                 BIT2
#define UART2_ReadRB8()                 READ_REG_BIT(S2CON, S2CON_S2RB8_MSK)

#define UART2_SendData(d)               (S2BUF = (d))
#define UART2_ReadData()                (S2BUF)

/////////////////////////////////////////////////

#define IAPCON_IAPEN_MSK                BIT7
#define IAP_Enable()                    SET_REG_BIT(IAP_CONTR, IAPCON_IAPEN_MSK)
#define IAP_Disable()                   CLR_REG_BIT(IAP_CONTR, IAPCON_IAPEN_MSK)

#define IAP_SetData(d)                  (IAP_DATA = (d))
#define IAP_ReadData()                  (IAP_DATA)

#define IAP_SetAddress(n)               IAP_ADDRL = BYTE0(n); \
                                        IAP_ADDRH = BYTE1(n)

#define IAP_Trigger()                   IAP_TRIG = 0x5a; \
                                        IAP_TRIG = 0xa5; \
                                        _nop_();         \
                                        _nop_();         \
                                        _nop_();         \
                                        _nop_()

#define IAP_Idle()                      IAP_CMD = 0
#define IAP_TriggerRead()               IAP_CMD = 1; IAP_Trigger()
#define IAP_TriggerProgram()            IAP_CMD = 2; IAP_Trigger()
#define IAP_TriggerErase()              IAP_CMD = 3; IAP_Trigger()

#define IAPCON_WT_MSK                  	(BIT2 | BIT1 | BIT0)
#define IAP_SetWaitTime(n)              MODIFY_REG(IAP_CONTR, IAPCON_WT_MSK, ((n) << 0))
#define IAP_SetTimeBase()               IAP_SetWaitTime((SYSCLK) <=  1000000 ? 7 : \
                                                        (SYSCLK) <=  2000000 ? 6 : \
                                                        (SYSCLK) <=  3000000 ? 5 : \
                                                        (SYSCLK) <=  6000000 ? 4 : \
                                                        (SYSCLK) <= 12000000 ? 3 : \
                                                        (SYSCLK) <= 20000000 ? 2 : \
                                                        (SYSCLK) <= 24000000 ? 1 : 0)

#define IAPCON_FAIL_MSK                 BIT4
#define IAP_CheckErrorFlag()            READ_REG_BIT(IAP_CONTR, IAPCON_FAIL_MSK)
#define IAP_ClearErrorFlag()            CLR_REG_BIT(IAP_CONTR, IAPCON_FAIL_MSK)

/////////////////////////////////////////////////

#define ADCCONTR_ADCPOWER_MSK           BIT7
#define ADC_Enable()                    SET_REG_BIT(ADC_CONTR, ADCCONTR_ADCPOWER_MSK)
#define ADC_Disable()                   CLR_REG_BIT(ADC_CONTR, ADCCONTR_ADCPOWER_MSK)

#define ADC_ReadResult()                MAKEWORD(ADC_RESL, ADC_RES)

#define ADCCONTR_ADCSTART_MSK           BIT3
#define ADC_Start()                     SET_REG_BIT(ADC_CONTR, ADCCONTR_ADCSTART_MSK)

#define ADCCONTR_ADCCHS_MSK             (BIT2 | BIT1 | BIT0)
#define ADC_ActiveChannel(n)            MODIFY_REG(ADC_CONTR, ADCCONTR_ADCCHS_MSK, ((n) << 0))

#define PWMCFG_CBTADC_MSK               BIT6
#define ADC_EnablePWMTrig()             SET_REG_BIT(PWMCFG, PWMCFG_CBTADC_MSK)

#define CLKDIV_ADRJ_MSK                 BIT5
#define ADC_ResultLeftAlign()           CLR_REG_BIT(CLK_DIV, CLKDIV_ADRJ_MSK)
#define ADC_ResultRightAlign()          SET_REG_BIT(CLK_DIV, CLKDIV_ADRJ_MSK)

#define ADCCONTR_SPEED_MSK              (BIT6 | BIT5)
#define ADC_SetClockDivider(n)          MODIFY_REG(ADC_CONTR, ADCCONTR_SPEED_MSK, ((n) << 5))
#define ADC_SetSpeedTo90Clocks()        ADC_SetClockDivider(3)
#define ADC_SetSpeedTo180Clocks()       ADC_SetClockDivider(2)
#define ADC_SetSpeedTo360Clocks()       ADC_SetClockDivider(1)
#define ADC_SetSpeedTo540Clocks()       ADC_SetClockDivider(0)

/////////////////////////////////////////////////

#define CCON_CR_MSK                     BIT6
#define PCA_Run()                       SET_REG_BIT(CCON, CCON_CR_MSK)
#define PCA_Stop()                      CLR_REG_BIT(CCON, CCON_CR_MSK)

#define CMOD_CIDL_MSK                   BIT7
#define PCA_IdlePause()                 SET_REG_BIT(CMOD, CMOD_CIDL_MSK)
#define PCA_IdleContinue()              CLR_REG_BIT(CMOD, CMOD_CIDL_MSK)

#define CMOD_CPS_MSK                    (BIT3 |BIT2 |BIT1)
#define PCA_SetClockSource(n)           MODIFY_REG(CMOD, CMOD_CPS_MSK, ((n) << 1))
#define PCA_CLK_SYSCLKD12()             PCA_SetClockSource(0)
#define PCA_CLK_SYSCLKD2()              PCA_SetClockSource(1)
#define PCA_CLK_TIMER0OV()              PCA_SetClockSource(2)
#define PCA_CLK_ECI()                   PCA_SetClockSource(3)
#define PCA_CLK_SYSCLK()                PCA_SetClockSource(4)
#define PCA_CLK_SYSCLKD4()              PCA_SetClockSource(5)
#define PCA_CLK_SYSCLKD6()              PCA_SetClockSource(6)
#define PCA_CLK_SYSCLKD8()              PCA_SetClockSource(7)

#define PCA_SetCounter(n)               (CH = HIBYTE(n), CL = LOBYTE(n))
#define PCA_InitCounter()               PCA_SetCounter(0)

#define PCA_SetCnReload(n, v)           CCAP##n##L = LOBYTE(v); \
                                        CCAP##n##H = LOBYTE(v)

#define PCA_SetCnMatch(n, v)            (CCAP##n##L = LOBYTE(v), CCAP##n##H = HIBYTE(v))

#define PCA_ReadCnCapture(n)            MAKEWORD(CCAP##n##L, CCAP##n##H)

#define CCAPMn_ECOM_MSK                 BIT6
#define CCAPMn_CCAPP_MSK                BIT5
#define CCAPMn_CCAPN_MSK                BIT4
#define CCAPMn_MAT_MSK                  BIT3
#define CCAPMn_TOG_MSK                  BIT2
#define CCAPMn_PWM_MSK                  BIT1
#define PCAPWMn_EBS_MSK                 (BIT7 | BIT6)

#define PCA_DisableCn(n)    			CCAPM##n = 0

#define PCA_SetCnAs6BitPWMMode(n)       CCAPM##n = (CCAPMn_ECOM_MSK | CCAPMn_PWM_MSK); \
                                        MODIFY_REG(PCA_PWM##n, PCAPWMn_EBS_MSK, ((2) << 6))
#define PCA_SetCnAs7BitPWMMode(n)       CCAPM##n = (CCAPMn_ECOM_MSK | CCAPMn_PWM_MSK); \
                                        MODIFY_REG(PCA_PWM##n, PCAPWMn_EBS_MSK, ((1) << 6))
#define PCA_SetCnAs8BitPWMMode(n)       CCAPM##n = (CCAPMn_ECOM_MSK | CCAPMn_PWM_MSK); \
                                        MODIFY_REG(PCA_PWM##n, PCAPWMn_EBS_MSK, ((0) << 6))

#define PCA_EnableCnCapturePWMPos(n)    MODIFY_REG(CCAPM##n, CCAPMn_CCAPP_MSK | CCAPMn_CCAPN_MSK, (CCAPMn_CCAPP_MSK))
#define PCA_EnableCnCapturePWMNeg(n)    MODIFY_REG(CCAPM##n, CCAPMn_CCAPP_MSK | CCAPMn_CCAPN_MSK, (CCAPMn_CCAPN_MSK))
#define PCA_EnableCnCapturePWMEdge(n)   CCAPM##n |= (CCAPMn_CCAPP_MSK | CCAPMn_CCAPN_MSK)

#define PCA_SetCnAsCapturePosMode(n)    CCAPM##n = (CCAPMn_CCAPP_MSK)
#define PCA_SetCnAsCaptureNegMode(n)    CCAPM##n = (CCAPMn_CCAPN_MSK)
#define PCA_SetCnAsCaptureEdgeMode(n)   CCAPM##n = (CCAPMn_CCAPP_MSK | CCAPMn_CCAPN_MSK)

#define PCA_SetCnAs16BitTimerMode(n)    CCAPM##n = (CCAPMn_ECOM_MSK | CCAPMn_MAT_MSK)

#define PCA_SetCnAsHighSpeedPulseMode(n) CCAPM##n = (CCAPMn_ECOM_MSK | CCAPMn_MAT_MSK | CCAPMn_TOG_MSK)

#define PCA_DisableC0()              	PCA_DisableCn(0)
#define PCA_DisableC1()              	PCA_DisableCn(1)
#define PCA_DisableC2()              	PCA_DisableCn(2)

#define PCA_SetC0Reload(v)              PCA_SetCnReload(0, (v))
#define PCA_SetC1Reload(v)              PCA_SetCnReload(1, (v))
#define PCA_SetC2Reload(v)              PCA_SetCnReload(2, (v))

#define PCA_SetC0Match(v)               PCA_SetCnMatch(0, (v))
#define PCA_SetC1Match(v)               PCA_SetCnMatch(1, (v))
#define PCA_SetC2Match(v)               PCA_SetCnMatch(2, (v))

#define PCA_ReadC0Capture()             PCA_ReadCnCapture(0)
#define PCA_ReadC1Capture()             PCA_ReadCnCapture(1)
#define PCA_ReadC2Capture()             PCA_ReadCnCapture(2)

#define PCA_SetC0As6BitPWMMode()        PCA_SetCnAs6BitPWMMode(0)
#define PCA_SetC1As6BitPWMMode()        PCA_SetCnAs6BitPWMMode(1)
#define PCA_SetC2As6BitPWMMode()        PCA_SetCnAs6BitPWMMode(2)

#define PCA_SetC0As7BitPWMMode()        PCA_SetCnAs7BitPWMMode(0)
#define PCA_SetC1As7BitPWMMode()        PCA_SetCnAs7BitPWMMode(1)
#define PCA_SetC2As7BitPWMMode()        PCA_SetCnAs7BitPWMMode(2)

#define PCA_SetC0As8BitPWMMode()        PCA_SetCnAs8BitPWMMode(0)
#define PCA_SetC1As8BitPWMMode()        PCA_SetCnAs8BitPWMMode(1)
#define PCA_SetC2As8BitPWMMode()        PCA_SetCnAs8BitPWMMode(2)

#define PCA_EnableC0CapturePWMPos()     PCA_EnableCnCapturePWMPos(0)
#define PCA_EnableC1CapturePWMPos()     PCA_EnableCnCapturePWMPos(1)
#define PCA_EnableC2CapturePWMPos()     PCA_EnableCnCapturePWMPos(2)

#define PCA_EnableC0CapturePWMNeg()     PCA_EnableCnCapturePWMNeg(0)
#define PCA_EnableC1CapturePWMNeg()     PCA_EnableCnCapturePWMNeg(1)
#define PCA_EnableC2CapturePWMNeg()     PCA_EnableCnCapturePWMNeg(2)

#define PCA_EnableC0CapturePWMEdge()    PCA_EnableCnCapturePWMEdge(0)
#define PCA_EnableC1CapturePWMEdge()    PCA_EnableCnCapturePWMEdge(1)
#define PCA_EnableC2CapturePWMEdge()    PCA_EnableCnCapturePWMEdge(2)

#define PCA_SetC0AsCapturePosMode()     PCA_SetCnAsCapturePosMode(0)
#define PCA_SetC1AsCapturePosMode()     PCA_SetCnAsCapturePosMode(1)
#define PCA_SetC2AsCapturePosMode()     PCA_SetCnAsCapturePosMode(2)

#define PCA_SetC0AsCaptureNegMode()     PCA_SetCnAsCaptureNegMode(0)
#define PCA_SetC1AsCaptureNegMode()     PCA_SetCnAsCaptureNegMode(1)
#define PCA_SetC2AsCaptureNegMode()     PCA_SetCnAsCaptureNegMode(2)

#define PCA_SetC0AsCaptureEdgeMode()    PCA_SetCnAsCaptureEdgeMode(0)
#define PCA_SetC1AsCaptureEdgeMode()    PCA_SetCnAsCaptureEdgeMode(1)
#define PCA_SetC2AsCaptureEdgeMode()    PCA_SetCnAsCaptureEdgeMode(2)

#define PCA_SetC0As16BitTimerMode()     PCA_SetCnAs16BitTimerMode(0)
#define PCA_SetC1As16BitTimerMode()     PCA_SetCnAs16BitTimerMode(1)
#define PCA_SetC2As16BitTimerMode()     PCA_SetCnAs16BitTimerMode(2)

#define PCA_SetC0AsHighSpeedPulseMode() PCA_SetCnAsHighSpeedPulseMode(0)
#define PCA_SetC1AsHighSpeedPulseMode() PCA_SetCnAsHighSpeedPulseMode(1)
#define PCA_SetC2AsHighSpeedPulseMode() PCA_SetCnAsHighSpeedPulseMode(2)

/////////////////////////////////////////////////

#define SPCTL_SPEN_MSK                  BIT6
#define SPI_Enable()                    SET_REG_BIT(SPCTL, SPCTL_SPEN_MSK)
#define SPI_Disable()                   CLR_REG_BIT(SPCTL, SPCTL_SPEN_MSK)

#define SPCTL_DORD_MSK                  BIT5
#define SPI_DataLSB()                   SET_REG_BIT(SPCTL, SPCTL_DORD_MSK)
#define SPI_DataMSB()                   CLR_REG_BIT(SPCTL, SPCTL_DORD_MSK)

#define SPCTL_MSTR_MSK                  BIT4
#define SPI_MasterMode()                SET_REG_BIT(SPCTL, SPCTL_MSTR_MSK)
#define SPI_SlaveMode()                 CLR_REG_BIT(SPCTL, SPCTL_MSTR_MSK)

#define SPCTL_SSIG_MSK                  BIT7
#define SPI_IgnoreSS()                  SET_REG_BIT(SPCTL, SPCTL_SSIG_MSK)
#define SPI_UnignoreSS()                CLR_REG_BIT(SPCTL, SPCTL_SSIG_MSK)

#define SPCTL_CPOL_MSK                  BIT3
#define SPCTL_CPHA_MSK                  BIT2
#define SPIMODE                         (SPCTL_CPOL_MSK | SPCTL_CPHA_MSK)
#define SPI_SetMode0()                  MODIFY_REG(SPCTL, SPIMODE, ((0) << 2))
#define SPI_SetMode1()                  MODIFY_REG(SPCTL, SPIMODE, ((1) << 2))
#define SPI_SetMode2()                  MODIFY_REG(SPCTL, SPIMODE, ((2) << 2))
#define SPI_SetMode3()                  MODIFY_REG(SPCTL, SPIMODE, ((3) << 2))

#define SPCTL_SPR_MSK                   (BIT1 | BIT0)
#define SPI_SetClockDivider(n)          MODIFY_REG(SPCTL, SPCTL_SPR_MSK, ((n) << 0))
#define SPI_SetClockDivider4()          SPI_SetClockDivider(0)
#define SPI_SetClockDivider16()         SPI_SetClockDivider(1)
#define SPI_SetClockDivider64()         SPI_SetClockDivider(2)
#define SPI_SetClockDivider128()        SPI_SetClockDivider(3)

#define SPI_SendData(d)                 (SPDAT = (d))
#define SPI_ReadData()                  (SPDAT)

/////////////////////////////////////////////////
//Interrupt Vector
/////////////////////////////////////////////////

#define     INT0_VECTOR             0       //0003H
#define     TMR0_VECTOR             1       //000BH
#define     INT1_VECTOR             2       //0013H
#define     TMR1_VECTOR             3       //001BH
#define     UART1_VECTOR            4       //0023H
#define     ADC_VECTOR              5       //002BH
#define     LVD_VECTOR              6       //0033H
#define     PCA_VECTOR              7       //003BH
#define     UART2_VECTOR            8       //0043H
#define     SPI_VECTOR              9       //004BH
#define     INT2_VECTOR             10      //0053H
#define     INT3_VECTOR             11      //005BH
#define     TMR2_VECTOR             12      //0063H
#define     USER_VECTOR             13      //006BH
#define     INT4_VECTOR             16      //0083H

/////////////////////////////////////////////////

#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()

/////////////////////////////////////////////////


#endif

