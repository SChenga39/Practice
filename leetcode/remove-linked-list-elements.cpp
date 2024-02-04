#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 思路
移除的可能是头节点或其它节点，为统一操作，可设置哨兵节点，其 next 指向 head，使移除节点的操作统一
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 边界判断
        if (!head) return nullptr;
        // 设置哨兵节点, 其值可以是任意的
        ListNode* guard = new ListNode(114514);
        guard->next = head;
        ListNode* pre = guard;
        ListNode* current = head;
        while (current) {
            if (current->val == val) {
                pre->next = current->next;
            } else {
                pre = current;
            }
            current = current->next;
        }
        return guard->next;
    }
};
