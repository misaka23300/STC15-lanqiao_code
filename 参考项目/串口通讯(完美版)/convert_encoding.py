#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
将项目中的C源文件和头文件从GB2312编码转换为UTF-8编码
"""

import os
import sys
import codecs
import glob

def detect_encoding(file_path):
    """尝试检测文件编码"""
    try:
        # 首先尝试UTF-8
        with open(file_path, 'r', encoding='utf-8') as f:
            f.read()
        return 'utf-8'
    except UnicodeDecodeError:
        try:
            # 尝试GB2312 (GBK)
            with open(file_path, 'r', encoding='gb2312') as f:
                f.read()
            return 'gb2312'
        except UnicodeDecodeError:
            try:
                # 尝试GBK (兼容更多字符)
                with open(file_path, 'r', encoding='gbk') as f:
                    f.read()
                return 'gbk'
            except UnicodeDecodeError:
                # 尝试其他常见编码
                try:
                    with open(file_path, 'r', encoding='utf-8-sig') as f:
                        f.read()
                    return 'utf-8-sig'
                except UnicodeDecodeError:
                    return None

def convert_file(file_path, target_encoding='utf-8'):
    """转换单个文件的编码"""
    source_encoding = detect_encoding(file_path)
    
    if source_encoding is None:
        print(f"无法检测 {file_path} 的编码，跳过")
        return False
    
    if source_encoding.lower().replace('-', '') == target_encoding.lower().replace('-', ''):
        print(f"{file_path} 已经是 {target_encoding} 编码，跳过")
        return True
    
    try:
        # 读取原始内容
        with open(file_path, 'r', encoding=source_encoding) as f:
            content = f.read()
        
        # 写入新编码
        with open(file_path, 'w', encoding=target_encoding) as f:
            f.write(content)
        
        print(f"成功转换 {file_path} 从 {source_encoding} 到 {target_encoding}")
        return True
    except Exception as e:
        print(f"转换 {file_path} 时出错: {e}")
        return False

def main():
    # 项目根目录
    project_root = os.path.dirname(os.path.abspath(__file__))
    
    # 查找所有C源文件和头文件
    patterns = [
        '**/*.c',
        '**/*.h',
        '**/*.txt',
        '**/*.md'
    ]
    
    files_to_convert = []
    for pattern in patterns:
        for file_path in glob.glob(os.path.join(project_root, pattern), recursive=True):
            # 跳过输出目录和其他生成的文件
            if 'Output' in file_path or '__pycache__' in file_path:
                continue
            files_to_convert.append(file_path)
    
    print(f"找到 {len(files_to_convert)} 个文件需要检查")
    
    converted_count = 0
    skipped_count = 0
    failed_count = 0
    
    for file_path in files_to_convert:
        if convert_file(file_path, 'utf-8'):
            converted_count += 1
        else:
            failed_count += 1
    
    print(f"\n转换完成:")
    print(f"  成功转换: {converted_count}")
    print(f"  转换失败: {failed_count}")
    
    return 0 if failed_count == 0 else 1

if __name__ == '__main__':
    sys.exit(main())