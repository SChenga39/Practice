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
 * 由于直接使用内置函数会有精度损失的问题，必须手动模拟
 */
int ans;
int n;
void solve() {
    cin >> n;
    // 注意必须是 1LL
    while ((1LL << ans) <= n)
        ++ans;
    cout << ans - 1 << endl;
}
