#include <bits/stdc++.h>
using namespace std;

class Solution {
  int subarraysWithSumK(vector<int> a, int b) {
    // optimal solution
    int xr = 0;
    map<int, int> mpp;
    int cnt = 0;
    mpp[xr]++; // {0, 1}

    for (int i = 0; i < a.size(); i++) {
      xr = xr ^ a[i];
      int x = xr ^ b;
      cnt += mpp[x];
      mpp[xr]++;
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  return 0;
}