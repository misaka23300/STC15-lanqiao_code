#include "log.h"
#include "uart.h"
#include <stdarg.h>

// 全局日志级别
LogLevel g_log_level = LOG_LEVEL_INFO;

// 日志级别字符串
const char* log_level_str[] = {
    "NONE",
    "ERROR",
    "WARN ",
    "INFO ",
    "DEBUG"
};

/**
 * 初始化日志系统
 * @param level 日志级别
 */
void log_init(LogLevel level)
{
    g_log_level = level;
    log_info("Log system initialized, level: %s", log_level_str[level]);
}

/**
 * 设置日志级别
 * @param level 日志级别
 */
void log_set_level(LogLevel level)
{
    g_log_level = level;
    log_info("Log level changed to: %s", log_level_str[level]);
}

/**
 * 输出日志
 * @param level 日志级别
 * @param format 格式化字符串
 * @param ap 可变参数列表
 */
static void log_output(LogLevel level, const char* format, va_list ap)
{
    if (level > g_log_level) {
        return;
    }

    // 输出日志级别
    uart_send_string("[");
    uart_send_string(log_level_str[level]);
    uart_send_string("] ");

    // 输出格式化内容
    char buffer[64];
    vsprintf(buffer, format, ap);
    uart_send_string(buffer);
    uart_send_string("\r\n");
}

/**
 * 输出错误日志
 * @param format 格式化字符串
 * @param ... 可变参数
 */
void log_error(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    log_output(LOG_LEVEL_ERROR, format, ap);
    va_end(ap);
}

/**
 * 输出警告日志
 * @param format 格式化字符串
 * @param ... 可变参数
 */
void log_warn(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    log_output(LOG_LEVEL_WARN, format, ap);
    va_end(ap);
}

/**
 * 输出信息日志
 * @param format 格式化字符串
 * @param ... 可变参数
 */
void log_info(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    log_output(LOG_LEVEL_INFO, format, ap);
    va_end(ap);
}

/**
 * 输出调试日志
 * @param format 格式化字符串
 * @param ... 可变参数
 */
void log_debug(const char* format, ...)
{
    va_list ap;
    va_start(ap, format);
    log_output(LOG_LEVEL_DEBUG, format, ap);
    va_end(ap);
}