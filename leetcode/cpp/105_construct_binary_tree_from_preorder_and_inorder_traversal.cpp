#include <iostream>
#include <vector>
#include <unordered_map>

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

// runtime 32 only beats 8%
// im suspect many people's answer are not right
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if(n == 0)
      return NULL;
    
    unordered_map<int, int> in_index;
    for(int i = 0; i < n; i++) {
      in_index[inorder[i]] = i;
    }
    vector<int> new_pre; // this stores the structure info
    for(int i = 0; i < n; i++) {
      new_pre.push_back(in_index[preorder[i]]);
    }
    return buildTreeHelper(new_pre, inorder);  
  }

  TreeNode* buildTreeHelper(vector<int>& new_pre, vector<int>& inorder) {
    int n = new_pre.size();
    if(n == 0)
      return NULL;
    
    int root_val_index = new_pre[0];
    if(n == 1)
      return new TreeNode(inorder[root_val_index]);
    
    vector<int> left, right;
    for(int i = 1; i < n; i++) {
      if(new_pre[i] < root_val_index) {
        left.push_back(new_pre[i]);
      } else {
        right.push_back(new_pre[i]);
      }
    }

    TreeNode* root = new TreeNode(inorder[root_val_index]);
    root->left = buildTreeHelper(left, inorder);
    root->right = buildTreeHelper(right, inorder);
    return root;
  }
};

int main() {
  vector<int> preorder = {3,1,4,2,6,5,7,8};
  vector<int> inorder = {1,2,3,4,5,6,7,8};

  Solution solution;
  TreeNode* result = solution.buildTree(preorder, inorder);
  return 0;
}
