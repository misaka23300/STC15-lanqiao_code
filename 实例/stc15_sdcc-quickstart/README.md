# STC15 SDCC 项目模板

这是适用于 STC15 的 SDCC 项目模板。

项目信息：
- 芯片：STC15
- 编译器：SDCC
- 烧录器：stcgal 或 STCISP

SDCC 可以通过 "安装实用工具功能" 进行安装。

而 stcgal 需要自行安装（如果使用 STCISP 进行烧录，则无需安装 stcgal）

## 例程功能

使用 软件 UART 在 TX 引脚 P31 上打印 `Hello, STC15F104W` 字符串。

同时执行 GPIO 翻转（P34）

main.c
```c
/**
 * 本例使用芯片：STC15F104W
 * 
 * 主时钟频率：16MHz, 在 config.h 中更改 MAIN_Fosc 调节主时钟频率
 * 
 * 软件 UART：
 *      TX 引脚：P31
 *      波特率：9600
 * 
 * 烧录工具：STC-ISP 
*/

#include "config.h"
#include "delay.h"
#include "soft_uart.h"

#define LED_Toggle() P34 = !P34

void main()
{
    while (1)
    {
        LOG("Hello, STC15F104W !");
        LED_Toggle();
        delay_ms(200);
    }
}
```

## 工程设置

- 设置主频：通过设置宏定义 `MAIN_Fosc` 来设置主频，默认 `MAIN_Fosc=16000000L`

- 设置芯片型号：通过设置宏定义 `MCU_Type` 来设置具体型号，默认 `MCU_Type=STC15F_L2K60S2`

- 该工程默认设置了 `DEBUG` 宏用于开启 LOG() 打印函数，不需要打印时，可以移除 `DEBUG` 宏定义

- 要设置芯片的 XDATA 和 FLASH 区域大小，请打开 `构建器选项 -> Other Global Options`

    默认设置如下：

    `--iram-size 128 --xram-size 0 --code-size 4096`

    这表示 XDATA 大小为 0，FLASH 大小 为 4096 bytes

    请根据实际需要进行修改

设置完成后，点击编译，hex 文件将生成到 build/Debug 目录下
