#include <bits/stdc++.h>
using namespace std;

/*
 * 分为窗口未填满和填满之后分别处理
 * 优化思路：以 O(1) 时间复杂度取得窗口中的最大值（使用双端队列）
 * 使用双端队列，其队首始终是最大值，即维护一个递减队列保存队列中递减的元素
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        // 边界判断
        if (!nums.size() || !k) { return res; }
        deque<int> deq;
        // 窗口未填满时
        for (int i = 0; i < k; ++i) {
            // 确保队首是窗口中的最大值
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
        }
        // 队列中刚好有 k 个元素组成了滑动窗口, 将队首元素加入到答案中
        res.push_back(deq.front());
        // 继续判断剩下元素
        for (int i = k; i < nums.size(); ++i) {
            // 移除最前端不属于当前窗口的元素(窗口向后移)
            if (deq.front() == nums[i - k]) { deq.pop_front(); }
            // 把双端队列中小于第 i 个位置的元素全部移除
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            // 将第 i 个位置的元素入队
            deq.push_back(nums[i]);
            res.push_back(deq.front());
        }
        return res;
    }
};
