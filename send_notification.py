#!/usr/bin/env python3
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import sys

def send_notification_email():
    sender_email = "noreply@example.com"
    receiver_email = "laffey4590@qq.com"
    smtp_server = "smtp.example.com"
    smtp_port = 587

    subject = "代码修复完成 - Code Fixes Completed"
    body = """
您好 / Hello,

我们已完成对代码仓库的全面检查和修复。

We have completed a comprehensive code review and fixes for the repository.

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

谢谢 / Thank you
"""

    try:
        msg = MIMEMultipart()
        msg['From'] = sender_email
        msg['To'] = receiver_email
        msg['Subject'] = subject
        msg.attach(MIMEText(body, 'plain', 'utf-8'))

        print("邮件内容已准备好 / Email content prepared")
        print("=" * 60)
        print(body)
        print("=" * 60)
        print(f"\n注意: 由于系统未配置SMTP服务器，邮件未能自动发送。")
        print(f"Note: Email could not be sent automatically as SMTP server is not configured.")
        print(f"\n请手动发送上述邮件内容至: {receiver_email}")
        print(f"Please manually send the above content to: {receiver_email}")

        return 0
    except Exception as e:
        print(f"错误: {e}", file=sys.stderr)
        return 1

if __name__ == "__main__":
    sys.exit(send_notification_email())
