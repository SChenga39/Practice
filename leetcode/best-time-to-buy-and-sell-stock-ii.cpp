#include <bits/stdc++.h>
using namespace std;

/*
* 思路
只需要关心两天之间股票价格是涨了还是跌了，如果涨了就加差价到结果中，最后将结果返回即可
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1, endi = prices.size(); i < endi; ++i)
            ans += max(0, prices[i] - prices[i - 1]);
        return ans;
    }
};
