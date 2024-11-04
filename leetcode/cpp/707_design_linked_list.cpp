#include <iostream>

using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node(): val(0), next(nullptr) {}
  Node(int x): val(x), next(nullptr) {}
  Node(int x, Node* ptr): val(x), next(ptr) {}
};

class MyLinkedList {
private:
  Node* head;
  int length;
public:
  MyLinkedList() {
    head = nullptr;
    length = 0;
  }
    
  int get(int index) {
    if(index < 0 || index >= length)
      return -1;
    Node* ptr = head;
    while(index > 0) {
      ptr = ptr->next;
      index--;
    }
    return ptr->val;
  }
    
  void addAtHead(int val) {
    Node* ptr = new Node(val, head);
    head = ptr;
    length++;
  }
    
  void addAtTail(int val) {
    if(length == 0) {
      addAtHead(val);
      return;
    }
    addAtIndex(length, val);
  }
    
  void addAtIndex(int index, int val) {
    if(index > length)
      return;
    if(index == 0) {
      addAtHead(val);
      return;
    }
    Node* ptr = head;
    while(index > 1) {
      ptr = ptr->next;
      index--;
    }
    ptr->next = new Node(val, ptr->next);
    length++;
  }
    
  void deleteAtIndex(int index) {
    if(index >= length)
      return;
    if(index == 0) {
      Node* temp = head;
      head = head->next;
      delete temp;
      length--;
      return;
    }
    Node* ptr = head;
    while(index > 1) {
      ptr = ptr->next;
      index--;
    }
    Node* temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    length--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
