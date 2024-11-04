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

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) {
      return head;
    }
    int count = 0;
    ListNode* l = head;
    while(l->next != NULL) {
      count++;
      l = l->next;
    }
    count++;
    k = k%count;
    k = (k>=0)?k : k + count; // only changed this a little now beats 86%
    l->next = head;
    while(true) {
      count--;
      l = l->next;
      if(count == k) {
        ListNode* temp = l->next;
        l->next = NULL;
        return temp;
      }
    }
    return NULL;
  }
};
