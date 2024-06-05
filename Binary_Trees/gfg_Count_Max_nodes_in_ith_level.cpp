#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNodes(int level) {
        int maxi = 0;
        maxi = 1 << (level - 1);
        return maxi;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}