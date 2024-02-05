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

int pre[35], in[35], post[35];
struct node {
    int data;
    node *lchild, *rchild;
};
int n;
// 由后序和中序构造二叉树
node* create(int postl, int postr, int inl, int inr) {
    if (postl > postr) return nullptr;
    node* root = new node;
    root->data = post[postr];
    int i = inl;
    while (in[i] != post[postr]) {
        i++;
    }
    int lsize = i - inl;
    root->lchild = create(postl, postl + lsize - 1, inl, i - 1);
    root->rchild = create(postl + lsize, postr - 1, i + 1, inr);
    return root;
}
int num;
// 对二叉树进行层次遍历
void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* now = q.front();
        q.pop();
        cout << now->data << endl;
        ++num;
        if (num < n) cout << " ";
        if (now->lchild) q.push(now->lchild);
        if (now->rchild) q.push(now->rchild);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    node* root = create(0, n - 1, 0, n - 1);
    bfs(root);
}
