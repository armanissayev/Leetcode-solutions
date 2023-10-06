#include <bits/stdc++.h>
using namespace std;

// 06.10.2023
// 343. Integer break
// The main idea is that it is awlays optimal to break a number into almost equal numbers. So, we will iterate over the number of parts that we will break, and compute the product of such break.

class Solution {
public:
    int integerBreak(int n) {
        int mx = 0;
        for (int k = 2; k <= n; ++ k) {
            int x = n / k, y = n / k + 1;
            int cnt1 = k - (n % k), cnt2 = n % k;
            int ans = 1;
            for (int i = 1; i <= cnt1; ++ i) ans *= x;
            for (int i = 1; i <= cnt2; ++ i) ans *= y;
            mx = max(mx, ans);
        }
        return mx;
    }
};