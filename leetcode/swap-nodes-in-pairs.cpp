#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 思路
- 将给定的链表中相邻节点两两交换后返回，返回的是交换完成的链表头节点
- 建议使用递归写法
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 终止条件判断
        if (!head || !head->next) return head;
        // 递归调用
        ListNode* sub = swapPairs(head->next->next);
        // 对于 head 来说, 与它交换的是它右边的节点
        // 先保存节点
        ListNode* headNext = head->next;
        // 改变 headNext 的指向
        headNext->next = head;
        // headNext 原来指向 sub , 现在让 head 指向 sub
        head->next = sub;
        // 交换后原来第二位的节点 headNext 变成了第一位, 直接返回
        return headNext;
    }
};
