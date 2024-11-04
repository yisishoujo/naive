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

class Solution {
public:
  Node* connect(Node* root) { // 可以改良一层一层地做
    if(root == NULL) {
      return root;
    }
    if(root->left == NULL) {
      connect(root->right);
      return root;
    }
    if(root->right == NULL) {
      connect(root->left);
      return root;
    }

    root->left->next = root->right;
    connect(root->right);

    rfindRL(root->left);

    return root;
  }
  
  Node* findRL(Node* root) {
    if(root->next == NULL)
      return NULL;
    root = root->next;
    while(root->left == NULL && root->right == NULL && root->next != NULL) {
      root = root->next;
    }
    
    if(root->left != NULL)
      return root->left;
    if(root->right != NULL)
      return root->right;
    return NULL;
  }

  Node* rfindRL(Node* root) {
    if(root == NULL)
      return NULL;
    if(root->right != NULL) {
      root->right->next = findRL(root);
      rfindRL(root->right);
    }
    if(root->left != NULL) {
      root->left->next = (root->right == NULL)? findRL(root): root->right;
      rfindRL(root->left);
    }
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

/*
class Solution {
public:
  Node* connect(Node* root) {
    if(root == NULL) {
      return root;
    }
    if(root->left == NULL) {
      connect(root->right);
      return root;
    }
    if(root->right == NULL) {
      connect(root->left);
      return root;
    }

    root->left->next = root->right;
    connect(root->left);
    connect(root->right);

    Node* rl = root->left;
    bool not_bottom = true;
    while(not_bottom) { // 不能处理中间较短两头深层的情况
      Node* rr = (rl->next->left == NULL)? rl->next->right: rl->next->left;
      if(rr == NULL)
        return root;
      if(rl->right != NULL) {      
        rl->right->next = rr;
        rl = rl->right;
      } else {
        if(rl->left == NULL)
          return root;
        rl->left->next = rr;
        rl = rl->left;
      }
    }
    return root;
  }
};
*/
