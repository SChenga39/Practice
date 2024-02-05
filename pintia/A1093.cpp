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
https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805373582557184

* 思路
对于每一个字符 A，只需要计算其左边出现的 P 和右边出现的 T 个数之积然后累加即可
*/
#define MOD 1000000007
#define N 100005
char str[N];
int leftP[N];
int len, ans, rightT;
void solve() {
    cin >> str;
    len = strlen(str);
    for (int i = 0; i < len; ++i) {
        // 避免索引超出范围
        if (i > 0) leftP[i] = leftP[i - 1];
        // 前面多了一个 P 字符
        if (str[i] == 'P') ++leftP[i];
    }
    // 从后往前遍历
    for (int i = len - 1; i >= 0; --i) {
        if (str[i] == 'T')
            ++rightT;
        else if (str[i] == 'A')
            ans = (ans + leftP[i] * rightT) % MOD;
    }
    cout << ans << endl;
}
