#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        // Bit Manipulation Approach

        // Step-1
        int ans = start ^ goal;
        // Step-2
        int cnt = 0;
        while (ans > 0) {
            cnt += ans & 1;
            ans >>= 1;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    return 0;
}