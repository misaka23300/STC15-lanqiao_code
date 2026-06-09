# 项目目录结构

```
│   └── CODE_STYLE.md
│   └── FIX_SUMMARY.md
│   └── LICENSE
│   └── README.md
├── STC32G_FreeRTOS/
├── FreeRTOS-STC32G-CORE-V1.0.2-DemoCode-20220609/
│   └── FreeRTOS_STC32G_Demo.uvopt
│   └── FreeRTOS_STC32G_Demo.uvproj
├── Sources/
├── FreeRTOS/
│   └── croutine.c
│   └── event_groups.c
├── include/
│   └── FreeRTOS.h
│   └── StackMacros.h
│   └── atomic.h
│   └── croutine.h
│   └── deprecated_definitions.h
│   └── event_groups.h
│   └── list.h
│   └── message_buffer.h
│   └── mpu_prototypes.h
│   └── mpu_wrappers.h
│   └── portable.h
│   └── projdefs.h
│   └── queue.h
│   └── semphr.h
│   └── stack_macros.h
│   └── stdint.h
│   └── stdint.readme
│   └── stream_buffer.h
│   └── task.h
│   └── timers.h
│   └── list.c
├── portable/
├── MemMang/
│   └── heap_1.c
│   └── heap_2.c
│   └── heap_3.c
│   └── heap_4.c
│   └── heap_5.c
├── STC32G12K128/
│   └── port.c
│   └── portasm.h
│   └── portmacro.h
│   └── queue.c
│   └── stream_buffer.c
│   └── tasks.c
│   └── timers.c
├── User/
│   └── DebugPrintf.c
│   └── MatrixKey.c
│   └── adc.c
│   └── adckey.c
│   └── display.c
├── include/
│   └── DebugPrintf.h
│   └── FreeRTOSConfig.h
│   └── MatrixKey.h
│   └── STC32G.H
│   └── adc.h
│   └── adckey.h
│   └── display.h
│   └── ntc.h
│   └── rtc.h
│   └── uart2_3.h
│   └── main.c
│   └── ntc.c
│   └── putchar.c
│   └── rtc.c
│   └── uart2_3.c
│   └── 请先阅读本使用方法.txt
├── FreeRTOS-STC32G-CORE-V1.0.2-Library-DemoCode-20220817/
│   └── FreeRTOS_STC32G_Demo.uvgui.laffe
│   └── FreeRTOS_STC32G_Demo.uvopt
│   └── FreeRTOS_STC32G_Demo.uvproj
├── Sources/
├── Driver/
├── inc/
│   └── STC32G_ADC.h
│   └── STC32G_CAN.h
│   └── STC32G_Clock.h
│   └── STC32G_Compare.h
│   └── STC32G_DMA.h
│   └── STC32G_Delay.h
│   └── STC32G_EEPROM.h
│   └── STC32G_Exti.h
│   └── STC32G_GPIO.h
│   └── STC32G_I2C.h
│   └── STC32G_LCM.h
│   └── STC32G_LIN.h
│   └── STC32G_NVIC.h
│   └── STC32G_PWM.h
│   └── STC32G_RTC.h
│   └── STC32G_SPI.h
│   └── STC32G_Soft_I2C.h
│   └── STC32G_Soft_UART.h
│   └── STC32G_Switch.h
│   └── STC32G_Timer.h
│   └── STC32G_UART.h
│   └── STC32G_USART.h
│   └── STC32G_WDT.h
├── isr/
│   └── STC32G_ADC_Isr.c
│   └── STC32G_CAN_Isr.c
│   └── STC32G_Compare_Isr.c
│   └── STC32G_DMA_Isr.c
│   └── STC32G_Exti_Isr.c
│   └── STC32G_GPIO_Isr.c
│   └── STC32G_I2C_Isr.c
│   └── STC32G_LCM_Isr.c
│   └── STC32G_LIN_Isr.c
│   └── STC32G_PWM_Isr.c
│   └── STC32G_RTC_Isr.c
│   └── STC32G_SPI_Isr.c
│   └── STC32G_Timer_Isr.c
│   └── STC32G_UART_Isr.c
├── lib/
│   └── STC32_MDU32_V1.1.LIB
├── src/
│   └── STC32G_ADC.c
│   └── STC32G_CAN.c
│   └── STC32G_Clock.c
│   └── STC32G_Compare.c
│   └── STC32G_DMA.c
│   └── STC32G_Delay.c
│   └── STC32G_EEPROM.c
│   └── STC32G_Exti.c
│   └── STC32G_GPIO.c
│   └── STC32G_I2C.c
│   └── STC32G_LCM.c
│   └── STC32G_LIN.c
│   └── STC32G_NVIC.c
│   └── STC32G_PWM.c
│   └── STC32G_RTC.c
│   └── STC32G_SPI.c
│   └── STC32G_Soft_I2C.c
│   └── STC32G_Soft_UART.c
│   └── STC32G_Timer.c
│   └── STC32G_UART.c
│   └── STC32G_USART.c
│   └── STC32G_WDT.c
├── FreeRTOS/
│   └── croutine.c
│   └── event_groups.c
├── include/
│   └── FreeRTOS.h
│   └── StackMacros.h
│   └── atomic.h
│   └── croutine.h
│   └── deprecated_definitions.h
│   └── event_groups.h
│   └── list.h
│   └── message_buffer.h
│   └── mpu_prototypes.h
│   └── mpu_wrappers.h
│   └── portable.h
│   └── projdefs.h
│   └── queue.h
│   └── semphr.h
│   └── stack_macros.h
│   └── stdint.h
│   └── stdint.readme
│   └── stream_buffer.h
│   └── task.h
│   └── timers.h
│   └── list.c
├── portable/
├── MemMang/
│   └── heap_1.c
│   └── heap_2.c
│   └── heap_3.c
│   └── heap_4.c
│   └── heap_5.c
├── STC32G12K128/
│   └── port.c
│   └── portasm.h
│   └── portmacro.h
│   └── queue.c
│   └── stream_buffer.c
│   └── tasks.c
│   └── timers.c
├── Task/
├── inc/
│   └── MatrixKey.h
│   └── adckey.h
│   └── display.h
│   └── i2c_ps.h
│   └── ntc.h
│   └── pwmb.h
│   └── rtc.h
│   └── uart2_3.h
├── src/
│   └── MatrixKey.c
│   └── adckey.c
│   └── display.c
│   └── i2c_ps.c
│   └── ntc.c
│   └── pwmb.c
│   └── rtc.c
│   └── uart2_3.c
├── User/
│   └── System_init.c
├── include/
│   └── FreeRTOSConfig.h
│   └── STC32G.H
│   └── System_init.h
│   └── main.c
│   └── putchar.c
│   └── 请先阅读本使用方法.txt
├── scripts/
│   └── clean_repo.py
│   └── format_code.py
│   └── send_fix_notification.py
│   └── send_notification.py
├── 参考项目/
├── 4串口 DMA 实例代码 STC32G/
├── 4串口 DMA 实例代码 STC32G/
│   └── Config.h
│   └── UART1.C
│   └── UART1.H
│   └── UART2.C
│   └── UART2.H
│   └── UART3.C
│   └── UART3.H
│   └── UART4.C
│   └── UART4.H
│   └── UART_DMA_STC32G.uvgui.laffe
│   └── UART_DMA_STC32G.uvopt
│   └── UART_DMA_STC32G.uvproj
├── library/
│   └── STC32G.H
│   └── STC32G_ADC.c
│   └── STC32G_ADC.h
│   └── STC32G_ADC_Isr.c
│   └── STC32G_CAN.c
│   └── STC32G_CAN.h
│   └── STC32G_CAN_Isr.c
│   └── STC32G_Clock.c
│   └── STC32G_Clock.h
│   └── STC32G_Compare.c
│   └── STC32G_Compare.h
│   └── STC32G_Compare_Isr.c
│   └── STC32G_DMA.c
│   └── STC32G_DMA.h
│   └── STC32G_DMA_Isr.c
│   └── STC32G_Delay.c
│   └── STC32G_Delay.h
│   └── STC32G_EEPROM.c
│   └── STC32G_EEPROM.h
│   └── STC32G_Exti.c
│   └── STC32G_Exti.h
│   └── STC32G_Exti_Isr.c
│   └── STC32G_GPIO.c
│   └── STC32G_GPIO.h
│   └── STC32G_GPIO_Isr.c
│   └── STC32G_I2C.c
│   └── STC32G_I2C.h
│   └── STC32G_I2C_Isr.c
│   └── STC32G_LCM.c
│   └── STC32G_LCM.h
│   └── STC32G_LCM_Isr.c
│   └── STC32G_LIN.c
│   └── STC32G_LIN.h
│   └── STC32G_LIN_Isr.c
│   └── STC32G_NVIC.c
│   └── STC32G_NVIC.h
│   └── STC32G_PWM.c
│   └── STC32G_PWM.h
│   └── STC32G_PWM_Isr.c
│   └── STC32G_RTC.c
│   └── STC32G_RTC.h
│   └── STC32G_RTC_Isr.c
│   └── STC32G_SPI.c
│   └── STC32G_SPI.h
│   └── STC32G_SPI_Isr.c
│   └── STC32G_Soft_I2C.c
│   └── STC32G_Soft_I2C.h
│   └── STC32G_Soft_UART.c
│   └── STC32G_Soft_UART.h
│   └── STC32G_Switch.h
│   └── STC32G_Timer.c
│   └── STC32G_Timer.h
│   └── STC32G_Timer_Isr.c
│   └── STC32G_UART.c
│   └── STC32G_UART.h
│   └── STC32G_UART_Isr.c
│   └── STC32G_USART_LIN.c
│   └── STC32G_USART_LIN.h
│   └── STC32G_WDT.c
│   └── STC32G_WDT.h
│   └── STC32_MDU32_V1.1.LIB
│   └── main.c
│   └── type_def.h
│   └── 代码说明.txt
├── SCM_15PA/
├── C51/
│   └── SCM_15PA.uvgui.mm
│   └── SCM_15PA.uvgui.zpc
│   └── SCM_15PA.uvopt
│   └── SCM_15PA.uvproj
├── Code/
│   └── dac.c
│   └── dac.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── kb.c
│   └── kb.h
│   └── main.c
│   └── main.h
│   └── rtc.c
│   └── rtc.h
│   └── seg.c
│   └── seg.h
│   └── sys.c
│   └── sys.h
│   └── ui.c
│   └── ui.h
├── 串口通讯(完美版)/
│   └── convert_encoding.py
├── 串口通讯(完美版)/
├── Doc/
│   └── Readme.txt
├── Output/
│   └── Project
│   └── Project.SBR
├── Project/
│   └── Project.uvgui.86132
│   └── Project.uvgui.laffe
│   └── Project.uvopt
│   └── Project.uvproj
├── User/
├── Inc/
│   └── LED.h
│   └── SMG.h
│   └── Sys.h
│   └── Timer.h
│   └── UART.h
│   └── config.h
├── Src/
│   └── LED.c
│   └── SMG.c
│   └── Sys.c
│   └── Timer.c
│   └── UART.c
│   └── main.c
├── 来源b站up主Sky少年y/
├── 0-1-LED和蜂鸣器/
│   └── LED和蜂鸣器.c
│   └── LED和蜂鸣器.uvgui.zi_xu2021
│   └── LED和蜂鸣器.uvopt
│   └── LED和蜂鸣器.uvproj
├── 1-LED的基本操作/
│   └── LED.c
│   └── LED.uvgui.zi_xu2021
│   └── LED.uvopt
│   └── LED.uvproj
├── 10-NE555的频率测量/
│   └── NE555的频率测量.uvgui.zi_xu2021
│   └── NE555的频率测量.uvopt
│   └── NE555的频率测量.uvproj
│   └── NE555频率测量.c
├── 11-AT24C02的基础操作/
│   └── AT24C02的基础操作.uvgui.zi_xu2021
│   └── AT24C02的基础操作.uvopt
│   └── AT24C02的基础操作.uvproj
│   └── AT24C02的操作.c
│   └── iic.c
│   └── iic.h
├── 12-超声波传感器/
│   └── 超声波传感器.c
│   └── 超声波传感器.uvgui.zi_xu2021
│   └── 超声波传感器.uvopt
│   └── 超声波传感器.uvproj
├── 2-蜂鸣器和继电器/
│   └── 蜂鸣器和继电器.c
│   └── 蜂鸣器继电器.uvgui.zi_xu2021
│   └── 蜂鸣器继电器.uvopt
│   └── 蜂鸣器继电器.uvproj
├── 3-数码管的基本显示/
│   └── 数码管.c
│   └── 数码管的基本显示.uvgui.zi_xu2021
│   └── 数码管的基本显示.uvopt
│   └── 数码管的基本显示.uvproj
├── 4-1-独立按键的基本驱动/
│   └── 独立按键1.c
│   └── 独立按键1.uvgui.zi_xu2021
│   └── 独立按键1.uvopt
│   └── 独立按键1.uvproj
├── 4-2-矩阵按键的基本驱动/
│   └── 矩阵按键.c
│   └── 矩阵按键.uvgui.zi_xu2021
│   └── 矩阵按键.uvopt
│   └── 矩阵按键.uvproj
├── 5-外部中断/
│   └── 外部中断.c
│   └── 外部中断.uvgui.zi_xu2021
│   └── 外部中断.uvopt
│   └── 外部中断.uvproj
├── 6-定时器与计数器/
│   └── 定时器与计数器.c
│   └── 定时器与计数器.uvgui.zi_xu2021
│   └── 定时器与计数器.uvopt
│   └── 定时器与计数器.uvproj
├── 7-DS1302的简单运用/
│   └── DS1302.uvgui.zi_xu2021
│   └── DS1302.uvopt
│   └── DS1302.uvproj
│   └── DS1302工程.c
│   └── ds1302.c
│   └── ds1302.h
├── 8-DS18B20温度的读取/
│   └── DS18B20温度的读取.uvgui.zi_xu2021
│   └── DS18B20温度的读取.uvopt
│   └── DS18B20温度的读取.uvproj
│   └── DS18B20温度读取.c
│   └── onewire.c
│   └── onewire.h
├── 9-PCF8591的简单运用/
│   └── PCF8591的简单运用.uvgui.zi_xu2021
│   └── PCF8591的简单运用.uvopt
│   └── PCF8591的简单运用.uvproj
│   └── PCF8591的运用.c
│   └── iic.c
│   └── iic.h
├── 来源b站up主combo努力中/
├── Driver/
│   └── Init.c
│   └── Init.h
│   └── Key.c
│   └── Key.h
│   └── Led.c
│   └── Led.h
│   └── Seg.c
│   └── Seg.h
│   └── ds1302.c
│   └── ds1302.h
├── User/
│   └── kangkang.uvgui.Administrator
│   └── kangkang.uvopt
│   └── kangkang.uvproj
│   └── main.c
├── 蓝桥杯单片机入门视频代码/
├── 1.LED/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 10.NE555频率测量/
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 11.DS18B20温度测量/
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 12.PCF8591芯片/
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 13.超声波测距/
│   └── csb.c
│   └── csb.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 14.串口通信/
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvgui.laffey
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 2.数码管/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 3.蜂鸣器和继电器/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 4.独立按键/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 5.矩阵键盘/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 6.定时器的应用/
│   └── main.c
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 7.比赛通用模板/
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 8.AT24C02存储芯片/
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 9.DS1302时钟芯片/
│   └── ds1302.c
│   └── ds1302.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── prj.uvgui.admin
│   └── prj.uvgui.laffey
│   └── prj.uvopt
│   └── prj.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 蓝桥杯单片机第八届（DS1302+DS18B20）/
│   └── STARTUP.A51
│   └── ds1302.c
│   └── ds1302.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
│   └── project.uvgui.admin
│   └── project.uvopt
│   └── project.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 蓝桥杯单片机第十一届第一场(PCF8591+AT24C02)/
│   └── STARTUP.A51
│   └── iic.c
│   └── iic.h
│   └── kbd.c
│   └── kbd.h
│   └── main.c
│   └── main.h
│   └── project.uvgui.admin
│   └── project.uvopt
│   └── project.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 蓝桥杯单片机第十二届第二场(NE555+PCF8591)/
├── 十二届二场/
│   └── STARTUP.A51
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── project.uvgui.admin
│   └── project.uvopt
│   └── project.uvproj
│   └── sys.c
│   └── sys.h
│   └── tube.c
│   └── tube.h
├── 实例/
├── 13/
│   └── 13.uvgui.laffe
│   └── 13.uvgui.laffey
│   └── 13.uvopt
│   └── 13.uvproj
│   └── STARTUP.A51
│   └── readme.md
├── src/
├── driver/
│   └── ds1302.c
│   └── key.c
│   └── led.c
│   └── onewire.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── ds1302.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── onewire.h
│   └── seg.h
│   └── uart.h
├── user/
│   └── boot.c
│   └── main.c
│   └── uart.c
├── 14/
│   └── README.md
├── code/
├── driver/
│   └── ds1302.c
│   └── iic.c
│   └── key.c
│   └── led.c
│   └── onewire.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── ds1302.h
│   └── error.h
│   └── iic.h
│   └── key.h
│   └── led.h
│   └── log.h
│   └── main.h
│   └── module.h
│   └── onewire.h
│   └── seg.h
│   └── uart.h
├── user/
│   └── boot.c
│   └── log.c
│   └── main.c
│   └── module.c
│   └── uart.c
│   └── debug.log
├── project/
│   └── 14.uvgui.laffe
│   └── 14.uvgui.顾离
│   └── 14.uvopt
│   └── 14.uvproj
│   └── STARTUP.A51
│   └── build.log
├── 14.1/
├── code/
├── driver/
│   └── ds1302.c
│   └── iic.c
│   └── key.c
│   └── led.c
│   └── onewire.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── ds1302.h
│   └── iic.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── onewire.h
│   └── seg.h
│   └── task.h
│   └── uart.h
├── main/
│   └── boot.c
│   └── main.c
│   └── task.c
│   └── uart.c
├── project/
│   └── 141.uvgui.laffe
│   └── 141.uvopt
│   └── 141.uvproj
│   └── STARTUP.A51
├── 15/
│   └── 15
│   └── 1555.uvgui.laffey
│   └── 1555.uvopt
│   └── 1555.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── sonic.c
│   └── sonic.h
│   └── uart.c
│   └── uart.h
├── 16.2/
├── code/
├── driver/
├── include/
│   └── ds1302.h
│   └── iic.h
│   └── key.h
│   └── led.h
│   └── onewire.h
│   └── seg.h
│   └── sonic.h
├── main/
│   └── ds1302.c
│   └── iic.c
│   └── key.c
│   └── led.c
│   └── onewire.c
│   └── seg.c
│   └── sonic.c
├── user/
├── include/
│   └── boot.h
│   └── main.h
│   └── task.h
│   └── uart.h
├── main/
│   └── boot.c
│   └── main.c
│   └── task.c
│   └── uart.c
├── project/
│   └── 162.uvgui.laffe
│   └── 162.uvopt
│   └── 162.uvproj
│   └── STARTUP.A51
├── 17.1/
├── code/
├── user/
├── include/
│   └── boot.h
│   └── main.h
├── main/
│   └── boot.c
│   └── main.c
├── 2.1串口/
│   └── 64.uvgui.laffe
│   └── 64.uvopt
│   └── 64.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── uart.c
│   └── uart.h
├── 2.2/
├── code/
│   └── display.c
│   └── display.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
├── 2.3/
│   └── 23.uvgui.laffe
│   └── 23.uvopt
│   └── 23.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── key.c
│   └── key.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── sonic.c
│   └── sonic.h
│   └── timer.c
│   └── timer.h
├── 5.18/
├── code/
├── driver/
├── include/
│   └── key.h
├── main/
│   └── key.c
├── user/
├── include/
│   └── boot.h
│   └── main.h
├── main/
│   └── boot.c
│   └── main.c
├── 5.30/
│   └── 530.uvgui.laffe
│   └── 530.uvopt
│   └── 530.uvproj
│   └── STARTUP.A51
├── driver/
├── inc/
│   └── key.h
│   └── led.h
│   └── onewire.h
│   └── seg.h
│   └── sonic.h
├── main/
│   └── key.c
│   └── led.c
│   └── onewire.c
│   └── seg.c
│   └── sonic.c
├── user/
├── inc/
│   └── boot.h
│   └── main.h
│   └── uart.h
├── main/
│   └── boot.c
│   └── main.c
│   └── uart.c
├── 5.8/
├── code/
├── driver/
├── include/
│   └── key.h
│   └── led.h
│   └── seg.h
│   └── sonic.h
├── main/
│   └── key.c
│   └── led.c
│   └── seg.c
│   └── sonic.c
├── user/
├── include/
│   └── boot.h
│   └── main.h
│   └── task.h
│   └── uart.h
├── main/
│   └── boot.c
│   └── main.c
│   └── task.c
│   └── uart.c
├── project/
│   └── 58.uvgui.laffe
│   └── 58.uvopt
│   └── 58.uvproj
│   └── STARTUP.A51
├── aicubes/
├── Sources/
│   └── clock.c
├── inc/
│   └── clock.h
│   └── config.h
│   └── def.h
│   └── pca.h
│   └── port.h
│   └── stc15f_def.h
│   └── timer.h
│   └── uart.h
│   └── main.c
│   └── pca.c
│   └── port.c
│   └── timer.c
│   └── uart.c
│   └── aicubes.aic
│   └── aicubes.uvgui.laffe
│   └── aicubes.uvopt
│   └── aicubes.uvproj
│   └── aicubes_bk1.uvgui.laffe
│   └── aicubes_bk1.uvopt
│   └── aicubes_bk1.uvproj
├── date/
├── 1/
│   └── 18B20.c
│   └── 18B20.h
│   └── STARTUP.A51
│   └── ceshi.uvgui.Administrator
│   └── ceshi.uvopt
│   └── ceshi.uvproj
│   └── csb.c
│   └── csb.h
│   └── iic.c
│   └── iic.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
│   └── smg.c
│   └── smg.h
│   └── sys.c
│   └── sys.h
├── 2/
│   └── 315
│   └── 315.M51
│   └── 315.uvopt
│   └── 315.uvproj
│   └── 315_uvproj.bak
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
│   └── sonic.c
│   └── sonic.h
│   └── 新建文本文档 (2).txt
│   └── 新建文本文档.txt
├── 2.27/
│   └── 27.uvgui.laffe
│   └── 27.uvgui.laffey
│   └── 27.uvopt
│   └── 27.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
├── main2.c/
│   └── main.c
│   └── onewire.c
│   └── onewire.h
│   └── seg.c
│   └── seg.h
│   └── sonic.c
│   └── sonic.h
├── 3/
│   └── 3232323
│   └── 3232323.M51
│   └── 3232323.uvgui.laffey
│   └── 3232323.uvopt
│   └── 3232323.uvproj
│   └── 3232323_uvproj.bak
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
├── 3.22/
├── code/
│   └── 3.22
│   └── 3.22.uvgui.laffey
│   └── 3.22.uvopt
│   └── 3.22.uvproj
│   └── 3.22_uvopt.bak
│   └── 3.22_uvproj.bak
│   └── 3.M51
│   └── STARTUP.A51
├── code/
│   └── 2333.md
│   └── boot.c
│   └── boot.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
├── 3.25/
│   └── 25.uvgui.laffe
│   └── 25.uvgui.laffey
│   └── 25.uvopt
│   └── 25.uvproj
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
│   └── sonic.c
│   └── sonic.h
├── 3.31/
│   └── 4444.uvgui.laffey
│   └── 4444.uvopt
│   └── 4444.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── sonic.c
│   └── sonic.h
│   └── readme.md
├── 4/
│   └── 383838383838383838.uvgui.laffe
│   └── 383838383838383838.uvgui.laffey
│   └── 383838383838383838.uvopt
│   └── 383838383838383838.uvproj
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
├── none/
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── sand.c
│   └── onewire.c
│   └── onewire.h
│   └── seg.c
│   └── seg.h
├── 4.2/
│   └── 42.uvgui.laffe
│   └── 42.uvgui.laffey
│   └── 42.uvopt
│   └── 42.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
├── 4.4/
│   └── 4.7.uvgui.laffey
│   └── 4.7.uvopt
│   └── 4.7.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
├── 4.7/
│   └── 47.uvgui.laffey
│   └── 47.uvopt
│   └── 47.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
├── 4.71/
│   └── 471.uvgui.laffey
│   └── 471.uvopt
│   └── 471.uvproj
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
├── 4.8 初始化测试/
│   └── 48.uvgui.laffe
│   └── 48.uvgui.laffey
│   └── 48.uvopt
│   └── 48.uvproj
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
├── 5/
│   └── boot.c
│   └── boot.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
├── 6/
│   └── 3.19999‘.uvgui.laffe
│   └── 3.19999‘.uvgui.laffey
│   └── 3.19999‘.uvopt
│   └── 3.19999‘.uvproj
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── ne555.c
│   └── ne555.h
│   └── onewire.c
│   └── onewire.h
│   └── seg.c
│   └── seg.h
│   └── sonic.c
│   └── sonic.h
├── codeReview/
├── hh/
│   └── STARTUP.A51
│   └── key.c
│   └── key.h
│   └── led.c
│   └── led.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
│   └── sys.c
│   └── sys.h
│   └── test
│   └── test.M51
│   └── test.uvgui.laffe
│   └── test.uvopt
│   └── test.uvproj
│   └── test_uvproj.bak
├── 结构体测试/
│   └── STARTUP.A51
├── code/
│   └── boot.c
│   └── boot.h
│   └── main.c
│   └── main.h
│   └── seg.c
│   └── seg.h
│   └── sonic.c
│   └── sonic.h
│   └── struct.uvgui.laffey
│   └── struct.uvopt
│   └── struct.uvproj
├── rewrite/
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── uart.c
│   └── uart.h
├── docs/
│   └── boot.md
│   └── main.md
│   └── facxie.uvgui.laffey
│   └── facxie.uvopt
│   └── facxie.uvproj
├── rewrite_test/
│   └── 5.19.uvgui.laffey
│   └── 5.19.uvopt
│   └── 5.19.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── key.c
│   └── key.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── sonic.c
│   └── sonic.h
│   └── uart.c
│   └── uart.h
├── stc15_sdcc-quickstart/
│   └── README.md
├── img/
│   └── stc15f104w_pins.png
├── libraries/
├── stc15_lib/
│   └── LICENSE
│   └── config.h
├── include/
│   └── ADC.h
│   └── EEPROM.h
│   └── Exti.h
│   └── GPIO.h
│   └── PCA.h
│   └── STC15Fxxxx.H
│   └── USART.h
│   └── delay.h
│   └── soft_uart.h
│   └── timer.h
├── source/
│   └── ADC.c
│   └── EEPROM.c
│   └── Exti.c
│   └── GPIO.c
│   └── PCA.c
│   └── USART.C
│   └── delay.c
│   └── soft_uart.c
│   └── timer.c
├── source/
│   └── main.c
│   └── stc15_sdcc-quickstart.code-workspace
├── 全功能/
│   └── STARTUP.A51
│   └── all.uvgui.laffe
│   └── all.uvgui.laffey
│   └── all.uvopt
│   └── all.uvproj
├── code/
│   └── boot.c
│   └── boot.h
│   └── dis.c
│   └── dis.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
│   └── sonic.c
│   └── sonic.h
├── 全功能重构/
│   └── 2333.uvgui.laffey
│   └── 2333.uvopt
│   └── 2333.uvproj
├── include/
│   └── boot.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── seg.h
│   └── task.h
├── main/
│   └── boot.c
│   └── key.c
│   └── led.c
│   └── main.c
│   └── seg.c
│   └── stc_err.c
│   └── task.c
│   └── task_timer.c
├── 温度计/
│   └── STARTUP.A51
│   └── boot.c
│   └── boot.h
│   └── display.c
│   └── display.h
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── key.c
│   └── key.h
│   └── main.c
│   └── main.h
│   └── onewire.c
│   └── onewire.h
│   └── xiaomi.code-workspace
│   └── xiaomi.uvgui.laffey
│   └── xiaomi.uvopt
│   └── xiaomi.uvproj
├── 闹钟/
│   └── boot.h
│   └── ds1302.c
│   └── iic.c
│   └── iic.h
│   └── main.c
│   └── main.h
├── 底层库/
│   └── ds1302.c
│   └── ds1302.h
│   └── iic.c
│   └── iic.h
│   └── onewire.c
│   └── onewire.h
├── 教程/
├── 2333/
│   └── 2333.aic
│   └── 2333.uvgui.laffey
│   └── 2333.uvopt
│   └── 2333.uvproj
│   └── 2333_bk1.uvproj
│   └── 2333_bk2.uvproj
├── Sources/
│   └── clock.c
├── inc/
│   └── clock.h
│   └── config.h
│   └── def.h
│   └── port.h
│   └── stc15f_def.h
│   └── timer.h
│   └── uart.h
│   └── main.c
│   └── port.c
│   └── timer.c
│   └── uart.c
├── led/
│   └── STARTUP.A51
├── include/
│   └── boot.h
│   └── led.h
│   └── main.h
│   └── led.uvgui.laffey
│   └── led.uvopt
│   └── led.uvproj
├── main/
│   └── boot.c
│   └── led.c
│   └── main.c
├── 模块/
├── 1.0 boot/
│   └── boot.c
│   └── boot.h
├── 1.1 seg/
│   └── seg.c
│   └── seg.h
├── 1.2 led/
│   └── led.c
│   └── led.h
├── 流水灯/
│   └── STARTUP.A51
│   └── led.c
│   └── led.h
│   └── 流水灯.uvgui.laffey
│   └── 流水灯.uvopt
│   └── 流水灯.uvproj
├── 1.3 key/
├── code/
├── driver/
│   └── key copy.c
│   └── key.c
│   └── led.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── seg.h
├── user/
│   └── boot.c
│   └── main.c
│   └── key.uvgui.laffe
│   └── key.uvopt
│   └── key.uvproj
├── 1.4 sonic/
│   └── Nu_Link_8051_Driver.ini
│   └── ciallo.code-workspace
│   └── ciallo.uvgui.laffe
│   └── ciallo.uvopt
│   └── ciallo.uvproj
├── include/
│   └── boot.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── seg.h
│   └── sonic.h
├── main/
│   └── boot.c
│   └── key.c
│   └── led.c
│   └── main.c
│   └── seg.c
│   └── sonic.c
├── 1.5 ne555/
├── code/
├── driver/
│   └── key.c
│   └── led.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── seg.h
├── user/
│   └── STARTUP.A51
│   └── boot.c
│   └── main.c
├── old/
│   └── 2333333.uvgui.laffe
│   └── 2333333.uvopt
│   └── 2333333.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
│   └── timer.c
│   └── timer.h
├── project/
│   └── STARTUP.A51
│   └── freq.uvgui.laffe
│   └── freq.uvopt
│   └── freq.uvproj
├── 1.6 串口通讯/
├── code/
├── include/
│   └── boot.h
│   └── main.h
│   └── uart.h
├── main/
│   └── boot.c
│   └── main.c
│   └── uart.c
├── project/
│   └── uaRt.uvgui.laffe
│   └── uaRt.uvopt
│   └── uaRt.uvproj
├── 1.7 PCA/
│   └── 64.uvgui.laffe
│   └── 64.uvopt
│   └── 64.uvproj
│   └── STARTUP.A51
├── code/
│   └── display.c
│   └── display.h
│   └── machine.c
│   └── machine.h
│   └── main.c
│   └── main.h
├── 1.8 rtc/
├── code/
├── driver/
│   └── ds1302.c
│   └── key copy.c
│   └── key.c
│   └── led.c
│   └── seg.c
├── include/
│   └── boot.h
│   └── ds1302.h
│   └── key.h
│   └── led.h
│   └── main.h
│   └── seg.h
├── user/
│   └── boot.c
│   └── main.c
├── project/
│   └── STARTUP.A51
│   └── ds1302.uvgui.laffe
│   └── ds1302.uvopt
│   └── ds1302.uvproj
├── 1.9 temp/
├── code/
├── driver/
│   └── boot.h
│   └── main.c
├── main/
│   └── boot.c
│   └── main.c
├── project/
│   └── STARTUP.A51
│   └── ds18b20.uvproj
├── 2.0 led/
│   └── 2.0led.uvgui.laffey
│   └── 2.0led.uvopt
│   └── 2.0led.uvproj
│   └── STARTUP.A51
├── include/
│   └── main.h
│   └── stdbool.h
├── main/
│   └── main.c
├── 2.1轮询/
│   └── 2.1轮询.uvgui.laffey
│   └── 2.1轮询.uvopt
│   └── 2.1轮询.uvproj
├── include/
│   └── main.h
├── main/
│   └── main.c
```
