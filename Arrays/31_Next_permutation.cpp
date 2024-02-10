#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &a) {
    // C++ STL
    // next_permutation(nums.begin(), nums.end());

    // C++ STL Implementation
    int ind = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] < a[i + 1]) {
        ind = i;
        break;
      }
    }
    // If the permutation given was the last.
    if (ind == -1) {
      reverse(a.begin(), a.end());
      return;
    }

    // Find the first greater element from the back.
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > a[ind]) {
        swap(a[i], a[ind]);
        break;
      }
    }
    // Now reverse the remaining part so to make the number smaller.
    reverse(a.begin() + ind + 1, a.end());
  }
};