#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int evenlyDivides(int N) {
        int cnt = 0;
        int lastdigit;
        int m = N;
        while (N > 0) {
            lastdigit = N % 10;
            if (lastdigit != 0 && m % lastdigit == 0) {
                cnt++;
            }
            N = N / 10;
        }
        return cnt;
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0;
}