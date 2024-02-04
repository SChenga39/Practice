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
维护两个数组，分别表示最近的两个最大的数，每次判断是否要更换，然后判断要更换的是哪个数组中的数
*/
int ar[4][5];
// a: 最大, b: 第二大
int a[5], b[5];
void solve() {
    for (auto& i : ar)
        for (auto& j : i)
            cin >> j;
    for (int i = 0; i < 5; ++i)
        a[i] = ar[0][i], b[i] = ar[1][i];

    for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            // 需要替换的情况
            if (ar[i][j] > a[j] || ar[i][j] > b[j]) {
                // 判断要换的是 a 还是 b
                if (a[j] > b[j]) {
                    // 换掉 b
                    b[j] = ar[i][j];
                } else {
                    // 换掉 a
                    int t = b[j];
                    b[j] = ar[i][j];
                    a[j] = t;
                }
            }
        }
    }
    for (long long i : a)
        cout << i << ' ';
    cout << endl;
    for (long long i : b)
        cout << i << ' ';
    cout << endl;
}
