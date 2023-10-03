#include <bits/stdc++.h>
using namespace std;

// 02.09.2023
// The main idea is to just count the number of letters 'A' and 'B' that we can delete. After that, if Alcie has more letters to delete, she will win. Otherwise, Bob wins.
class Solution {
public:
    bool winnerOfGame(string colors) {
        int cntA = 0, cntB = 0;
        for (int i = 1; i < colors.size() - 1; ++ i) {
            if (colors[i] == colors[i - 1] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') ++ cntA;
                else ++ cntB;
            }
        }
        if (cntA > cntB) return 1;
        else return 0;
    }
};