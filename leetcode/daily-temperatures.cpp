#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 构建栈存放每日温度下标
        stack<int> st;
        // 保存输出结果
        vector<int> res(temperatures.size());
        // 从头开始遍历每天的温度
        for (int i = 0, end = temperatures.size(); i < end; ++i) {
            // 当天温度和栈首元素比较, 若栈不为空且当天温度大于栈首元素
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                // 获取栈首元素并移除
                int preIndex = st.top();
                st.pop();
                // 更新结果数组
                res[preIndex] = i - preIndex;
            }
            st.push(i);
        }
        return res;
    }
};
