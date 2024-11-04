#include <iostream>
#include <vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // chatGPT suggested correction
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* ptr = head;
    ListNode* tail = nullptr;  // Previous segment's tail
    ListNode* newHead = nullptr;  // New head after first reversal

    while (ptr != nullptr) {
      vector<ListNode*> vec;
      int count = k;
      while (count-- && ptr != nullptr) {
        vec.push_back(ptr);
        ptr = ptr->next;
      }

      if (vec.size() < k) {
        if (tail != nullptr) {
          tail->next = vec[0];
        }
        break;
      }
      for (int i = k - 1; i > 0; i--) {
        vec[i]->next = vec[i - 1];
      }
      if (newHead == nullptr) {
        newHead = vec[k - 1];
      }

      if (tail != nullptr) {
        tail->next = vec[k - 1];
      }
      tail = vec[0];
      tail->next = ptr;
    }

    return newHead == nullptr ? head : newHead;
  }
};

/*
class Solution { // my original but encounter error when submit
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* ptr = head;
    ListNode* tail = head;

    while(ptr != NULL) {
      vector<ListNode*> vec;
      int count = k;
      while(count-- && ptr) {
        vec.push_back(ptr);
        ptr = ptr->next;
      }

      if(vec.size() < k)
        return head;

      for(int i = 1; i < k; i++) {
        vec[i]->next = vec[i-1];
      }
      if(tail == head) {
        head = vec[k-1];
      } else {
        tail->next = vec[k-1];
        tail = vec[0];
        tail->next = ptr;
      }
    }
    return head;   
  }
};
*/

ListNode* vectorToListNode(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;

    // Iterate through the vector and create nodes
    for (size_t i = 1; i < vec.size(); ++i) {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }

    return head;
}

int main() {
  vector<int> vec = {1,2,3,4,5};
  int k = 2;
  ListNode* head = vectorToListNode(vec);
  Solution solution;
  ListNode* result = solution.reverseKGroup(head, k);
  return 0;
}
