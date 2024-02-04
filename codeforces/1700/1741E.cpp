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
 * 表示序列数目的数不确定是在序列的左边还是右边，因此使用动态规划
 * 将所有可能作为序列首位的值在遍历的过程中置为 1 即可
 */

int n;
int ar[200005];
int dp[200005];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> ar[i];
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i + ar[i] <= n && dp[i - 1]) dp[i + ar[i]] = 1;
        if (i - ar[i] - 1 >= 0 && dp[i - ar[i] - 1]) dp[i] = 1;
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
}
