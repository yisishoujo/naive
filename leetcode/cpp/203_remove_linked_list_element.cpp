#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // no delete, only slightly less memory usage
public:
  ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr)
      return head;
    ListNode* ptr = head;
    while(ptr->next != nullptr) {
      if(ptr->next->val == val) {
        ptr->next = ptr->next->next;
      } else {
        ptr = ptr->next;
      }
    }
    if(head->val == val)
      return head->next;
    return head;
  }
};

/*
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    if(head == nullptr)
      return head;
    ListNode* dummyhead = new ListNode(0, head);
    ListNode* cur = head;
    ListNode* pre = dummyhead;
    while(cur != nullptr) {
      if(cur->val == val) {
        cur = cur->next;
        delete pre->next;
        pre->next = cur;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    head = dummyhead->next;
    delete dummyhead;
    return head;
  }
};
*/
