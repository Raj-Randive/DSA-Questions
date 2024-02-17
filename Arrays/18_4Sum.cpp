#include <bits/stdc++.h>
using namespace std;

class Solution {
  //   vector<vector<int>> fourSum(vector<int> &nums, int target) {
  // // brute force
  // int n = nums.size();
  // set<vector<int>> st;

  // for(int i=0; i<n; i++){
  //     for(int j=i+1; j<n; j++){
  //         for(int k=j+1; k<n; k++){
  //             for(int l=k+1; l<n; l++){
  //                 long long sum = nums[i] + nums[j];
  //                 sum += nums[k];
  //                 sum += nums[l];
  //                 if(sum == target){
  //                     vector<int> temp = {nums[i], nums[j], nums[k],
  //                     nums[l]}; sort(temp.begin(), temp.end());
  //                     st.insert(temp);
  //                 }
  //             }
  //         }
  //     }
  // }

  // vector<vector<int>> ans(st.begin(), st.end());
  // return ans;

  // better solution
  //     int n = nums.size();
  //     set<vector<int>> st;

  //     for (int i = 0; i < n; i++) {
  //       for (int j = i + 1; j < n; j++) {
  //         set<long long> hashset;
  //         for (int k = j + 1; k < n; k++) {
  //           long long sum = nums[i] + nums[j];
  //           sum += nums[k];
  //           long long fourth = target - sum;
  //           if (hashset.find(fourth) != hashset.end()) {
  //             vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
  //             sort(temp.begin(), temp.end());
  //             st.insert(temp);
  //           }
  //           hashset.insert(nums[k]);
  //         }
  //       }
  //     }

  //     vector<vector<int>> ans(st.begin(), st.end());
  //     return ans;
  //   }

  vector<vector<int>> fourSum(vector<int> &a, int target) {
    // Optimal solution
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      if (i > 0 && a[i] == a[i - 1])
        continue;

      for (int j = i + 1; j < n; j++) {
        if (j != i + 1 && a[j] == a[j - 1])
          continue;

        int k = j + 1;
        int l = n - 1;
        while (k < l) {
          long long sum = a[i] + a[j];
          sum += a[k];
          sum += a[l];
          if (sum == target) {
            vector<int> temp = {a[i], a[j], a[k], a[l]};
            ans.push_back(temp);
            k++;
            l--;
            // make sure k and l are not pointing to the duplicate elements
            while (k < l && a[k] == a[k - 1])
              k++;
            while (k < l && a[l] == a[l + 1])
              l--;
          } else if (sum < target)
            k++;
          else
            l--;
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