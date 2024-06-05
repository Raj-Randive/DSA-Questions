#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {

    // Solution using bit manipulation
    vector<vector<int>> ans;
    int n = nums.size();
    int subsets = 1 << n; // Total subsets - 2^n

    for (int i = 0; i < subsets; i++) {
      vector<int> temp;
      for (int j = 0; j < n; j++) {
        // check if the bit is set or not
        if (i & (1 << j)) {
          temp.push_back(nums[j]);
        }
      }
      ans.push_back(temp);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}
