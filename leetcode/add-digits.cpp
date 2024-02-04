#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addDigits(int num) { return (num - 1) % 9 + 1; }
};

class Solution2 {
public:
    int addDigits(int num) {
        if (num) return num % 9 ? num % 9 : 9;
        return 0;
    }
};
