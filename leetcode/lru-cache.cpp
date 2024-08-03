#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> l;

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        // 将 list 中 it 所指的 pair 移到 list 开头
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // 将 list 中 it 所指的 pair 移到 list 开头
            l.splice(l.begin(), l, it->second);
            // 更新其值
            it->second->second = value;
            return;
        }
        if (mp.size() == capacity) {
            int key_to_delete = l.back().first;
            l.pop_back();
            mp.erase(key_to_delete);
        }
        l.emplace_front(key, value);
        mp[key] = l.begin();
    }
};
