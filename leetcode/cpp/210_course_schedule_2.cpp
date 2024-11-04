#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution { // shocking! modified from 207 so slightly
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> pre(numCourses);
    for(auto p: prerequisites) {
      pre[p[0]].push_back(p[1]);
    }
    
    vector<bool> vb(2*numCourses, false);

    vector<int> result;
    for(int i = 0; i < numCourses; i++) {
      if(!helper(numCourses, i, pre, vb, result))
        return {};
    }
    return result;
  }

  bool helper(int n, int l, const vector<vector<int>>& pre, vector<bool>& vb, vector<int>& result) {
    if(vb[l]) 
      return true;
    if(vb[l+n])
      return false;
    vb[l+n] = true;
    
    for(auto i: pre[l]) {
      if(!helper(n, i, pre, vb, result))
        return false;
    }
    result.push_back(l);
    vb[l] = true;
    return true;
  }
};
