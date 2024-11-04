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
/*

// first solution, not passed because
// requires false return for empty root and targetSum=0
class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL) {
      if(targetSum == 0)
        return true;
      return false;
    }
    int newtarget = targetSum - root->val;
    bool left = hasPathSum(root->left, newtarget);
    bool right = hasPathSum(root->right, newtarget);
    if(left || right)
      return true;
    return false;
  }
};
 */

class Solution {
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
      return false;
    int newtarget = targetSum - root->val;
    if(root->left == NULL && root->right == NULL)
      return newtarget == 0; // return instead of add to condition beats 71%
    return hasPathSum(root->left, newtarget) || hasPathSum(root->right, newtarget);
  }
};
