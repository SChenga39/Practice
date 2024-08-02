#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = nums.size(), mod = 0;
        for (int i = 0; i < n; ++i) {
            mod = (mod + nums[i]) % k;
            // 又得到了 mod，说明这一段前缀和之差正好被 k 整除
            if (mp.count(mod)) {
                // 注意：需要保证数组长度不小于 2
                if (i - mp[mod] >= 2) return true;
            } else {
                // 记录得到当前 mod 时所在的位置
                mp[mod] = i;
            }
        }
        return false;
    }
};
