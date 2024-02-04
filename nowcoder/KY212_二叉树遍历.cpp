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
https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce

* 思路
- 根据前序序列找到根节点位置
- 在中序序列中找到根节点位置
- 根据根据中序序列根节点位置将前序序列和中序序列分成两部分
- 按照左右根（后序遍历）的方式遍历序列
*/
void post_order(const string& pre, const string& mid) {
    if (!pre.size()) return;

    // 从前序序列中确定根节点
    char root = pre[0];
    // 从中序序列中找出根节点位置
    int root_index = mid.find(root);
    // 根据根节点序列将前序遍历和中序遍历序列分成两部分
    string left_pre = pre.substr(1, root_index);
    string right_pre = pre.substr(root_index + 1);
    string left_mid = mid.substr(0, root_index);
    string right_mid = mid.substr(root_index + 1);
    // 后序遍历: 左右根
    post_order(left_pre, left_mid);
    post_order(right_pre, right_mid);
    cout << root;
}
void solve() {
    string pre, mid;
    while (cin >> pre >> mid) {
        post_order(pre, mid);
        cout << endl;
    }
}
