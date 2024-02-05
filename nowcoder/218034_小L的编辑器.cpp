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
使用两个字符串分别存储中心位置的前后缀，再将后缀翻转，拼接得到结果
*/
string ar, at;
string post, pre;  // 前缀和后缀字符串
void solve() {
    cin >> ar >> at;
    int len = ar.size();
    for (int i = 0; i < len; ++i) {
        if (at[i] == 'L')
            post += ar[i];
        else
            pre += ar[i];
    }
    reverse(post.begin(), post.end());
    cout << pre << post;
}
