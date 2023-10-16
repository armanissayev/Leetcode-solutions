#include <bits/stdc++.h>
using namespace std;

// 16.10.2023
// 119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last, cur = {1};
        for (int i = 1; i <= rowIndex; ++ i) {
            last = cur;
            cur.clear();
            cur.push_back(1);
            for (int j = 1; j < last.size(); ++ j) {
                cur.push_back(last[j - 1] + last[j]);
            }
            cur.push_back(1);
        }
        return cur;
    }
};