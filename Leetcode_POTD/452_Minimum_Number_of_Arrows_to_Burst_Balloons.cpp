#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    // Similar to overlapping concept
    // Sort according to the second index i.e endIndex.
    int cnt = 0, n = points.size(), endIndex = 0;
    sort(points.begin(), points.end(), cmp);

    // for(int i=0; i<n; i++){
    //     cout<<points[i][0] << " " << points[i][1] << "\n";
    // }

    for (int i = 0; i < points.size(); i++) {
      if (cnt == 0 || (points[i][0] > endIndex)) {
        cnt++;
        endIndex = points[i][1];
      }
    }
    return cnt;
  }
};

int main() {
  Solution sol;
  return 0;
}