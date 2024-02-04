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
* 描述
守形数：它的平方的低位部分等于它本身，判断一个数是否是守形数
*/
void solve() {
    int n;
    while (cin >> n)
        if (n < 10)
            cout << (n * n % 10 == n ? "Yes" : "No") << endl;
        else
            cout << (n * n % 100 == n ? "Yes" : "No") << endl;
}
