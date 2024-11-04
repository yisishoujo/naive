#include <iostream>
#include <vector>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // this is one in the top solutions
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(0);
    ListNode *tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int digit1 = (l1 != nullptr) ? l1->val : 0;
      int digit2 = (l2 != nullptr) ? l2->val : 0;

      int sum = digit1 + digit2 + carry;
      int digit = sum % 10;
      carry = sum / 10;

      ListNode *newNode = new ListNode(digit);
      tail->next = newNode; // typical tail
      tail = tail->next;

      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
  }
};

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

// Function to print the linked list
void printList(ListNode *head) {
  while (head != nullptr) {
    std::cout << head->val << " -> ";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

int main() {
  std::vector<int> vec1 = {9, 9, 9, 9, 9, 9, 9};
  std::vector<int> vec2 = {9, 9, 9, 9};
  ListNode *l1 = vectorToListNode(vec1);
  ListNode *l2 = vectorToListNode(vec2);

  Solution solution;

  printList(solution.addTwoNumbers(l1, l2));

  return 0;
}
