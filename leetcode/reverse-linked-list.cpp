#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 递归
- 通过递归函数⼀直递归到链表的最后⼀个结点为⽌，该结点就是反转成功后的头结点，是最终的返回结果
- 在递归函数中让下一个节点的 next 指向当前节点
- 在递归函数中让当前节点的 next 指向 null
- 将结果返回给上一层递归函数
- 所有递归完成后链表翻转成功
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* current = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return current;
    }
};

/*
* 三指针
- 遍历一次链表，使用三个指针逐步翻转每一个节点
*/
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *current = head, *next;
        while (current) {
            next = current->next;
            current->next = pre;
            pre = current;
            current = next;
        }
        return pre;
    }
};
