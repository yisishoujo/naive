#include <iostream>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
  : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution { // much faster
public:
  Node* connect(Node* root) {
    Node* parent = root;
    Node* dummy = new Node();

    while(parent != NULL) {
      Node* curr = parent;
      Node* child = dummy;

      while(curr != NULL) {
        if(curr->left != NULL) {
          child->next = curr->left;
          child = child->next;
        }
        if(curr->right != NULL) {
          child->next = curr->right;
          child = child->next;
        }
        curr = curr->next;
      }
      parent = dummy->next;
      dummy->next = NULL;
    }
    delete dummy;

    return root;
  }
};

int main() {
  Node* n7 = new Node(7);
  Node* n8 = new Node(8);
  Node* n5 = new Node(5);
  Node* n6 = new Node(6, NULL, n8, NULL);
  Node* n4 = new Node(4, n7, NULL, NULL);
  Node* n3 = new Node(3, NULL, n6, NULL);
  Node* n2 = new Node(2, n4, n5, NULL);
  Node* n1 = new Node(1, n2, n3, NULL);

  Solution solution;
  solution.connect(n1);

  cout << n2->next->val << endl;
  cout << n5->next->val << endl;
  cout << n7->next->val << endl;
  return 0;
}
