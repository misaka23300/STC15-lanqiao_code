/**
 * @file Init.c
 * @brief 未指定描述
 * @date 2026 - 6 - 9
 * @version 1.0
 */

#include <Init.h>

void System_Init()
{
	P0 = 0xff;
	P2 = P2 & 0x1f | 0x80;
	P2 = P2 & 0x1f;
	
	P0 = 0x00;
	P2 = P2 & 0x1f | 0xa0;
	P2 = P2 & 0x1f;
}