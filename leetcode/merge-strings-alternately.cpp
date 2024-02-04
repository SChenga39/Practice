#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 使用双指针分别指向两个字符串
- 在 while 循环中插入时判断是否越界即可
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        int i = 0, j = 0;
        string ans;
        ans.reserve(len1 + len2);
        while (i < len1 || j < len2) {
            if (i < len1) { ans.push_back(word1[i++]); }
            if (j < len2) { ans.push_back(word2[j++]); }
        }
        return ans;
    }
};
