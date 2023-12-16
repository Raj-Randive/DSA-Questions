#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isCommonPrefix(vector<string> &v, int len) {
    string s1 = v[0].substr(0, len);
    for (int i = 1; i < v.size(); i++) {
      if (!(v[i].find(s1) == 0)) {
        return false;
      }
    }
    return true;
  }

  string longestCommonPrefix(vector<string> &strs) {
    // ********************** Sorting Technique **********************
    // int n = strs.size();
    // if (n == 0) return "";
    // string common="";
    // sort(strs.begin(), strs.end());

    // string first=strs[0], last=strs[n-1];

    // for(int i=0; i < min(first.size(), last.size()); i++ ){
    //     if(first[i] != last[i]){
    //         return common;
    //     }
    //     common+=first[i];
    // }
    // return common;

    // ********************** Binary Search **********************
    int n = strs.size();
    if (n == 0)
      return "";

    int minLen = INT_MAX;
    for (string s : strs) {
      minLen = min(minLen, int(s.length()));
    }

    int low = 1;
    int high = minLen;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (isCommonPrefix(strs, mid)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return strs[0].substr(0, (low + high) / 2);
  }
};

int main() {
  Solution sol;
  //   vector<string> str = {"flower", "flow", "flight"};
  vector<string> str = {"dog", "racecar", "car"};
  cout << sol.longestCommonPrefix(str);

  return 0;
}