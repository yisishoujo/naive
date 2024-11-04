#include <iostream>

using namespace std;

class MinStack {
public:
  stack<pair<int, int>> ms;
  MinStack() {
    
  }
    
  void push(int val) {
    if(ms.empty()) {
      ms.push({val, val});
      return;
    }
    ms.push({val, min(val, ms.top().second)});
  }
    
  void pop() {
    if(ms.empty())
      return;
    ms.pop();
  }
    
  int top() {
    if(ms.empty())
      return 0;
    return ms.top().first;
  }
    
  int getMin() {
    if(ms.empty())
      return 0;
    return ms.top().second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
