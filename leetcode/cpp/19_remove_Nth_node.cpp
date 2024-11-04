/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution { // traverse exactly once
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n <= 0)
      return head;
    ListNode* ptr = head;
    for(int i = 0; i < n; i++) {
      if(ptr == nullptr)
        return head;
      ptr = ptr->next;
    }
    ListNode* p = head;
    if(ptr == nullptr) {
      head = head->next;
      delete p;
      return head;
    }
    while(ptr->next != nullptr) {
      p = p->next;
      ptr = ptr->next;
    }
    ptr = p->next->next;
    delete p->next;
    p->next = ptr;
    return head;
  }
};
