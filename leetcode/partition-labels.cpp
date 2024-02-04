#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 先遍历数组获取每一个元素最后一次出现的位置
- 再使用贪心判断如果当前元素是这个字母最后一次出现那么划分一个区间并开始下一个区间
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        vector<int> ans;
        // 找出所有元素最后一次出现的位置
        for (int i = 0, endi = s.size(); i < endi; ++i) {
            last[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0, endi = s.size(); i < endi; ++i) {
            // 更新 end 为区间字母最后一次出现的位置
            end = max(end, last[s[i] - 'a']);
            if (end == i) {
                ans.emplace_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
