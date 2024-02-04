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
 * dp，不能连续选同一个，但是可以不选
 */
int dp[100005][3];
int ar[2][100005];
int n;
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ar[0][i];
    for (int i = 0; i < n; ++i)
        cin >> ar[1][i];

    dp[0][0] = 0;
    dp[0][1] = ar[0][0];
    dp[0][2] = ar[1][0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + ar[0][i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + ar[1][i];
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}
