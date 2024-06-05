#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function for finding XOR from 1 to N
    int XORN(int n) {
        if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n + 1;
        else if (n % 4 == 3) return 0;
        else return n;
    }

    int findXOR(int l, int r) {
        return (XORN(l - 1) ^ XORN(r));
    }
};

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}