#include <bits/stdc++.h>
using namespace std;

// 04.10.2023
// 706. Design HashMap
// The main idea is to use simple set structure. However, I think it is not an original solution. If you know how to solve it without set, please contact me.

class MyHashMap {
public:
    set<pair<int, int>> st;    
    MyHashMap() {
    }
    
    void put(int key, int value) {
        auto it = st.lower_bound({key, 0});
        if (it == st.end() || it->first > key) st.insert({key, value});
        else {
            st.erase(it);
            st.insert({key, value});
        }
    }
    
    int get(int key) {
        auto it = st.lower_bound({key, 0});
        if (it == st.end() || it->first > key) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        auto it = st.lower_bound({key, 0});
        if (it == st.end() || it->first > key) return;
        st.erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */