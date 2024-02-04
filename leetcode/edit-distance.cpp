#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 双向 BFS
- dp：开二维数组, dp[i][j] 表示 word1.substr(0, i) 与 word2.substr(0, j) 之间的编辑距离
  - 递推方程
    - $dp[i][j]=\begin{cases}dp[i-1][j-1],& w1[i]=w2[i]\\
       min(dp[i-1][j-1]+1,dp[i-1,j]+1,dp[i,j-1]+1), & w1[i]\neq w2[i]\end{cases}$
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
        }
        return dp[m][n];
    }
};
