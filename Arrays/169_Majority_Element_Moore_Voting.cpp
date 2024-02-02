#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int majorityElement(vector<int> &a) {

    // Moore's Voting Algorithm
    int cnt = 0;
    int element;
    for (int i = 0; i < a.size(); i++) {
      if (cnt == 0) {
        cnt = 1;
        element = a[i];
      } else if (a[i] == element) {
        cnt++;
      } else {
        cnt--;
      }
    }
    // verify if it is greater than n/2 or not
    int cnt1 = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == element)
        cnt1++;
    }
    if (cnt1 > a.size() / 2)
      return element;
    return -1;
  }
};

int main() {
  Solution sol;
  return 0;
}