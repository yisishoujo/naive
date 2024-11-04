
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
      return head;
    ListNode* pre = head;
    ListNode* cur = head->next;
    head->next = nullptr;
    head = cur->next;
    while(head != nullptr) {
      cur->next = pre;
      pre = cur;
      cur = head;
      head = head->next;
    }
    cur->next = pre;
    return cur;
  }
};
