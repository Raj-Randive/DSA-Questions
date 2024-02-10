#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // Optimal Solution : Kadane's Algorithm
    // Also store the indexes of the subarray, so that we can return the
    // subarray.

    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    int start = -1;
    for (int i = 0; i < nums.size(); i++) {

      if (sum == 0)
        start = i;
      sum += nums[i];
      if (sum > maxi) {
        maxi = sum;
        ansStart = start;
        ansEnd = i;
      }
      if (sum < 0)
        sum = 0;
    }
    // cout << ansStart << " " << ansEnd << "\n";
    return maxi;
  }
};