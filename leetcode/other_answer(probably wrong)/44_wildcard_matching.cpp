#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution { // time limit exceeded on stupid testcase
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int pl = p.size();
    if(pl == 0)
      return n == 0;
    
    bool ge = false;
    bool onlyl = true;
    int len = 0;
    int i = 0;
    for(; i < pl; i++) {
      if(p[i] == '*') {
        ge = true;
      } else if(p[i] == '?') {
        len++;
      } else {
        onlyl = false;
        break;
      }
    }

    if(onlyl)
      return (ge)? (n >= len) : (n == len);
    
    if(ge) {
      for(int j = len; j < n; j++) {
        if(s[j] == p[i] && isMatch(s.substr(j+1), p.substr(i+1)))
          return true;
      }
      return false;
    }

    if(len > 0)
      return s[len] == p[i] && isMatch(s.substr(len+1), p.substr(i+1));

    if(p[0] != s[0])
      return false;
    return isMatch(s.substr(1), p.substr(1));
  }
};
