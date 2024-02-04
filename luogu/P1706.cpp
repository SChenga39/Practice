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
本题可用 dfs 或 next_permutation 解决
*/
int src[1005], out[1005], n;
int flag[1005];  // flag 用于判断是否用过这个数
void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; ++i)
            cout << "    " << out[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
        if (!flag[i]) {       // 如果当前的数没有用过
            flag[i] = 1;      // 标记当前的数为用过
            out[x] = src[i];  // 填入要输出数组
            dfs(x + 1);       // 填下一个
            flag[i] = 0;      // 回溯
        }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        src[i] = i + 1;
    // 从第 0 格开始搜
    dfs(0);
}
