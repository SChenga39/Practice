#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 思路
- 使用快慢指针（Floyd 判圈法）
- 给定两个指针 slow 和 fast 置于链表开头
- 每次 fast 前进两步，slow 前进一步，若 fast 可走到尽头则无环路
- 当 slow 和 fast 第一次相遇时将 fast 移动到开头，再让 slow 和 fast 每次前进一步
- 当 slow 和 fast 第二次相遇时相遇的节点即为环路开始点
*/
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        do {
            if (!fast || !fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
