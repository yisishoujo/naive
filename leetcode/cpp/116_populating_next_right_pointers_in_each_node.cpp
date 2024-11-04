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

class Solution { // too easy; the only problem is check NULL
public:
  Node* connect(Node* root) { // why has return value
    if(root == NULL || root->left == NULL) {
      return root;
    }
    if(root->left != NULL) {
      root->left->next = root->right;
      connect(root->left);
      connect(root->right);
    }
    Node* rl = root->left;
    while(rl->right != NULL) {
      rl->right->next = rl->next->left;
      rl = rl->right;
    }
    return root;
  }
};
