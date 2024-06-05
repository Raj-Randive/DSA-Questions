#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // Sieve Of Eratosthenes

        vector<int> prime(n, 1);
        for (int i = 2; i * i < n; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = 0;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    return 0;
}