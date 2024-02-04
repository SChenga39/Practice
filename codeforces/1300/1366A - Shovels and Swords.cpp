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
int t;
int a, b;
int m, n;
int res;
void solve() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        if (a >= b + b || b >= a + a) {
            cout << min(a, b) << endl;
        } else {
            m = min(a, b), n = max(a, b);
            res = (n - m);
            m -= res;
            n -= 2 * res;
            res += m / 3.0 * 2;
            cout << res << endl;
        }
    }
}
