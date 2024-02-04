#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 思路
- 设置虚拟节点将虚拟节点和原链表头节点连接
- 从虚拟头节点开始访问
- 只要当前访问节点下一个节点和下下个节点都存在则继续访问
- 访问过程中若下一个节点和下下个节点相同说明这个节点值相同的所有节点都应该被删除
- 删除的方法：先记录这个值，再使用 while 循环不断查找相同的节点值
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* guard = new ListNode(-1);
        guard->next = head;
        ListNode* pre = guard;
        // 统一操作
        while (pre->next && pre->next->next) {
            // 有重复元素
            if (pre->next->val == pre->next->next->val) {
                int value = pre->next->val;
                // 删除所有重复元素所在节点
                while (pre->next && pre->next->val == value) {
                    pre->next = pre->next->next;
                }
            } else {
                pre = pre->next;
            }
        }
        return guard->next;
    }
};
