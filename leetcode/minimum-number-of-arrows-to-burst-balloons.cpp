#include <bits/stdc++.h>
using namespace std;

/*
* 思路
可以在每个气球的右边界射箭，先将所有气球位置按右边界排序再在每次射箭的过程中更新右边界的位置
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 按右边界排序
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int current = points[0][1];
        int ans = 1;
        for (const auto& item : points) {
            if (item[0] > current) {
                // 将下一个箭设置在这个被引爆气球的右边界
                current = item[1];
                ++ans;
            }
        }
        return ans;
    }
};
