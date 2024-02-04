#include <bits/stdc++.h>
#include <linked_list.h>
using namespace std;

/*
* 思路
- 构造哨兵节点指向原链表头节点
- 设置两个指针，pre 指向哨兵节点，current 指向原链表头部
- 两个指针向前移动直到 pre 指向第一个要反转节点的前面一个节点
- 开始翻转操作
  - 设置临时变量 temp 为 current 的 next，保存当前需要反转节点后面的节点（需要交换 temp 和 current）
  - 让 current 的 next 位置变成 temp 的下一个节点
  - 让 temp 的 next 变成 current
  - 让 pre 的 next 变成 temp
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* guard = new ListNode(-1);
        guard->next = head;
        // 注意 pre 和 current 节点的位置
        ListNode* pre = guard;
        ListNode* current = head;
        // 移动到要翻转链表的起始处
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
            current = current->next;
        }
        for (int i = 0; i < right - left; ++i) {
            // 可画图理解
            ListNode* tmp = current->next;
            current->next = current->next->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return guard->next;
    }
};
