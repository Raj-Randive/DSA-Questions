#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // Optimal Solution --> SC - O(1)

    // int col[m] = {0}; --> matrix[0][..]
    // int row[n] = {0}; --> matrix[..][0]
    int col0 = 1;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          // Mark i-th row
          matrix[i][0] = 0;
          // Mark j-th col
          if (j != 0) {
            matrix[0][j] = 0;
          } else {
            col0 = 0;
          }
        }
      }
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {

        if (matrix[i][j] != 0) {
          if (matrix[i][0] == 0 || matrix[0][j] == 0) {
            matrix[i][j] = 0;
          }
        }
      }
    }

    if (matrix[0][0] == 0) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[0][j] = 0;
      }
    }

    if (col0 == 0) {
      for (int i = 0; i < matrix.size(); i++) {
        matrix[i][0] = 0;
      }
    }
  }
};