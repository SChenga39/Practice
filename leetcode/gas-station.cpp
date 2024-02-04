#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 如果总油量小于总消耗则一定走不完
        int remain = 0;
        for (int i : gas)
            remain += i;
        for (int i : cost)
            remain -= i;
        if (remain < 0) return -1;

        int current = 0, i = 0, idx = 0;
        int gasSize = gas.size();
        while (i < gasSize) {
            current += gas[i] - cost[i];
            if (current >= 0) ++i;
            // 当前油不够, 重新开始计算并更新索引
            else {
                current = 0;
                idx = i + 1;
                ++i;
            }
        }
        return idx;
    }
};
