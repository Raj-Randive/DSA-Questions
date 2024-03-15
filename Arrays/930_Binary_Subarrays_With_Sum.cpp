#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
  int slidingWindowAtMost(vector<int> &nums, int goal) {
    int start = 0, currentSum = 0, totalCount = 0;

    // Iterate through the array using a sliding window approach
    for (int i = 0; i < nums.size(); i++) {
      currentSum += nums[i];

      // adjusting the windows size
      while (start <= i && currentSum > goal) {
        currentSum = currentSum - nums[start];
        start++;
      }

      totalCount = totalCount + (i - start + 1);
    }
    return totalCount;
  }

  int numSubarraysWithSum(vector<int> &nums, int goal) {
    // // Optimal Approach - Prefix Sum concept
    // map<int, int> mp;
    // mp[0] = 1;
    // int cnt=0, preSum=0;
    // for(int i=0; i<nums.size(); i++){
    //     preSum +=nums[i];
    //     int remove = preSum - goal;
    //     cnt += mp[remove];
    //     mp[preSum]+=1;
    // }
    // return cnt;

    // Sliding Window Approach
    return (slidingWindowAtMost(nums, goal) -
            slidingWindowAtMost(nums, goal - 1));
  }
};

int main() {
  Solution sol;
  return 0;
}