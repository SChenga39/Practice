#include <bits/stdc++.h>
using namespace std;

// 使用 set 记录已出现元素
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> res;
        for (int i : nums)
            s.insert(i);
        for (int i = 1, endi = nums.size(); i <= endi; ++i)
            if (s.find(i) == s.end()) res.push_back(i);
        return res;
    }
};

// 遍历数组并一每个元素为索引将对应元素置为负
class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 遍历数组并将相应元素置为负数
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            // 将对应位置上的元素置为负数(用绝对值保证是负数)
            nums[idx] = -abs(nums[idx]);
        }
        // 没有被置为负数的位索引即为缺失元素
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};
