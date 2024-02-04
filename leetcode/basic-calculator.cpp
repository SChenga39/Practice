#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 对于一个表达式，可分为左表达式、运算符、右表达式三部分
- 左右表达式可以是数字也可以是表达式
- 对于只含加减和括号的表达式，从左往右计算，遇到括号就先算括号里的
* 步骤
- 使用栈存储字符串表达式中的数字，设置变量 res 保存计算结果
- 一开始可认为 res=0 作为左表达式，同时当前运算符为 +，然后遍历字符数组，寻找右表达式
- 获取字符串中每个字符
- 若当前字符是数字则查看当前字符后一位是否存在，若后一位仍然是数字则继续累加
- 一旦确定数字就可以进行运算 res = res + sign * value
- 若遇到运算符则将所有操作视为加法操作
- 若遇到 ( 则先计算括号内的数字直到遇到 )
- 若遇到 ) 则将栈中存放的元素取出
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1;
        int res = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                int value = c - '0';
                while (i + 1 < len && isdigit(s[i + 1])) {
                    ++i;
                    value = value * 10 + s[i] - '0';
                }
                res = res + sign * value;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
            } else if (c == ')') {
                int formerSign = st.top();
                st.pop();
                int formerRes = st.top();
                st.pop();
                res = formerRes + formerSign * res;
            }
        }
        return res;
    }
};
