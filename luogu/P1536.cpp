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
将所有联通的城镇分为一组，最后的答案为总组数减一
*/
// fa[] 数组为并查集数组
int fa[1005], cnt = 0, flag[1005], n, m, x, y;
// 在集合中查找元素
int findf(int x) {
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}
// 合并联通的元素
void mergef(int x, int y) {
    int fx = findf(x), fy = findf(y);
    if (fx != fy) fa[fx] = fy;
}
void solve() {
    while (cin >> n) {
        if (!n) break;
        memset(flag, 0, sizeof(flag));
        cin >> m;
        cnt = 0;
        // 初始化 fa[] 数组
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        // 遍历每一条路, 将联通的村落放在一组
        for (int i = 1; i <= m; ++i) {
            cin >> x >> y;
            mergef(x, y);
        }
        // 遍历 flag 数组查找有多少组
        for (int i = 1; i <= n; ++i)
            if (!flag[findf(i)]) flag[findf(i)] = 1, ++cnt;
        // 打印输出结果
        cout << cnt - 1 << endl;
    }
}
