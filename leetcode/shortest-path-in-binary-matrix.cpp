#include <bits/stdc++.h>
using namespace std;

/*
 * 使用 bfs 解决，注意边界条件
 */
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dx{-1, 0, 0, 1, -1, 1, 1, -1};
        vector<int> dy{0, -1, 1, 0, -1, 1, -1, 1};

        if (grid[0][0] || grid[m - 1][n - 1]) return -1;

        int res = 0;
        vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        v[0][0] = true;

        while (!q.empty()) {
            int t = q.size();
            ++res;
            for (int i = 0; i < t; ++i) {
                auto [a, b] = q.front();
                q.pop();

                if (a == m - 1 && b == n - 1) return res;

                for (int j = 0; j < 8; ++j) {
                    if (0 <= a + dx[j] && a + dx[j] < m && 0 <= b + dy[j] && b + dy[j] < n
                        && !v[a + dx[j]][b + dy[j]] && !grid[a + dx[j]][b + dy[j]]) {
                        q.push({a + dx[j], b + dy[j]});
                        v[a + dx[j]][b + dy[j]] = 1;
                    }
                }
            }
        }

        return -1;
    }
};
