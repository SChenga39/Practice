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
 * 利用前缀和的思想，依次找到两个数组相异元素个数
 */
int n, q;
int l, r;
int res;
string a, b;
void solve() {
    cin >> n >> q >> a >> b;

    vector<vector<int>> v;
    vector<int> cnt(26, 0);

    v.push_back(cnt);

    for (int i = 0; i < n; ++i) {
        ++cnt[a[i] - 'a'];
        --cnt[b[i] - 'a'];
        v.push_back(cnt);
    }

    while (q--) {
        cin >> l >> r;
        res = 0;
        for (int i = 0; i < 26; ++i) {
            res += abs(v[l - 1][i] - v[r][i]);
        }
        cout << (res >> 1) << endl;
    }
}
