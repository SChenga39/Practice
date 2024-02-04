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
* 描述
输入待插入节点数和 N 个互不相同的正整数（按顺序插入节点的关键字值）
要求将它们按顺序插入一个初始为空的二叉排序树，每次插入成功后求对应父亲节点关键字值
*/
typedef struct Node {
    int data;
    struct Node *left, *right;
} TreeNode, *Tree;
Tree t;
int n;
int ar[105];
void insert(int i, Tree tree) {
    if (i < tree->data) {
        if (tree->left != nullptr) {
            insert(i, tree->left);
        } else {
            tree->left = new TreeNode;
            tree->left->data = i;
            tree->left->left = nullptr;
            tree->left->right = nullptr;
            cout << tree->data << endl;
            return;
        }
    } else {
        if (tree->right != nullptr) {
            insert(i, tree->right);
        } else {
            tree->right = new TreeNode;
            tree->right->data = i;
            tree->right->left = nullptr;
            tree->right->right = nullptr;
            cout << tree->data << endl;
            return;
        }
    }
}

void solve() {
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        t = new TreeNode;
        t->data = ar[0];
        t->left = nullptr;
        t->right = nullptr;
        cout << -1 << endl;
        for (int i = 1; i < n; ++i) {
            insert(ar[i], t);
        }
    }
}
