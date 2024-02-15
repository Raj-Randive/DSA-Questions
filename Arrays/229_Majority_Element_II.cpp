#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int el1, el2;
    int min = nums.size() / 3 + 1;
    for (int i = 0; i < nums.size(); i++) {
      if (cnt1 == 0 && nums[i] != el2) {
        cnt1 = 1;
        el1 = nums[i];
      } else if (cnt2 == 0 && nums[i] != el1) {
        cnt2 = 1;
        el2 = nums[i];
      } else if (el1 == nums[i])
        cnt1++;
      else if (el2 == nums[i])
        cnt2++;
      else {
        cnt1--;
        cnt2--;
      }
    }

    // Manual Checking for el1 and el2;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == el1)
        cnt1++;
      else if (nums[i] == el2)
        cnt2++;
    }
    if (cnt1 >= min)
      ans.push_back(el1);
    if (cnt2 >= min)
      ans.push_back(el2);
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}