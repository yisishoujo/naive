#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// i.e. if there is a loop
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> pre(numCourses);
    for(auto p: prerequisites) {
      pre[p[0]].push_back(p[1]);
    }
    
    vector<bool> vb(2*numCourses, false);

    for(int i = 0; i < numCourses; i++) {
      if(!helper(numCourses, i, pre, vb))
        return false;
    }
    return true;
  }

  bool helper(int n, int l, const vector<vector<int>>& pre, vector<bool>& vb) {
    if(vb[l])
      return true;
    if(vb[l+n])
      return false;
    vb[l+n] = true;
    
    for(auto i: pre[l]) {
      if(!helper(n, i, pre, vb))
        return false;
    }
    vb[l] = true;
    return true;
  }
};

/*
  // chatGPT modified
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pre(numCourses);
        for (auto p : prerequisites) {
            pre[p[1]].push_back(p[0]);  // Reverse the edges for DFS
        }

        vector<int> state(numCourses, 0);  // 0: unvisited, 1: visiting, 2: visited

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && !helper(i, pre, state))
                return false;
        }
        return true;
    }

    bool helper(int l, const vector<vector<int>>& pre, vector<int>& state) {
        if (state[l] == 1)  // Currently visiting
            return false;   // Cycle detected
        if (state[l] == 2)  // Already visited
            return true;    // No need to check again

        state[l] = 1;  // Mark as visiting
        for (auto i : pre[l]) {
            if (!helper(i, pre, state))
                return false;  // Cycle detected in recursion
        }
        state[l] = 2;  // Mark as visited
        return true;
    }
};

*/

int main() {
  Solution solution;
  int n = 5;
  vector<vector<int>> prerequisites = {{1,4},{2,4},{3,1},{3,2}};
  cout << solution.canFinish(5, prerequisites) << endl;
  return 0;
}
