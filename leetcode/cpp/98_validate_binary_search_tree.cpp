
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
  bool isValidBST(TreeNode* root) { // stupid boundary cases this beats 98%
    return isValidHelper(root, LONG_MIN, LONG_MAX);
  }

  bool isValidHelper(TreeNode* root, long left, long right) {
    if(root == NULL)
      return true;
    int mid = root->val;
    if(mid <= left || mid >= right)
      return false;
    
    return isValidHelper(root->left, left, mid) && isValidHelper(root->right, mid, right);
  }
};

/*
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return isValidHelper(root, INT_MIN, INT_MAX);
  }

  bool isValidHelper(TreeNode* root, int left, int right) {
    if(root == NULL)
      return true;
    int mid = root->val;
    if(mid < left || mid > right)
      return false;
    
    if(left == right)
      return mid == left && root->left == NULL && root->right == NULL;
    
    if(mid == left) { // to avoid mid-1 overflow
      if(root->left != NULL)
        return false;
      return isValidHelper(root->right, mid+1, right);
    }
    if(mid == right) {
      if(root->right != NULL)
        return false;
      return isValidHelper(root->left, left, mid-1);
    }
    
    return isValidHelper(root->left, left, mid-1) && isValidHelper(root->right, mid+1, right);
  }
};
*/
