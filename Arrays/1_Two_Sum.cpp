#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &a, int target) {
    // Better Solution
    map<int, int> hashMap;
    for (int i = 0; i < a.size(); i++) {
      int x = a[i];
      int y = target - a[i];
      if (hashMap.find(y) != hashMap.end()) {
        return {i, hashMap[y]};
      } else {
        hashMap[x] = i;
      }
    }
    return {-1, -1};
  }
};

int main() {
  Solution s;
  return 0;
}