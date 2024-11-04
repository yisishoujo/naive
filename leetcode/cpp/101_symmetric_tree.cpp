#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if(root == NULL)
      return true;
    return isSymmetric2(root->left, root->right);
  }
  bool isSymmetric2(TreeNode* left, TreeNode* right) {
    if(left == NULL) {
      if(right == NULL)
        return true;
      return false;
    }
    if(right == NULL)
      return false;
    if(left->val != right->val)
      return false;

    return isSymmetric2(left->left, right->right) && isSymmetric2(left->right, right->left);
  }
};
