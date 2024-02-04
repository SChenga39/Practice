#include <bits/stdc++.h>
using namespace std;

/*
 * 一个凹槽由三根柱子围成
 * 一旦新添加的主子高度大于栈顶元素则有可能形成凹槽
 * 新添加的柱子高度小于栈顶元素则必然无法和当前栈中元素构成凹槽
 * 如果新添加的柱子高度等于栈顶元素也无法构成凹槽，将当前柱子加入栈中等待接下来的柱子
 * 计算完一个凹槽面积后将栈顶元素弹出，观察剩下栈中元素是否能和新添加的元素构成一个新的凹槽
 */
class Solution {
public:
    int trap(vector<int>& height) {
        // 小于两个柱子时不会形成坑
        if (height.size() <= 2) return 0;
        // st 存储下标
        stack<int> st;
        int ans = 0;
        for (int i = 0, end = height.size(); i < end; ++i) {
            // 栈为空直接加入栈中
            if (st.empty()) {
                st.push(i);
            }
            // 元素小于或等于栈顶元素则无法形成凹槽
            else if (height[i] <= height[st.top()]) {
                st.push(i);
            }
            // 元素大于栈顶元素, 可能形成凹槽
            else {
                // 移除栈顶后剩余元素也可能和该元素形成凹槽, 因此 while
                while (!st.empty() && height[i] > height[st.top()]) {
                    // 获取栈顶下标, bottom 为凹槽底部
                    int bottom = st.top();
                    st.pop();
                    // 栈顶元素出栈后栈不为空说明凹槽左侧存在
                    if (!st.empty()) {
                        // 凹槽左侧高度和右侧高度取小再减底部高度即为凹槽高度
                        int h = min(height[st.top()], height[i]) - height[bottom];
                        // 宽度为当前下标减去左侧下标加一
                        int w = i - st.top() - 1;
                        ans += h * w;
                    }
                }
                st.push(i);
            }
        }
        return ans;
    }
};
