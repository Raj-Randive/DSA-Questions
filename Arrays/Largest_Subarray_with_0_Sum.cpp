#include <bits/stdc++.h>
using namespace std;

class Solution {
  int getLongestZeroSumSubarrayLength(vector<int> &arr) {
    // optimal solution
    unordered_map<int, int> mpp;
    int n = arr.size();
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum == 0) {
        maxi = i + 1;
      } else {
        if (mpp.find(sum) != mpp.end()) {
          maxi = max(maxi, i - mpp[sum]);
        } else {
          mpp[sum] = i;
        }
      }
    }
    return maxi;
  }
};

int main() {
  Solution sol;
  return 0;
}