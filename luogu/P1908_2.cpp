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
* 思路：树状数组
- 将原数组排序并记录每个元素第一次出现的位置
- 从后往前遍历原数组，遍历一次在计数数组对应位置加一，并其将前面的内容全部相加并添加到结果中
*/
#define lowbit(x) (x & -x)
const int N = 5e5 + 5;
int n, m, a[N], b[N];
int tr[N];
unordered_map<int, int> mp;
void add(int k, int x) {
    for (; k <= n; k += lowbit(k))
        tr[k] += x;
}
int sum(int k) {
    int res = 0;
    for (; k; k -= lowbit(k))
        res += tr[k];
    return res;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b + n);
    m = unique(b, b + n) - b;
    for (int i = 0; i < m; i++)
        mp[b[i]] = i + 1;

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = mp[a[i]];
        res += sum(x - 1);
        add(x, 1);
    }
    cout << res << endl;
}
