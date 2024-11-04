#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int n;
  bool repeatedSubstringPattern(string s) {
    n = s.size();
    vector<int> next(n, 0);
    findnext(next, s);
    if(next[n-1] != 0 && n%(n-next[n-1]) == 0)
      return true;
    return false;
  }

  void findnext(vector<int>& next, string s) { // the famous KMP algorithm
    int j = 0;
    next[0] = j;
    for(int i = 1; i < n; i++) {
      while(j != 0 && s[i] != s[j]) {
        j = next[j-1];
      }
      if(s[i] == s[j])
        j++;

      next[i] = j;
    }
    
  }
};

int main() {
  string s = "aabaaf";
  Solution solution;
  cout << solution.repeatedSubstringPattern(s) << endl;

  return 0;
}
