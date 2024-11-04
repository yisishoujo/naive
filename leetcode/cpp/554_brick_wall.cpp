#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    int n = wall.size();
    unordered_map<int, int> gap; // unordered_map
    for(const auto& row: wall) {
      int m = 0;
      for(const auto& b:row) { // avoid最后一项可以降低runtime
        gap[m]++;
        m += b;
      }
    }
    gap[0] = 0;
    int maxgap = 0;
    for(const auto& a: gap) {
      if(a.second > maxgap)
        maxgap = a.second; // 改成maxGap = max(maxGap, a.second);可以降低runtime
    }

    return n - maxgap;
  }
};

int main() {
  vector<vector<int>> wall = {{1,1}, {2}, {1,1}};
  Solution solution;
  cout << solution.leastBricks(wall) << endl;
  return 0;
}
