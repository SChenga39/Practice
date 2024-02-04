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
int n;
int ar[100005];
int q;
int t;
int res;
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    sort(ar, ar + n);

    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t;

        res = upper_bound(ar, ar + n, t) - ar;
        if (t == ar[res]) ++res;
        cout << res << endl;
    }
}
