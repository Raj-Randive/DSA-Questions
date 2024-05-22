#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string oddEven(int N) {
        // Last bit of any odd number is always one.
        if (N & 1) return "odd";
        else return "even";
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
        cout << ob.oddEven(N) << endl;
    }
    return 0;
}