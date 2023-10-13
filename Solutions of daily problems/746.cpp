#include <bits/stdc++.h>
using namespace std;

// 13.20.2023
// 746. Min Cost Climbing Stairs
// The main idea is to use dynamic programming. Let's say that dp[i] is the minimal to leave the i-th step on staircase. As we can climnb one or two staircases, transitions will be following:
// dp[i - 1] + a[i] -> dp[i]
// dp[i - 2] + a[i] -> dp[i] 

class Solution {
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int>& a) {
        dp[0] = a[0], dp[1] = a[1];
        for (int i = 2; i < a.size(); ++ i)
            dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
        return min(dp[a.size() - 1], dp[a.size() - 2]);
    }
};