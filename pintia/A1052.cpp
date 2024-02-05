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
https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464

* 思路
- 建立结构体数组表示链表，按从首地址开始的顺序遍历链表
- 在链表中的结点 flag 为 true 并统计有效节点个数 valid（有的节点不在链表中）
- 将链表排序，若节点不在链表中则排在最后面，最后只输出 valid 个节点
*/
struct Node {
    int address, next, key;
    char flag;
} ar[100005];
int n, valid;
int head;
int address, key, nextAddress;
void solve() {
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &address, &key, &nextAddress);
        ar[address] = {address, nextAddress, key, false};
    }
    for (int i = head; i != -1; i = ar[i].next) {
        ar[i].flag = true;
        ++valid;
    }
    if (!valid) {
        puts("0 -1");
    } else {
        // 此处必须指定排序到 100000, 因为用到了后面的空间
        sort(ar, ar + 100000, [](const Node& a, const Node& b) {
            return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
        });
        printf("%d %05d\n", valid, ar[0].address);
        for (int i = 0; i < valid; ++i) {
            printf("%05d %d ", ar[i].address, ar[i].key);
            if (i != valid - 1) {
                printf("%05d\n", ar[i + 1].address);
            } else {
                puts("-1");
            }
        }
    }
}
