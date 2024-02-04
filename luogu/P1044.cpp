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
dfs 中的变量有两个：栈中的元素个数和操作数序列中的元素个数
将这两个变量传入 dfs 函数中进行递归求解
*/
int n;
int f[20][20];
// 分别表示操作队列和栈中的数据
int dfs(int inQueue, int inStack) {
    // 记忆化搜索: 查表
    if (f[inQueue][inStack]) return f[inQueue][inStack];
    // 操作队列中没有数的话剩下的结果只有一种可能
    if (inQueue == 0) return 1;
    // 栈中不为空时将一个元素出栈后继续搜索
    if (inStack > 0) f[inQueue][inStack] += dfs(inQueue, inStack - 1);
    // 将操作队列中的一个数加入栈中继续搜索
    f[inQueue][inStack] += dfs(inQueue - 1, inStack + 1);
    return f[inQueue][inStack];
}
void solve() {
    cin >> n;
    cout << dfs(n, 0) << endl;
}
