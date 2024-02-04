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
使用并查集，将属于相同组的合并（相互之间属于亲戚），在查询时直接看两人是不是属于同一组
*/
int fa[5005];
int n, m, p, tmp1, tmp2;
int findf(int x) {
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}
void mergef(int x, int y) {
    int fx = findf(x), fy = findf(y);
    if (fx != fy) fa[fx] = fy;
}
void solve() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        cin >> tmp1 >> tmp2;
        mergef(tmp1, tmp2);
    }
    for (int i = 1; i <= p; ++i) {
        cin >> tmp1 >> tmp2;
        if (findf(tmp1) == findf(tmp2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
