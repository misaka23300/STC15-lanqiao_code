# C语言代码标准化规范

## 1. 文件结构

### 1.1 文件命名
- 文件名使用小写字母和下划线，如 `main.c`, `uart_driver.h`
- 头文件以 `.h` 结尾，源文件以 `.c` 结尾

### 1.2 文件头注释
每个C文件开头必须包含标准文件头：

```c
/**
 * @file main.c
 * @brief 主程序入口文件
 * @author Author Name
 * @date 2024-01-15
 * @version 1.0
 */
```

## 2. 代码风格

### 2.1 缩进
- 使用 **4个空格** 进行缩进，不使用Tab
- 函数体、循环体、条件语句体都需要缩进

### 2.2 大括号
- 左大括号 `{` 不单独占一行，紧跟在语句后面
- 右大括号 `}` 单独占一行，与对应的语句对齐

```c
// 正确
if (condition) {
    // code
} else {
    // code
}

// 错误
if (condition)
{
    // code
}
```

### 2.3 空格
- 关键字和括号之间要有空格：`if (condition)` 而非 `if(condition)`
- 运算符两边要有空格：`a = b + c` 而非 `a=b+c`
- 逗号后面要有空格：`func(a, b, c)` 而非 `func(a,b,c)`

### 2.4 换行
- 一行代码不超过 **80个字符**
- 长表达式需要换行时，在运算符后换行

## 3. 命名规范

### 3.1 变量命名
- 使用 **蛇形命名法**：`unsigned char led_state;`
- 全局变量加 `g_` 前缀：`unsigned int g_system_tick;`
- 静态变量加 `s_` 前缀：`static unsigned char s_counter;`

### 3.2 函数命名
- 使用 **蛇形命名法**：`void uart_send_data(unsigned char data);`
- 函数名要清晰表达功能

### 3.3 宏定义
- 使用 **全大写加下划线**：`#define MAX_BUFFER_SIZE 100`

### 3.4 结构体命名
- 使用 **蛇形命名法**，以 `_t` 结尾：`typedef struct { ... } timer_t;`

## 4. 注释规范

### 4.1 函数注释
每个函数前必须有注释：

```c
/**
 * @brief 初始化串口1
 * @param baud_rate 波特率
 * @return 无
 */
void uart1_init(unsigned int baud_rate) {
    // code
}
```

### 4.2 代码注释
- 复杂逻辑需要注释说明
- 注释要简洁明了，避免废话
- 使用 `//` 进行单行注释
- 使用 `/* */` 进行多行注释

## 5. 变量声明

### 5.1 变量定义位置
- 局部变量在函数开头声明
- 全局变量在文件开头声明

### 5.2 类型使用
- 优先使用标准类型：`uint8_t`, `uint16_t`, `int16_t` 等（需包含 `<stdint.h>`）
- 避免使用 `unsigned char` 以外的非标准类型

## 6. 函数设计

### 6.1 函数大小
- 单个函数不超过 **50行**
- 功能复杂时拆分为多个函数

### 6.2 参数传递
- 输入参数使用 const 修饰：`void func(const uint8_t *data);`
- 输出参数使用指针：`void get_data(uint8_t *result);`

## 7. 条件语句

### 7.1 if-else
- 条件表达式要清晰
- 单行语句也要用大括号包裹

```c
// 正确
if (a > 0) {
    do_something();
}

// 错误
if (a > 0) do_something();
```

### 7.2 switch-case
- 每个 case 都要有 `break`（除非有意贯穿）
- default 分支不能省略

## 8. 中断服务函数

### 8.1 命名规则
- 使用 `Isr` 后缀：`void Timer0_Isr(void) interrupt 1`

### 8.2 代码限制
- 中断服务函数要简短
- 避免在中断中调用耗时函数
- 共享变量使用 `volatile` 修饰

## 9. 头文件保护

### 9.1 防止重复包含
每个头文件必须包含保护：

```c
#ifndef __UART_DRIVER_H__
#define __UART_DRIVER_H__

// 头文件内容

#endif // __UART_DRIVER_H__
```

### 9.2 包含顺序
- 先包含标准库头文件
- 再包含项目头文件

## 10. 编程实践

### 10.1 错误处理
- 对返回值进行检查
- 使用断言进行参数校验

### 10.2 内存管理
- 嵌入式系统中避免使用动态内存分配
- 如果必须使用，确保有足够的错误处理

### 10.3 代码可读性
- 保持代码简洁
- 使用有意义的变量名和函数名
- 避免魔法数字，使用宏定义

---

**版本**: 1.0  
**日期**: 2026-06-09  
**适用项目**: STC15-lanqiao_code