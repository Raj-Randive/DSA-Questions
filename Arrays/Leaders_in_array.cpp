#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a) {
  // Optimal Solution

  int n = a.size();
  vector<int> ans;
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > maxi) {
      maxi = a[i];
      ans.push_back(a[i]);
    }
  }
  return ans;
}