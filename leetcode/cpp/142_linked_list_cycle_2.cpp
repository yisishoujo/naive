/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(head == nullptr)
      return nullptr;
    ListNode* ptr = head;
    unordered_set<ListNode*> mus;
    while(!mus.count(ptr)) {
      mus.insert(ptr);
      ptr = ptr->next;
      if(ptr == nullptr)
        return nullptr;
    }
    return ptr;
  }
  };
 */

// Floyd's cycle-finding algorithm
class Solution {
public:
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head; // length from head to meet is multiplier of cycle
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// time complexity: O(n) // meet before slow finish one cycle

