#include <bits/stdc++.h>
using namespace std;

class Solution {
  //   vector<vector<int>> triplet(int n, vector<int> &arr) {
  //     // Better solution
  //     set<vector<int>> st;

  //     for (int i = 0; i < n; i++) {
  //       set<int> hashset;
  //       for (int j = i + 1; j < n; j++) {
  //         int third = -(arr[i] + arr[j]);
  //         if (hashset.find(third) != hashset.end()) {
  //           vector<int> temp = {arr[i], arr[j], third};
  //           sort(temp.begin(), temp.end());
  //           st.insert(temp);
  //         }
  //         hashset.insert(arr[j]);
  //       }
  //     }
  //     vector<vector<int>> ans(st.begin(), st.end());
  //     return ans;
  //   }
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j++;
        } else if (sum > 0) {
          k--;
        } else {
          vector<int> temp = {nums[i], nums[j],
                              nums[k]}; // already in sorted order
          ans.push_back(temp);
          j++;
          k--;
          // keep them moving until they are not equal to the previous element.
          while (j < k && nums[j] == nums[j - 1])
            j++;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}