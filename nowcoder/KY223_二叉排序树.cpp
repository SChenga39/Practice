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
 * 考查二叉树的创建和三种遍历方式
 */
typedef struct Node {
    int value;
    struct Node *l, *r;
    explicit Node(int value) : value(value), l(nullptr), r(nullptr) {}
} Node, *Tree;
Tree insert(Tree t, int a) {
    if (!t)
        t = new Node(a);
    else if (a < t->value)
        t->l = insert(t->l, a);
    else if (a > t->value)
        t->r = insert(t->r, a);
    return t;
}
void preorder(Tree t) {
    if (!t) return;

    cout << t->value << ' ';
    preorder(t->l);
    preorder(t->r);
}
void inorder(Tree t) {
    if (!t) return;

    inorder(t->l);
    cout << t->value << ' ';
    inorder(t->r);
}
void postorder(Tree t) {
    if (!t) return;

    postorder(t->l);
    postorder(t->r);
    cout << t->value << ' ';
}
int n;
int ar[105];
void solve() {
    while (cin >> n) {
        Tree t = nullptr;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            t = insert(t, ar[i]);
        }
        preorder(t);
        cout << endl;
        inorder(t);
        cout << endl;
        postorder(t);
        cout << endl;
    }
}
