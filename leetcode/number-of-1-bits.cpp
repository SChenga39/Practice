#include <bits/stdc++.h>
using namespace std;

// JDK 代码
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = n - ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0f0f0f0f;
        n = n + (n >> 8);
        n = n + (n >> 16);
        return n & 0x3f;
    }
};

// 将 1 不断左移并不断取与
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i)
            if (n & (1 << i)) ++res;
        return res;
    }
};
