#include <iostream>
#include <vector>
#include <unordered_set>

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

class Solution { // extremely uneffective
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if(n == 0)
      return NULL;
    
    int root = preorder[0];
    if(n == 1)
      return new TreeNode(root);
    
    int sep;
    unordered_set<int> us;
    for(int i = 0; i < n; i++) {
      if(inorder[i] == root) {
        sep = i;
        break;
      } else {
        us.insert(inorder[i]);
      }
    }

    vector<int> prel, prer;
    for(int i = 1; i < n; i++) {
      if(us.find(preorder[i]) != us.end()) {
        prel.push_back(preorder[i]);
      } else {
        prer.push_back(preorder[i]);
      }
    }
    
    vector<int> inl = vector<int>(inorder.begin(), inorder.begin() + sep);
    vector<int> inr = vector<int>(inorder.begin()+sep+1, inorder.end());

    if(sep == 0) {
      vector<int> prer = vector<int>(preorder.begin()+1, preorder.end());
      return new TreeNode(root, NULL, buildTree(prer, inr));
    }
    if(sep == n) {
      vector<int> prel = vector<int>(preorder.begin(), preorder.end()-1);
      return new TreeNode(root, buildTree(prel, inl), NULL);
    }
    return new TreeNode(root, buildTree(prel, inl), buildTree(prer, inr));
  }
};

/*
    unordered_map<int, int> index;
    int n = inorder.size();
    for(int i = 0; i < n; i++) {
      index[inorder[i]] = i;
    }
    vector<int> pretrans;
    for(int i = 0; i < n; i++) {
      pretrans.push_back(index[preorder[i]]);
    }
    unordered_map<int, int> lmap;
    int level = 0;
    for(int i = 0; i < n; i++) {
      lmap[pretrans[i]] = level;
      if(pretrans[i+1] < pretrans[i]) {
        level++;
      }
    }
  }
*/
