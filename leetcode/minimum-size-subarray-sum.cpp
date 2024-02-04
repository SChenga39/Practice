#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 初始化滑动窗口，左边界为 0，不断寻找右边界的位置
- 计算滑动窗口中所有元素和直到大于 target
- 大于 target 后不断右移左边界直到区间元素和小于 target
- 返回值可以被初始化为 INF，可用于判断是否被更新，若没有则表示没有满足条件的子数组，需要返回 0
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int INF = 0x3F3F3F3F;
        // 初始化左边界和区间元素和
        int left = 0, sum = 0;
        // 初始化区间
        int result = INF;
        // 不断移动右边界
        for (int right = 0; right < nums.size(); ++right) {
            // 更新区间元素和
            sum += nums[right];
            // 右移左边界寻找最小区间长度
            while (sum >= target) {
                result = min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        // 判断 result 是否被更新过, 若没有则返回 0
        return result == INF ? 0 : result;
    }
};
