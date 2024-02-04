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
int n, q, d;
const int range = 1000005;
bool prime[range];
void init() {
    // value=1: not prime
    prime[0] = prime[1] = true;
    for (int i = 2; i * i < range; ++i)
        if (!prime[i])
            for (int j = i * i; j < range; j += i)
                prime[j] = true;
}
void solve() {
    init();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        d = sqrt(q);
        cout << (!prime[d] && d * d == q ? "YES" : "NO") << endl;
    }
}
