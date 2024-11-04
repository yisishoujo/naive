#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution { // 输出的是路径数，而要求的最短路径长度 // 而且也算错了
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    unordered_map<int, pair<int, int>> s;
    s[0] = {1, 1};
    unordered_set<int> reached; 
    bool changed = true;
    while(changed) {
      unordered_map<int, pair<int, int>> temp;
      changed = false;
      for(auto& e: redEdges) {
        if(s[e[0]].second != 0 && reached.find(e[1]) == reached.end()) {
          temp[e[1]].first += s[e[0]].second;
        }
      }
      for(auto& e: blueEdges) {
        if(s[e[0]].first != 0 && reached.find(e[1]) == reached.end()) {
          temp[e[1]].second += s[e[0]].first;
        }
      }
      for(auto& t: temp) {
        reached.insert(t.first);
        changed = true;
        s[t.first] = t.second;
      }
    }

    vector<int> answer(n, -1);
    for(int i = 0; i < n; i++) {
      if(reached.find(i) != reached.end())
        answer[i] = s[i].first + s[i].second;
    }
    if(answer[0] == -1)
      answer[0] = 0;
    return answer; // this returns number of shortest paths
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
