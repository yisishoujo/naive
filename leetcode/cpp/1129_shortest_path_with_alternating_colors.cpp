#include <iostream>
#include <vector>

using namespace std;

class Solution { // beats 98% runtime and 99.67% memory
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<pair<int, int>> result(n, {0, 0});
    result[0] = {1, 1};

    bool changed = true;
    while(changed) {
      changed = false;
      for(auto& e: redEdges) {
        if(result[e[0]].second != 0) {
          if(result[e[1]].first == 0 || result[e[0]].second + 1 < result[e[1]].first) {
            result[e[1]].first = result[e[0]].second + 1;
            changed = true;
          }
        }
      }
      for(auto& e: blueEdges) {
        if(result[e[0]].first != 0) {
          if(result[e[1]].second == 0 || result[e[0]].first + 1 < result[e[1]].second) {
            result[e[1]].second = result[e[0]].first + 1;
            changed = true;
          }
        }
      }
    }

    vector<int> answer{n}; // no need to set default value
    for(int i = 0; i < n; i++) {
      answer[i] = (result[i].first != 0 && result[i].second != 0)? (min(result[i].first, result[i].second) - 1): (max(result[i].first, result[i].second) - 1);
    }
    return answer;
  }
};

int main() {
  int n = 6;
  vector<vector<int>> redEdges = {{3,4},{1,5},{1,0},{5,3},{2,1},{2,0},{0,3},{1,2},{5,2},{1,4},{1,3},{5,0},{4,5},{5,5},{3,3}};
  vector<vector<int>> blueEdges = {{2,5},{3,0},{1,2},{4,3},{3,4},{0,4},{5,0},{5,2},{1,0},{0,2}};

  Solution solution;
  solution.shortestAlternatingPaths(n, redEdges, blueEdges);
  return 0;
}
