#include <iostream>
#include <vector>

using namespace std;

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // by far the most confortable solution written by me
public:
  ListNode* partition(ListNode* head, int x) {  
    ListNode* above_head = new ListNode(0);
    ListNode* under_head = new ListNode(0);
    ListNode* index = head;
    ListNode* above_tail = above_head;
    ListNode* under_tail = under_head;

    for(; index != nullptr; index = index->next) {
      if(index->val < x) {
        under_tail->next = index;
        under_tail = index; 
      } else {
        above_tail->next = index;
        above_tail = index;
      }
    }

    under_tail->next = above_head->next;
    above_tail->next = nullptr;

    ListNode* result = under_head->next;
    delete above_head;
    delete under_head;

    return result;
  }
};

// used in problem 2
ListNode *vectorToListNode(const std::vector<int> &vec) {
  if (vec.empty())
    return nullptr;

  ListNode *head = new ListNode(vec[0]);
  ListNode *current = head;

  for (size_t i = 1; i < vec.size(); ++i) {
    current->next = new ListNode(vec[i]);
    current = current->next;
  }

  return head;
}

void printList(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->val << " -> ";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

int main() {
  vector<int> vec = {1,4,3,2,5,2};
  int x = 3;
  ListNode* head = vectorToListNode(vec);

  Solution solution;
  printList(solution.partition(head, x));

  return 0;
}
