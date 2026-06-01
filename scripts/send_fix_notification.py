#!/usr/bin/env python3
"""
代码修复通知邮件发送脚本
Code Fix Notification Email Script

使用方法 / Usage:
    python3 scripts/send_fix_notification.py --smtp-host <smtp_host> --smtp-port <port> --username <user> --password <pass>

示例 / Example:
    python3 scripts/send_fix_notification.py --smtp-host smtp.qq.com --smtp-port 587 --username your_email@qq.com --password your_auth_code
"""

import smtplib
import argparse
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import sys

def create_email_content():
    subject = "代码修复完成 - Code Fixes Completed"

    body = """您好 / Hello,

我们已完成对代码仓库的全面检查和修复。

修复内容 / Fixes Applied:

1. 定时器中断修复 (Timer Interrupt Fix)
   文件: 教程/led/main/main.c
   问题: Timer1_Isr中断处理函数中遗漏了task_500ms.cnt的递增
   修复: 添加了缺失的计数器递增逻辑

2. 超声波测距模块修复 (Sonic Module Fix)
   文件: 模块/1.4 sonic/main/sonic.c
   问题: 类型转换优先级错误导致距离计算不正确
   修复: 修正了类型转换和浮点数运算的优先级

3. 串口通讯模块修复 (UART Module Fix)
   文件: 模块/1.6 串口通讯/code/main/uart.c
   问题: memset函数参数错误，复用了rx_buf而非tx_buf
   修复: 修正为正确的tx_buf缓冲区初始化

4. 显示逻辑修复 (Display Logic Fix)
   文件: 实例/rewrite_test/code/main.c
   问题: 数字提取逻辑错误，sonic.distance % 10 / 10 永远为0
   修复: 修正为正确的十位数和个位数提取

所有修复已推送到新分支: fix/code-quality-improvements
All fixes have been pushed to new branch: fix/code-quality-improvements

GitHub链接 / GitHub Link:
https://github.com/misaka23300/STC15-lanqiao_code/pull/new/fix/code-quality-improvements

请审查并决定是否合并 / Please review and decide whether to merge.

谢谢 / Thank you"""

    return subject, body

def send_email(smtp_host, smtp_port, username, password, to_email):
    subject, body = create_email_content()

    msg = MIMEMultipart()
    msg['From'] = username
    msg['To'] = to_email
    msg['Subject'] = subject
    msg.attach(MIMEText(body, 'plain', 'utf-8'))

    try:
        print(f"正在连接到 SMTP 服务器: {smtp_host}:{smtp_port}")
        server = smtplib.SMTP(smtp_host, smtp_port)
        server.starttls()

        print(f"正在登录邮箱: {username}")
        server.login(username, password)

        print(f"正在发送邮件到: {to_email}")
        server.send_message(msg)

        server.quit()
        print("✓ 邮件发送成功 / Email sent successfully!")
        return True

    except smtplib.SMTPAuthenticationError:
        print("✗ 认证失败，请检查用户名和密码")
        print("✗ Authentication failed, please check username and password")
        return False
    except smtplib.SMTPException as e:
        print(f"✗ SMTP错误: {e}")
        print(f"✗ SMTP Error: {e}")
        return False
    except Exception as e:
        print(f"✗ 错误: {e}")
        print(f"✗ Error: {e}")
        return False

def main():
    parser = argparse.ArgumentParser(description='发送代码修复通知邮件')
    parser.add_argument('--smtp-host', required=True, help='SMTP服务器地址')
    parser.add_argument('--smtp-port', type=int, required=True, help='SMTP服务器端口')
    parser.add_argument('--username', required=True, help='发送邮箱地址')
    parser.add_argument('--password', required=True, help='邮箱授权码或密码')
    parser.add_argument('--to', default='laffey4590@qq.com', help='收件人邮箱')

    args = parser.parse_args()

    if send_email(args.smtp_host, args.smtp_port, args.username, args.password, args.to):
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == "__main__":
    main()
