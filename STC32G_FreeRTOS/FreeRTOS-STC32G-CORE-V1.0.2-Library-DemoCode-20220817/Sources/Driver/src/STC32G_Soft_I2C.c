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

#include	"STC32G_Soft_I2C.h"

#define SLAW    0x5A
#define SLAR    0x5B

sbit    SDA = P0^1; //٦ﺎﺯﻣSDA
sbit    SCL = P0^0; //٦ﺎﺯﻣSCL

//========================================================================
// ﻑﺥﺗﻱ: void I2C_Delay(void)
// ﺃﻭﺗﻲ: I2Cﺭﺳﺗ١ﻑﺥﺗﻱ.
// ٢ﺧﺗﻱ: none.
// ٧٥؛ﻅ: none.
// ٠ﻧ١ﺹ: V1.0, 2020-09-15
//========================================================================
void I2C_Delay(void) //for normal MCS51, delay (2 * dly + 4) T, for STC12Cxxxx delay (4 * dly + 10) T
{
	uint8_t  dly;
	dly = MAIN_Fosc / 2000000UL;        //٠٤2usﺱﺋﺛﻛ
	while(--dly);
}

//========================================================================
// I2Cﻁ¬ﺩﻉﻑﺥﺗﻱ
//========================================================================
void I2C_Start(void)         //start the I2C, SDA High-to-low when SCL is high
{
	SDA = 1;
	I2C_Delay();
	SCL = 1;
	I2C_Delay();
	SDA = 0;
	I2C_Delay();
	SCL = 0;
	I2C_Delay();
}       


void I2C_Stop(void)           //STOP the I2C, SDA Low-to-high when SCL is high
{
	SDA = 0;
	I2C_Delay();
	SCL = 1;
	I2C_Delay();
	SDA = 1;
	I2C_Delay();
}

void S_ACK(void)              //Send ACK (LOW)
{
	SDA = 0;
	I2C_Delay();
	SCL = 1;
	I2C_Delay();
	SCL = 0;
	I2C_Delay();
}

void S_NoACK(void)           //Send No ACK (High)
{
	SDA = 1;
	I2C_Delay();
	SCL = 1;
	I2C_Delay();
	SCL = 0;
	I2C_Delay();
}
        
void I2C_Check_ACK(void)     //Check ACK, If F0=0, then right, if F0=1, then error
{
	SDA = 1;
	I2C_Delay();
	SCL = 1;
	I2C_Delay();
	F0  = SDA;
	SCL = 0;
	I2C_Delay();
}

//========================================================================
// ﻑﺥﺗﻱ: void I2C_WriteAbyte(uint8_t dat)
// ﺃﻭﺗﻲ: I2C٧ﺂﺛﺣﺯ؛٨ﻲﻁﺿﺵﻏﺗﻱﺹ÷ﻑﺥﺗﻱ.
// ٢ﺧﺗﻱ: ٧ﺂﺛﺣ٥ﺅﺗﻱﺹ÷.
// ٧٥؛ﻅ: none.
// ٠ﻧ١ﺹ: V1.0, 2020-09-15
//========================================================================
void I2C_WriteAbyte(uint8_t dat)     //write a byte to I2C
{
	uint8_t i;
	i = 8;
	do
	{
		if(dat & 0x80)  SDA = 1;
		else            SDA = 0;
		dat <<= 1;
		I2C_Delay();
		SCL = 1;
		I2C_Delay();
		SCL = 0;
		I2C_Delay();
	}
	while(--i);
}

//========================================================================
// ﻑﺥﺗﻱ: uint8_t I2C_ReadAbyte(void)
// ﺃﻭﺗﻲ: I2C٦ﺀﺑ­ﺯ؛٨ﻲﻁﺿﺵﻏﺗﻱﺹ÷ﻑﺥﺗﻱ.
// ٢ﺧﺗﻱ: none.
// ٧٥؛ﻅ: ٦ﺀﺑ­ﺗﻱﺹ÷.
// ٠ﻧ١ﺹ: V1.0, 2020-09-15
//========================================================================
uint8_t I2C_ReadAbyte(void)          //read A byte from I2C
{
	uint8_t i,dat;
	i = 8;
	SDA = 1;
	do
	{
		SCL = 1;
		I2C_Delay();
		dat <<= 1;
		if(SDA)     dat++;
		SCL  = 0;
		I2C_Delay();
	}
	while(--i);
	return(dat);
}

//========================================================================
// ﻑﺥﺗﻱ: void	SI2C_WriteNbyte(uint8_t addr, uint8_t *p, uint8_t number)
// ﺃﻭﺗﻲ: I2Cﺫ٤ﺑﺽﺗﻱﺹ÷ﻑﺥﺗﻱ.
// ٢ﺧﺗﻱ: addr: ﺿ٨٦ﺎ٥ﻅﺿ٧, *pﺫ٤ﺑﺽﺗﻱﺹ÷٤ﻧ٤ﺂﺧ؛ﺿﺃ, numberﺫ٤ﺑﺽﺗﻱﺹ÷٨ﻲﺗﻱ.
// ٧٥؛ﻅ: none.
// ٠ﻧ١ﺹ: V1.0, 2020-09-15
//========================================================================
void SI2C_WriteNbyte(uint8_t addr, uint8_t *p, uint8_t number)          /*  WordAddress,First Data Address,Byte lenth   */
{
	I2C_Start();
	I2C_WriteAbyte(SLAW);
	I2C_Check_ACK();
	if(!F0)                                           //F0=0,right, F0=1,error
	{
		I2C_WriteAbyte(addr);
		I2C_Check_ACK();
		if(!F0)
		{
			do
			{
				I2C_WriteAbyte(*p); p++;
				I2C_Check_ACK();
				if(F0)  break;
			}
			while(--number);
		}
	}
	I2C_Stop();
}

//========================================================================
// ﻑﺥﺗﻱ: void	SI2C_ReadNbyte(uint8_t addr, uint8_t *p, uint8_t number)
// ﺃﻭﺗﻲ: I2C٦ﺀﺑ­ﺗﻱﺹ÷ﻑﺥﺗﻱ.
// ٢ﺧﺗﻱ: addr: ﺿ٨٦ﺎ٥ﻅﺿ٧, *p٦ﺀﺑ­ﺗﻱﺹ÷٤ﻧ٤ﺂﺧ؛ﺿﺃ, number٦ﺀﺑ­ﺗﻱﺹ÷٨ﻲﺗﻱ.
// ٧٥؛ﻅ: none.
// ٠ﻧ١ﺹ: V1.0, 2020-09-15
//========================================================================
void SI2C_ReadNbyte(uint8_t addr, uint8_t *p, uint8_t number)       /*  WordAddress,First Data Address,Byte lenth   */
{
	I2C_Start();
	I2C_WriteAbyte(SLAW);
	I2C_Check_ACK();
	if(!F0)
	{
		I2C_WriteAbyte(addr);
		I2C_Check_ACK();
		if(!F0)
		{
			I2C_Start();
			I2C_WriteAbyte(SLAR);
			I2C_Check_ACK();
			if(!F0)
			{
				do
				{
					*p = I2C_ReadAbyte();   p++;
					if(number != 1)     S_ACK();    //send ACK
				}
				while(--number);
				S_NoACK();          //send no ACK
			}
		}
	}
	I2C_Stop();
}
