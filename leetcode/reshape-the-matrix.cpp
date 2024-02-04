#include <bits/stdc++.h>
using namespace std;

/*
 * 创建一个二维数组作为结果，然后以元素个数 i 为索引
 * 分别用 i / column 和 i % column
 * 获取修改之前行和列的索引并写入新的二维数组中即可
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n) return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; ++i)
            res[i / c][i % c] = mat[i / n][i % n];
        return res;
    }
};
