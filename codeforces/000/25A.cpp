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
int ar[105];
int a, t;
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        ar[i] &= 1;
        a += ar[i];
    }
    t = (a == 1);
    for (int i = 0; i < n; ++i) {
        if (ar[i] == t) {
            cout << i + 1 << endl;
            return;
        }
    }
}
