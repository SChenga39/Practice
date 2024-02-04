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
vector<int> ab, ba;
void solve() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B') ab.push_back(i);
        if (s[i] == 'B' && s[i + 1] == 'A') ba.push_back(i);
    }
    if (ab.empty() || ba.empty()) {
        cout << "NO" << endl;
        return;
    }
    for (int i : ab) {
        for (int j : ba) {
            if (i == j + 1 || i == j - 1) {
                continue;
            } else {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
