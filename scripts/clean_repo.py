#!/usr/bin/env python3
"""
仓库整理工具
适用于 STC15-lanqiao_code 项目

功能：
1. 整理目录结构
2. 清理冗余文件
3. 删除编译产物
4. 生成目录结构文档
"""

import os
import shutil
import sys

# 需要删除的文件类型
DELETE_PATTERNS = [
    '*.o', '*.obj', '*.lst', '*.map', '*.crf',
    '*.hex', '*.lnp', '*.plg', '*.__i', '*.SRC',
    '*.OBJ', '*.ia', '*.htm', '*.html', '*.pdf',
    '*.zip', '*.rar', '*.7z', '*.uvgui.*',
]

# 需要删除的目录
DELETE_DIRS = [
    'Listings',
    'Objects',
    '.vs',
    '软件工具',
]

# 需要保留的目录（参考项目）
KEEP_DIRS = [
    '参考项目',
    'STC32G_FreeRTOS',
]

def should_delete_file(filename):
    """判断文件是否应该删除"""
    for pattern in DELETE_PATTERNS:
        if filename.lower().endswith(pattern.lower().replace('*', '')):
            return True
    return False

def should_delete_dir(dirname):
    """判断目录是否应该删除"""
    return dirname in DELETE_DIRS

def clean_directory(path, dry_run=False):
    """清理目录"""
    deleted_files = 0
    deleted_dirs = 0
    
    for dirpath, dirnames, filenames in os.walk(path):
        # 跳过某些目录
        if '.git' in dirpath:
            continue
        
        # 删除文件
        for filename in filenames:
            if should_delete_file(filename):
                full_path = os.path.join(dirpath, filename)
                if not dry_run:
                    os.remove(full_path)
                deleted_files += 1
                print(f"删除文件: {full_path}")
        
        # 删除目录（需要从底向上删除）
        for dirname in list(dirnames):
            if should_delete_dir(dirname):
                full_path = os.path.join(dirpath, dirname)
                if not dry_run:
                    shutil.rmtree(full_path)
                deleted_dirs += 1
                print(f"删除目录: {full_path}")
    
    return deleted_files, deleted_dirs

def generate_structure(root_dir, prefix=""):
    """生成目录结构文档"""
    lines = []
    for item in sorted(os.listdir(root_dir)):
        if item.startswith('.'):
            continue
        
        full_path = os.path.join(root_dir, item)
        rel_path = os.path.join(prefix, item)
        
        if os.path.isdir(full_path):
            lines.append(f"├── {item}/")
            lines.extend(generate_structure(full_path, rel_path))
        else:
            lines.append(f"│   └── {item}")
    
    return lines

def main():
    root_dir = '.'
    
    print("="*60)
    print("仓库整理工具")
    print("="*60)
    
    # 清理文件和目录
    print("\n1. 清理冗余文件和目录...")
    deleted_files, deleted_dirs = clean_directory(root_dir)
    print(f"   删除文件: {deleted_files}")
    print(f"   删除目录: {deleted_dirs}")
    
    # 生成目录结构文档
    print("\n2. 生成目录结构文档...")
    structure = generate_structure(root_dir)
    with open('DIRECTORY_STRUCTURE.md', 'w', encoding='utf-8') as f:
        f.write("# 项目目录结构\n\n")
        f.write("```\n")
        f.write("\n".join(structure))
        f.write("\n```\n")
    print("   已生成: DIRECTORY_STRUCTURE.md")
    
    print("\n" + "="*60)
    print("整理完成！")
    print("="*60)

if __name__ == "__main__":
    main()