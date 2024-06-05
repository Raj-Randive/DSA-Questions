#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print_divisors(int n) {

        vector<int> ans;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);
                if ((n / i) != i) ans.push_back(n / i);
            }
        }
        sort(ans.begin(), ans.end());
        for (auto x : ans) {
            cout << x << " ";
        }
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}