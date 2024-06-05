#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long lcm;
        long long gcd = 1;

        // GCD
        int x = A;
        int y = B;
        while (x > 0 && y > 0) {
            if (x > y) x = x % y;
            else y = y % x;
        }
        if (x == 0) gcd = y;
        else gcd = x;

        // LCM
        long long num = A * B;
        lcm = num / gcd;

        return { lcm, gcd };
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A, B;

        cin >> A >> B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}