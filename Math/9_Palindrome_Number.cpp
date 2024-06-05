#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long rev = 0;
        int original = x;
        while (x) {
            int lastdigit = x % 10;
            rev = rev * 10 + lastdigit;
            x /= 10;
        }
        if (rev == original) return true;
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}