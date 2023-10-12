#include <bits/stdc++.h>
using namespace std;

// 12.10.2023
// 1095. Find in Mountain Array
// The main idea is to find such index j, where all elements before j are increasing, and decreasing after.
// After that we will launch binary searches to the both sides of j to find target. 
// If we do not have target in our array, we will return -1. Otherwise, we will return the minimum index among all possible answers.

class Solution {
public:
    int findInMountainArray(int target, MountainArray &a) {
        int len = a.length();
        int l = 1, r = len - 1, j = 0, val = a.get(0);
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = a.get(mid), y = a.get(mid - 1);
            if (x > y) l = mid + 1, val = x, j = mid;
            else r = mid - 1;
        }
        if (val == target) return j;

        l = 0, r = j - 1;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = a.get(mid);
            if (x >= target) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        if (ans != -1 && a.get(ans) == target) return ans;
        ans = -1;
        l = j + 1, r = len - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int x = a.get(mid);
            if (x <= target) r = mid - 1, ans = mid;
            else l = mid + 1; 
        }
        if (ans != -1 && a.get(ans) == target) return ans;
        return -1;
    }
};