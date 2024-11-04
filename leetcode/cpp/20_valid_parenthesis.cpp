#include <iostream>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<int> ms;
    for(auto it = s.begin(); it != s.end(); it++) {
      switch(*it) {
      case '(':
        ms.push(1);
        break;
      case ')':
        if(ms.empty() || ms.top() != 1)
          return false;
        ms.pop();
        break;
      case '[':
        ms.push(2);
        break;
      case ']':
        if(ms.empty() || ms.top() != 2)
          return false;
        ms.pop();
        break;
      case '{':
        ms.push(3);
        break;
      case '}':
        if(ms.empty() || ms.top() != 3)
          return false;
        ms.pop();
        break;
      }
    }
    if(ms.empty())
      return true;
    return false;
  }
};
