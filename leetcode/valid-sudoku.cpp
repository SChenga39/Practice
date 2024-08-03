#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        string s;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                s = board[i][j];
                if (s != "."
                    && (!st.insert(s + " in row " + to_string(i)).second
                        || !st.insert(s + " in column " + to_string(j)).second
                        || !st.insert(s + " in block " + to_string(i / 3) + "-" + to_string(j / 3))
                                .second)) {
                    return false;
                }
            }
        }
        return true;
    }
};

