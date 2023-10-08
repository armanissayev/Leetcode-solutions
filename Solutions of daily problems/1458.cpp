#include <bits/stdc++.h>
using namespace std;

// 08.10.2023
// 1458. Max Dot Product of Two Subsequences
// The main idea is to use dynamic programming. Let's say that dp[i][j] - stores the maximum dot product of a subsequences that ends at 'i' in the first array, and 'j' in the second array.
// There will be 3 transitions:
// 1. We have already taken 'j', so 'i' does not change - dp[i - 1][j]
// 2. We have already taken 'i', si 'j' does not change - dp[i][j - 1]
// 3. We will take both 'i' and 'j', and compute the new value - max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]
// Among all these transitions, we will store only the greatest one.

class Solution {
public:
    int dp[505][505];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j <= m; ++ j) dp[i][j] = -1e9;
        }
        for (int i = 1; i <= n; ++ i) {
            for (int j = m; j >= 1; -- j) {
                dp[i][j] = max(dp[i - 1][j], max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]);
            }
            for (int j = 1; j <= m; ++ j) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};