#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {

    // Optimal Solution
    int n = arr.size();
    int m = queries.size();
    vector<int> prefixXor;
    vector<int> answer;
    prefixXor.push_back(arr[0]);
    int xr = arr[0];
    for (int i = 1; i < n; i++) {
      xr = xr ^ arr[i];
      prefixXor.push_back(xr);
    }
    for (int i = 0; i < m; i++) {
      if (queries[i][0] == 0) {
        answer.push_back(prefixXor[queries[i][1]]);
      } else {
        answer.push_back(
            (prefixXor[queries[i][1]] ^ prefixXor[queries[i][0] - 1]));
      }
    }
    return answer;
  }
};

int main() {
  Solution sol;
  return 0;
}