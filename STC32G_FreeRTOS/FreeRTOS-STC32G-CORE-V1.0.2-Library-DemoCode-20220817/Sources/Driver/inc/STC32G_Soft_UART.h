/**
 * @file STC32G_Soft_UART.h
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#ifndef	__STC32G_SOFT_UART_H
#define	__STC32G_SOFT_UART_H

#include	"FreeRTOS.h"

void	TxSend( uint8_t dat );
void 	PrintString( uint8_t code *puts );

#endif
