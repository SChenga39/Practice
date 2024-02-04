#include <bits/stdc++.h>
using namespace std;

/*
 * 每个元素有三种状态
 * 只有当元素状态改变时摆动数组的长度加一
 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // 三种状态: 初始、正在上升、正在下降
        enum State { INIT, UP, DOWN };
        // 小于两个元素时整个数组均为摆动数组
        if (nums.size() < 2) { return nums.size(); }
        int len = 1;
        int state = INIT;
        // 从第二个元素开始每次判断当前元素和前一个元素的关系
        // 每次均在状态改变时增加 len
        for (int i = 1, end = nums.size(); i < end; ++i) {
            if (state == INIT) {
                if (nums[i] > nums[i - 1]) {
                    state = UP;
                    ++len;
                } else if (nums[i] < nums[i - 1]) {
                    state = DOWN;
                    ++len;
                }
            } else if (state == UP) {
                if (nums[i] < nums[i - 1]) {
                    state = DOWN;
                    ++len;
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    state = UP;
                    ++len;
                }
            }
        }
        return len;
    }
};
