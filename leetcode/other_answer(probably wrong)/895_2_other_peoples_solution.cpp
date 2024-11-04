#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Node{
  int val;
  int time;
  int freq;
  Node(){}
  Node(int _val, int _time, int _freq){
    val=_val;
    time=_time;
    freq=_freq;
  }

    
};
struct cmp{
  bool operator () (const Node& lhs,const Node&rhs)const {
    return lhs.freq==rhs.freq?lhs.time<rhs.time:lhs.freq<rhs.freq;
  }
};
class FreqStack {
public:
    
  unordered_map<int,int> v2f; // provide frequency for node

  priority_queue<Node,vector<Node>,cmp>pq;
  // queue of node, stored in vector<node>, compare function cmp
  int global_time=0;

  FreqStack() {
  }
    
  void push(int val) {
    int f;
    if(v2f.count(val)){
      f = ++v2f[val];
    }else{
      f=1;
      v2f[val]=1;
    }
    Node n(val,global_time++,f);
    pq.push(n);
  }
    
  int pop() {
    if(pq.empty()){
      return -1;
    }
    Node n=pq.top();
    pq.pop();
    v2f[n.val]--;
    if(!v2f[n.val])
      {
        v2f.erase(n.val);
      }
    return n.val;
  }
};

int main() {
  FreqStack freqStack = FreqStack();
  freqStack.push(5); // The stack is [5]
  freqStack.push(7); // The stack is [5,7]
  freqStack.push(5); // The stack is [5,7,5]
  freqStack.push(7); // The stack is [5,7,5,7]
  freqStack.push(4); // The stack is [5,7,5,7,4]
  freqStack.push(5); // The stack is [5,7,5,7,4,5]
  freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5
  freqStack.pop();
  freqStack.pop();
  freqStack.pop();
  freqStack.pop();
  freqStack.pop();
  return 0;
}
