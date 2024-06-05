#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        // Maths Concept - Digits Extraction
        // Don't use long or long long

        int ans = 0;
        while (x) {
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            else {
                ans = ans * 10 + x % 10;
                x = x / 10;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}