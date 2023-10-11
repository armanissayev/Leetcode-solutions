#include <bits/stdc++.h>
using namespace std;

// 11.10.2023
// 2251. Number of Flowers in Full Bloom
// The main idea is to compress all possible positions of flowers, as we do not need such positions, that people will not visit. After that, we will implement the scanline method.
// Scanline is used to update the range of array in offline mode. After that, we will have access to the number of flowers at specific time. Time complexity is O(nlogn) because of compression.

class Solution {
public:
    int pr[200004];
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> v;
        for (auto f : flowers) {
            int l = f[0], r = f[1];
            v.push_back(l); v.push_back(r);
        }
        for (auto x : people) v.push_back(x);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for (auto f : flowers) {
            int l = f[0], r = f[1];
            l = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
            r = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;
            ++ pr[l];
            -- pr[r + 1];
        }
        for (int i = 1; i <= v.size(); ++ i) pr[i] += pr[i - 1];
        vector<int> ans;
        for (auto x : people) {
            x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
            ans.push_back(pr[x]);
        }
        return ans;
    }
};