#include <iostream>

using namespace std;

class Node {
public:
  int val;
  int count;
  Node* next;

  Node() : val(0), count(0), next(NULL) {}

  Node(int _val) : val(_val), count(1), next(NULL) {}

  Node(int _val, int _count) : val(_val), count(_count), next(NULL) {}

  Node(int _val, int _count, Node* _next)
  : val(_val), count(_count), next(_next) {}
};

class FreqStack { // runtime beat 5% memory beat 95%
public:
  Node* freq;
  int max;
  FreqStack() {
    freq = new Node(); // needed for faster delete in afterwards has a end
  }
    
  void push(int val) {
    if(freq == NULL) {
      freq = new Node(val);
      return;
    }
    Node* ptr = freq;
    while(ptr != NULL) {
      if(ptr->val == val) {
        freq = new Node(val, ptr->count + 1, freq);
        return;
      }
      ptr = ptr->next;
    }
    freq = new Node(val, 1, freq);
  }
    
  int pop() {
    Node* ptr = freq;
    Node* max_ptr;
    
    while(ptr != NULL) {
      if(ptr->count > max) {
        max = ptr->count;
        max_ptr = ptr;
      }
      ptr = ptr->next;
    }
    int result = max_ptr->val;
    max = max - 2; // actual max has to be > this max

    Node* temp = max_ptr->next; // well-known technique
    max_ptr->val = temp->val; // copy next to current to delete current
    max_ptr->count = temp->count;
    max_ptr->next = temp->next;
    delete temp;
    
    return result;
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
