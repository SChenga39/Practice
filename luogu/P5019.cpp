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
* 思路
直接输入，当且仅当后一个输入大于前一个输入时需要多填 $\Delta$ 次土来使深坑填满
*/
int n, a;
int sum, l;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (a > l) sum += (a - l);
        l = a;
    }
    cout << sum << endl;
}
