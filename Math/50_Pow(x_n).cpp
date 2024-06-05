#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // TLE

        // double ans=1;
        // long long m = abs(n);
        // for(long long i=1; i<=m; i++){
        //     ans = ans*x;
        // }
        // if(n<0) return 1.0/ans;
        // return ans;

        int m = n;
        double ans = 1;
        n = abs(n);
        while (n > 0) {
            if (n % 2 == 1) {
                ans = ans * x;
                n -= 1;
            }
            else {
                n /= 2;
                x = x * x;
            }
        }
        if (m < 0) ans = 1.0 / ans;
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}