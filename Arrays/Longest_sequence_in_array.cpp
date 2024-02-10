#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int> &a) {

  // Better Solution - by Sorting (TC: O(NlogN))
  // int n = a.size();
  // if(n==0) return 0;
  // int longest = 1, cntCurr=0, lastSmaller = INT_MIN;

  // sort(a.begin(), a.end());

  // for(int i=0; i<n; i++){
  //     if(a[i]-1 == lastSmaller){
  //         cntCurr+=1;
  //         lastSmaller = a[i];
  //     }
  //     else if(a[i] != lastSmaller){
  //         cntCurr=1;
  //         lastSmaller = a[i];
  //     }
  //     longest = max(longest, cntCurr);
  // }
  // return longest;

  // Optimal Solution - using Set data structure
  int n = a.size();
  if (n == 0)
    return 0;
  int longest = 1;
  unordered_set<int> st;

  for (int i = 0; i < n; i++) {
    st.insert(a[i]);
  }
  for (auto it : st) {
    if (st.find(it - 1) == st.end()) {
      int cnt = 1;
      int x = it;
      while (st.find(x + 1) != st.end()) {
        x += 1;
        cnt += 1;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}