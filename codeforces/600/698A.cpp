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

// 使用 dp 求解，虽然题目要求最小休息天数，但 dp 只能求最大值，因此使用正向求解
int dp[105][3];
int ar[105];
int n;
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }

    // 要使自己的工作天数最大化, 则休息天数最小
    if (ar[0] & 1) ++dp[0][1];
    if (ar[0] & 2) ++dp[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
        if (ar[i] & 1) ++dp[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        if (ar[i] & 2) ++dp[i][2];
    }
    cout << n - max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
}
