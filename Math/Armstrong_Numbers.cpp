#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string armstrongNumber(int n) {

        // Concept - Digits Extraction

        int sum = 0;
        int original = n;
        while (n) {
            int ld = n % 10;
            sum += (ld * ld * ld);
            n /= 10;
        }
        if (original == sum) return "Yes";
        else return "No";

    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}