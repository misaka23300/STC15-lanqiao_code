/**
 * @file boot.c
 * @brief 引导与定时器初始化模块
 * @details 初始化端口模式、锁存线(latch)和定时器1，以及提供短延时函数。
 * @author
 * @date 2025-12-09
 */

#include "boot.h"

/**
 * @brief 初始化硬件引脚模式并启动定时器1
 *
 * 该函数设置所有端口的模式寄存器为准双向口（或默认值），
 * 对 P0 输出特定序列并通过 latch 控制锁存线，随后初始化定时器1并使能全局中断。
 *
 * @note 调用此函数后，定时器1中断被使能（ET1 = 1），全局中断使能（EA = 1）。
 */
void boot_init()
{
    P0M0 = 0x00;
    P0M1 = 0x00;
    P1M0 = 0x00;
    P1M1 = 0x00;
    P2M0 = 0x00;
    P2M1 = 0x00;
    P3M0 = 0x00;
    P3M1 = 0x00;
    P4M0 = 0x00;
    P4M1 = 0x00;
    P5M0 = 0x00;
    P5M1 = 0x00;
    P6M0 = 0x00;
    P6M1 = 0x00;
    P7M0 = 0x00;
    P7M1 = 0x00;

    P0 = 0xFF;
    latch(4);

    P0 = 0xAF;
    latch(5);

    P0 = 0x00;
    latch(6);

    P0 = 0xFF;
    latch(7);

    latch(0);

    Timer1_Init();
    EA = 1;
}

/**
 * @brief 设置 P2 端口以选择不同的 latch 状态
 *
 * 根据参数 i 修改 P2 的高三位以控制不同的锁存设备/通路：
 * - 4 => 设置为 0x80
 * - 5 => 设置为 0xA0
 * - 6 => 设置为 0xC0
 * - 7 => 设置为 0xE0
 * - 0 => 清除高三位（恢复 0）
 *
 * @param i latch 索引（0,4,5,6,7）
 */
void latch(uint8_t i)
{
    switch (i) {
        case 4: {
            P2 = (P2 & 0x1F) | 0x80;
            break;
        }
        case 5: {
            P2 = (P2 & 0x1F) | 0xA0;
            break;
        }
        case 6: {
            P2 = (P2 & 0x1F) | 0xC0;
            break;
        }
        case 7: {
            P2 = (P2 & 0x1F) | 0xE0;
            break;
        }
        case 0: {
            P2 = P2 & 0x1F;
            break;
        }
    }
}

/**
 * @brief 初始化定时器1以产生约1毫秒中断（基于12.000MHz晶振）
 *
 * @note 配置为12T模式，设置初值并使能定时器中断。
 */
void Timer1_Init(void) // 1毫秒@12.000MHz
{
    AUXR &= 0xBF; // 定时器时钟12T模式
    TMOD &= 0x0F; // 设置定时器模式
    TL1 = 0x18;   // 设置定时初始值
    TH1 = 0xFC;   // 设置定时初始值
    TF1 = 0;      // 清除TF1标志
    TR1 = 1;      // 定时器1开始计时
    ET1 = 1;      // 使能定时器1中断
}

/**
 * @brief 约14微秒延时（基于12.000MHz）
 *
 * @note 依赖编译器的空操作指令与循环消耗来实现短延时。
 */
void Delay14us(void) //@12.000MHz
{
    unsigned char data i;

    _nop_();
    _nop_();
    i = 39;
    while (--i);
}

/*
 * 以下为备用/注释掉的定时器配置函数，保留原注释并添加文档说明以便未来使用或文档生成。
 *
 * @brief 注释掉的函数：timer_0_sonic - 用于定时器0的声纳计时（示例）
 * @brief 注释掉的函数：timer_0_ne555 - 用于 NE555 外部脉冲处理（示例）
 */
/* void timer_0_sonic()
{
    AUXR &= 0x7F;			//定时器时钟12T模式
    TMOD &= 0xF0;			//设置定时器模式
    TL0 = 0x00;				//设置定时初始值
    TH0 = 0x00;				//设置定时初始值
    TF0 = 0;				//清除TF0标志
    TR0 = 0;				//定时器0开始计时
    ET0 = 0;				//使能定时器0中断
}

void timer_0_ne555()
{
    //TMOD -> 0000 0110
    // AUXR -> 0xxx xxxx
    TMOD = (TMOD & 0xF0) | 0x06;
    TL0 = 0xFF;
    TH0 = 0xFF;
    ET0 = 1;
}
 */