/**
 * @file seg.c
 * @brief 数码管驱动与字模定义
 * @details 提供数码管显示缓冲(seg)、字模数组(letter)以及逐位刷新函数(seg_display)。
 *          字模在显示前被取反（~letter[...]）以匹配目标硬件的驱动极性。
 * @date 2025-12-09
 */

#include "seg.h"

/**
 * @brief 数码管显示缓冲
 * @details 每个元素为 letter 中的索引，代表对应位上要显示的字符。
 *          seg_display() 会逐位读取并输出到数码管。
 */
uint8_t seg[8] = {0, 0, 0, 0, 0, 0, 0, 0};

/**
 * @brief 7 段字模表（标准数字与部分字母/符号）
 * @details 每个字节为段位掩码，具体段位映射依硬件接线而定。
 *          在实际驱动时对该字模取反以满足驱动逻辑。
 */
code uint8_t letter[] = { // 标准字库
    //   0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71,
    // black  -     H    J    K    L    N    o   P    U     t    G    Q    r   M    y
    0x00, 0x40, 0x76, 0x1E, 0x70, 0x38, 0x37, 0x5C, 0x73, 0x3E, 0x78, 0x3d, 0x67, 0x50, 0x37, 0x6e, 0xBF, 0x86, 0xDB,
    0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF, 0x46, 0x63}; // 0. 1. 2. 3. 4. 5. 6. 7. 8. 9. -1

/**
 * @brief 数码管逐位扫描刷新函数
 * @details 使用静态索引 i 逐位选通并输出对应段码：
 *          - 清空 P0 并切换 latch(7)/latch(0)
 *          - 输出位选 P0 = 1<<i 并 latch
 *          - 输出段码 ~letter[seg[i]] 并 latch
 * @note 该函数应由周期性中断或主循环频繁调用以维持显示稳定。
 * @return void
 */
void seg_display()
{
    static uint8_t i = 0;

    P0 = 0xFF;
    latch(7);
    latch(0);

    P0 = 0x01 << i;
    latch(6);
    latch(0);

    P0 = ~letter[seg[i]];
    latch(7);
    latch(0);

    i++;
    if (i == 8) {
        i = 0;
    }
}

void seg_set(uint8_t position, uint8_t number)
{
    seg[position] = number;
}