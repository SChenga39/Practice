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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

int l, r, a;
inline int f(int x, int a) {
    return x / a + x % a;
}
void solve() {
    cin >> l >> r >> a;
    if (l / a == r / a)
        cout << max(f(l, a), f(r, a)) << endl;
    else
        cout << f((r / a - 1) * a + (a - 1), a) << endl;
}
