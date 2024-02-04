#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
 * 首先通过快慢指针找到链表中心点（让 fast 每次移动两布，slow 每次移动一步）
 * 翻转 slow 右边的链表
 * 获取左右区域反转后的头节点
 * 让 left 和 right 同时向后移动，在此过程中判断每个节点是否相同
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 边界判断: 链表为空或小于三个节点
        if (!head || !head->next) return true;
        if (!head->next->next) return head->val == head->next->val;
        // 快慢指针寻找链表中点
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 翻转右区域指针, 准备比较两链表
        ListNode* right = reverse(slow->next);
        ListNode* left = head;
        while (right) {
            if (left->val != right->val) { return false; }
            right = right->next;
            left = left->next;
        }
        return true;
    }

    // 翻转函数
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* current = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return current;
    }
};
