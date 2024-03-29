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
 * 选取一个数之后周围的两个数都不能选了，因此是跳着选
 * 可以跳一个或者跳两个（不可能是跳三个，那样不如跳两个大）
 */
int n;
int t;
int max_;
int freq[100005];
int dp[100005];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        max_ = max(max_, t);
        ++freq[t];
    }

    dp[1] = freq[1];
    for (int i = 2; i <= max_; ++i) {
        dp[i] = max(dp[i - 2] + freq[i] * i, dp[i - 1]);
    }
    cout << dp[max_] << endl;
}
