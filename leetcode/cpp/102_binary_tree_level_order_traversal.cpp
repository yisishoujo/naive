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

class Solution { // recursive is bad but not that bad 7ms
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == NULL)
      return {};
    vector<vector<int>> level;
    levelOrderHelper(root, level, 0);
    return level;
  }
  void levelOrderHelper(TreeNode* root, vector<vector<int>>& level, int l) {
    if(root == NULL)
      return;
    if (l == level.size())
      level.push_back({});

    level[l].push_back(root->val);
    
    levelOrderHelper(root->left, level, l+1);
    levelOrderHelper(root->right, level, l+1);
  }
};

// chatGPT suggest using a queue
class Solution2 { // 4ms
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
        
    queue<TreeNode*> q;
    q.push(root);
        
    while (!q.empty()) {
      int levelSize = q.size();
      vector<int> currentLevel;
            
      for (int i = 0; i < levelSize; ++i) {
        TreeNode* currentNode = q.front();
        q.pop();
        currentLevel.push_back(currentNode->val);
        
        if (currentNode->left) q.push(currentNode->left);
        if (currentNode->right) q.push(currentNode->right);
      }
      result.push_back(currentLevel);
    }
        
    return result;
  }
};

// then he suggest use vector
class Solution3 { // 2ms
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    vector<TreeNode*> currentLevel = {root};

    while (!currentLevel.empty()) {
      vector<int> levelValues;
      vector<TreeNode*> nextLevel;

      for (TreeNode* node : currentLevel) {
        levelValues.push_back(node->val);
        if (node->left) nextLevel.push_back(node->left);
        if (node->right) nextLevel.push_back(node->right);
      }

      result.push_back(levelValues);
      currentLevel = nextLevel;
    }

    return result;
  }
};
