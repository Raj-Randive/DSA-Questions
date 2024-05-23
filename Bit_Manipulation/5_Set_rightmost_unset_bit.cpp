#include<bits/stdc++.h> 
using namespace std;

class Solution
{
public:
    int setBit(int N)
    {
        //check if all the bits are set to 1 then directly return the number
        if (N & (N + 1) == 0) return N;
        return (N | N + 1);
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
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}