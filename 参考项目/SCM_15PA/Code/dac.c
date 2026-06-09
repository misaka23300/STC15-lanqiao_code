/**
 * @file dac.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include "dac.h"

#if 0
//
void initDAC( void )
{
	I2CStart();
	I2CSendByte(0x90 );
    I2CWaitAck();
	I2CSendByte(0x43 );  //
	I2CWaitAck();
	I2CStop();
	delay10Ms();
}
#endif

//
void setDAC( unsigned char dat )
{
	I2CStart();
	I2CSendByte(0x90 );
	I2CWaitAck();
	I2CSendByte(0x40 );  //
	I2CWaitAck();
	
	I2CSendByte( dat );
	I2CWaitAck();
	I2CStop();
}