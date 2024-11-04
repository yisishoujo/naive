#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    int n = tokens.size();
    stack<int> stk;
    for(int i = 0; i < n; i++) {
      if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
        int y = stk.top();
        stk.pop();
        int x = stk.top();
        stk.pop();
        if (tokens[i] == "+") stk.push(x + y);
        if (tokens[i] == "-") stk.push(x - y);
        if (tokens[i] == "*") stk.push(x * y);
        if (tokens[i] == "/") stk.push(x / y);
      } else {
        stk.push(stoi(tokens[i]));
      }
    }
    return stk.top();
  }
};
