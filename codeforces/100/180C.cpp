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
 * 从左到右和从右到左分别数每个字母左边的小写字母个数和右边的大写字母个数
 * 找出某个位置的字母使得左边小写字母和右边大写字母总数最小
 */
string s;
int l[100005], r[100005];
void solve() {
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i)
        l[i] = l[i - 1] + ('a' <= s[i - 1] && s[i - 1] <= 'z' ? 1 : 0);

    for (int i = n - 1; i > 0; --i)
        r[i - 1] = r[i] + ('A' <= s[i] && s[i] <= 'Z' ? 1 : 0);

    int res = n;
    for (int i = 0; i < n; ++i)
        res = min(res, l[i] + r[i]);

    cout << res << endl;
}
