#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
 * 把两个链表从原链表中找出来
 * 设置两个指针 odd 和 even 均指向链表头节点
 * 设置 evenHead 指向偶节点的头节点
 * 让奇节点尾的 next 指向 evenHead
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        // 获取初始奇节点和偶节点
        ListNode *odd = head, *even = head->next;
        // 提前记录偶节点的头, 准备后续连接
        ListNode* evenHead = even;
        // 以偶节点作为结束标志
        while (even && even->next) {
            // 第一个节点的下一个是第三个节点
            odd->next = even->next;
            // 第一个节点后移到第三个节点
            odd = odd->next;
            // 第二个节点的下一个是第四个节点
            even->next = odd->next;
            // 第二个节点后移到第四个节点
            even = even->next;
        }
        // 连接奇节点和偶节点
        odd->next = evenHead;
        return head;
    }
};
