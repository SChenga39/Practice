#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        for (int i = 0, end = nums.size(); i < end; i++) {
            curr += nums[i];
            if (curr == sum) return i;
            sum -= nums[i];
        }
        return -1;
    }
};
