#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        std::reverse(s.begin(), s.end());
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] == s[right]) {
                ++left, --right;
            } else {
                return isPalindrome(s.substr(left, right - left + 1))
                       || isPalindrome(s.substr(left + 1, right - left + 1));
            }
        }
        return true;
    }
    static bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) { return false; }
            ++left, --right;
        }
        return true;
    }
};
