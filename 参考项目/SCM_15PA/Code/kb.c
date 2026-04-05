#include "kb.h"

// 键盘扫描模块，实现矩阵键盘的按键检测
// 使用状态机进行行列扫描，避免阻塞主程序

extern bdata unsigned char flag;

static unsigned char keyValue = 255; // 当前检测到的按键值，255表示无按键
//
// 清除列线，设置行线为输入模式，准备检测行
static void clsC(void)
{
    P42 = 0;
    P44 = 0;
    P32 = 1;
    P33 = 1;
}
// 清除行线，设置列线为输入模式，准备检测列
static void clsR(void)
{
    P42 = 1;
    P44 = 1;
    P32 = 0;
    P33 = 0;
}

unsigned char keyGet(void) { return keyValue; }
void keySet(unsigned char value) { keyValue = value; }

// 键盘扫描主函数，使用状态机实现按键检测
// 通过定时器中断调用，避免阻塞主程序
void keyScan(void)
{
    static unsigned char keyStatus = 0; // 状态机状态变量
    static unsigned char col = 0; // 当前检测的列号

    // 检查扫描标志位，如果未设置则返回
    if ((flag & 0x01) == 0)
        return;
    flag &= ~0x01; // 清除扫描标志位

    switch (keyStatus) {
    case 0: // 初始状态：检测是否有按键按下
        clsR(); // 设置列线为输入，行线为输出
        if ((P42 == 0) || (P44 == 0)) { // 如果有列线为低电平，表示有按键按下
            keyStatus = 1; // 进入下一状态
        }
        break;
    case 1: // 确定按键所在列
        clsR(); // 保持列线输入状态
        if (P44 == 0) { // 第1列有按键
            col = 1;
            keyStatus = 2;
        } else if (P42 == 0) { // 第2列有按键
            col = 2;
            keyStatus = 2;
        } else { // 无按键，重置状态
            keyStatus = 0;
        }
        break;
    case 2: // 检测行线，确定具体按键值
        clsC(); // 设置行线为输入，列线为输出
        keyStatus = 3; // 进入等待释放状态
        if ((P32 == 0) && (col == 1)) { // 第1列第1行按键
            keyValue = 5;
        } else if ((P33 == 0) && (col == 1)) { // 第1列第2行按键
            keyValue = 4;
        } else if ((P32 == 0) && (col == 2)) { // 第2列第1行按键
            keyValue = 9;
        } else if ((P33 == 0) && (col == 2)) { // 第2列第2行按键
            keyValue = 8;
        } else { // 无有效按键，重置状态
            keyStatus = 0;
            col = 0;
        }
        break;
    case 3: // 等待按键释放
        clsC(); // 保持行线输入状态
        if ((P32 == 1) && (P33 == 1)) { // 按键已释放
            keyStatus = 0; // 重置状态机
        }
        break;
    }
}
