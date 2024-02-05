#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const long long INFLL = 0x3F3F3F3F3F3F3F3F;
#define endl '\n'
#define int long long

void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}

/*
https://ac.nowcoder.com/acm/problem/201612

* 思路
字符串子序列问题
*/
char cur, str[9] = "iloveyou";
int res[9] = {1};
void solve() {
    while (cin >> cur)
        for (int i = 0; i < 8; i++)
            if (cur == str[i] - 32 || cur == str[i]) res[i + 1] = (res[i + 1] + res[i]) % 20010905;
    cout << res[8] << endl;
}
