#include <bits/stdc++.h>
using namespace std;

// 07.10.2023
// 1420. Build array where you can find the maximum Exactly K comparisons
// The main idea is to use dynamic programming. Let's say that dp[i][j][x] - stores the number of arrays of length i, where we made exactly j comparisons, and the maximum of this array is equal to x.
// Transitions will look like this:
// *for all 1 <= y <= x, dp[i - 1][j][x] -> dp[i][j][x]
// *for all x + 1 <= y <= m, dp[i - 1][j - 1][x] -> dp[i][j][y]
// At the end, we will sum up all possible cases and return it as answer.

class Solution {
public:
    int dp[55][55][105], mod = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        for (int i = 1; i <= m; ++ i) dp[1][1][i] = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 1; j <= min(k, i); ++ j) {
                for (int x = 1; x <= m; ++ x) {
                    for (int y = 1; y <= x; ++ y) {
                        (dp[i][j][x] += dp[i - 1][j][x]) %= mod;
                    }
                    if (j > 0) {
                        for (int y = x + 1; y <= m; ++ y) {
                            (dp[i][j][y] += dp[i - 1][j - 1][x]) %= mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++ i) (ans += dp[n][k][i]) %= mod;
        return ans;
    }
};