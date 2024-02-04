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
可以考虑记忆化搜索，使用二维数组存放点每一道菜后剩余的钱数，再结合 dfs 搜索解题
*/
int n, m, ans;
int val[105];       // 每道菜的价格
int f[105][10005];  // 记忆化搜索数组
// cur 表示当前的是第几道菜, left 表示剩余的钱数
int dfs(int cur, int left) {
    if (f[cur][left])  // 查表, 如果存在数组则直接返回
        return f[cur][left];
    if (val[cur] > left) return 0;   // 不能完成, 返回 0 不计数
    if (val[cur] == left) return 1;  // 钱正好够用, 返回 1 使计数+1
    // 以上条件均不满足则继续搜索
    for (int i = cur + 1; i < n; ++i)
        f[cur][left] += dfs(i, left - val[cur]);
    return f[cur][left];
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    for (int i = 0; i < n; ++i)
        ans += dfs(i, m);
    cout << ans << endl;
}
