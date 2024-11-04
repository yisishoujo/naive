#include <iostream>

using namespace std;

/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

    MyCircularDeque(int k) Initializes the deque with a maximum size of k.
    boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
    boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
    int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
    int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
    boolean isEmpty() Returns true if the deque is empty, or false otherwise.
    boolean isFull() Returns true if the deque is full, or false otherwise.
 */

class MyCircularDeque {
public:
  int* array;
  int maxindex;
  int front;
  int last;
  bool empty;

  MyCircularDeque(int k) {
    if(k <= 0)
      return;
    array = new int[k];
    maxindex = k - 1;
    front = 0;
    last = 0;
    empty = true;
  }
    
  bool insertFront(int value) {
    if(isFull())
      return false;
    if(!isEmpty()) {
      if(front == 0) {
        front = maxindex;
      } else {
        front--;
      }
    }
    array[front] = value;
    empty = false;
    return true;
  }
    
  bool insertLast(int value) {
    if(isFull())
      return false;
    if(!isEmpty()) {
      if(last == maxindex) {
        last = 0;
      } else {
        last++;
      }
    }
    array[last] = value;
    empty = false;
    return true;
  }
    
  bool deleteFront() {
    if(isEmpty())
      return false;
    if(front == last) {
      empty = true;
      return true;
    }
    if(front == maxindex) {
      front = 0;
    } else {
      front++;
    }
    return true;
  }
    
  bool deleteLast() {
    if(isEmpty())
      return false;
    if(front == last) {
      empty = true;
      return true;
    }
    if(last == 0) {
      last = maxindex;
    } else {
      last--;
    }
    return true;
  }
    
  int getFront() {
    if(isEmpty())
      return -1;
    return array[front];
  }
    
  int getRear() {
    if(isEmpty())
      return -1;
    return array[last];
  }
    
  bool isEmpty() {
    return empty;
  }
    
  bool isFull() {
    if(isEmpty())
      return false;
    if(front - last == 1 || (front == 0 && last == maxindex))
      return true;
    return false;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
  MyCircularDeque obj = MyCircularDeque(1);
  obj.insertLast(1);

  return 0;
}
