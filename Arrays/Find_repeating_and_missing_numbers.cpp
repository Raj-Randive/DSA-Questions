#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> a) {
    // // Better Approach ****************************
    // int n = a.size();
    // int hash[n+1] = {0};

    // for(int i=0; i<n; i++){
    //     hash[a[i]]++;
    // }
    // int repeating = -1, missing = -1;

    // for(int i=1; i<=n; i++){
    //     if(hash[i] == 2) repeating = i;
    //     else if(hash[i] == 0) missing = i;

    //     if(repeating!=-1 && missing!=-1) break;
    // }

    // return {repeating, missing};

    // // Optimal Approach - 1 ****************************
    // long long n = a.size();
    // // (S-(Sn)) = x - y
    // // (S2-(S2n)) = X^2 - Y^2
    // long long SN = (n*(n+1))/2;
    // long long S2N = (n*(n+1)*(2*n+1))/6;
    // long long S=0, S2=0;

    // for(int i=0; i<n; i++){
    //     S+=a[i];
    //     S2+= (long long)a[i] * (long long)a[i];
    // }
    // long long val1 = S-SN;  // X-Y
    // long long val2 = S2 - S2N;
    // val2 = val2 / val1;  // X+Y

    // long long X = (val1 + val2) / 2;
    // long long Y = val2-X;

    // return {(int)X, (int)Y};

    // Optimal Approach - 2 ****************************
    long long n = a.size();
    int xr = 0;
    for (int i = 0; i < n; i++) {
      xr ^= a[i];
      xr ^= (i + 1);
    }

    // find the bit number
    int bitNo = 0;
    while (1) {
      if ((xr & (1 << bitNo)) != 0) {
        break;
      }
      bitNo++;
    }

    // Putting them into two parts
    int zeroGroup = 0;
    int oneGroup = 0;

    for (int i = 0; i < n; i++) {
      // Part of ones club
      if ((a[i] & (1 << bitNo)) != 0) {
        oneGroup = oneGroup ^ a[i];
      }
      // Part of zero club
      else {
        zeroGroup = zeroGroup ^ a[i];
      }
    }

    for (int i = 1; i <= n; i++) {
      // Part of ones club
      if ((i & (1 << bitNo)) != 0) {
        oneGroup = oneGroup ^ i;
      }
      // Part of zero club
      else {
        zeroGroup = zeroGroup ^ i;
      }
    }

    // final check which is repeating and which is missing
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == zeroGroup)
        cnt++;
    }

    if (cnt == 2)
      return {zeroGroup, oneGroup};

    return {oneGroup, zeroGroup};
  }
};

int main() {
  Solution sol;
  return 0;
}