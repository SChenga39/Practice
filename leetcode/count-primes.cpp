#include <bits/stdc++.h>
using namespace std;

/*
 * 埃筛法
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n);
        // 0 表示是素数, 1 表示不是素数
        for (int i = 2; i * i < n; ++i)
            if (!isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = 1;
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (!isPrime[i]) ++ans;
        return ans;
    }
};
