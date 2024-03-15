#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {

    // // Brute force solution ************************
    // int product;
    // vector<int> answer;
    // for(int i=0; i<nums.size(); i++){
    //     product=1;
    //     for(int j=0; j<nums.size(); j++){
    //         if(j!=i){
    //             product = product * nums[j];
    //         }
    //     }
    //     answer.push_back(product);
    // }
    // return answer;

    // // Dividing it by that particular number ************************
    // int n=nums.size();
    // vector<int> answer;
    // int product = 1;
    // for(int x : nums){
    //     product *= x;
    // }

    // for(int i=0; i<n; i++){
    //     int val = product / nums[i];
    //     answer.push_back(val);
    // }
    // return answer;

    // ************************ Optimal Solution ************************
    // int n = nums.size();
    // vector<int> prefix(n, 0);
    // vector<int> suffix(n, 0);
    // prefix[0] = 1;
    // suffix[n-1] = 1;

    // for(int i=1; i<n; i++){
    //     prefix[i] = prefix[i-1] * nums[i-1];
    // }
    // for(int i=n-2; i>=0; i--){
    //     suffix[i] = suffix[i+1] * nums[i+1];
    // }
    // vector<int> answer(n, 0);
    // for(int i=0; i<n; i++){
    //     answer[i] = prefix[i] * suffix[i];
    // }
    // return answer;

    // ************************ Optimal Solution ************************
    // complexity: Time: O(n) Space: O(1)
    int n = nums.size();
    vector<int> answer(n, 1);
    int curr = 1;

    for (int i = 0; i < n; i++) {
      answer[i] *= curr;
      curr *= nums[i];
    }
    curr = 1;
    for (int i = n - 1; i >= 0; i--) {
      answer[i] *= curr;
      curr *= nums[i];
    }
    return answer;
  }
};

int main() {
  Solution sol;
  return 0;
}