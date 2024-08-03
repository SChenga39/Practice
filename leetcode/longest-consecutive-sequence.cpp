#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);

        int x, res = 0;
        for (int num : st) {
            if (!st.count(num - 1)) {
                x = num + 1;
                while (st.count(x)) {
                    ++x;
                }
                res = x - num > res ? x - num : res;
            }
        }
        return res;
    }
};
