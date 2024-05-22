#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Find the largest power of 2
    int largestPower(int n) {
        int power = 0;
        while ((1 << power) <= n) power++;     // Means --> 2^power
        return power - 1;
    }

    int countSetBits(int n)
    {
        if (n == 0) return 0;

        int x = largestPower(n);
        int y = x * (1 << (x - 1));
        int z = n - (1 << x) + 1;
        return y + z + countSetBits(z - 1);
    }
};

int main()
{
    int t;
    cin >> t;// input testcases
    while (t--) //while testcases exist
    {
        int n;
        cin >> n; //input n
        Solution ob;
        cout << ob.countSetBits(n) << endl;
    }
    return 0;
}