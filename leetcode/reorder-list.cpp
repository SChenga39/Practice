#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* middle = middleNode(head);
        ListNode *left = head, *right = middle->next;
        middle->next = nullptr;
        // 将右边的链表翻转准备连接
        right = reverseList(right);
        while (left && right) {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;
            left->next = right;
            left = leftNext;
            right->next = left;
            right = rightNext;
        }
    }
    // 通过快慢指针找到链表中点
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 翻转链表
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* current = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return current;
    }
};
