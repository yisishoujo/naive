#include <iostream>
#include <vector>
#include <string>

using namespace std;

// stupid test case s=p="" waste me a lot of time
class Solution {
public:
  int length;
  bool isMatch(string s, string p) {
    length = s.size();
    int pos = 0;
    
    vector<string> par = parse(p);
    // too many edge cases
    int i = 0;
    int m = par.size();
    if(m == 0) {
      if(length == 0)
        return true;
      return false;
    }
    if(p[0] != '*') {
      if(!match_helper(s, par[0]))
        return false;
      pos += par[0].size();
      i++;
      if(m == 1) {
        if(pos == length)
          return true;
        return false;
      }
    }
    
    for(; i < m-1; i++) {
      if(!match_helper(s, pos, par[i]))
        return false;
    }
    
    int last = par[m-1].size();
    if(last != 0) {
      if(pos > length - last)
        return false;
      pos = length - last;
      if(!match_helper(s, pos, par[m-1]))
        return false;
    }
    
    return true;
  }

  vector<string> parse(string p) { // split by *
    vector<string> result;
    int n = p.size();
    int i = 0;
    while(i < n) {
      string ps;
      while(i < n && p[i] == '*') {
        i++;
      }
      while(i < n && p[i] != '*') {
        ps += p[i];
        i++;
      }
      result.push_back(ps);
    }
    return result;
  }

  bool match_helper(string &s, string p) {
    int n = p.size();
    if(n > length)
      return false;

    for(int i = 0; i < n; i++) {
      if(p[i] != '?' && s[i] != p[i])
        return false;
    }

    return true;
  }

  bool match_helper(string &s, int &pos, string p) {
    int n = p.size();
    
    if(pos + n > length)
      return false;
    while(pos+n <= length) {
      int i = 0;
      for(; i < n; i++) {
        if(p[i] != '?' && s[pos+i] != p[i])
          break;
      }
      if(i == n) {
        pos += n;
        return true;
      }
      pos++;
    }
    return false;
  }
};

int main() {
  string s = "mississippi", p = "m??*ss*?i*pi";
  Solution solution;
  cout << solution.isMatch(s, p) << endl;
  return 0;
}
