#include <bits/stdc++.h>
using namespace std;

/*
 * 注意：mp[0] = 1 表示从头开始的数组，其 mod 为 0
 */
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0;
        int mod;
        for (int i = 0; i < n; ++i) {
            mod = prefix[i] % k;
            if (mod < 0) mod += k;

            if (mp.count(mod)) {
                res += mp[mod];
                ++mp[mod];
            } else {
                mp[mod] = 1;
            }
        }
        return res;
    }
};
