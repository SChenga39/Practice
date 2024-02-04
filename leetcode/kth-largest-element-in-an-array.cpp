#include <bits/stdc++.h>
using namespace std;

/*
* 思路
- 维护一个有 K 个元素的最小堆（优先队列）
- 遍历数组，在遍历过程中对每个访问元素作如下判断
  - 优先队列⾥⾯的元素个数达到了 k 个，且当前访问的元素⼩于了优先队列中的最⼩值（即队头元素）
  - 说明当前访问的元素没有资格加⼊到优先队列中，那么继续访问下⼀个元素
  - 否则，将元素插⼊队列，在优先队列内部会进⾏排序操作，使得优先级队列的头是队列中最⼩的元素
  - 插⼊成功之后，如果个数超过了 k，那么需要把最⼩的元素移除
- 遍历结束之后，minHeap 存储了数组的前 k 个最⼤的元素
- 第 k ⼤的元素就是优先队列 minHeap 中的最⼩值
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 队列头是最小的元素, 元素按升序从队列移除
        priority_queue<int, vector<int>, greater<>> pq;
        for (int& num : nums) {
            // 元素值过小且优先队列已满
            if (pq.size() == k && num <= pq.top()) { continue; }
            pq.push(num);
            // 优先队列已满, 将最小元素出队
            if (pq.size() > k) { pq.pop(); }
        }
        return pq.top();
    }
};
