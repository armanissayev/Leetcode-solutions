#include <bits/stdc++.h>
using namespace std;

// 05.10.2023
// 229. Majority Element II
// The main idea is to sort the given array, and check for some x, if there is a subarray of length (n / 3) + 1 that contains only numbers x. If yes, we will add x to the answer

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt = nums.size() / 3 + 1;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i + cnt - 1 < nums.size(); ++ i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i + cnt - 1]) ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};