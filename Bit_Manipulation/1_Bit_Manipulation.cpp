
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bitManipulation(int num, int i) {
        // Get the ith Bit
        vector<int> ans;

        if (num & (1 << (i - 1))) ans.push_back(1);
        else ans.push_back(0);

        // Set the ith bit
        int setbitNum = (num | (1 << (i - 1)));
        ans.push_back(setbitNum);

        // Clear the ith bit
        int clearbitNum = (num & ~(1 << (i - 1)));
        ans.push_back(clearbitNum);

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }

    }
};

int main() {
    Solution sol;
    return 0;
}


