#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void swapIfGreater(vector<int> &nums1, vector<int> &nums2, int ind1,
                     int ind2) {

    if (nums1.size() == 0 || nums2.size() == 0)
      return;

    if (nums1[ind1] > nums2[ind2]) {
      swap(nums1[ind1], nums2[ind2]);
    }
  }

  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // // Optimal Solution - 1
    // // Two pointer approach

    // int left=m-1;
    // int right=0;

    // while(left>=0 && right<n){
    //     if(nums1[left] >= nums2[right]) {
    //         swap(nums1[left], nums2[right]);
    //         left--, right++;
    //     }
    //     else{
    //         break;
    //     }
    // }

    // sort(nums1.begin(), nums1.begin()+m);
    // sort(nums2.begin(), nums2.end());
    // for(int i=m; i<m+n; i++){
    //     nums1[i]=nums2[i-m];
    // }

    // Optimal Solution - 2
    // Gap Method - Inspired from shell sort
    int len = m + n;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
      int left = 0;
      int right = left + gap;

      while (right < len) {
        // In array1 and array2
        if (left < m && right >= m) {
          swapIfGreater(nums1, nums2, left, right - m);
        }
        // In array2 and array2
        else if (left >= m) {
          swapIfGreater(nums2, nums2, left - m, right - m);
        }
        // In array1 and array1
        else {
          swapIfGreater(nums1, nums1, left, right);
        }
        left++, right++;
      }
      if (gap == 1)
        break;
      gap = (gap / 2) + (gap % 2);
    }
    for (int i = m; i < len; i++) {
      nums1[i] = nums2[i - m];
    }
  }
};

int main() {
  Solution sol;
  return 0;
}