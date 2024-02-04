#include <bits/stdc++.h>
using namespace std;

// 散列，插入同时检查是否有匹配元素
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            int pairNumber = target - nums[i];
            auto it = map.find(pairNumber);
            if (it != map.end()) {
                return {map[pairNumber], i};
            } else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};

// pair 排序
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        pair<int, int> p[size];
        for (int i = 0; i < size; ++i) {
            p[i] = {i, nums[i]};
        }

        sort(p, p + size, [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second;
        });

        int l = 0, r = size - 1;
        while (l < r) {
            if (p[l].second + p[r].second < target) {
                ++l;
            } else if (p[l].second + p[r].second > target) {
                --r;
            } else {
                return {p[l].first, p[r].first};
            }
        }
        return {};
    }
};
