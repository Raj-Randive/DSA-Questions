

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // // global variable
  // int cnt=0;

  int merge(vector<int> &arr, int low, int mid, int high) {

    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // storing elements in temp array in sorted manner
    int cnt = 0;
    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      }

      // Right is Smaller
      else {
        temp.push_back(arr[right]);
        cnt += (mid - left + 1);
        right++;
      }
    }

    // if elements on the left half are still left
    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }

    // if elements on the right half are still left
    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    // transfering all elements from temporary to arr
    for (int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
    }
    return cnt;
  }

  int mergeSort(vector<int> &arr, int low, int high) {

    int cnt = 0;

    if (low >= high)
      return cnt;

    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);

    return cnt;
  }

  int numberOfInversions(vector<int> &a, int n) {

    return mergeSort(a, 0, n - 1);
  }
};

int main() {
  Solution sol;
  return 0;
}