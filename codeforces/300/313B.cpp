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

string s;
int dp[100005];
int n, t, l, r;
void solve() {
    cin >> s;
    n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == s[i]) ++t;
        dp[i] = t;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        cout << dp[r - 1] - dp[l - 1] << endl;
    }
}
