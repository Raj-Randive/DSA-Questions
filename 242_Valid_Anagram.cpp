#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    // The first approach in my mind - "Sorting"

    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // if(s==t) return true;
    // return false;

    // 2nd Approach - Hashing
    vector<int> v(26, 0);
    if (s.length() != t.length())
      return false;
    for (int i = 0; i < s.length(); i++) {
      v[s[i] - 'a']++;
      v[t[i] - 'a']--;
    }
    for (int x : v) {
      if (x != 0)
        return false;
    }
    return true;
  }
};

int main() {
  class Solution sol;
  cout << sol.isAnagram("anagram", "nagaram") << "\n";

  return 0;
}