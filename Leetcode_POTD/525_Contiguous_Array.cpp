#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    // int currSum=0, maxLength=0;
    // int n = nums.size();
    // unordered_map<int, int> mpp;
    // mpp[0] = -1;

    // for(int i=0; i<nums.size(); i++){
    //     currSum += nums[i] == 1 ? 1 : -1;

    //     if( mpp.count(currSum) ){
    //         maxLength = max( maxLength,  i-mpp[currSum]);
    //     }
    //     else{
    //         mpp[currSum] = i;
    //     }
    // }
    // return maxLength;

    int sum = 0;
    unordered_map<int, int> mpp;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {

      sum += (nums[i] == 1) ? 1 : -1;
      auto itr = mpp.find(sum);

      if (sum == 0) {
        if (maxLength < i + 1) {
          maxLength = i + 1;
        }
      } else if (itr != mpp.end()) {
        if (maxLength < i - itr->second) {
          maxLength = i - itr->second;
        }
      } else if (itr == mpp.end()) {
        mpp.insert({sum, i});
      }
    }
    return maxLength;
  }
};

int main() {
  Solution sol;
  return 0;
}