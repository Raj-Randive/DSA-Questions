#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n & (n - 1)) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    return 0;
}