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
 * 若 a 是质数，则 a 和其他数的 lcm 为其乘积
 * a 是合数，那么 a 和其约数的 lcm 为 a
 */
int n, ans;
void solve() {
    cin >> n;
    ans = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (!(n % i)) { ans = max(ans, n / i); }
    }
    cout << ans << ' ' << n - ans << endl;
}
