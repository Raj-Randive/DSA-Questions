// Type-2 Solution - generating each rows and adding them to the list
#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> generateRows(int rowNumber) {
    long long res = 1;
    vector<int> Row;
    Row.push_back(1);
    for (int col = 1; col < rowNumber; col++) {
      res = res * (rowNumber - col);
      res = res / col;
      Row.push_back(res);
    }
    return Row;
  }

  vector<vector<int>> generate(int N) {
    vector<vector<int>> ans;
    vector<int> Row;
    for (int i = 1; i <= N; i++) {
      Row = generateRows(i);
      ans.push_back(Row);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}