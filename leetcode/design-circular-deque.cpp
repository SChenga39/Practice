#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 涉及下标减操作均需加容量再取模防止下标为负
- 涉及下标加操作均需加容量再取模防止下标越界
*/
class MyCircularDeque {
private:
    // capacity 为数组容量, 其大小为 k + 1
    // front 和 rear 分别为队头和队尾指针
    int capacity, front, rear;
    vector<int> arr;

public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        arr = vector<int>(capacity);
        front = rear = 0;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        // 防止为负
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        return true;
    }
    bool insertLast(int value) {
        if (isFull()) return false;
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        // 防止为负
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int getRear() {
        if (isEmpty()) return -1;
        // 防止为负
        return arr[(rear - 1 + capacity) % capacity];
    }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear + 1) % capacity == front; }
};
