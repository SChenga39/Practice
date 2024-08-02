#include <bits/stdc++.h>
using namespace std;

/*
 * 先计算前缀和，然后将当前位置的前缀和存入 map
 * 遍历数组的同时查找 map，看前面是否有「前缀和」和「当前位置前缀和」之和等于 k
 * 如果有，则加上前面「前缀和」的数量 mp[prefix[i]-k]
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (prefix[i] == k) ++res;
            if (mp.count(prefix[i] - k)) res += mp[prefix[i] - k];
            ++mp[prefix[i]];
        }
        return res;
    }
};
