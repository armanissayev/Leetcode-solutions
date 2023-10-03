#include <bits/stdc++.h>
using namespace std;

// 03.10.2023
// The main idea is to count the number of occurrence of a[i] that comes before i, and sum up these values. 

class Solution {
public:
    int cnt[105];
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        for (auto x : nums) {
            ans += cnt[x];
            ++ cnt[x];
        }
        return ans;
    }
};