#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 设置哨兵节点方便操作
        ListNode* guard = new ListNode(-1);
        guard->next = head;
        ListNode *pre = guard, *end = guard;
        // 不断找到翻转链表的尾部
        while (end->next) {
            // k 个一组寻找 next 指针, 注意需要确保 end 不为空
            for (int i = 0; i < k && end; ++i) {
                end = end->next;
            }
            // 如果寻找的过程中出现 end 为空说明节点数不足 k
            // 此时保持原来的顺序即可
            if (!end) { break; }
            // next: 待翻转链表区域的第一个节点
            ListNode* next = end->next;
            // 尾部节点先断开
            end->next = nullptr;
            // start: 已翻转链表区域的第一个节点
            ListNode* start = pre->next;
            // pre 指向原链表的最后一个节点, 通过递归获得
            pre->next = nullptr;
            pre->next = reverse(start);
            // 已翻转链表区域尾节点的 next 指向待翻转链表第一个节点
            start->next = next;
            // pre: 每次要翻转的链表头节点的上一个节点
            pre = start;
            // end: 待翻转链表区域头节点的上一个节点
            end = start;
        }
        return guard->next;
    }

    ListNode* reverse(ListNode* head) {
        // 递归终止条件: head 为空或 head 的下一个为空
        if (!head || !head->next) return head;
        // 递归调用直到无法递归
        ListNode* current = reverse(head->next);
        head->next->next = head;
        // 防止出现无尽循环
        head->next = nullptr;
        return current;
    }
};
