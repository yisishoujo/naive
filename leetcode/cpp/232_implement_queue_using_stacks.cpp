#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
  stack<int> in;
  stack<int> out;
  MyQueue() {
    
  }
    
  void push(int x) {
    in.push(x);
  }
    
  int pop() {
    int x = this->peek();
    out.pop();
    return x;
  }
    
  int peek() {
    if(out.empty()) {
      while(!in.empty()) {
        int x = in.top();
        in.pop();
        out.push(x);
      }
    }
    return out.top();
  }
    
  bool empty() {
    return out.empty() && in.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
