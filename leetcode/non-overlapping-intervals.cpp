#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 选择的区间结尾越小，留给其它区间的空间越大，越能保留更多区间
- 采取的贪心策略为优先保留结尾小且不相交的区间
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int total = 0, prev = intervals[0][1];
        for (int i = 1, end = intervals.size(); i < end; ++i) {
            if (intervals[i][0] < prev)
                ++total;
            else
                prev = intervals[i][1];
        }
        return total;
    }
};
