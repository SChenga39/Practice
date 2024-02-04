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
使用递归的方法，在 dfs 函数中指定四个参数
分别表示剩下还有多少数需要选、截至目前的总和、接下来需要在数组中搜索的起止索引
*/
// 使用 ans 记录最终所有结果
int n, k, ar[25], ans = 0;
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 6 != 1 && num % 6 != 5) return false;
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0) return false;
    return true;
}
void dfs(int numberToChoose, int nowSum, int from) {
    // 如果选完了就判断和是否为质数并返回
    if (!numberToChoose && isPrime(nowSum)) {
        ++ans;
        return;
    }
    for (int i = from; i < n; ++i) {
        // 调整状态: 选过的数 + 1, 和也加上目前要选的数
        dfs(numberToChoose - 1, nowSum + ar[i], i + 1);
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    dfs(k, 0, 0);
    cout << ans << endl;
}
