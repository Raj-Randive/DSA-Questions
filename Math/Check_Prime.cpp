#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int isPrime(int N) {

        // Optimised Code. TC : O(Sqrt(N))
        int cnt = 0;
        for (int i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                cnt++;
                if ((N / i) != i) cnt++;
            }
        }
        if (cnt == 2) return true;
        return false;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0;
}