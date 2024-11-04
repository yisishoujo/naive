#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution { // 最短的交替颜色的路径长度 // 依然算错了
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    unordered_map<int, pair<bool, bool>> s;
    s[0] = {1, 1};
    unordered_map<int, int> reached;
    reached[0] = 0;
    bool changed = true;
    int length = 0;
    while(changed) {
      unordered_map<int, pair<bool, bool>> temp;
      changed = false;
      length++;
      for(auto& e: redEdges) {
        if(s[e[0]].second && reached.find(e[1]) == reached.end()) {
          temp[e[1]].first = true;
        }
      }
      for(auto& e: blueEdges) {
        if(s[e[0]].first && reached.find(e[1]) == reached.end()) {
          temp[e[1]].second = true;
        }
      }
      for(auto& t: temp) {
        reached[t.first] = length;
        changed = true;
        s[t.first] = t.second;
      }
    }

    vector<int> answer(n, -1);
    for(int i = 0; i < n; i++) {
      if(reached.find(i) != reached.end())
        answer[i] = reached[i];
    }
    return answer;
  }
};

int main() {
  int n = 3;
  vector<vector<int>> redEdges = {{0,1},{1,2}};
  vector<vector<int>> blueEdges = {};

  Solution solution;
  solution.shortestAlternatingPaths(n, redEdges, blueEdges);
  return 0;
}
