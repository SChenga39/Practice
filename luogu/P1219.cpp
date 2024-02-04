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
- 用整个棋盘可能的状态当作搜索树上的节点
- dfs 的每一层枚举当前棋盘这一行的每一列，看是否能在某一列放棋子；在该行放下棋子后再向下一行搜索
- 用三个数组存储列、左斜线、右斜线的占用情况
*/
// 用三个数组代表线是否被占用
// a 为纵向, b 为斜向 左下, c 为斜向右下
int n, loc[20], a[20], b[20], c[40], ans = 0;
// 打印当前状态下数组情况
void print() {
    for (int i = 1; i <= n; ++i)
        cout << loc[i] << " ";
    cout << endl;
}
// x 代表当前搜索的是哪一行
void dfs(int x) {
    if (x > n) {
        ++ans;
        if (ans > 3) return;
        print();
        return;
    }
    for (int i = 1; i <= n; ++i)
        if (!a[i] && !b[i + x] && !c[x - i + n - 1]) {
            // 做出更改
            loc[x] = i;
            a[i] = 1, b[i + x] = 1, c[x - i + n - 1] = 1;
            // 继续搜索
            dfs(x + 1);
            // 撤销更改
            a[i] = 0, b[i + x] = 0, c[x - i + n - 1] = 0;
        }
}
void solve() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
}
