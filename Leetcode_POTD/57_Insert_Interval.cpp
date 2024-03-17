#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    // int n=intervals.size();
    // vector<vector<int>> arr;
    // arr.push_back(newInterval);
    // for(int i=0; i<n; i++){
    //     arr.push_back({intervals[i][0], intervals[i][1]});
    // }
    // sort(arr.begin(), arr.end());
    // // for(int i=0; i<arr.size(); i++){
    // //     cout << arr[i][0] << " " << arr[i][1] << "\n";
    // // }

    // vector<vector<int>> ans;
    // for(int i=0; i<arr.size(); i++){
    //     int start = arr[i][0];
    //     int end = arr[i][1];

    //     if(!ans.empty()  &&  end <= ans.back()[1] ){
    //         continue;
    //     }

    //     for(int j=i+1; j<arr.size(); j++){
    //         if(arr[j][0] <= end){
    //             end = max(end, arr[j][1]);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }
    // return ans;

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;

    // No Overlaps
    while (i < n && intervals[i][1] < newInterval[0]) {
      ans.push_back(intervals[i]);
      i++;
    }

    // Overlapping case
    while (i < n && newInterval[1] >= intervals[i][0]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    ans.push_back(newInterval);

    // newInterval merged  --> after effects
    while (i < n) {
      ans.push_back(intervals[i]);
      i++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  return 0;
}