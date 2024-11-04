#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> pre(numCourses, vector<int>(numCourses, 0));
    for(auto p: prerequisites) {
      if(pre[p[0]][p[1]] == -1)
        return {};
      pre[p[0]][p[1]] = 1;
      pre[p[1]][p[0]] = -1;
    }

    for(int i = numCourses - 1; i >= 0; i--) {
      vector<int> p, n;
      for(int j = 0; j < i; j++) {
        if(pre[i][j] == 1)
          n.push_back(j);
        if(pre[i][j] == -1)
          p.push_back(j);
      }
      if(!helper(p, n, pre))
        return {};
    }

    vector<int> index = {0};
    for(int i = 1; i < numCourses; i++) {
      int pos = 0;
      for(int j = 0; j < i; j++) {
        if(pre[i][j] == -1) {
          pos = min(index[j], pos);
        } else if (pre[i][j] == 1) {
          pos = max(index[j]+1, pos);
        }
      }
      for(int j = 0; j < i; j++) {
        if(index[j] >= pos) {
          index[j]++;
        }
      }
      index.push_back(pos);
    }

    vector<int> result(numCourses, 0);
    for(int i = 0; i < numCourses; i++) {
      result[index[i]] = i;
    }
    return result;
  }

  bool helper(vector<int>& p, vector<int>& n, vector<vector<int>>& pre) {
    for(auto i: p) {
      for(auto j: n) {
        if(pre[i][j] == -1)
          return false;
        pre[i][j] = 1;
        pre[j][i] = -1;
      }
    }
    return true;
  }
};
