#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
 * 首先遍历链表求链表长度 len
 * k 可先对 len 取模以节省移动操作
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        // 计算链表长度
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            ++len;
        }
        k %= len;
        // 用 p 指向旋转后的头节点
        ListNode *p = head, *q = head;
        for (int i = 0; i < k; ++i) {
            p = p->next;
        }
        // 继续移位直到 p 到达原链表末尾
        // 此时 q 到达 旋转后链表的最后一个元素
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        // 连接原链表末尾和开头的节点
        p->next = head;
        // 记录新的头节点后删除末尾节点的 next
        ListNode* newHead = q->next;
        q->next = nullptr;
        return newHead;
    }
};
