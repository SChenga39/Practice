#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 设置 index 表示 popped 数组下标，判断该索引指向的元素是否能正常出栈
- 遍历 pushed 数组每个元素，遍历时把当前遍历的元素加入栈中
- 执行以下判断
  - 栈中是否有元素
  - 栈顶元素是否和 popped 当前下标元素相同
- 若同时满足两条件则可在栈上执行 pop 操作
- 遍历完后若栈不为空则出栈序列不合法，否则合法
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int index = 0;
        stack<int> s;
        for (int i : pushed) {
            s.push(i);
            while (!s.empty() && s.top() == popped[index]) {
                s.pop();
                ++index;
            }
        }
        return s.empty();
    }
};
