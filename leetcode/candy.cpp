#include <bits/stdc++.h>
using namespace std;

/*
* 思路
每次只考虑一个孩子和单侧孩子糖果关系，遍历两次并更新每个孩子获得的糖果数，最后求和获取结果
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 3) return ans;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            // i 及右边的数之和不可能等于零, 开始下一次循环
            if (nums[i] > 0) break;
            // 去重操作
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // 找到和为 0 的三个数
                if (!sum) {
                    vector<int> v = {nums[i], nums[left], nums[right]};
                    ans.emplace_back(v);
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    // 移动到下一个不相同的数
                    ++left, --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
