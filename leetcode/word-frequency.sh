#!/usr/bin/env bash

# 1. tr -s 将多个字符压缩成一个字符
# 2. 先 sort 再 uniq
# 3. sort -r 倒序排序
# 4. awk 格式输出
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
