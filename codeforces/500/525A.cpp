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
int res;
int ar[26];
string s;
void solve() {
    cin >> n >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        // Even
        if ((i & 1) == 0) {
            ++ar[s[i] - 'a'];
            continue;
        }

        // Odd
        if (!ar[s[i] - 'A'])
            ++res;
        else
            --ar[s[i] - 'A'];
    }
    cout << res << endl;
}
