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
 * 从 1 遍历到 10e12 会 TLE
 * 考虑从结果本身出发，将一个数重复两遍之后看是否大于 n
 * 如果大于则输出 n-1 即为答案
 */
int n;
void solve() {
    cin >> n;
    int i = 1;
    while (true) {
        if (stoll(to_string(i) + to_string(i)) > n) break;
        ++i;
    }
    cout << i - 1 << endl;
}
