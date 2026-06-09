#!/usr/bin/env python3
"""
C代码格式化工具
适用于 STC15-lanqiao_code 项目

功能：
1. 自动格式化所有C语言源文件
2. 添加标准文件头注释
3. 检查并修复常见代码风格问题

使用方法：
    python3 scripts/format_code.py [目录路径]
"""

import os
import sys
import subprocess
import re
from datetime import datetime

# 支持的文件扩展名
SUPPORTED_EXTENSIONS = ('.c', '.h')

# 文件头模板
FILE_HEADER_TEMPLATE = """/**
 * @file {filename}
 * @brief {brief}
 * @date {date}
 * @version 1.0
 */
"""

def find_c_files(root_dir):
    """查找所有C语言源文件"""
    c_files = []
    for dirpath, dirnames, filenames in os.walk(root_dir):
        # 排除某些目录
        if '.git' in dirpath or 'Listings' in dirpath or 'Objects' in dirpath:
            continue
        
        for filename in filenames:
            if filename.endswith(SUPPORTED_EXTENSIONS):
                c_files.append(os.path.join(dirpath, filename))
    return c_files

def format_with_clang(filename):
    """使用clang-format格式化文件"""
    try:
        subprocess.run(
            ['clang-format', '-i', filename],
            check=True,
            capture_output=True
        )
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error formatting {filename}: {e.stderr.decode()}")
        return False
    except FileNotFoundError:
        print("clang-format not found, skipping automatic formatting")
        return False

def add_file_header(filename):
    """添加标准文件头注释"""
    with open(filename, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # 检查是否已有文件头
    if content.startswith('/**'):
        return False
    
    # 获取文件名
    basename = os.path.basename(filename)
    
    # 推断文件描述
    brief = infer_brief(basename)
    
    # 生成文件头
    header = FILE_HEADER_TEMPLATE.format(
        filename=basename,
        brief=brief,
        date=datetime.now().strftime('%Y-%m-%d')
    )
    
    # 添加文件头
    new_content = header + '\n' + content
    
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    return True

def infer_brief(filename):
    """根据文件名推断文件描述"""
    name_map = {
        'main.c': '主程序入口文件',
        'boot.c': '系统启动初始化文件',
        'uart.c': '串口驱动文件',
        'timer.c': '定时器驱动文件',
        'led.c': 'LED驱动文件',
        'key.c': '按键驱动文件',
        'seg.c': '数码管驱动文件',
        'iic.c': 'I2C总线驱动文件',
        'ds1302.c': 'DS1302实时时钟驱动',
        'onewire.c': '单总线驱动文件',
        'sonic.c': '超声波传感器驱动',
        'display.c': '显示模块驱动',
        'machine.c': '机器控制模块',
        'adc.c': 'ADC模数转换驱动',
        'rtc.c': '实时时钟驱动',
        'clock.c': '时钟配置模块',
        'port.c': '端口配置模块',
        'pca.c': 'PCA模块驱动',
    }
    
    base = filename.lower()
    for key in name_map:
        if key in base:
            return name_map[key]
    
    return '未指定描述'

def fix_common_issues(filename):
    """修复常见代码风格问题"""
    with open(filename, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    changes = 0
    
    # 修复空格问题
    # 1. if/while/for 后需要空格
    content, count = re.subn(r'\b(if|while|for)\(', r'\1 (', content)
    changes += count
    
    # 2. 运算符两边需要空格
    operators = ['=', '+', '-', '*', '/', '%', '==', '!=', '<', '>', '<=', '>=', '&&', '||', '+=', '-=', '*=', '/=']
    for op in operators:
        # 匹配运算符两边没有空格的情况
        pattern = r'([a-zA-Z0-9_])' + re.escape(op) + r'([a-zA-Z0-9_])'
        content, count = re.subn(pattern, r'\1 ' + op + ' \2', content)
        changes += count
    
    # 3. 逗号后需要空格
    content, count = re.subn(r',([a-zA-Z0-9_])', r', \1', content)
    changes += count
    
    # 4. 函数参数列表中的空格
    content, count = re.subn(r'\(\s*([a-zA-Z])', r'( \1', content)
    changes += count
    content, count = re.subn(r'([a-zA-Z0-9_])\s*\)', r'\1 )', content)
    changes += count
    
    # 5. 修复多余空行
    content = re.sub(r'\n{3,}', '\n\n', content)
    
    if changes > 0:
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(content)
    
    return changes

def main():
    # 获取目标目录
    if len(sys.argv) > 1:
        root_dir = sys.argv[1]
    else:
        root_dir = '.'
    
    # 查找所有C文件
    c_files = find_c_files(root_dir)
    print(f"找到 {len(c_files)} 个C语言源文件")
    
    # 格式化每个文件
    formatted = 0
    headers_added = 0
    issues_fixed = 0
    
    for filename in c_files:
        print(f"\n处理: {filename}")
        
        # 添加文件头
        if add_file_header(filename):
            headers_added += 1
            print("  ✓ 添加文件头")
        
        # 修复常见问题
        fixes = fix_common_issues(filename)
        issues_fixed += fixes
        if fixes > 0:
            print(f"  ✓ 修复 {fixes} 个代码风格问题")
        
        # 使用clang-format格式化
        if format_with_clang(filename):
            formatted += 1
            print("  ✓ 使用clang-format格式化")
    
    # 输出统计信息
    print("\n" + "="*60)
    print(f"格式化完成！")
    print(f"处理文件数: {len(c_files)}")
    print(f"添加文件头: {headers_added}")
    print(f"修复问题数: {issues_fixed}")
    print(f"clang格式化: {formatted}")
    print("="*60)

if __name__ == "__main__":
    main()