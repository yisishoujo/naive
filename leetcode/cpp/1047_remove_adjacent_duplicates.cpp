#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> sc;
    auto it = s.end();
    while(it != s.begin()) {
      it--;
      if(!sc.empty() && sc.top() == *it)
        sc.pop();
      else
        sc.push(*it);
    }

    string r;
    while(!sc.empty()) {
      r += sc.top();
      sc.pop();
    }
    return r;
  }
};

class Solution {
public:
  string removeDuplicates(string S) {
    string result;
    for(char s : S) {
      if(result.empty() || result.back() != s)
        result.push_back(s);
      else
        result.pop_back();
    }
    return result;
  }
};
