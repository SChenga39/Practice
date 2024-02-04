#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* currentNode = head;
        // 用于存放所有节点指针
        unordered_map<Node*, Node*> map;
        // 遍历一遍并创建所有节点, 方便后续遍历
        while (currentNode) {
            Node* tmp = new Node(currentNode->val);
            map[currentNode] = tmp;
            currentNode = currentNode->next;
        }
        currentNode = head;
        while (currentNode) {
            Node* valueCurrent = map[currentNode];
            // 遍历并找出当前节点的 next 指向的节点
            Node* keyNext = currentNode->next;
            Node* valueNext = map[keyNext];
            valueCurrent->next = valueNext;
            // 遍历并找出当前节点的 random 指向的节点
            Node* keyRandom = currentNode->random;
            Node* valueRandom = map[keyRandom];
            valueCurrent->random = valueRandom;
            // 查找下一个节点
            currentNode = currentNode->next;
        }
        // 节点之间通过 map 对应
        // currentNode -> map[currentNode]
        // head -> map[head]
        return map[head];
    }
};
