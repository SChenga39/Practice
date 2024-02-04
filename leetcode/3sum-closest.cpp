#include <bits/stdc++.h>
using namespace std;

/*
 * 先将数组进⾏排序操作，从⼩到⼤
 * 开始遍历整个数组，在遍历过程中观察设置的三个位置的元素之后的⼤⼩
 * num[i] 为从左到右观察过去的元素
 * left 为从 i 到 len - 1 的元素，right 为从 len - 1 向左移动到 i 的元素
 * 在移动过程中，计算三者和
 * 将计算的结果和 ans 进⾏⽐较，寻找出更接近于 target 的那个和
 * 如果三者之和⼩于 target ，那么说明需要找更⼤的数
 * 如果三者之和⼤于 target ，那么说明需要找更⼩的数
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 初始化结果
        int ans = nums[0] + nums[1] + nums[2];
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // 更新结果
                if (abs(target - sum) < abs(target - ans)) ans = sum;
                if (sum < target)
                    ++left;
                else if (sum > target)
                    --right;
                // 只有一组结果, 找到了就直接返回
                else
                    return ans;
            }
        }
        return ans;
    }
};
