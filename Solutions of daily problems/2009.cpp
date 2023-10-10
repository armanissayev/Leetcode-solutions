#include <bits/stdc++.h>
using namespace std;

// 10.10.2023
// 2009. Minimum number of operations to make array continuous
// The main idea is iterate all possible the least values of continuous array. Answer is maxmimum nums.size() - 1, as we can leave only one number which will be minimum one.
// So, we will try to build array with the minimum x. Let's count the number of variables that lies in range [x, x + nums.size() - 1]. Each variable should be computed only once.
// Take the maximum count among all possible values of x, and subtract it from the length of array. This will be an answer.

class Solution {
public:
    int minOperations(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 1;
        multiset<int>st;
        int j = 0, res = 0;
        for (int i = 0; i < a.size(); ++ i) {
            while (j < a.size() && a[j] < a[i] + a.size()) {
                if (st.find(a[j]) == st.end()) ++ res;
                st.insert(a[j]);
                ++ j;
            }
            ans = max(ans, res);
            st.erase(st.find(a[i]));
            if (st.find(a[i]) == st.end()) -- res;
        }
        return a.size() - ans;
    }
};