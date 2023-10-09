#include <bits/stdc++.h>
using namespace std;

// 09.10.2023
// 34. Find first and last position of element in sorted array
// The main idea is to implement simple binary search algorithm, to find such indexes. As the array is monotonic, binary search will work

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, i = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
            else {
                i = mid;
                r = mid - 1;
            }
        }
        l = 0, r = nums.size() - 1;
        int j = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > target) r = mid - 1;
            else if (nums[mid] < target) l = mid + 1;
            else {
                j = mid;
                l = mid + 1;
            }
        }
        vector <int> ans;
        ans.push_back(i);
        ans.push_back(j);
        return ans;
    }
};