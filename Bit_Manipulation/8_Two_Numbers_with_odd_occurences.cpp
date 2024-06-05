#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        // Using Bit Manipulation
        // Bucket Concept
        long XORR = 0;
        for (int i = 0; i < N; i++) {
            XORR = XORR ^ Arr[i];
        }

        long rightMostBit = (XORR & (XORR - 1)) ^ XORR;
        long long b1 = 0; long long b2 = 0;

        for (int i = 0; i < N; i++) {
            if (Arr[i] & rightMostBit) b1 = b1 ^ Arr[i];
            else b2 = b2 ^ Arr[i];
        }

        // if(b1>b2) return {b1, b2};
        // else return {b2, b1};

        return (b1 > b2) ? vector<long long int>{b1, b2} : vector<long long int>{ b2, b1 };
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0;i < N;i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int>ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0;i < ans.size();i++)cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}