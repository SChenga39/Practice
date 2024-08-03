#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // 有障碍物：当前格子路径数量置 0
                    dp[j] = 0;
                } else if (j > 0) {
                    // 从左边的格子变化
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};
