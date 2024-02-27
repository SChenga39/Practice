#!/usr/bin/env bash

# NR 在 awk 中指行号
awk 'NR == 10' file.txt

# -n 表示只输出匹配行, p 表示 Print
sed -n 10p file.txt

# +10 表示从第 10 行开始输出
tail -n+10 file.txt | head -1
