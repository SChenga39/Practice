#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 要让剩下的数字尽量小则需要保证靠前的数字尽可能小
- 正在访问的元素是否删除依赖下一个元素是否大于它
- 使用栈数据结构
* 步骤
- 初始化栈，用于存储需要保留的数字
- 在遍历数组过程中对于每个访问到的元素都判断栈是否为空
- 若栈不为空且栈顶元素大于此时遍历的字符且还没有删除足够多的数字，则之前存放到栈的数字需要被抛弃
- 删除栈顶元素后重复执行第三步
- 重复执行 2、3、4
- 如果还没有删除足够多的元素则继续移除栈顶元素
- 将栈结果导出到字符串并翻转后返回
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans;
        for (char digit : num) {
            // 栈不为空、栈顶元素大于此时遍历的元素、没有删除足够的数字则需要将栈顶元素弹出
            while (!st.empty() && st.top() > digit && k > 0) {
                st.pop();
                --k;
            }
            // 如果当前字符为 0 且栈为空则不把 0 放进栈, 避免数字以 0 开头
            if (digit == '0' && st.empty()) continue;
            // 剩余符合要求的数字放入栈中
            st.push(digit);
        }
        // 遍历完所有字符后未删除足够数字则需要继续删除栈顶元素(个位)
        while (!st.empty() && k > 0) {
            st.pop();
            --k;
        }
        // 操作完毕若栈为空则返回字符 0
        if (st.empty()) return "0";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
