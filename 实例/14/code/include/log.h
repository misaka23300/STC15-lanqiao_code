#ifndef __LOG_H__
#define __LOG_H__

#include "boot.h"

// 日志级别定义
typedef enum {
    LOG_LEVEL_NONE = 0,    // 无日志
    LOG_LEVEL_ERROR = 1,   // 错误
    LOG_LEVEL_WARN = 2,    // 警告
    LOG_LEVEL_INFO = 3,    // 信息
    LOG_LEVEL_DEBUG = 4    // 调试
} LogLevel;

// 全局日志级别
extern LogLevel g_log_level;

// 日志初始化
void log_init(LogLevel level);

// 日志输出函数
void log_error(const char* format, ...);
void log_warn(const char* format, ...);
void log_info(const char* format, ...);
void log_debug(const char* format, ...);

// 日志级别设置
void log_set_level(LogLevel level);

#endif