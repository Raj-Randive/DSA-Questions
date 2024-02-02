#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void sortColors(vector<int> &a) {
    // Optimal Solution : Dutch National Flag Algorithm
    int low = 0, mid = 0, high = a.size() - 1;
    while (mid <= high) {
      if (a[mid] == 0) {
        swap(a[low++], a[mid++]);
      } else if (a[mid] == 1) {
        mid++;
      } else if (a[mid] == 2) {
        swap(a[mid], a[high--]);
      }
    }
  }
};

int main() {
  Solution sol;
  return 0;
}