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
 * 直接将 a 和 b 从 1 到 1000 遍历，找是否有满足 4ab + 3a + 3b 的 a 和 b
 */
int ar[100000];
int n, tmp, ans, ptr, res;
int a = 1, b = 1;
void solve() {
    cin >> n;
    // 打表
    while (a <= 1000) {
        while ((ans = (4 * a * b + 3 * a + 3 * b)) <= 1000) {
            ar[ptr++] = ans;
            ++b;
        }
        ++a;
        b = a;
    }
    sort(ar, ar + ptr);
    // query
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (!binary_search(ar, ar + ptr, tmp)) ++res;
    }
    cout << res << endl;
}
