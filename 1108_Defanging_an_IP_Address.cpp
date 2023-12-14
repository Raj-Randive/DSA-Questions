#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string defangIPaddr(string s) {
    // Common Way
    // int i;
    // string s1;
    // for (i = 0; i < s.length(); i++) {
    //   if (s[i] == '.') {
    //     s1 += '[';
    //     s1 += '.';
    //     s1 += ']';
    //   } else {
    //     s1 += s[i];
    //   }
    // }
    // return s1;

    int i = 0;
    while (i < s.length()) {
      if (s[i] == '.') {
        s = s.substr(0, i) + "[.]" + s.substr(i + 1, -1);
        i = i + 3;
      } else {
        i++;
      }
    }
    return s;
  }
};

int main() {
  Solution s1;
  string ans;
  ans = s1.defangIPaddr("1.1.1.1");
  cout << ans << "\n";

  return 0;
}