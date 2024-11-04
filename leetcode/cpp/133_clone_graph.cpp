#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> um;

    return helper(node, um);
  }

  Node* helper(Node* node, unordered_map<Node*, Node*>& um) {
    if(node == nullptr)
      return nullptr;
    if(um.find(node) != um.end())
      return um[node];
    
    Node* root = new Node(node->val);
    um[node] = root;
    for(auto i: node->neighbors) {
      root->neighbors.push_back(helper(i, um));
    }
    return root;
  }
};
