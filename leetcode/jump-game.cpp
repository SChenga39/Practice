#include <bits/stdc++.h>
using namespace std;

/*
 * 设置数组 jump 保存在每个位置出发时一次性最远可到达的位置
 * 如果在一个位置 i 的 jump[i] 大于最大可到达下标则更新 maxJump
 * 循环结束后如果 index 大于数组大小则说明可到达最后一个下标
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 记录每个点可以到达的最远下标
        int jump[nums.size()];
        for (int i = 0, end = nums.size(); i < end; ++i) {
            jump[i] = i + nums[i];
        }
        int index = 0, maxJump = jump[0];
        while (index <= maxJump && index < nums.size()) {
            // 更新能达到的最远下标
            if (maxJump < jump[index]) { maxJump = jump[index]; }
            ++index;
        }
        // 如果能达到数组末尾则返回 true
        if (index > nums.size() - 1) { return true; }
        return false;
    }
};
